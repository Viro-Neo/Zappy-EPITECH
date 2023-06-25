/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Map
*/

#include "Map.hpp"

Map::Map( int winW, int winH, int sizeX, int sizeY) : _mapRender(sf::Quads, 0)
{
    this->_winHeight = winH;
    this->_winWidth = winW;
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    this->_tileSize = sf::Vector2u(32, 32);
    this->_zoom = 1;
    this->pos = sf::Vector2i(0, 0);
    for (unsigned int i = 0; i < _sizeY; i++)
        for (unsigned int j = 0; j < _sizeX; j++) {
            Tile tmp;
            tmp.x = i;
            tmp.y = j;
            tmp.DERAUMERE = 0;
            tmp.FOOD = 0;
            tmp.LINEMATE = 0;
            tmp.MENDIANE = 0;
            tmp.PHIRAS = 0;
            tmp.SIBUR = 0;
            tmp.THYSTAME = 0;
            this->_map.push_back(tmp);
        }
    this->_mapRender.resize(sizeX * sizeY * 4);
    if (!_tileset.loadFromFile("gui_zappy/assets/GrassText.png"))
        throw std::exception();
}

Map::~Map()
{
}

int Map::resizeMap(int sizeX, int sizeY)
{
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    this->_mapRender.resize(sizeX * sizeY * 4);
    this->_map.clear();
    for (unsigned int i = 0; i < _sizeY; i++)
        for (unsigned int j = 0; j < _sizeX; j++) {
            Tile tmp;
            tmp.x = i;
            tmp.y = j;
            tmp.DERAUMERE = 0;
            tmp.FOOD = 0;
            tmp.LINEMATE = 0;
            tmp.MENDIANE = 0;
            tmp.PHIRAS = 0;
            tmp.SIBUR = 0;
            tmp.THYSTAME = 0;
            this->_map.push_back(tmp);
        }
    return 0;
}

bool Map::updateMap()
{
    for (unsigned int i = 0; i < _sizeX; i++)
        for (unsigned int j = 0; j < _sizeY; j++) {
            this->_map.at(i + j * _sizeX).PLAYER.clear();
        }
    for (auto it = this->getTeam().begin(); it != this->getTeam().end(); it++) {
        for (auto player = (*it).getPlayerList().begin(); player != (*it).getPlayerList().end(); player++) {
            this->_map.at((*player).getPos().x + (*player).getPos().y * this->_sizeX).PLAYER.push_back(*player);
        }
    }
    return true;
}



bool Map::updateTexture()
{
    for (unsigned int i = 0; i < _sizeX; i++)
        for (unsigned int j = 0; j < _sizeY; j++) {
            int curr = chooseText(i, j);
            int tu = curr % (this->_tileset.getSize().x / _tileSize.x);
            int tv = curr / (this->_tileset.getSize().x / _tileSize.x);
            sf::Vertex *quad = &this->_mapRender[(i + j * _sizeX) * 4];
            quad[0].position = sf::Vector2f(i * _tileSize.x * this->_zoom + this->pos.x, j * _tileSize.y * this->_zoom  + this->pos.y);
            quad[1].position = sf::Vector2f((i + 1) * _tileSize.x * this->_zoom + this->pos.x, j * _tileSize.y * this->_zoom + this->pos.y);
            quad[2].position = sf::Vector2f((i + 1) * _tileSize.x * this->_zoom + this->pos.x,  (j + 1) * _tileSize.y * this->_zoom + this->pos.y);
            quad[3].position = sf::Vector2f(i * _tileSize.x * this->_zoom + this->pos.x, (j + 1) * _tileSize.y * this->_zoom + this->pos.y);
            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * _tileSize.x, tv * _tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * _tileSize.x, tv * _tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * _tileSize.x, (tv + 1) * _tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * _tileSize.x, (tv + 1) * _tileSize.y);
        }
    return true;
}

void Map::moveMap(int lateral, int vertical)
{
    this->pos.x += lateral;
    this->pos.y += vertical;  
}

void Map::setTile(Tile t)
{
    this->_map.at(t.y + t.x * this->_sizeY).DERAUMERE = t.DERAUMERE;
    this->_map.at(t.y + t.x * this->_sizeY).FOOD = t.FOOD;
    this->_map.at(t.y + t.x * this->_sizeY).LINEMATE = t.LINEMATE;
    this->_map.at(t.y + t.x * this->_sizeY).MENDIANE = t.MENDIANE;
    this->_map.at(t.y + t.x * this->_sizeY).PHIRAS = t.PHIRAS;
    this->_map.at(t.y + t.x * this->_sizeY).SIBUR = t.SIBUR;
    this->_map.at(t.y + t.x * this->_sizeY).THYSTAME = t.THYSTAME;
}

void Map::zoom(bool zoomin)
{
    if (zoomin)
        this->_zoom += 0.1;
    else
        this->_zoom -= 0.1;
}

void Map::addTeam(Team t)
{
    this->team.push_back(t);
}

std::vector<Team>& Map::getTeam()
{
    return this->team;
}

struct Tile &Map::getTileInfo(sf::Vector2i mousePos)
{
    for (int x = 0; x < this->_sizeX; x++)
        for (int y = 0; y < this->_sizeY; y++) {
            sf::Vertex *quad = &this->_mapRender[(x + y * _sizeX) * 4];
            if (quad[0].position.x <= mousePos.x && quad[0].position.y <= mousePos.y && quad[2].position.x >= mousePos.x && quad[2].position.y >= mousePos.y)
                return this->_map.at(x + y * _sizeX);
        }
    throw std::exception();
}

std::vector<Incantation> &Map::getIncantationList()
{
    return this->_incantationList;
}

int Map::chooseText(unsigned int i,unsigned int j)
{
    Tile t = this->_map.at(i + j * this->_sizeX);
    if (t.PLAYER.empty()) {
        if (t.FOOD < 2 && t.DERAUMERE < 2)
            return 0;
        if (t.FOOD > t.DERAUMERE * 2)
            return 6;
        else 
            return 5;
    } else {
        Orientation o = t.PLAYER.front().getOrientation();
        if (o == Orientation::WEST)
            return 1;
        if (o == Orientation::NORTH)
            return 2;
        if (o == Orientation::EAST)
            return 3;
        if (o == Orientation::SOUTH)
            return 4;
    }
    return 0;
}