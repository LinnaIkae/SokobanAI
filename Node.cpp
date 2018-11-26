/* 
 * File:   Node.cpp
 * Author: Lefa
 * 
 * Created on 24. November 2018, 15:50
 */

#include "Node.hpp"

Node::Node(int x_, int y_, Node* parent_, std::vector<Edge> edges_out_) :
x(x_), y(y_), parent(parent_), edges_out(edges_out_) {
};

Node::Node(const Node& orig) {
}

Node::~Node() {
}

