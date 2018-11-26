#pragma once
/* 
 * File:   Grid.h
 * Author: Lefa
 *
 * Created on November 20, 2018, 11:24 PM
 * 
 */

#include <SFML/Graphics.hpp>

class Grid {
    /* Grid class should include the static parts of the map, but the 
      player, crates and goal should be separate. They should be in and
      object possibly called Game.*/
public:
    Grid();
    Grid(sf::Vector2f s_cell, unsigned rows_, unsigned columns_);
    Grid(const Grid& orig);
    virtual ~Grid();

    sf::Vector2f getCellSize() const {
        return cell_size;
    }

    unsigned getRows() const {
        return rows;
    }

    unsigned getColumns() const {
        return columns;
    }

    unsigned getCellAmount() const {
        return cells.size();
    }

    void setCellSize(const sf::Vector2f cs) {
        cell_size = cs;
    }

    void setRows(const unsigned rows_) {
        rows = rows_;
    }

    void setColumns(const unsigned columns_) {
        columns = columns_;
    }

    sf::Vector2f getCellPos(unsigned row, unsigned col) const;
    sf::Vector2f getCellPos(sf::Vector2f vec) const;

    std::vector<sf::RectangleShape> getCells() const {
        return cells;
    }

    sf::RectangleShape& getCellAt(unsigned row, unsigned col);
    sf::Vector2f getCellCenter(unsigned row, unsigned col) const;
    void draw(sf::RenderWindow &window) const;

    void setTexture(const sf::Texture* txtr, const sf::IntRect sr,
            unsigned row, unsigned col);

    void drawSpriteAt(sf::Sprite& sprite, sf::RenderWindow& window,
            unsigned row, unsigned col) const;

private:
    sf::Vector2f cell_size;
    float rows;
    float columns;
    std::vector<sf::RectangleShape> cells;
};


