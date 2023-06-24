/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Interface.cpp
*/

#include "Interface.hpp"

#include <utility>

Interface::Interface(struct Tile tile)
{
    _tile = std::move(tile);
}

void Interface::updateInterface(struct Tile tile)
{
    _backRect.setSize(sf::Vector2f(200, 200));
    _backRect.setFillColor(sf::Color::Black);
    _backRect.setOutlineThickness(2);
    _backRect.setOutlineColor(sf::Color::White);
    _backRect.setPosition(0, 0);
}
