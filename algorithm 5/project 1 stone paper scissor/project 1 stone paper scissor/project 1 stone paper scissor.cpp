#include<iostream>
#include<cstdlib>
#include<string>
#include<math.h>
using namespace std;
enum enGameChoice{stone=1,paper=2,scissor=3};
enum enWineer{Player1=1,computer=2,Draw=3};

struct stRoundInfo {
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice computerChoice;
	enWineer Winner;
	string WinnerName;
};
struct stGameResult {
	short GameRound = 0;
	short Player1Wintimes = 0;
	short computer2wintimes = 0;
	short DrawTime = 0;
	enWineer GameWinner;
	string winnername="";
};
int RandomNumber(int from, int to) {
	int Randomnum = rand() % (to - from + 1) + from;
	return Randomnum;
}
enGameChoice ReadPlayer1choice() {
	short choice = 1;
	do {
		cout << "\n Your choice :[1] stone ,[2] paper,[3] scissor ?";
		cin >> choice;

	} while (choice < 1 || choice>3);
	return (enGameChoice)choice;
}
enGameChoice Getcomputerchoice() {
	return enGameChoice(RandomNumber(1, 3));
}
enWineer whoWonTheRound(stRoundInfo RoundInfo) {
	if (RoundInfo.Player1Choice == RoundInfo.computerChoice) {
		return enWineer::Draw;
	}
	switch (RoundInfo.Player1Choice) {
	case enGameChoice::stone:
		if (RoundInfo.computerChoice == enGameChoice::paper) {
			return enWineer::computer;
	}
		break;
	case enGameChoice::paper:
		if (RoundInfo.computerChoice == enGameChoice::scissor) {
			return enWineer::computer;
		}
		break;
	case enGameChoice::scissor:
		if (RoundInfo.computerChoice == enGameChoice::stone) {
			return enWineer::computer;
		}
		break;
	}
	return enWineer::Player1;
}
string WinnerName(enWineer winner) {
	string arrWinnerName[3] = { "palyer1","computer","no winner" };
	return arrWinnerName[winner - 1];
}
string choiceName(enGameChoice choice) {
	string arrGamechoice[3] = { "stone","paper","scissor" };
	return arrGamechoice[choice - 1];

}
void setwinnerScreenColor(enWineer winner) {
	switch (winner)
	{
	case enWineer::Player1:
		system("color 2F");//turn screen to green
		break;
	case enWineer::computer:
		system("color 4F");//turn screen to red
		cout << "\a";
		break;
	case enWineer::Draw:
		system("color 6F");//turn screen to yellow
		break;
	}
}
void printresultround(stRoundInfo RoundInfo) {
	cout << "\n ___________________Round[" << RoundInfo.RoundNumber << "]_____________\n\n";
	cout << "player1 choice: " << choiceName(RoundInfo.Player1Choice) << endl;
	cout << "computer choice: " << choiceName(RoundInfo.computerChoice) << endl;
	cout << "Round winner : [" << RoundInfo.WinnerName << "]\n";
	cout << "______________________________\n" << endl;
	setwinnerScreenColor(RoundInfo.Winner);

}
enWineer WhoWonTheGame(short Playe1WinTimes, short computerwinTimes) {
	if (Playe1WinTimes > computerwinTimes)
		return enWineer::Player1;
	else if (computerwinTimes > Playe1WinTimes)
		return enWineer::computer;
	else
		return enWineer::Draw;
}
stGameResult fillGameResult(short HowManyRound, short Player1WinTimes, short computerwinTime, short DrawTime) {

	stGameResult GameResult;

	GameResult.GameRound = HowManyRound;
	GameResult.Player1Wintimes = Player1WinTimes;
	GameResult.computer2wintimes = computerwinTime;
	GameResult.DrawTime = DrawTime;
	GameResult.GameWinner = WhoWonTheGame(Player1WinTimes, computerwinTime);
	GameResult.winnername = WinnerName(GameResult.GameWinner);
	return GameResult;
}
stGameResult PlayGame(short HowManyRound) {
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, computerwinTime = 0, DrawTime = 0;
	for (short GameRound = 1; GameRound <= HowManyRound; GameRound++) {
		cout << "\n Round [" << GameRound << "] begins : \n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1choice();
		RoundInfo.computerChoice = Getcomputerchoice();
		RoundInfo.Winner = whoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWineer::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWineer::computer)
			computerwinTime++;
		else
			DrawTime++;
		printresultround(RoundInfo);

	}
	return fillGameResult(HowManyRound, Player1WinTimes, computerwinTime, DrawTime);
}
string Tabs(short NumberofTabs) {
	string t = "";
	for (int i = 1; i < NumberofTabs; i++) {
		t = t + "\t";
		
	}
	return t;
}
void showGameOverscreen() {
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "                    +++ G a m e O v e r +++\n ";
	cout << Tabs(2) << "__________________________________________________________\n\n";

}

void showFinalGameResult(stGameResult GameResult) {
	cout << Tabs(2) << "____________________________[Game Result ]______________________\n\n";
	cout << Tabs(2) << "Game Round               : " << GameResult.GameRound << endl;
	cout << Tabs(2) << "player 1 won times   : " << GameResult.Player1Wintimes << endl;
	cout << Tabs(2) << "computer won times   : " << GameResult.computer2wintimes << endl;
	cout << Tabs(2) << "Draw times : " << GameResult.DrawTime << endl;
	cout << Tabs(2) << "final winner : " << GameResult.winnername << endl;
	cout << Tabs(2) << "_____________________________________________\n";
	setwinnerScreenColor(GameResult.GameWinner);
}
short ReadHowManyRound() {
	short GameRound = 1;
	do {
		cout << "How Many Round 1 to 10 ? \n";
		cin >> GameRound;
	} while (GameRound < 1 || GameRound>10);
	return GameRound;
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
		showGameOverscreen();
		showFinalGameResult(GameResult);


		cout << endl << Tabs(3) << "Do You want to play again ? Y/N ";
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');

}
int main() {

	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}