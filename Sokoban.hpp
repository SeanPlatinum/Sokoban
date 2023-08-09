// Copyright [2023] <Sean Diaz>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream> //NOLINT
#include <vector> //NOLINT
#include <map> //NOLINT

using std::map;
using std::cout;
using std::cin;
using std::vector;
using std::istream;

enum Movement {
    UP = sf::Keyboard::W,
    DOWN = sf::Keyboard::S,
    LEFT = sf::Keyboard::A,
    RIGHT = sf::Keyboard::D,
    NONE
};
class Sokoban : public sf::Drawable {
 public:
    void movePlayer(Movement move) {
    int dx = 0, dy = 0;
    switch (move) {
        case UP:
            dy = -1;
            break;
        case DOWN:
            dy = 1;
            break;
        case LEFT:
            dx = -1;
            break;
        case RIGHT:
            dx = 1;
            break;
        default:
            break;
    }

        int newPosX = newPlayerPosX + dy;
        int newPosY = newPlayerPosY + dx;
        char newSymbol = matrix[newPosX][newPosY];  // remember...row...column
        if (newSymbol == '.') {
            matrix[newPlayerPosX][newPlayerPosY] = '.';
            newPlayerPosX = newPosX;
            newPlayerPosY = newPosY;
            matrix[newPlayerPosX][newPlayerPosY] = '@';
        } else if (newSymbol == 'A') {
        int boxPosX = newPosX + dy;
        int boxPosY = newPosY + dx;
        char boxSymbol = matrix[boxPosX][boxPosY];
        if (boxSymbol == '.') {
            matrix[boxPosX][boxPosY] = 'A';
            matrix[newPosX][newPosY] = '@';
            matrix[newPlayerPosX][newPlayerPosY] = '.';
            newPlayerPosX = newPosX;
            newPlayerPosY = newPosY;
            matrix[newPlayerPosX][newPlayerPosY] = '@';
        }  else if (boxSymbol == 'a') {
            matrix[boxPosX][boxPosY] = 'A';
            matrix[newPosX][newPosY] = '@';
            matrix[newPlayerPosX][newPlayerPosY] = '.';
            newPlayerPosX = newPosX;
            newPlayerPosY = newPosY;
            matrix[newPlayerPosX][newPlayerPosY] = '@';
            // If the player is currently on the target location, update the matrix
            if (matrix[newPlayerPosX][newPlayerPosY] == 'a') {
                matrix[newPlayerPosX][newPlayerPosY] = 'a';
            }
        }
        }
            if (isWon()) {
                sf::Music music;
                music.openFromFile("wins.wav");
                music.play();
                music.stop();
                cout << "winner" << std::endl;
                music.~Music();
                exit(111);
            }
    }

    bool isWon() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == 'a') {
                    return false;
                }
            }
        }
        return true;
    }

    friend istream& operator>>(istream& in, Sokoban& level);
    int getRow() const {
        return row;
    }
    int getcolumn() const {
        return column;
    }

 private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        sf:: Texture wall;
        sf:: Texture floor;
        sf:: Texture player;
        sf:: Texture box;
        sf:: Texture storageLoc;
        sf:: Texture playerFloor;
        // sf:: Texture stuckBox;
        wall.loadFromFile("block_06.png");
        player.loadFromFile("player_05.png");
        floor.loadFromFile("ground_01.png");
        box.loadFromFile("crate_03.png");
        storageLoc.loadFromFile("ground_04.png");
        playerFloor.loadFromFile("ground_01.png");

        map<char, sf::Texture> texture_map;
        texture_map['.'] = floor;
        texture_map['#'] = wall;
        // texture_map['@'] = playerFloor;
        texture_map['@'] = player;
        texture_map['A'] = box;
        texture_map['a'] = storageLoc;
        // Loop through the matrix and draw the sprites
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                char symbol = matrix[i][j];
                sf::Sprite sprite;
                sprite.setTexture(texture_map[symbol]);
                sprite.setScale(64.0f / texture_map[symbol].getSize().x, 64.0f / texture_map[symbol].getSize().y); //NOLINT
                sprite.setPosition(j * 64.0f, i * 64.0f);
                if (symbol == '@') {
                    sf::Sprite floor_sprite;
                    floor_sprite.setTexture(floor);
                    floor_sprite.setScale(64.0f / floor.getSize().x, 64.0f / floor.getSize().y);
                    floor_sprite.setPosition(j * 64.0f, i * 64.0f);
                    target.draw(floor_sprite, states);
                }
                target.draw(sprite, states);
            }
        }
    }
    int newPlayerPosX;
    int newPlayerPosY;

 protected:
    int row;
    int column;
    vector<vector<char>> matrix;
    vector<vector<sf::Texture>> textures;
};

istream& operator>>(istream& in, Sokoban& level) {
      in >> level.row >> level.column;
      level.matrix.resize(level.row, vector<char>(level.column));
      for (int i = 0; i < level.row; i++) {
        for (int j = 0; j < level.column; j++) {
            in >> level.matrix[i][j];
            if (level.matrix[i][j] == '@') {
                level.newPlayerPosX = i;
                level.newPlayerPosY = j;
            }
        }
    }
      return in;
}
