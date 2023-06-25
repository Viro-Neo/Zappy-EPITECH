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
    _font.loadFromFile(_fontTTf);
    sf::Vector2f pos = {10, 10};
    sf::Vector2f size = {5, 10};
    setRect(pos, size);
    _text._textFood.setFont(_font);
    _text._textLinemate.setFont(_font);
    _text._textDeraumere.setFont(_font);
    _text._textMendiane.setFont(_font);
    _text._textSibur.setFont(_font);
    _text._textPhiras.setFont(_font);
    _text._textThystame.setFont(_font);
}

void Interface::displayInterface()
{
    // display background
    // display text
}

void Interface::setTextFood(std::string text, sf::Vector2f pos, int size)
{
    _text._textFood.setString(text);
    _text._textFood.setPosition(pos);
    _text._textFood.setCharacterSize(size);
}

void Interface::setTextlinemate(std::string text, sf::Vector2f pos, int size)
{
    _text._textLinemate.setString(text);
    _text._textLinemate.setPosition(pos);
    _text._textLinemate.setCharacterSize(size);
}

void Interface::setTextDeraumere(std::string text, sf::Vector2f pos, int size)
{
    _text._textDeraumere.setString(text);
    _text._textDeraumere.setPosition(pos);
    _text._textDeraumere.setFont(_font);
    _text._textDeraumere.setCharacterSize(size);
}

void Interface::setTextSibur(std::string text, sf::Vector2f pos, int size)
{
    _text._textSibur.setString(text);
    _text._textSibur.setPosition(pos);
    _text._textSibur.setCharacterSize(size);
}

void Interface::setTextMendiane(std::string text, sf::Vector2f pos, int size)
{
    _text._textMendiane.setString(text);
    _text._textMendiane.setPosition(pos);
    _text._textMendiane.setCharacterSize(size);
}

void Interface::setTextPhiras(std::string text, sf::Vector2f pos, int size)
{
    _text._textPhiras.setString(text);
    _text._textPhiras.setPosition(pos);
    _text._textPhiras.setCharacterSize(size);
}

void Interface::setTextThystame(std::string text, sf::Vector2f pos, int size)
{
    _text._textThystame.setString(text);
    _text._textThystame.setPosition(pos);
    _text._textThystame.setCharacterSize(size);
}

void Interface::setRect(sf::Vector2f pos, sf::Vector2f size)
{
    _backRect.setPosition(pos);
    _backRect.setSize(size);
    _backRect.setFillColor(sf::Color::Red);
}

void Interface::print_tile()
{
    sf::Vector2f vec = _backRect.getPosition();
    sf::Vector2f rect = _backRect.getSize();
    setTextFood(std::to_string(_tile.FOOD), vec, 2);
    vec.x + 1;
    setTextlinemate(std::to_string(_tile.LINEMATE), vec, 2);
    vec.x + 1;
    setTextDeraumere(std::to_string(_tile.DERAUMERE), vec, 2);
    vec.x + 1;
    setTextSibur(std::to_string(_tile.SIBUR), vec, 2);
    vec.x + 1;
    setTextMendiane(std::to_string(_tile.MENDIANE), vec, 2);
    vec.x + 1;
    setTextPhiras(std::to_string(_tile.PHIRAS), vec, 2);
    vec.x + 1;
    setTextThystame(std::to_string(_tile.THYSTAME), vec, 2);
}