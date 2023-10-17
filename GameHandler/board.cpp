#include <iostream>

#include "board.hpp"
#include "../MenuHandler/menu.hpp"


void Board::showBoard()
{
        //Displays game boards with field numbering, and menu return function
        
        backToMenu();
        std::cout<<"      |       |       \n"
                 <<"  "<<field[0]<<"   |   "<<field[1]<<"   |   "<<field[2]<<"  \n"
                 <<"      |       |       \n"
                 <<"- - - + - - - + - - - \n"
                 <<"      |       |       \n"
                 <<"  "<<field[3]<<"   |   "<<field[4]<<"   |   "<<field[5]<<"  \n"
                 <<"      |       |       \n"
                 <<"- - - + - - - + - - - \n"
                 <<"      |       |       \n"
                 <<"  "<<field[6]<<"   |   "<<field[7]<<"   |   "<<field[8]<<"  \n"
                 <<"      |       |       \n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::enteringNumField()
{
    showingWhichSignPlaying();
    
    //Entering the number of the field in which the character is to appear
    std::cout<<"Enter the field in which you want to insert a character (1-9): ";   
    std::cin>>numField;    
    
    //Checking in the loop if the character is in the range 1-9
    while(numField<0 || numField>9)
    {  
        std::cout<<"Wrong sign! Try one more time: ";
        std::cin>>numField;
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::checkingField()
{
    //checking in a loop whether the specified field is free, if so it assigns a character to the selected field
    while(field[numField-1] == 'X' || field[numField-1] == 'O')
    {
        std::cout<<"This field is occupied! Select another\n";
        enteringNumField();
    }    
    
    field[numField-1] = signOnBoard;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::checkIfGameIsFinished()
{
    //Checks if the game is over and who won or drew
    //Combinations of game ends
    int finishCombinations[8][3] 
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    
    //loop through combinations checking if it's the end of the game, if it's won it returns who it is and ends the function
    for(int i = 0; i < 8; i++)
    {
        int a = finishCombinations[i][0];
        int b = finishCombinations[i][1];
        int c = finishCombinations[i][2];
        
        if(field[a] == field[b] && field[b] == field[c])
        {
            std::cout<<"The winner is -> "<<signOnBoard<<"\n";
            resetNumb=false;
            return;
        }
    }
    
    //if all fields are filled in and no one has won, it returns information about a tie
    if(field[0]!='1' && field[1]!='2' && field[2]!='3' && field[3]!='4' && field[4]!='5' 
       && field[5]!='6' && field[6]!='7' && field[7]!='8' && field[8]!='9') 
        {
            std::cout<<"Close game! Tie!\n";
            resetNumb=false;
        }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::moveOfOtherPlayer()
{
        //Player's move, write in the sign in the free and correct field and refresh the board
        enteringNumField();
        checkingField();
        checkIfGameIsFinished();
        refreshBoard();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::randomFieldGeneration()
{
     //Generates a random field number 
    numField = rand()%8;
     //Checking in the loop if the field is free, if no, generates random field number
    while(field[numField] == 'X' || field[numField] == 'O')
    {   
        numField = rand()%8;
    }
    //writes a character into empty field number
    field[numField] = signOnBoard;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::checkingIfCanFinish()
{
    // Array of winning combinations
    int winningCombinations[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    // Loop through the winning combinations
    for (int i = 0; i < 8; i++) {
        int a = winningCombinations[i][0];
        int b = winningCombinations[i][1];
        int c = winningCombinations[i][2];
        if (field[a] == field[b] && (field[b] == 'O' || field[b] == 'X') && field[c] != 'O' && field[c] != 'X') {
            field[c] = signOnBoard;
            return;
        } else if (field[b] == field[c] && (field[c] == 'O' || field[c] == 'X') && field[a] != 'O' && field[a] != 'X') {
            field[a] = signOnBoard;
            return;
        } else if (field[a] == field[c] && (field[c] == 'O' || field[c] == 'X') && field[b] != 'O' && field[b] != 'X') {
            field[b] = signOnBoard;
            return;
        }
    }
    // If no winning combinations found, randomly select a field
    Board::randomFieldGeneration();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::playingMediumLvlPlayerStarts()
{
    //A mid-level game system where the player starts
    //After each move it is checked if the reset number is true, if not it breaks out of the loop and the game is over
    while(true)
    {   
        signOnBoard = 'O';
        moveOfOtherPlayer();
        if(resetNumb==false)
        {
            break;
        }

        signOnBoard = 'X';
        checkingIfCanFinish();
        refreshBoard();
        if(resetNumb==false)
        {
            break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::playingMediumLvlComputerStarts()
{
    //A mid-level game system where the computer starts
    //After each move it is checked if the reset number is true, if not it breaks out of the loop and the game is over
    while(true)
    {   
        signOnBoard = 'O';
        checkingIfCanFinish();
        refreshBoard();
        if(resetNumb==false)
        {
            break;
        }
        
        signOnBoard = 'X';
        moveOfOtherPlayer();
        if(resetNumb==false)
        {
            break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::playWithFriend()
{
    //game system where two players compete against each other
    //After each move it is checked if the reset number is true, if not it breaks out of the loop and the game is over
    showBoard();
    while(true)
    {   
        signOnBoard = 'O';
        moveOfOtherPlayer();
        if(resetNumb==false)
        {
            break;
        }
        signOnBoard = 'X';
        moveOfOtherPlayer();
        if(resetNumb==false)
        {
            break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::playOnEasyLvl()
{
    //A easy-level game system where the player starts
    //After each move it is checked if the reset number is true, if not it breaks out of the loop and the game is over
    showBoard();
    
    while(true)
    {   
        signOnBoard = 'O';
        moveOfOtherPlayer();
        if(resetNumb==false)
        {
            break;
        }
        signOnBoard = 'X';
        
        randomFieldGeneration();
        refreshBoard();
        if(resetNumb==false)
        {
            break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::playOnMediumLvl()
{
    //The function of the game at the middle level, where the number 0 or 1 is drawn at the beginning,
    //if it is 1 then the player starts, if 0 then computer
    //consistent with this, the relevant functions are performed
    showBoard();
    randNum = rand()%2;
    if(randNum == 1)
    {
        playingMediumLvlPlayerStarts();
    }
    else 
    {
        playingMediumLvlComputerStarts();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::playOnHardLvl()
{
    //A hard-level game system where the computer always starts on to middle field of board
    //After each move it is checked if the reset number is true, if not it breaks out of the loop and the game is over
    showBoard();
    while(true)
    {   
        signOnBoard = 'O';
        if(field[4] == signOnBoard)
        {
            checkingIfCanFinish();
        }
        else 
        {
            field[4] = signOnBoard;
        }
        refreshBoard();
        
        if(resetNumb == false)
        {
            break;
        }
        
        signOnBoard = 'X';
        moveOfOtherPlayer();
        if(resetNumb ==  false)
        {
            break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::backToMenu()
{
    //A feature that allows during the game to return to the menu when entering a field number
    std::cout<<"If you want to back to menu, press 0"<<"\n";
    
    if(numField==0)
    {
        system("cls");
        Menu m1;
        m1.levelChoice();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::showingWhichSignPlaying()
{
    //Shows which character will now be written into the given field on the board
    if(signOnBoard=='O')
    {
        std::cout<<"Turn of -> O\n";
    }
     if(signOnBoard=='X')
    {
        std::cout<<"Turn of -> X\n";
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::refreshBoard()
{
    //Clearing and showing the board again with the changes and checking if anyone won
        system("cls");
        showBoard();
        checkIfGameIsFinished();
}