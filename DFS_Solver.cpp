/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DFS_Solver.cpp
 * Author: Lefa
 * 
 * Created on 3. Dezember 2018, 18:48
 */

#include "DFS_Solver.hpp"

DFS_Solver::DFS_Solver() {
}

DFS_Solver::DFS_Solver(std::vector<std::string> lines) :
BFS_Solver(lines) {
};

DFS_Solver::DFS_Solver(const DFS_Solver& orig) {
}

DFS_Solver::~DFS_Solver() {
}

Node DFS_Solver::popFringe() {
    Node n = this->fringe.back();

    const std::vector<Node>::iterator fringe_it = std::find(
            fringe.begin(), fringe.end(), n);

    fringe.erase(fringe_it);
    return n;
}

