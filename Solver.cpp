#include "Solver.hpp"
#include <iostream>

Solver::Solver() {
}

Solver::Solver(const Solver& orig) {
}

Solver::~Solver() {
}

void Solver::logLocations() const {
    std::cout << "Agent: " << agent.x << ", " << agent.y << std::endl;

    std::cout << "Free spaces (x, y)" << std::endl;
    for (auto v : this->freeSpaces) {
        std::cout << v.x << ", " << v.y << std::endl;
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
    for (int y = 0; y < lines.size(); y++) {
        std::string line = lines[y];
        if (line.length() > this->rows) {
            this->rows = line.length();
        }
        this->columns += 1;
        std::cout << "line of input: " << line << std::endl;
        for (int x = 0; x < line.length(); x++) {
            char c = line[x];
            sf::Vector2i coords(x, y);
            switch (c) {
                case(' '):
                {
                    this->freeSpaces.push_back(coords);
                    break;
                }
                case('#'):
                {
                    break;
                }
                case('$'):
                {
                    this->freeSpaces.push_back(coords);
                    this->boxes.push_back(coords);
                    break;
                }
                case('*'):
                {
                    this->freeSpaces.push_back(coords);
                    this->boxes.push_back(coords);
                    this->goals.push_back(coords);
                    break;
                }
                case('@'):
                {
                    this->freeSpaces.push_back(coords);
                    this->agent = coords;
                    break;
                }

                case('.'):
                {
                    this->freeSpaces.push_back(coords);
                    this->goals.push_back(coords);
                    break;
                }
                case('+'):
                {
                    this->freeSpaces.push_back(coords);
                    this->agent = coords;
                    this->goals.push_back(coords);
                    break;
                }
                default:
                {

                }

            }
        }
    }
}



