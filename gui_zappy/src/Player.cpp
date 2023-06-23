/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
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

sf::Vector2u Player::getPos()
{
    return this->pos;
}

void Player::setPos(sf::Vector2u pos)
{
    this->pos = pos;
}