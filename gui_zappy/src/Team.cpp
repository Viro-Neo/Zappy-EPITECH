/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Team
*/

#include "Team.hpp"

Team::Team(std::string name)
{
}

Team::~Team()
{
}

std::vector<Player>& Team::getPlayerList()
{
    return this->_playerList;
}

std::string Team::gatName()
{
    return this->_name;
}

void Team::addPlayer(Player player)
{
    this->_playerList.push_back(player);
}

int Team::getNbPlayer()
{
    return this->_nbPlayer;
}