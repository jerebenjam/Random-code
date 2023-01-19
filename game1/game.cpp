#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int maxNum)
{
    maxNumber = maxNum;
    cout<<"GAME CONSTRUCTOR: object initialized whit "<<maxNumber<<" as a maximum value"<<endl;
}

Game::~Game()
{
    cout<<"GAME DESTRUCTOR: object cleared from stack memory"<<endl;
}

void Game::play()
{
    srand(time(NULL));
    randomNumber = rand() % maxNumber+1;

    while(true)  {
        numOfGuesses++;
        cout <<"Give your guess between 0-"<<maxNumber<< endl;
        cin >> playerGuess;

        if(playerGuess == randomNumber) {
            cout <<"Your guess is right = "<<randomNumber<<endl;
            break;
        }
        else if(playerGuess < randomNumber) {
            cout <<"Your guess is too small"<<endl;
        }
        else    {
            cout <<"Your guess is too big"<<endl;
        }
    }
    printGameResult();
}

void Game::printGameResult()
{
    cout<<"You guessed the right answer = "<<randomNumber<<" whit "<<numOfGuesses<<" guesses"<<endl;
}
