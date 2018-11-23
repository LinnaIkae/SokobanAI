#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <valarray>
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
    sf::IntRect wall(0, 0, 64, 64);
    sf::IntRect player(362, 248, 42, 59);
    sf::IntRect crate(192, 0, 64, 64);
    sf::IntRect goal(96, 384, 32, 32);
    sf::IntRect ground(128, 64, 64, 64);
    int rows = g.getRows();
    int cols = g.getColumns();
    //set the boundaries of the grid to walls.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i == 0 || j == 0 || i == rows-1 || j == cols-1){
                g.setTexture(&texture, wall, i, j);
            }
        }
    }
    
    g.setTexture(&texture, player, 2, 4);
    g.setTexture(&texture, goal, 2, 1);
    
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
//                case (sf::Event::MouseMoved):{
//                    float x = event.mouseMove.x;
//                    float y = event.mouseMove.y;
//                    circ.setPosition(x, y);
//                    break;
//                }
                default:
                    break;
            }
        }
        window.clear(sf::Color::White);
        
        g.draw(window);
        window.display();
    }
    return 0;
}


