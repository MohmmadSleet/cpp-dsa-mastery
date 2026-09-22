// play 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
#include<cstdlib>
#include<string>
using namespace std;
enum enGameChoice{Stone=1,Scissor=2,Paper=3};
enum enWinner{Player=1,Computer=2,Draw=3};

struct stRoundInfo {
    short RoundNumber = 0 ;
    enGameChoice player1Choice;
    enGameChoice computerChoice;
    enWinner WinnerINTheRound;
    string WinnerName;

};
struct stGameResult{
    short RoundNumber = 0;
    short Player1WinTime = 0;
    short ComputerwinTime = 0;
    short DrawTime = 0;
    enWinner WinnerInTheGame;
    string WinnerName;

};
short ReadHowManyRound() {
    short RoundNum = 0;
    do {
        cout << "How Many Round do you want to play from 1 to 10 ?";
        cin >> RoundNum;
    } while (RoundNum > 10 || RoundNum < 1);
    return RoundNum;
}
enGameChoice ReadChoicePlayer() {
    short ChoicePlayer = 0;
    do {
        cout << "What are you need choice [1]stone, [2]scissor,[3]paper ?";
        cin >> ChoicePlayer;

    } while (ChoicePlayer > 3 || ChoicePlayer < 1);
    return (enGameChoice)ChoicePlayer;
}
int RandomChoice(int From,int To) {

    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
enGameChoice GetChoiceComputer(){

    return (enGameChoice)RandomChoice(1, 3);
}
enWinner CheckTheWinnerInTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.player1Choice == RoundInfo.computerChoice) {
        return enWinner::Draw;
    }
    switch (RoundInfo.player1Choice) {
    case enGameChoice::Stone:
        if (RoundInfo.computerChoice == enGameChoice::Scissor) {
            return enWinner::Player;
        }
        break;
    case enGameChoice::Scissor:
        if (RoundInfo.computerChoice == enGameChoice::Paper) {
            return enWinner::Player;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.computerChoice == enGameChoice::Stone) {
            return enWinner::Player;
        }
        break;
    }
    return enWinner::Computer;

}
string NameWinner(enWinner winner) {
    string arrWinnerName[3] = { "player1 ","computer ","Draw" };
    return arrWinnerName[winner - 1];
}
string ChoiceName(enGameChoice GameChoice) {
    string arrGameChoice[3] = { "Stone","scissor","Paper" };
    return arrGameChoice[GameChoice - 1];

}
void SetWinnerScreenColor(enWinner Winner) {
    if (Winner == enWinner::Player) {
        system("Color 2F");
    }
    else if (Winner == enWinner::Computer) {
        system("Color 4F");
    }
    else {
        system("Color 6F");
    }
}
void PrintTheResultRound(stRoundInfo RoundInfo) {
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1  Choice: " << ChoiceName(RoundInfo.player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.computerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "] \n";  
    cout << "__________________________________\n" << endl;

     SetWinnerScreenColor(RoundInfo.WinnerINTheRound);
}
enWinner CheckTheWinnerInTheGame(stGameResult GameResult) {
    if (GameResult.Player1WinTime == GameResult.ComputerwinTime)
        return enWinner::Draw;
    else if (GameResult.Player1WinTime > GameResult.ComputerwinTime)
        return enWinner::Player;
    else
        return enWinner::Computer;
}
stGameResult FillTheGameResult(short Player1winTime,short computerwinTime,short DrawTime,short NumberRound){
    stGameResult GameResult;
    GameResult.Player1WinTime = Player1winTime;
    GameResult.ComputerwinTime = computerwinTime;
    GameResult.DrawTime = DrawTime;
    GameResult.RoundNumber = NumberRound;
    GameResult.WinnerInTheGame = CheckTheWinnerInTheGame(GameResult);
    GameResult.WinnerName = NameWinner(GameResult.WinnerInTheGame);
    return GameResult;

}
stGameResult PlayGame(short NumberRound) {
    stRoundInfo RoundInfo;
    short Player1WinTime = 0, ComputerWinTime = 0, DrawTime = 0;

    for (int i = 1; i <= NumberRound; i++) {

        RoundInfo.RoundNumber = i;
        RoundInfo.player1Choice = ReadChoicePlayer();
        RoundInfo.computerChoice = GetChoiceComputer();
        RoundInfo.WinnerINTheRound = CheckTheWinnerInTheRound(RoundInfo);
        RoundInfo.WinnerName = NameWinner(RoundInfo.WinnerINTheRound);
    
        if (RoundInfo.WinnerINTheRound == enWinner::Player)
            Player1WinTime++;
        else if (RoundInfo.WinnerINTheRound == enWinner::Computer)
            ComputerWinTime++;
        else
            DrawTime++;
        PrintTheResultRound(RoundInfo);
    }
    
    return FillTheGameResult(Player1WinTime, ComputerWinTime, DrawTime, NumberRound);
}

void ResetScreen() {
    system("cls");
    system("color 0F");
}
void ShowTheGameOverInTheScreen() {
    cout << "\t\t" << "__________________________________________________________\n\n";
    cout << "\t\t" << "                 +++ G a m e  O v e r +++\n";
    cout << "\t\t" << "__________________________________________________________\n\n";

}
void PrintTheGameResult(stGameResult GameResult) {
    cout  << "_____________________ [Game Results ]_____________________\n\n"; 
    cout  <<  "Game Rounds        : " << GameResult.RoundNumber << endl;
    cout  << "Player1 won times  : " << GameResult.Player1WinTime << endl;
    cout  << "Computer won times : " << GameResult.ComputerwinTime << endl;
    cout  << "Draw times         : " << GameResult.DrawTime << endl;  
    cout  << "Final Winner       : " << GameResult.WinnerName << endl; 
    cout  << "___________________________________________________________\n";     
    SetWinnerScreenColor(GameResult.WinnerInTheGame);

}
void StartGame() {
    char PlayAgain = 'N';
    do {
        ResetScreen();
        stGameResult GameResult = PlayGame(ReadHowManyRound());
        ShowTheGameOverInTheScreen();
        PrintTheGameResult(GameResult);
        cout << "\t\t" << "Do you want to play again ? Y/N?";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
    {

    }
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
