#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Grid.hpp"
#include "Solver.hpp"
#include "BFS_Solver.hpp"

/*
 * 
 */

sf::Sprite create_centered_Sprite(sf::Texture& texture, sf::IntRect rect) {
    sf::Sprite spr(texture, rect);
    spr.setOrigin(rect.width / 2, rect.height / 2);
    return spr;
}

int main(int argc, char** argv) {


    std::vector<std::string> input_strings;
    std::string str;

    std::ifstream input("C:/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/dist/Debug/MinGW-Windows/sokoban.sok");
    while (!input.is_open()) {
        std::cout << "failed to open input file, exiting" << std::endl;
        return -1;
    }
    while (std::getline(input, str)) {
        input_strings.push_back(str);
    }
    BFS_Solver s;
    s.parseInput(input_strings);

    s.logLocations();
    Node node(s.agent, (s.boxes));
    s.expandEdges(node);




    const int width = 600;
    const int height = 600;
    const int rows = 10;
    const int cols = 10;
    Grid g = Grid(sf::Vector2f(width / cols, height / rows), rows, cols);

    //setting the input texturesheet and finding the used parts
    sf::Texture texture;
    if (!texture.loadFromFile("Spritesheet/sprites.png")) {
        std::cout << "failed loading texture file" << std::endl;
    }
    const sf::IntRect wallR(0, 256, 64, 64);
    const sf::IntRect playerR(362, 248, 42, 59);
    const sf::IntRect crateR(192, 0, 64, 64);
    const sf::IntRect goalR(128, 384, 32, 32);
    const sf::IntRect groundR(64, 256, 64, 64);

    // Set the boundaries of the grid to walls and the rest to ground.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                g.setTexture(&texture, wallR, i, j);
            } else {
                g.setTexture(&texture, groundR, i, j);
            }
        }
    }
    sf::Sprite player = create_centered_Sprite(texture, playerR);
    sf::Sprite crate = create_centered_Sprite(texture, crateR);
    sf::Sprite goal = create_centered_Sprite(texture, goalR);

    std::vector<sf::Sprite> sprites = {
        player, goal, crate
    };

    // It might be best to pass an array like this to the main loop from the
    // solver every time a new state of game is calculated.
    std::vector<int> player_pos = {1, 1};
    std::vector<int> goal_pos = {
        1, 1,
        2, 2,
        3, 4,
        4, 8
    };
    std::vector<int> crate_pos = {
        7, 1,
        3, 2,
        6, 4,
        5, 8
    };

    //
    //    sf::ContextSettings settings;
    //    settings.antialiasingLevel = 8;
    //    sf::RenderWindow window(sf::VideoMode(width, height), "My window",
    //            sf::Style::Default, settings);
    //
    //    window.setFramerateLimit(15);
    //    while (window.isOpen()) {
    //        // Check all the window's events that were triggered since the last 
    //        // iteration of the loop.
    //        sf::Event event;
    //        while (window.pollEvent(event)) {
    //            switch (event.type) {
    //                case (sf::Event::Closed):
    //                {
    //                    window.close();
    //                    break;
    //                }
    //                default:
    //                    break;
    //            }
    //        }
    //        window.clear(sf::Color::White);
    //        g.draw(window);
    //        for (unsigned i = 0; i < goal_pos.size() / 2; i++) {
    //            g.drawSpriteAt(goal, window,
    //                    goal_pos[2 * i], goal_pos[2 * i + 1]);
    //        }
    //        for (unsigned i = 0; i < crate_pos.size() / 2; i++) {
    //            g.drawSpriteAt(crate, window,
    //                    crate_pos[2 * i], crate_pos[2 * i + 1]);
    //        }
    //        window.display();
    //    }


    return 0;
}



