/* 
 * File:   Node.hpp
 * Author: Lefa
 *
 * Created on 24. November 2018, 15:50
 */
#pragma once
#include <vector>

class Node;

struct Edge {
    const Node* dest; //TODO: figure this stuff out, maybe smart pointer
    const int weight;
};

class Node {
public:
    Node(const Node& orig);
    virtual ~Node();

    Node(int x_, int y_, Node* parent_, std::vector<Edge> edges_out_);

    int getDegree();

    void addEdge(Edge e);
    void addEdges(std::vector<Edge> e);
    void removeEdge(Edge e);
    void removeEdges(std::vector<Edge> e);

    std::vector<Edge> getEdges_Out();

private:
    Node();

public:
    int x, y;
    Node* parent;
    std::vector<Edge> edges_out;

};



