/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Interface
*/

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Interface : public sf::Drawable, public sf::Transformable {
    public:
        Interface(struct Tile tile);
        ~Interface();

    protected:
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
                states.transform *= getTransform();
                //states.texture = &_tileset;
                target.draw(_backRect, states);
        }
        sf::RectangleShape _backRect;
        struct Tile _tile;
};

#endif /* !INTERFACE_HPP_ */
