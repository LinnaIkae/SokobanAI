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
#include <SFML/Graphics.hpp>

class Solver {
public:
    Solver();
    Solver(const Solver& orig);
    virtual ~Solver();

    enum Dir {
        DOWN, UP, LEFT, RIGHT
    };

    void parseInput(std::vector<std::string> lines);

    void setColumns(int columns) {
        this->columns = columns;
    }

    void setRows(int rows) {
        this->rows = rows;
    }

    void logLocations() const;

    std::vector<Node> expandNode(Node n);

protected:
    std::vector<sf::Vector2i> freeSpaces;
    std::vector<sf::Vector2i> boxes;
    std::vector<sf::Vector2i> goals;
    sf::Vector2i agent;
    std::vector<Node> nodes;
public:
    int rows, columns;

};
