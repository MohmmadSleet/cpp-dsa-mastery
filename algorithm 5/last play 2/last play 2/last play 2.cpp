
#include<iostream>
#include<string>
#include<cstdlib>
#include<math.h>
using namespace std;
enum enOperaterType { add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };
enum enQuestionType { Easy = 1, Med = 2, Hard = 3, MixQL = 4 };
struct stQuestion {
	int NumberOfQuestion = 0;
	int Number1 = 0;
	int Number2 = 0;
	enOperaterType OperaterType;
	enQuestionType QuestionLevel;
	int CorrectAnswer=0;
	int PlayerAnswer = 0;
	bool isCorrect = false;

};

struct stQuizz {
	stQuestion QuestionList[100];
	int NumberOfQuestion = 0;
	int NumberOfCorrectAnswer = 0;
	int NumberOfWrongAnswer = 0;
	enQuestionType QuesionLevel;
	enOperaterType OperaterType;
	bool IsPass = true;

};
short ReadNumberOfQuestion() {
	short Number = 0;
	do {
		cout << "please enter the Number Of question ? \n";
		cin >> Number;
	} while (Number > 10 || Number < 1);
	return Number;
}
int RandomNumber(int From,int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;

}
enQuestionType ReadQuestionLevel() {
	short Level = 0;
	do {
		cout << "What is level ? [1] Easy, [2] Med, [3] Hard,[4] Mix" << endl;
		cin >> Level;

	} while (Level > 4 || Level < 1);
	return (enQuestionType)Level;
}
enOperaterType ReadOperaterType()
{
	short op;
	do {
		cout << "What the Operater Type? [1] add, [2] Sub, [3] Mult, [4] Div , [5] Mix " << endl;
		cin >> op;
	} while (op > 5 || op < 1);
	return (enOperaterType)op;
}
int SimpleClculater(int Number1, int Number2, enOperaterType Op) {
	switch (Op) {
	case enOperaterType::add:
		return Number1 + Number2;
		break;
	case enOperaterType::Sub:
		return Number1 - Number2;
		break;
	case enOperaterType::Mult:
		return Number1 * Number2;
		break;
	case enOperaterType::Div:
		return Number1 / Number2;
		break;

	}
}
stQuestion StorgeOfQuestionintheFun(stQuizz& Quizz) {
	stQuestion Question;
	if (Quizz.OperaterType == enOperaterType::MixOp) {
		Quizz.OperaterType =(enOperaterType)RandomNumber(1, 4);
	}
	if (Quizz.QuesionLevel == enQuestionType::MixQL) {
		Quizz.QuesionLevel = (enQuestionType)RandomNumber(1, 3);
	}
	Question.OperaterType = Quizz.OperaterType;
	Question.QuestionLevel = Quizz.QuesionLevel;
	switch (Question.QuestionLevel)
	{
	case enQuestionType::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleClculater(Question.Number1, Question.Number2, Question.OperaterType);
		break;
	case enQuestionType::Med:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleClculater(Question.Number1, Question.Number2, Question.OperaterType);
		break;
	case enQuestionType::Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleClculater(Question.Number1, Question.Number2, Question.OperaterType);
		break;

	}
	return Question;
}
void GenerateQuizzQuestion(stQuizz& Quizz) {
	for (int i = 0; i < Quizz.NumberOfQuestion; i++) {
		Quizz.QuestionList[i] = StorgeOfQuestionintheFun(Quizz);
	}
}
string GetOperaterType(enOperaterType OperaterType) {
	string arr[4] = { " + "," - "," * "," / " };
	return arr[OperaterType - 1];
}
void PrintTheQuestion(short i,stQuizz Quizz) {
	cout << "Quision :" << endl;
	cout << Quizz.QuestionList[i].Number1 << endl;
	cout << Quizz.QuestionList[i].Number2 << "    " << GetOperaterType(Quizz.QuestionList[i].OperaterType) << endl;
	cout << "------------------\n";
}
int ReadTheAnswer() {
	int Answer = 0;
	cin >> Answer;
	return Answer;
}
void SetScreenColor(bool AnswerResult) {
	if (AnswerResult == true) 
		system("color 2F");
	else
		system("color 4F");


}

void PrintTheResultQustion(short i, stQuizz& Quizz) {
	if (Quizz.QuestionList[i].PlayerAnswer != Quizz.QuestionList[i].CorrectAnswer) {
		Quizz.QuestionList[i].isCorrect = false;
		Quizz.NumberOfWrongAnswer++;
		cout << "Worng Answer :-( \n";
		cout << "The right answer is: ";
		cout << Quizz.QuestionList[i].CorrectAnswer;
		cout << "\n";
	}

	else { 
		Quizz.QuestionList[i].isCorrect = true;
		Quizz.NumberOfCorrectAnswer++;
		cout << "Right Answer :-) \n";
	} 
	cout << endl;
	SetScreenColor(Quizz.QuestionList[i].isCorrect);
}
string GetFinalResultsText(bool IsPass) {
	if (IsPass == true)
		return " Pass ";
	else
		return "False";
}
string GetQuestionLevelText(enQuestionType Question) {
	string arr[4] = { " Easy "," Med"," Hard " };
	return arr[Question - 1];
}
void PrintTheResultQuizz(stQuizz& Quizz) {
	cout << "\n";    
	cout << "______________________________\n\n"; 
	cout << " Final Resutls is " << GetFinalResultsText(Quizz.IsPass);
	cout << "\n______________________________\n\n";
	cout << "Number of Questions: " << Quizz.NumberOfQuestion << endl; 
	cout << "Questions Level    : " << GetQuestionLevelText(Quizz.QuesionLevel) << endl;  
	cout << "OpType             : " << GetOperaterType(Quizz.OperaterType) << endl;
	cout << "Number of Right Answers: " << Quizz.NumberOfCorrectAnswer << endl; 
	cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswer << endl;
	cout << "______________________________\n";
}


void AskAndCorrectAnswer(stQuizz &Quizz) {
	for (int i = 0; i < Quizz.NumberOfQuestion; i++) {
		PrintTheQuestion(i,Quizz);
		Quizz.QuestionList[i].PlayerAnswer = ReadTheAnswer();
		PrintTheResultQustion(i,Quizz);

	}
	Quizz.IsPass = (Quizz.NumberOfCorrectAnswer > Quizz.NumberOfWrongAnswer);

}
void PlayMathGmae() {
	stQuizz Quizz;
	Quizz.NumberOfQuestion = ReadNumberOfQuestion();
	Quizz.QuesionLevel = ReadQuestionLevel();
	Quizz.OperaterType = ReadOperaterType();

	GenerateQuizzQuestion(Quizz);
	AskAndCorrectAnswer(Quizz);
	PrintTheResultQuizz(Quizz);

}

void ResetScreen() {
	system("cls");
	system("color 0F");
}
void StartGame() {
	char PlayAgain = 'y';
	do {

		ResetScreen();
		PlayMathGmae();
		cout << "Do you want to play again? Y/N\n";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main() {

	srand((unsigned)time(NULL));
	StartGame();

	return 0;

}