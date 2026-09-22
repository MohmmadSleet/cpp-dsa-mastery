#include<iostream>
#include<string>
#include<cstdlib>
#include<math.h>

using namespace std;
enum enGameChoice{stone=1,paper=2,scissor=3};
enum enWinner{player1=1,computer=2,draw=3};

struct stRoundInfo {
	short NumberRound;
	enGameChoice Player1;
	enGameChoice computer;
	enWinner Winner;
	string WinnerName;

};
struct stGameResult {
	short NumberRound;
	short Player1winTimes;
	short computerwinTimes;
	short DrawTimes;
	enWinner Winner;
	string WinnerName;
};
int RandomNumber(int from, int to) {
	int Randnum = rand() % (to - from + 1) + from;
	return Randnum;
}
short ReadHowManyRound() {
	short numberRound = 0;
	do {
		cout << "enter the Round From 1 to 10 " << endl;
		cin >> numberRound;
	} while (numberRound > 10 || numberRound < 1);
	return numberRound;
}
enGameChoice  ReadPlayer1Choice() {
	short ChoicePlayer;
	do {
		cout << "Enter the choice :[1] stone,[2]=paper,[3]=scissor \n";
		cin >> ChoicePlayer;
	} while (ChoicePlayer > 3 || ChoicePlayer < 1);
	return enGameChoice(ChoicePlayer);
}
enGameChoice GetChoiceComputer() {
	return enGameChoice(RandomNumber(1, 3));
}
enWinner CheckTheWinner(stRoundInfo RoundInfo) {
	if (RoundInfo.Player1 == RoundInfo.computer)
	{
		return enWinner::draw;
	}
	switch (RoundInfo.Player1)
	{
	case enGameChoice::stone:
		if (RoundInfo.computer ==enGameChoice::paper) {
			
			return enWinner::computer;

		}
		break;

	case enGameChoice::paper:
		if (RoundInfo.computer == enGameChoice::scissor) {
			
			return enWinner::computer;
			
		}
		break;
	case enGameChoice::scissor:
		if (RoundInfo.computer == enGameChoice::stone) {
			return enWinner::computer;
		}
		break;
	}
	return enWinner::player1;
}
string WinnerName(enWinner Winner) {
	string arrWinnerName[3] = { "player1","compuer","draw" };
	return arrWinnerName[Winner - 1];
}
string ChoiceName(enGameChoice Choice) {
	string arrChoiceName[3] = {"stone","paper","scissor"};
	return arrChoiceName[Choice - 1];
}
void setColorScreen(enWinner Winner) {
	switch (Winner) {
	case enWinner::player1:
		system("color 2F");
		break;
	case enWinner::computer:
		system("color  4F");
		break;
	case enWinner::draw:
		system("color 6F");
		break;
	}
}
void printResultRound(stRoundInfo RoundInfo) {
	
	cout << "\n___________________________________________________\n";
	cout << "Number Round = " << RoundInfo.NumberRound << endl;
	cout << "choice Player 1 = " <<ChoiceName(RoundInfo.Player1) << endl;;
	cout << "choice computer = " << ChoiceName(RoundInfo.computer) << endl;
	cout << "Winner Name = " << RoundInfo.WinnerName << endl;
	setColorScreen(RoundInfo.Winner);
}
enWinner CheckTheWinnerInFinal(stGameResult GameResult) {
	if (GameResult.Player1winTimes > GameResult.computerwinTimes)
		return enWinner::player1;
	else if (GameResult.Player1winTimes < GameResult.computerwinTimes)
		return enWinner::computer;
	else
		return enWinner::draw;
}
stGameResult FillGameResult(short Round, short player1win, short computerwin, short draw) {
	stGameResult GameResult;
	GameResult.NumberRound = Round;
	GameResult.Player1winTimes = player1win;
	GameResult.computerwinTimes = computerwin;
	GameResult.DrawTimes = draw;
	GameResult.Winner = CheckTheWinnerInFinal(GameResult);
	GameResult.WinnerName = WinnerName(GameResult.Winner);
     
	return GameResult;
}
stGameResult PlayGame(short Round) {
	stRoundInfo RoundInfo;
	short player1win = 0, computewin = 0, draw = 0;
	for (int i = 1; i <= Round; i++) {
		RoundInfo.NumberRound = i;
		RoundInfo.Player1 = ReadPlayer1Choice();
		RoundInfo.computer = GetChoiceComputer();
		RoundInfo.Winner = CheckTheWinner(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
		
		if (RoundInfo.Winner == enWinner::player1)
			player1win++;
		else if (RoundInfo.Winner == enWinner::computer)
			computewin++;
		else
			draw++;
		printResultRound(RoundInfo);
	}
	return FillGameResult(Round,player1win, computewin, draw);
}
void ShowGameOverInScreen() {
	cout << "\n ___________________________________________________\n";

	cout << "                + + G A M E O V E R + +                               ";
	cout << "\n________________________________________________________\n";
}
void ShowResultGame(stGameResult GameResult) {
	cout << "\n_________________________________________________________\n";
	cout << "Number Round In The Game =  " << GameResult.NumberRound << endl;
	cout << "Player 1 win the Game =  " << GameResult.Player1winTimes << endl;
	cout << "computer win in Game =  " << GameResult.computerwinTimes << endl;
	cout << "Draw in Game =  " << GameResult.DrawTimes << endl;
	cout << "Winner In The Game = " << GameResult.WinnerName<<endl;
	cout << "\n__________________________________________________________\n";
}
void ResetScreen() {
	system("cls");
	system("color 0F");
}
void StartGame() {
	char PlayAgain = 'Y';
	do {
		ResetScreen();
		stGameResult GameResult = PlayGame(ReadHowManyRound());
		ShowGameOverInScreen();
		ShowResultGame(GameResult);
		cout << "\n\n" << "Do You want to play again Y/N";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main() {
	
	srand((unsigned)time(NULL));

	StartGame();
	return 0;

}