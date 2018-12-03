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



int main(int argc, char** argv) {


    std::vector<std::string> input_strings;
    std::string str;

    std::ifstream input("C:/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/"
            "levels/connection.sok");
    while (!input.is_open()) {
        std::cout << "failed to open input file, exiting" << std::endl;
        return -1;
    }
    while (std::getline(input, str)) {
        input_strings.push_back(str);
    }
    BFS_Solver s(input_strings);

    s.logLocations();

    //    Node node(s.agent, (s.boxes));
    //
    //    std::cout << s.graphSearch() << std::endl;


    const int width = 600;
    const int height = 600;
    const int rows = 10;
    const int cols = 10;
    Grid g = Grid(sf::Vector2f(width / cols, height / rows), rows, cols, s);



    // It might be best to pass an array like this to the main loop from the
    // solver every time a new state of game is calculated.



    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(width, height), "My window",
            sf::Style::Default, settings);

    //window.setFramerateLimit(200);
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
        window.clear(sf::Color::White);

        window.display();



        //this could be done in a more sensible way...
        s.graphSearch(g, window);
        std::cout << "Type anything to end the program: >";
        char* in;
        std::cin >> in;
        window.close();


    }


    return 0;
}



