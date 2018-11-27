/* 
 * File:   Node.cpp
 * Author: Lefa
 * 
 * Created on 24. November 2018, 15:50
 */

#include "Node.hpp"

Node::Node(sf::Vector2i agent_, Node* parent_, std::vector<Edge> edges_out_) :
agent(agent_), parent(parent_), edges_out(edges_out_) {
};

Node::Node(const Node& orig) {
}

Node::~Node() {
}

