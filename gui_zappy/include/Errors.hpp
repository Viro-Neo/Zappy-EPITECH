/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-nathan.warin
** File description:
** Errors.hpp
*/

#ifndef ERRORS_HPP_
    #define ERRORS_HPP_

#include <iostream>

class Errors {
    public:
        class NotEnoughArgumentsError : public std::exception {
            private:
                const std::string message = "Not enough arguments";
            public:
                const char *what() const throw();
        };
        class ArgumentNotANumber : public std::exception {
            private:
                const std::string message = "Argument is not a number";
            public:
                const char *what() const throw();
        };
        class ArgumentError : public std::exception {
            private:
                const std::string message = "Only first argument should be a float or too much '.' in argument";
            public:
                const char *what() const throw();
        };
        class PizzaTypeError : public std::exception {
            private:
                const std::string message = "Wrong pizza type";
            public:
                const char *what() const throw();
        };
        class PizzaSizeError : public std::exception {
            private:
                const std::string message = "Wrong pizza size";
            public:
                const char *what() const throw();
        };
        class PizzaNumberError : public std::exception {
            private:
                const std::string message = "Wrong pizza number";
            public:
                const char *what() const throw();
        };
        class PipeOpenError : public std::exception {
            private:
                const std::string message = "Pipe coulnd't open right";
            public:
                const char *what() const throw();
        };
        class PipeWrongHandling : public std::exception {
            private:
                const std::string message = "Pipe function used wrongly";
            public:
                const char *what() const throw();
        };
        class PipeReadError : public std::exception {
            private:
                const std::string message = "Reading Error occured";
            public:
                const char *what() const throw();
        };
};

#endif