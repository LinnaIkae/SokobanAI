#include "Grid.hpp"
#include <iostream>

Grid::Grid(sf::Vector2f s_cell, unsigned rows_, unsigned columns_) :
cell_size(s_cell), rows(rows_), columns(columns_) {
    std::vector<sf::Vector2f> cellPosit;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cellPosit.push_back(getCellPos(i, j));
        }
    }
    for (sf::Vector2f pos : cellPosit) {
        sf::RectangleShape rect(cell_size);
        rect.setPosition(pos);
        cells.push_back(rect);
        //std::cout<<"Size of Cells: "<<Cells.size()<<endl;
    }
}

Grid::Grid() {
}

Grid::Grid(const Grid& orig) {
}

Grid::~Grid() {
}

sf::Vector2f Grid::getCellPos(unsigned row, unsigned col) const {
    float posx = cell_size.x*row;
    float posy = cell_size.y*col;
    return sf::Vector2f(posx, posy);
}

sf::Vector2f Grid::getCellPos(sf::Vector2f vec) const {
    float posx = cell_size.x * vec.x;
    float posy = cell_size.y * vec.y;
    return sf::Vector2f(posx, posy);
}

void Grid::draw(sf::RenderWindow& window) const {
    for (const auto& rect : cells) {
        window.draw(rect);
    }
}

sf::RectangleShape& Grid::getCellAt(unsigned row, unsigned col) {
    int index = row * columns + col;
    //std::cout << "index: " << index << endl;
    return cells.at(index);
}

void Grid::setTexture(const sf::Texture* txtr, sf::IntRect sr,
        unsigned row, unsigned col) {
    sf::RectangleShape& rect = getCellAt(row, col);
    rect.setTexture(txtr);
    rect.setTextureRect(sr);
}

sf::Vector2f Grid::getCellCenter(unsigned row, unsigned col) const {
    float x = row * cell_size.x + cell_size.x / 2;
    float y = col * cell_size.y + cell_size.y / 2;
    return sf::Vector2f(x, y);
}

void Grid::drawSpriteAt(sf::Sprite& sprite, sf::RenderWindow& window,
        unsigned row, unsigned col) const {
    if (row == 0 || col == 0 || row == rows || col == columns)
        std::cout << "Warning: You are placing a sprite on the outside wall."
            << std::endl;
    sprite.setPosition(getCellCenter(row, col));
    window.draw(sprite);
}

