#include "Solver.hpp"
#include <iostream>

Solver::Solver() {
}

Solver::Solver(const Solver& orig) {
}

Solver::~Solver() {
}

static void Solver::parseInput(std::vector<std::string> lines) {
    for (auto line : lines) {
        std::cout << "line of input: " << line << std::endl;
    }
}



