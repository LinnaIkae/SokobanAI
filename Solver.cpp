#include "Solver.hpp"
#include <iostream>

Solver::Solver() :
agent(0, 0) {
}

Solver::Solver(std::vector<std::string> lines) :
agent(0, 0), fringe(std::vector<Node>(0)) {
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
        std::string line = lines[y];
        if (line.length() > (unsigned) this->rows) {
            this->rows = line.length();
        }
        this->columns += 1;
        std::cout << line << std::endl;
        for (unsigned x = 0; x < line.length(); x++) {
            char c = line[x];
            std::pair<int, int> coords(x, y);
            sf::Vector2i coords_v(x, y);
            switch (c) {
                case(' '):
                {
                    this->freeSpaces.insert(coords);
                    break;
                }
                case('#'):
                {
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

std::vector<Node> Solver::expandEdges(Node& node) {
    std::vector<Node> children;
    children.reserve(4);
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
            // Neighbor tile contains a box
            sf::Vector2i push = pshs[i];
            std::pair<int, int> pushp(push.x, push.y);

            //error happening here
            int box_is_blocking = (std::count(node.boxes.begin(), node.boxes.end(),
                    push));

            int behind_is_free = this->freeSpaces.count(pushp);

            if (behind_is_free == 1 && box_is_blocking == 0) {
                std::vector<sf::Vector2i> newBoxes = node.boxes;
                std::vector<sf::Vector2i>::iterator box_it = std::find(
                        newBoxes.begin(), newBoxes.end(), mvv);

                newBoxes.erase(box_it);
                newBoxes.push_back(push);
                for (int i = 0; i < newBoxes.size(); i++) {
                    std::cout << "Old box: " << node.boxes[i].x << node.boxes[i].y << std::endl;
                    std::cout << "New box: " << newBoxes[i].x << newBoxes[i].y << std::endl;
                }

                Node child(mvv, newBoxes, &node);
                children.push_back(child);
                std::cout << "adding push: " << mvv.x << ", " << mvv.y << " " <<
                        pushp.first << ", " << pushp.second << std::endl;
            }
        } else {
            //Neigbor tile has no box.
            std::pair<int, int> mv(mvv.x, mvv.y);
            int moveFree = this->freeSpaces.count(mv);
            if (moveFree == 1) {

                Node child(mvv, node.boxes, &node);
                children.push_back(child);
                std::cout << "adding move: " << mv.first << ", " << mv.second << std::endl;
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

std::vector<Node*> Solver::retracePath(Node* node) const {
    std::vector<Node*> steps;
    while ((*node).parent != NULL) {
        steps.push_back(node);
        std::cout << "Pointer before: " << node << "Parent: " << node->parent << std::endl;
        node = (*node).parent;
        std::cout << "pointer after: " << node << "Parent: " << node->parent << std::endl;
        return steps;
        //std::cout << (*node).agent.x << (*node).agent.y << std::endl;
        //std::cout << (*(*node).parent).agent.x << (*(*node).parent).agent.y << std::endl;
    }
    return steps;



}




