#pragma once
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DFS_Solver.hpp
 * Author: Lefa
 *
 * Created on 3. Dezember 2018, 18:48
 */
#include "Solver.hpp"
#include "BFS_Solver.hpp"

class DFS_Solver : public BFS_Solver {
public:
    DFS_Solver();
    DFS_Solver(std::vector<std::string> lines);
    DFS_Solver(const DFS_Solver& orig);
    virtual ~DFS_Solver();

    Node popFringe();
private:

};


