#include "Grid.hpp"
#include <iostream>
#include <set>

Grid::Grid(sf::Vector2f s_cell, unsigned rows_, unsigned columns_, Solver& s) :
cell_size(s_cell), rows(rows_ + 1), columns(columns_) {
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
    }



    //setting the input texturesheet and finding the used parts
    if (!texture.loadFromFile("Spritesheet/sprites.png")) {
        std::cout << "failed loading texture file" << std::endl;
    }
    wallR = sf::IntRect(0, 256, 64, 64);
    playerR = sf::IntRect(362, 248, 42, 59);
    crateR = sf::IntRect(192, 0, 64, 64);
    goalR = sf::IntRect(128, 384, 32, 32);
    groundR = sf::IntRect(64, 256, 64, 64);

    std::set<std::pair<int, int>> walls = s.walls;
    std::set<std::pair<int, int>> freeSpaces = s.freeSpaces;
    std::vector<sf::Vector2i> goals = s.goals;

    for (auto goal : goals) {
        goal_pos.push_back(goal.x);
        goal_pos.push_back(goal.y);
    }

    //the vector range check is failing for this...
    for (auto w_pair : walls) {
        //std::cout << w_pair.first << w_pair.second << std::endl;
        this->setTexture(&texture, wallR, w_pair.first, w_pair.second);
    }

    for (auto g_pair : freeSpaces) {
        this->setTexture(&texture, groundR, g_pair.first, g_pair.second);
    }

    player = create_centered_Sprite(texture, playerR);
    crate = create_centered_Sprite(texture, crateR);
    goal = create_centered_Sprite(texture, goalR);

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

void Grid::draw(sf::RenderWindow& window, Node& node) {

    window.clear(sf::Color::White);

    // Drawing the static playfield:
    for (const auto& rect : cells) {
        window.draw(rect);
    }
    std::vector<int> crate_pos;

    // Drawing all the sprites: 

    for (auto box : node.boxes) {
        crate_pos.push_back(box.x);
        crate_pos.push_back(box.y);
    }

    drawSpriteAt(player, window, node.agent.x, node.agent.y);

    for (unsigned i = 0; i < crate_pos.size() / 2; i++) {
        drawSpriteAt(crate, window,
                crate_pos[2 * i], crate_pos[2 * i + 1]);
    }

    for (unsigned i = 0; i < goal_pos.size() / 2; i++) {
        drawSpriteAt(goal, window,
                goal_pos[2 * i], goal_pos[2 * i + 1]);
    }

    window.display();
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
        unsigned row, unsigned col) {
    if (row == 0 || col == 0 || row == rows || col == columns)
        std::cout << "Warning: You are placing a sprite on the outside wall."
            << std::endl;
    sprite.setPosition(getCellCenter(row, col));
    window.draw(sprite);
}

sf::Sprite Grid::create_centered_Sprite(sf::Texture& texture, sf::IntRect rect) {
    sf::Sprite spr(texture, rect);
    spr.setOrigin(rect.width / 2, rect.height / 2);
    return spr;
}

