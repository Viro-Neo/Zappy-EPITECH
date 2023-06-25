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
        Incantation(int level, sf::Vector2u pos, Player starter, std::list<Player> &participent);
        ~Incantation();
        void finishIncantation(int result);
        sf::Vector2u &getPos(void);
        Player &getStarter(void);
        std::list<Player> &getParticipent(void);
    protected:
    private:
        int _level;
        sf::Vector2u _pos;
        Player _starter;
        std::list<Player> _participent;
};



#endif /* !INCANTATION_HPP_ */
