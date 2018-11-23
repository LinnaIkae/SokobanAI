#pragma once
/* 
 * File:   Grid.h
 * Author: Lefa
 *
 * Created on November 20, 2018, 11:24 PM
 * 
 */

//Seuraavaksi pitäisi sisällyttää ehkä rectanglet tai tiedot niistä tämän
//luokan sisälle.

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class Grid {
public:
    Grid();
    Grid(sf::Vector2f s_cell,unsigned int rows_,unsigned int columns_);
    Grid(const Grid& orig);
    virtual ~Grid();
     
    sf::Vector2f getCellSize(){
        return cellSize;
    }
    unsigned int getRows(){
        return rows;
    }
    unsigned int getColumns(){
        return columns;
    }
    int getCellAmount(){
        return Cells.size();
    }
    void setCellSize(const sf::Vector2f cs){
        cellSize = cs;
    }
    void setRows(const unsigned int rows_){
        rows = rows_;
    }
    void setColumns(const unsigned int columns_){
        columns = columns_;
    }
    
    sf::Vector2f getCellPos(float row, float column);
    sf::Vector2f getCellPos(sf::Vector2f vec);
    
    vector<sf::RectangleShape> getCells(){
        return Cells;
    }
    
    sf::RectangleShape& getCellAt(int row, int col);
    void draw(sf::RenderWindow &window);
    void setTexture(const sf::Texture* txtr, sf::IntRect sr, int row, int col);
    
private:
    sf::Vector2f cellSize;
    float rows;
    float columns;
    vector<sf::RectangleShape> Cells;
};


