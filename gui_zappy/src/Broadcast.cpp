/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Broadcast
*/

#include "Broadcast.hpp"

Broadcast::Broadcast(sf::CircleShape _circle, std::string text)
{
    if (!this->_font.loadFromFile("gui_zappy/assets/arial.tts"))
        throw std::exception();
    this->_text.setFillColor(sf::Color::Yellow);
    this->_text.setString(text);
    this->_text.setFont(this->_font);
    this->_text.setCharacterSize(24);
    this->_circle = _circle;
    this->_nbScale = 0;
    this->scale = 1;
}

Broadcast::~Broadcast()
{
}

void Broadcast::scaleCircle()
{
    this->_circle.scale(1.05, 1.05);
    this->_text.scale(1.05, 1.05);
    this->_nbScale++;
}

float Broadcast::getScaleNb()
{
    return this->_nbScale;
}
