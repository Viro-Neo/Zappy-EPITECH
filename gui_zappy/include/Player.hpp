/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_
    #include <SFML/Graphics.hpp>

struct Inventory
{
    int FOOD;
    int LINEMATE;
    int DERAUMERE;
    int SIBUR;
    int MENDIANE;
    int PHIRAS;
    int THYSTAME;
};

enum Orientation {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
};

class Player {
    public:
        Player(int id, int x, int y, Orientation o, int level, std::string teamName);
        ~Player();
        int getLevel();
        void setLevel(int lv);
        int getId();
        bool getIncantation();
        void setIncantation(bool);
        std::string getTeamName();
        void setTeamName(std::string);
        sf::Vector2u getPos();
        void setPos(sf::Vector2u pos);
        Inventory inventory;
    protected:
    private:
        int _id;
        sf::Vector2u pos;
        int level;
        Orientation _orientaton;
        std::string _teamName;
        bool _incantation;
};



#endif /* !PLAYER_HPP_ */
