/* 
 * File:   Grid.cpp
 * Author: Lefa
 * 
 * Created on November 20, 2018, 11:24 PM
 * 
 * cerdit for sprites to: 1001.com
 * 
 */

#include <valarray>

#include "Grid.h"

Grid::Grid(sf::Vector2f s_cell, unsigned int rows_, unsigned int columns_):
    cellSize(s_cell), rows(rows_), columns(columns_){
    vector<sf::Vector2f> cellPosit;
    for(int i = 0; i < rows ; i++){
        for( int j = 0; j < columns ; j++){
            cellPosit.push_back(getCellPos(i, j));
        }
    }
    for(sf::Vector2f pos: cellPosit){
        sf::RectangleShape rect(cellSize);
        rect.setPosition(pos);
        Cells.push_back(rect);
        //cout<<"Size of Cells: "<<Cells.size()<<endl;
    }
}

Grid::Grid() {
}

Grid::Grid(const Grid& orig) {
}

Grid::~Grid() {
}
sf::Vector2f Grid::getCellPos(float row, float column){
        float posx = cellSize.x*row;
        float posy = cellSize.y*column;
        return sf::Vector2f(posx, posy);
    }
sf::Vector2f Grid::getCellPos(sf::Vector2f vec){
        float posx = cellSize.x*vec.x;
        float posy = cellSize.y*vec.y;
        return sf::Vector2f(posx, posy);
    }

void Grid::draw(sf::RenderWindow& window){
        for(sf::RectangleShape rect: Cells){
            window.draw(rect);
        }
    }

sf::RectangleShape& Grid::getCellAt(int row, int col){
    int index = row*columns+col;
    cout << "index: " << index << endl;
    return Cells.at(index);
}

void Grid::setTexture(const sf::Texture* txtr, sf::IntRect sr, int row, int col){
    sf:: RectangleShape& rect = getCellAt(row, col);
    cout << "x: "<< rect.getPosition().x << ", y: " << rect.getPosition().y <<endl;
    rect.setTexture(txtr);
    rect.setTextureRect(sr);
}
