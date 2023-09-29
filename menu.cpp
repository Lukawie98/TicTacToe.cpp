#include <iostream>
#include <unistd.h>

#include "menu.h"
#include "board.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
    void Menu::optionMainMenuSelect()        
    {        
        //typing a 'char' option from the keyboard
        std::cin>>option;
        system("cls");  
        
        //After entering a variable, selecting a given option from the menu
        switch(option)
        {
                case START:
                {   
                    levelChoice();
                    Board brd1;
                    brd1.showBoard();
                    break;
                }
                case EXIT:
                {
                    std::cout<<"Goodbye!\n";
                    sleep (2);
                    exit(0);
                    break;
                }
                default:
                {
                    std::cout<<"Wrong sign! Try one more time.\n";
                    sleep (3);
                    system("cls");
                    break;
                }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
    void Menu::runMenu()
    {
        std::string gameTitle="TIC TAC TOE GAME!";
        std::string starsDesign (gameTitle.length(), '*');
        
        //Display the menu in a loop using the function to select options 
        while(true)
        {
            std::cout   <<starsDesign<<"\n"
                        <<gameTitle<<"\n\n"
                        <<"Select an option: \n"
                        <<"-----------------\n"
                        <<"Press 1 to Play!\n"
                        <<"Press 2 to EXIT\n"
                        <<starsDesign<<"\n"
                        <<"\nEnter: ";
            optionMainMenuSelect();
        }
    }    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      
    void Menu::showlvlSelectMenu() 
    {
        //Displaying the menu for selecting the mode of game
        system("cls"); 
        std::cout<<"Select an option: \n"
                 <<"1 - Play with your friend\n"
                 <<"2 - Computer EASY\n"
                 <<"3 - Computer MEDIUM\n"
                 <<"4 - Computer HARD\n"
                 <<"5 - Back to main menu\n\n";
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      
    void Menu::gameModeSelect()
    {
        //Displaying menu for selecting mode and entering variable
        
        showlvlSelectMenu();
        std::cout<<"\nEnter: ";
        std::cin>>choiceOfLevel;
            
        std::cout<<"\n";
        system("cls");
        
        //Selecting the given option from the menu            
            switch(choiceOfLevel)
            {
                    case FRIEND:
                    {
                        Board brd1;
                        brd1.playWithFriend();
                        break;
                    }    
                    case EASY:
                    {   
                        Board brd1;
                        brd1.playOnEasyLvl();
                        break;
                    }
                    case MEDIUM:
                    {
                        Board brd1;
                        brd1.playOnMediumLvl();
                        break;
                    }
                    case HARD:
                    {
                        Board brd1;
                        brd1.playOnHardLvl();
                        break;
                    }
                    case BACK:
                    {
                        runMenu();
                        break;
                    }
                    
                    default:
                    {
                        system("cls");
                        std::cout<<"Inncorect sign \n";
                        break;
                   }
            }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
    void Menu::levelChoice()
    {
        //Display in a loop the entire game mode selection menu with the function of approval after the completed game or incorrect sign.
        while(true)
        {
            gameModeSelect();
            
            std::cout<<"Press enter to return to menu";
            getchar(); getchar();
            system("cls");
        }
    } 