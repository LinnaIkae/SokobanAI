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




    /*    Next steps:
     * Paras olisi ehkä käyttää deque fringeen, koska siitä vain otetaan alusta
     * tai lopusta tässä. Toki sitten kun pitää tehdä monimutkasempaa hakua niin
     * tarvittaisiin list-tyyppi.
     * 
     * Myöskin tarvitaan "globaali" järjestetty lista, jossa on kaikki Nodet, jotta 
     * parentteihin päästään käsiksi. Tällöin fringen elementit voisivat vain
     * osoittaa tähän järjestettyyn listaan.
     */



    bool ended = false;
    bool paused = false;
    int step_cnt = 0;

    std::vector<std::string> input_strings;
    std::string str;

    std::ifstream input("C:/Users/Lefa/Documents/NetBeansProjects/Sokoban_SFML/"
            "levels/simple.sok");

    //fix the col and row stuff below.
    while (!input.is_open()) {
        std::cout << "failed to open input file, exiting" << std::endl;
        return -1;
    }
    while (std::getline(input, str)) {
        input_strings.push_back(str);
    }
    DFS_Solver s(input_strings);

    //s.logLocations();


    //for now keeping these constant seems to work and trying to make the window
    //adapt is a mess I don't want to get into again for a while.
    const int rows = 15; //s.rows;
    const int cols = 15; //s.columns;
    const int width = 600; //80 * cols; //values lower than 60 make sprites not fit
    const int height = 600; //80 * rows;
    float scale_x = width / cols;
    float scale_y = height / rows;

    //the sprites need to be scaled by factor (width/cols / 60 x height/rows / 60)

    Grid g = Grid(sf::Vector2f(scale_x, scale_y), rows, cols, s);

    sf::Vector2f sprite_scale(scale_x / 60, scale_y / 60);
    g.setSpriteScale(sprite_scale);

    sf::ContextSettings settings;
    //settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(width, height), "Sokoban by Plebor",
            sf::Style::Default, settings);

    //window.setFramerateLimit(50);
    window.setKeyRepeatEnabled(false);

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/comic.ttf"));

    sf::Text text;
    text.setFont(font);
    text.setString(L"Paused"); //L-etuliite on tärkeä jos haluaa ääkköset
    text.setCharacterSize(22);
    text.setFillColor(sf::Color::Cyan);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(400, 100));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case (sf::Event::Closed):
                {
                    window.close();
                    break;
                }
                case (sf::Event::KeyPressed):
                {
                    if (event.key.code == sf::Keyboard::Space) {
                        paused = !paused;
                        std::cout << "Steps in total: " << step_cnt << std::endl;
                    }
                    break;
                }
                default:
                    break;
            }
        }
        window.clear(sf::Color::Black);

        /*Also using this library would be cool to benchmark performance and to
        actually see speed.
        
            https://github.com/subh83/DOSL
        
        From this library I could take inspiration and tips on how to implement
        the path retrace function.
         */
        if (paused) {
            g.draw(window, s.current);
            window.draw(text);
        } else if (ended) {
            g.draw(window, s.current);
        } else {
            ended = s.searchStep(g, window);
            step_cnt += 1;
        }

        window.display();
    }


    return 0;
}



