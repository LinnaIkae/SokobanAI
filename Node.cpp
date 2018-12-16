/* 
 * File:   Node.cpp
 * Author: Lefa
 * 
 * Created on 24. November 2018, 15:50
 */

#include "Node.hpp"
#include <iostream>

Node::Node() {
}

Node::Node(sf::Vector2i agent_, std::list<sf::Vector2i> boxes_) :
agent(agent_), parent(nullptr), boxes(boxes_) {
};

Node::Node(sf::Vector2i agent_, std::list<sf::Vector2i> boxes_, Node* parent_) :
agent(agent_), parent(parent_), boxes(boxes_) {
};

Node::Node(const Node& orig) {
    agent = orig.agent;
    boxes = orig.boxes;
    parent = orig.parent;
}

Node::~Node() {
    //delete parent; //causes crash
}


using std::cout;
using std::endl;

void Node::debugPrint() const {
    cout << "<<<< Node at: " << agent.x << ", " << agent.y << endl;
    cout << "  Address of this node: " << this << endl;
    cout << "  Pointer to parent:    " << parent << endl;
    cout << "  Boxes: " << endl;
    for (auto b : boxes) {
        cout << "    " << b.x << ", " << b.y << endl;
    }
    cout << ">>>>" << endl;
};

