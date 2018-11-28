#pragma once
/* 
 * File:   Node.hpp
 * Author: Lefa
 *
 * Created on 24. November 2018, 15:50
 */
#include <vector>
#include <SFML/Graphics.hpp>

class Node {
private:
    Node();
public:
    Node(sf::Vector2i agent_, std::vector<sf::Vector2i> boxes_);
    Node(sf::Vector2i agent_, std::vector<sf::Vector2i> boxes_, Node* parent_);
    Node(const Node& orig);
    virtual ~Node();

    //int getDegree();
    //    void addEdge(Edge e);
    //    void addEdges(std::vector<Edge> e);
    //    void removeEdge(Edge e);
    //    void removeEdges(std::vector<Edge> e);
    //std::vector<Edge> getEdges_Out();


public:
    sf::Vector2i agent;
    Node* parent;
    std::vector<sf::Vector2i> boxes;
    //std::vector<Edge> edges_out;

};



