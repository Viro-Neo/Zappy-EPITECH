/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Incantation
*/

#ifndef INCANTATION_HPP_
#define INCANTATION_HPP_
    #include <SFML/Graphics.hpp>
    #include <list>
    #include <Player.hpp>
class Incantation {
    public:
        Incantation(int level, sf::Vector2i pos, Player starter, std::list<Player> &participent);
        ~Incantation();
        void finishIncantation(int result);
        sf::Vector2i &getPos(void);
        Player &getStarter(void);
        std::list<Player> &getParticipent(void);
        void addTime(int time);
        const sf::Sprite &getSprite() const;
        void setSpirtePos(sf::Vector2i pos);
    protected:
    private:
        int _level;
        sf::Vector2i _pos;
        Player _starter;
        std::list<Player> _participent;
        sf::Sprite _sprite;
        sf::Texture _text;
        int _time;
};



#endif /* !INCANTATION_HPP_ */
