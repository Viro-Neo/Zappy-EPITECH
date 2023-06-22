/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(int sizeX, int sizeY) : _mapRender(sf::Quads, 0)
{
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    this->_tileSize = sf::Vector2u(32, 32);
    this->_zoom = 1;
    for (unsigned int i = 0; i < _sizeY; i++)
        for (unsigned int j = 0; j < _sizeX; j++) {
            this->_map.push_back(Tile());
        }
    this->_mapRender.resize(sizeX * sizeY * 4);
}

Map::~Map()
{
}

int Map::resizeMap(int sizeX, int sizeY)
{
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    this->_mapRender.resize(sizeX * sizeY * 4);
    return 0;
}

bool Map::updateMap(std::vector<std::string> bct)
{
    return true;
}

bool Map::updateTexture()
{
    for (unsigned int i = 0; i < _sizeX; i++)
        for (unsigned int j = 0; j < _sizeY; j++) {
            Tile curr = this->_map[i + j * _sizeX];
            // int tu = curr % (this->_tileset.getSize().x / tileSize.x);
            // int tv = curr / (this->_tileset.getSize().x / tileSize.x);
            sf::Vertex *quad = &this->_mapRender[(i + j * _sizeX) * 4];
            quad[0].position = sf::Vector2f(i * _tileSize.x * this->_zoom, j * _tileSize.y * this->_zoom);
            quad[1].position = sf::Vector2f((i + 1) * _tileSize.x * this->_zoom, j * _tileSize.y * this->_zoom);
            quad[2].position = sf::Vector2f((i + 1) * _tileSize.x * this->_zoom, (j + 1) * _tileSize.y * this->_zoom);
            quad[3].position = sf::Vector2f(i * _tileSize.x * this->_zoom, (j + 1) * _tileSize.y * this->_zoom);
            // on définit ses quatre coordonnées de texture
            // quad[0].texCoords = sf::Vector2f(tu * _tileSize.x, tv * _tileSize.y);
            // quad[1].texCoords = sf::Vector2f((tu + 1) * _tileSize.x, tv * _tileSize.y);
            // quad[2].texCoords = sf::Vector2f((tu + 1) * _tileSize.x, (tv + 1) * _tileSize.y);
            // quad[3].texCoords = sf::Vector2f(tu * _tileSize.x, (tv + 1) * _tileSize.y);
        }
    return true;
}
// ajouter les event
// resize la map des info
// faire une class player
// ajouter les texture