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

void Interface::displayInterface()
{
    // display background
    // display text
}

void Interface::setText(std::string text, sf::Vector2f pos, int size)
{
    _font.loadFromFile("assets/arial.ttf");
    _text.setString(text);
    _text.setPosition(pos);
    _text.setFont(_font);
    _text.setCharacterSize(size);
}

void Interface::setRect(sf::Vector2f pos, sf::Vector2f size)
{
    _backRect.setPosition(pos);
    _backRect.setSize(size);
    _backRect.setFillColor(sf::Color::Black);
}
