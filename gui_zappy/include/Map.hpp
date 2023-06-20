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
typedef struct Tile {
    int FOOD;
    int LINEMATE;
    int DERAUMERE;
    int SIBUR;
    int MENDIANE;
    int PHIRAS;
    int THYSTAME;
    bool PLAYER;
};
class Map : public sf::Drawable, public sf::Transformable {
    public:
        Map(int sizeX, int sizeY);
        ~Map();
        bool updateMap(std::vector<std::string> bct);
        bool updateTexture();
    protected:
    private:
        
        int _sizeX;
        int _sizeY;
        sf::VertexArray _mapRender;
        float _zoom;
        std::vector<Tile> _map;
        int _squareSize;
        sf::Texture _tileset;
        sf::Vector2u _tileSize;
};



#endif /* !MAP_HPP_ */
