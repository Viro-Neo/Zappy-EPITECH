/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Broadcast
*/

#ifndef BROADCAST_HPP_
#define BROADCAST_HPP_
    #include <SFML/Graphics.hpp>
class Broadcast : public sf::Drawable, public sf::Transformable {
    public:
        Broadcast(sf::CircleShape _circle, std::string text);
        ~Broadcast();
        void scaleCircle();
        float getScaleNb();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
                states.transform *= getTransform();
                target.draw(_circle);
                target.draw(_text);
        }
        sf::CircleShape _circle;
        sf::Text _text;
        sf::Font _font;
        float _nbScale;
        float scale;
    private:
};

#endif /* !BROADCAST_HPP_ */
