#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <valarray>
#include <SFML/Graphics/Transformable.hpp>
#include "Grid.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Grid g = Grid(sf::Vector2f(60, 60), 5, 6);
    sf::Texture texture;
    if(!texture.loadFromFile("Spritesheet/sprites.png")){
        cout << "failed loading texture file" << endl;
    }
    const sf::IntRect wallR(0, 0, 64, 64);
    const sf::IntRect playerR(362, 248, 42, 59);
    const sf::IntRect crateR(192, 0, 64, 64);
    const sf::IntRect goalR(96, 384, 32, 32);
    const sf::IntRect groundR(128, 64, 64, 64);
    int rows = g.getRows();
    int cols = g.getColumns();
    //set the boundaries of the grid to walls.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i == 0 || j == 0 || i == rows-1 || j == cols-1){
                g.setTexture(&texture, wallR, i, j);
            }
        }
    }
    sf::Sprite player(texture, playerR);
    player.setOrigin(playerR.width/2, playerR.height/2);
    player.setPosition(g.getCellCenter(1,1));
    
    sf::Sprite crate(texture, crateR);
    crate.setOrigin(crateR.width/2, crateR.height/2);
    crate.setPosition(g.getCellCenter(2, 2));
    
    sf::Sprite goal(texture, goalR);
    goal.setOrigin(goalR.width/2, goalR.height/2);
    goal.setPosition(g.getCellCenter(2, 1));
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(600, 600), "My window",
            sf::Style::Default, settings);
    
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){
                case (sf::Event::Closed):{
                    window.close();
                    break;
                }
                default:
                    break;
            }
        }
        window.clear(sf::Color::White);
        g.draw(window);
        window.draw(player);
        window.draw(goal);
        window.draw(crate);
        window.display();
    }
    
    
    return 0;
}



