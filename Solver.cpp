#include "Solver.hpp"
#include <iostream>

Solver::Solver() :
agent(0, 0) {
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

std::vector<Node> Solver::expandEdges(Node& n) {
    std::vector<Node> children;
    sf::Vector2i mv_down(0, 1);
    sf::Vector2i mv_up(0, -1);
    sf::Vector2i mv_right(1, 0);
    sf::Vector2i mv_left(-1, 0);
    std::vector<sf::Vector2i> mvs = {mv_down, mv_up, mv_right, mv_left};

    sf::Vector2i pu_down = sf::Vector2i(0, 2) + n.agent;
    sf::Vector2i pu_up = sf::Vector2i(0, -2) + n.agent;
    sf::Vector2i pu_right = sf::Vector2i(2, 0) + n.agent;
    sf::Vector2i pu_left = sf::Vector2i(-2, 0) + n.agent;
    std::vector<sf::Vector2i> pshs = {pu_down, pu_up, pu_right, pu_left};

    for (unsigned i = 0; i < mvs.size(); i++) {
        sf::Vector2i mvv = mvs[i] + n.agent;
        int moveBox = std::count(n.boxes.begin(), n.boxes.end(), mvv);
        if (moveBox == 1) {
            // Neighbor tile contains a box
            sf::Vector2i push = pshs[i];
            std::pair<int, int> pushp(push.x, push.y);
            int pushBox = std::count(n.boxes.begin(), n.boxes.end(), push);
            int pushFree = this->freeSpaces.count(pushp);
            if (pushFree == 1 && pushBox == 0) {
                Node child(mvv, n.boxes, &n);
                children.push_back(child);
                std::cout << "adding push: " << mvv.x << ", " << mvv.y << " " <<
                        pushp.first << ", " << pushp.second << std::endl;
            }
        } else {
            //Neigbor tile can be moved to.
            std::pair<int, int> mv(mvv.x, mvv.y);
            int moveFree = this->freeSpaces.count(mv);
            if (moveFree == 1) {
                Node child(mvv, n.boxes, &n);
                children.push_back(child);
                std::cout << "adding move: " << mv.first << ", " << mv.second << std::endl;
            }
        }
    }
    return children;
}




