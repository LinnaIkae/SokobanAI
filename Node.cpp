/* 
 * File:   Node.cpp
 * Author: Lefa
 * 
 * Created on 24. November 2018, 15:50
 */

#include "Node.hpp"

Node::Node(Node* parent_, sf::Vector2i agent_, std::vector<sf::Vector2i> boxes_) :
agent(agent_), parent(parent_), boxes(boxes_) {
};

Node::Node(const Node& orig) {
}

Node::~Node() {
}


