/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.hpp"

struct Tile {
    int FOOD;
    int LINEMATE;
    int DERAUMERE;
    int SIBUR;
    int MENDIANE;
    int PHIRAS;
    int THYSTAME;
    std::vector<Player> PLAYER;
};
class Map : public sf::Drawable, public sf::Transformable {
    public:
        Map(int sizeX = 100, int sizeY = 100);
        ~Map();
        bool updateMap(std::vector<std::string> bct);
        bool updateTexture();
        int resizeMap(int sizeX, int sizeY);
        void moveMap(int , int);
        void zoom(bool zoomin);

    protected:
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
                states.transform *= getTransform();
                //states.texture = &_tileset;
                target.draw(_mapRender, states);
        }
        int _sizeX;
        int _sizeY;
        sf::VertexArray _mapRender;
        float _zoom;
        std::vector<Tile> _map;
        int _squareSize;
        sf::Texture _tileset;
        sf::Vector2u _tileSize;
        sf::Vector2u pos;
        std::vector<Player> playerList;
};



#endif /* !MAP_HPP_ */
