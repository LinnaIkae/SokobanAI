#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Grid.hpp"
#include "Solver.hpp"
#include "BFS_Solver.hpp"
#include "DFS_Solver.hpp"

int main(int argc, char** argv) {


    std::vector<std::string> input_strings;
    std::string str;

    std::ifstream input("C:/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/"
            "levels/sokoban.sok");

    //DONT USE sokoban2.sok before you fix the col and row stuff below.
    while (!input.is_open()) {
        std::cout << "failed to open input file, exiting" << std::endl;
        return -1;
    }
    while (std::getline(input, str)) {
        input_strings.push_back(str);
    }
    DFS_Solver s(input_strings);

    s.logLocations();


    //for now keeping these constant seems to work and trying to make the window
    //adapt is a mess I don't want to get into again for a while.
    const int rows = 10; //s.rows;
    const int cols = 10; //s.columns;
    const int width = 600; //80 * cols; //values lower than 60 make sprites not fit
    const int height = 600; //80 * rows;
    Grid g = Grid(sf::Vector2f(width / cols, height / rows), rows, cols, s);


    sf::ContextSettings settings;
    //settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(width, height), "My window",
            sf::Style::Default, settings);

    //window.setFramerateLimit(5);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case (sf::Event::Closed):
                {
                    window.close();
                    break;
                }
                default:
                    break;
            }
        }
        window.clear(sf::Color::Black);

        window.display();

        //this could be done in a more sensible way...

        s.graphSearch(g, window);
        std::cout << "Type anything to end the program: >";
        char* in = "   ";
        std::cin >> in;
        window.close();


    }


    return 0;
}



