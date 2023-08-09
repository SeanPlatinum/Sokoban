// Copyright [2023] <Sean Diaz>
#include <SFML/Audio.hpp>
#include <iostream> //NOLINT
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream> //NOLINT
#include <vector> //NOLINT
#include "Sokoban.hpp" //NOLINT

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
        // Load the Sokoban level
    Sokoban level;
    cout << "press R to restart" << std::endl;
    file >> level;
    sf::RenderWindow window(sf::VideoMode(level.getcolumn() * 64, level.getRow() * 64), "Sokoban");
        while (window.isOpen()) {
        // Handle events
        sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                        window.close();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            level.movePlayer(UP);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            level.movePlayer(DOWN);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            level.movePlayer(LEFT);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            level.movePlayer(RIGHT);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            std::ifstream file(argv[1]);
            file >> level;
        }
        window.clear();
        window.draw(level);
        window.display();
        sf::sleep(sf::milliseconds(100));
        }
        return 0;
}
