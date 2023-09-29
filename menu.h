#pragma once
#include <string>


class Menu
{
    char option{0};             //sign in the main menu for selecting options
    char choiceOfLevel{0};      //sign in the option selection menu used to select the mode of game
    std::string gameTitle{0};   //Title of the game
    std::string starsDesign{0}; //Design to menu as long as title
    

public:
    enum Option : char {START='1', EXIT};
    enum ChoiceOfLevel : char {FRIEND='1', EASY, MEDIUM, HARD, BACK};
    void optionMainMenuSelect();
    void runMenu();             
    void showlvlSelectMenu();
    void gameModeSelect();
    void levelChoice(); 
};