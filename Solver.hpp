#pragma once
/* 
 * File:   Solver.hpp
 * Author: Lefa
 *
 * Created on 24. November 2018, 14:47
 * 
 * Parent class/interface where all the different sokoban solvers should inherit
 * their basic functions.
 */
#include <vector>
#include <string>
#include "Node.hpp"

class Solver {
private:
public:
    Solver();
    Solver(const Solver& orig);
    virtual ~Solver();

    enum Dir {
        DOWN, UP, LEFT, RIGHT
    };

    static void parseInput(std::vector<std::string> lines);

    void setColumns(int columns) {
        this->columns = columns;
    }

    std::vector<int> getPositions() const {
        return positions;
    }

    void setPositions(std::vector<int> positions) {
        this->positions = positions;
    }

    void setRows(int rows) {
        this->rows = rows;
    }


private:
    int rows, columns;
    std::vector<int> positions;
    std::vector<Node> nodes;

};
