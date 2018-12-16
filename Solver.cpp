#include "Solver.hpp"
#include <iostream>

Solver::Solver() :
agent(0, 0) {
}

Solver::Solver(std::vector<std::string> lines) :
agent(0, 0), fringe(std::list<Node>(0)) {
    this->parseInput(lines);
}

Solver::Solver(const Solver& orig) {
}

Solver::~Solver() {
}

void Solver::logLocations() const {
    std::cout << "Agent: " << agent.x << ", " << agent.y << std::endl;

    std::cout << "Free spaces (x, y)" << std::endl;
    for (auto v : this->freeSpaces) {
        std::cout << v.first << ", " << v.second << std::endl;
    }
    std::cout << "Boxes (x, y)" << std::endl;
    for (auto v : this->boxes) {
        std::cout << v.x << ", " << v.y << std::endl;
    }
    std::cout << "Goals (x, y)" << std::endl;
    for (auto v : this->goals) {

        std::cout << v.x << ", " << v.y << std::endl;
    }
}

void Solver::parseInput(std::vector<std::string> lines) {
    this->rows = 0;
    this->columns = 0;
    for (unsigned y = 0; y < lines.size(); y++) {
        bool hit_left_wall = false;
        std::string line = lines[y];
        if (line.length() > (unsigned) this->columns) {
            this->columns = line.length();
        }
        this->rows += 1;
        std::cout << line << std::endl;

        for (unsigned x = 0; x < line.length(); x++) {
            char c = line[x];
            std::pair<int, int> coords(x, y);
            sf::Vector2i coords_v(x, y);
            switch (c) {
                case(' '):
                {
                    if (hit_left_wall) {
                        this->freeSpaces.insert(coords);
                    }
                    break;
                }
                case('#'):
                {
                    hit_left_wall = true;
                    this->walls.insert(coords);
                    break;
                }
                case('$'):
                {
                    this->freeSpaces.insert(coords);
                    this->boxes.push_back(coords_v);
                    break;
                }
                case('*'):
                {
                    this->freeSpaces.insert(coords);
                    this->boxes.push_back(coords_v);
                    this->goals.push_back(coords_v);
                    break;
                }
                case('@'):
                {
                    this->freeSpaces.insert(coords);
                    this->agent = coords_v;
                    break;
                }

                case('.'):
                {
                    this->freeSpaces.insert(coords);
                    this->goals.push_back(coords_v);
                    break;
                }
                case('+'):
                {
                    this->freeSpaces.insert(coords);
                    this->agent = coords_v;
                    this->goals.push_back(coords_v);
                    break;
                }
                default:
                {

                }

            }
        }
    }
}

std::list<Node> Solver::expandEdges(Node& node) {
    std::list<Node> children;
    sf::Vector2i mv_down(0, 1);
    sf::Vector2i mv_up(0, -1);
    sf::Vector2i mv_right(1, 0);
    sf::Vector2i mv_left(-1, 0);
    std::vector<sf::Vector2i> mvs = {mv_down, mv_up, mv_right, mv_left};

    sf::Vector2i pu_down = sf::Vector2i(0, 2) + node.agent;
    sf::Vector2i pu_up = sf::Vector2i(0, -2) + node.agent;
    sf::Vector2i pu_right = sf::Vector2i(2, 0) + node.agent;
    sf::Vector2i pu_left = sf::Vector2i(-2, 0) + node.agent;
    std::vector<sf::Vector2i> pshs = {pu_down, pu_up, pu_right, pu_left};

    for (unsigned i = 0; i < mvs.size(); i++) {
        sf::Vector2i mvv = mvs[i] + node.agent;
        int neighbor_has_box = std::count(node.boxes.begin(), node.boxes.end(), mvv);

        if (neighbor_has_box == 1) {
            sf::Vector2i push = pshs[i];
            std::pair<int, int> pushp(push.x, push.y);

            int box_is_blocking = (std::count(node.boxes.begin(), node.boxes.end(),
                    push));

            int behind_is_free = freeSpaces.count(pushp);

            if (behind_is_free == 1 && box_is_blocking == 0) {
                std::list<sf::Vector2i> newBoxes = node.boxes;

                newBoxes.remove(mvv);
                newBoxes.push_back(push);

                Node child(mvv, newBoxes, &node);
                std::cout << "parent: " << std::endl;
                node.debugPrint();

                std::cout << "child: " << std::endl;
                child.debugPrint();
                children.push_back(child);
            }
        } else {
            //Neigbor tile has no box.
            std::pair<int, int> mv(mvv.x, mvv.y);
            int moveFree = this->freeSpaces.count(mv);
            if (moveFree == 1) {

                Node child(mvv, node.boxes, &node);
                children.push_back(child);
                //std::cout << "adding move: " << mv.first << ", " << mv.second << std::endl;
            }
        }
    }
    return children;
}

bool Solver::goalCheck(Node& node) {
    // This seems to be working.
    int goals_satisfied = 0;
    int box_in_goal;
    for (auto goal : goals) {
        box_in_goal = std::count(node.boxes.begin(), node.boxes.end(),
                goal);
        goals_satisfied += box_in_goal;
    }

    if (goals_satisfied == goals.size()) {
        return true;
    } else return false;

}

std::vector<Node> Solver::retracePath(Node node) const {


    //might be best to also or only return the path in LUDR - format

    std::vector<Node> steps;
    while ((node).parent != NULL) {
        steps.push_back(node);
        node.debugPrint();
        node = *(node.parent);
        return steps;
    }
    return steps;
}

void Solver::printFringe() {
    std::cout << "----- Fringe: -----" << std::endl;
    for (auto f : fringe) {
        f.debugPrint();
    }

}


