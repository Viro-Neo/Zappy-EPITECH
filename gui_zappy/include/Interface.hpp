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
        Interface() = default;
        Interface(struct Tile tile);
        ~Interface() = default;
        void displayInterface();

        void setText(std::string text, sf::Vector2f pos, int size);
        void setRect(sf::Vector2f pos, sf::Vector2f size);

    protected:
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
                states.transform *= getTransform();
                //states.texture = &_tileset;
                target.draw(_backRect, states);
        }
        sf::RectangleShape _backRect;
        sf::Text _text;
        sf::Font _font;
        struct Tile _tile;
};

#endif /* !INTERFACE_HPP_ */
