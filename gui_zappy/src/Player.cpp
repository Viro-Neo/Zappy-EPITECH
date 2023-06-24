/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(int id, int x, int y, Orientation o, int level, std::string teamName)
{
    this->_id = id;
    this->pos.x = x;
    this->pos.y = y;
    this->_orientaton = o;
    this->level = level;
    this->_teamName = teamName;
}

Player::~Player()
{
}

int Player::getLevel()
{
    return this->level;
}

void Player::setLevel(int lv)
{
    this->level = lv;
}

int Player::getId()
{
    return this->_id;
}

bool Player::getIncantation()
{
    return this->_incantation;
}

void Player::setIncantation(bool a)
{
    this->_incantation = a;
}

sf::Vector2u Player::getPos()
{
    return this->pos;
}

void Player::setPos(sf::Vector2u pos)
{
    this->pos = pos;
}

std::string Player::getTeamName()
{
    return this->_teamName;
}

void Player::setTeamName(std::string name)
{
    this->_teamName = name;
}