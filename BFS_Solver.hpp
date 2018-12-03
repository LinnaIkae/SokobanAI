/* 
 * File:   BFS_Solver.hpp
 * Author: Lefa
 *
 * Created on 24. November 2018, 15:27
 */

#pragma once
#include "Solver.hpp"
#include <iostream>
#include "Grid.hpp"

class BFS_Solver : public Solver {
public:
    BFS_Solver();
    BFS_Solver(std::vector<std::string> lines);
    BFS_Solver(const BFS_Solver& orig);
    virtual ~BFS_Solver();

    virtual Node popFringe();
    bool graphSearch(Grid& g, sf::RenderWindow& window);
private:

};

