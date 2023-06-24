/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Incantation
*/

#include "Incantation.hpp"

Incantation::Incantation(int level, sf::Vector2u pos, Player starter, std::list<Player> &participent) : _starter(starter)
{
    this->_level = level;
    this->_pos = pos;
    this->_participent = participent;
}

Incantation::~Incantation()
{
}

void Incantation::finishIncantation(int result)
{
    return;
}

sf::Vector2u& Incantation::getPos(void)
{
    return this->_pos;
}

Player& Incantation::getStarter(void)
{
    return this->_starter;
}

std::list<Player>& Incantation::getParticipent(void)
{
    return this->_participent;
}