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
#include <set>
#include <list>
#include "Node.hpp"
#include <SFML/Graphics.hpp>

class Solver {
public:
    Solver();
    Solver(std::vector<std::string> lines);
    Solver(const Solver& orig);
    virtual ~Solver();

    enum Dir {
        DOWN, UP, LEFT, RIGHT
    };

    void parseInput(std::vector<std::string> lines);

    void logLocations() const;

    std::list<Node> expandEdges(Node& n);

    bool goalCheck(Node& node);

    std::vector<Node> retracePath(Node node) const;

    void printFringe();

public:
    sf::Vector2i agent;
    std::set<std::pair<int, int> > freeSpaces;
    std::set<std::pair<int, int> > walls;
    std::list<sf::Vector2i> boxes;
    std::vector<sf::Vector2i> goals;
    std::list<Node> fringe, closed;
    int rows, columns;


};
