/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** FunctionManager.hpp
*/

#ifndef B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_FUNCTIONMANAGER_HPP
    #define B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_FUNCTIONMANAGER_HPP

    #include <map>
    #include <list>
    #include <string>
    #include "ParseCommands.hpp"

class FunctionManager {
public:
    FunctionManager(); // Constructor initializes the map
    ~FunctionManager() = default;

    void callFunction(std::string, Map);

    std::map<std::string, void (*)(std::list<std::string> arg, Map myMap)> getFct() const;
    void setFct(const std::map<std::string, void (*)(std::list<std::string> arg, Map myMap)> &fct);

private:
    std::map<std::string, void (*fct)(std::list<std::string> arg, Map myMap)> _fct;
};

#endif //B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_FUNCTIONMANAGER_HPP
