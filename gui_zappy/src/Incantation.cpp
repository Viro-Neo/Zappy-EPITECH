/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Incantation
*/

#include "Incantation.hpp"

Incantation::Incantation(int level, sf::Vector2u pos, Player starter, std::vector<Player> participent) : _starter(starter)
{
    this->_level = level;
    this->_pos = pos;
    this->_participent = participent;
}

Incantation::~Incantation()
{
}

