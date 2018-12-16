#pragma once
/* 
 * File:   Grid.h
 * Author: Lefa
 *
 * Created on November 20, 2018, 11:24 PM
 * 
 */

#include <SFML/Graphics.hpp>
#include "Solver.hpp"
#include "Node.hpp"

class Grid {
    /* Grid class should include the static parts of the map, but the 
      player, crates and goal should be separate. They should be in and
      object possibly called Game.*/
public:
    Grid();
    Grid(std::string inf);
    Grid(sf::Vector2f s_cell, unsigned rows_, unsigned columns_m, Solver& s);
    Grid(const Grid& orig);
    virtual ~Grid();

    sf::Vector2f getCellPos(unsigned row, unsigned col) const;
    sf::Vector2f getCellPos(sf::Vector2f vec) const;

    std::vector<sf::RectangleShape> getCells() const {
        return cells;
    }

    sf::RectangleShape& getCellAt(unsigned row, unsigned col);
    sf::Vector2f getCellCenter(unsigned row, unsigned col) const;
    void draw(sf::RenderWindow &window, Node& node);

    void setTexture(const sf::Texture* txtr, const sf::IntRect sr,
            unsigned row, unsigned col);

    void drawSpriteAt(sf::Sprite& sprite, sf::RenderWindow& window,
            unsigned row, unsigned col);

    sf::Sprite create_centered_Sprite(sf::Texture& texture, sf::IntRect rect);

    void setSpriteScale(sf::Vector2f scale) {
        sprite_scale = scale;
    }
public:
    sf::Vector2f cell_size;
    float rows;
    float columns;
    std::vector<sf::RectangleShape> cells;
    sf::IntRect wallR;
    sf::IntRect playerR;
    sf::IntRect crateR;
    sf::IntRect goalR;
    sf::IntRect groundR;
    sf::Texture texture;
    sf::Sprite player;
    sf::Sprite crate;
    sf::Sprite goal;
    std::vector<int> goal_pos;
private:
    sf::Vector2f sprite_scale;
};


