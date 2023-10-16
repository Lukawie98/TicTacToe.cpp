#pragma once

class Board
{
    char field[9] {'1','2','3','4','5','6','7','8','9'}; //fields on the game board
    int numField{1};      //typed number of the field to which we want to give our sign
    bool resetNumb{true}; //variable, which changed to false means the end of game
    char signOnBoard{0};  //the sign 'X' or 'O' to be entered in the selected field
    int randNum{0};       //a random number that determines who starts at medium level
    
public:
    
    void showBoard();          
    void enteringNumField();    
    void checkingField(); 
    
    void checkIfGameIsFinished();
    
    void moveOfOtherPlayer();   
    void randomFieldGeneration();  
    void checkingIfCanFinish(); 
    void playingMediumLvlPlayerStarts();
    void playingMediumLvlComputerStarts();
    void playWithFriend();
    void playOnEasyLvl();
    void playOnMediumLvl();
    void playOnHardLvl();
    void backToMenu();
    void showingWhichSignPlaying();
    void refreshBoard();
};