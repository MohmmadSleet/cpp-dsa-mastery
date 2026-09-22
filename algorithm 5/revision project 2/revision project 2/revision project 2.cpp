// revision project 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
enum enQuestionLevel  { Easy = 1,Med = 2,Hard = 3,Mix = 4 };
enum enOperaterType{Add=1,Sub=2,Mult=3,Div=4,MixOp=5};
struct stQuestion {
    int Number1 = 0;
    int Number2 = 0;
    enQuestionLevel QuestionLevel;
    enOperaterType OperaterType;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool isCorrect = false;
};
struct stQuiz {
    stQuestion QuestionList[100];
    short NumberOfQuestion = 0;
    enQuestionLevel QuestionLevel;
    enOperaterType OperaterType;
    int NumberOfCorrectAnswer = 0;
    int NumberOFWrongAnswer = 0;
    bool ispass = false;
};
short ReadHowManyQuestion() {
    short QuestionNumber = 0;
    do { 
        cout << "How Many Question From 1 To 10 ? " << endl;
        cin >> QuestionNumber;
    } while (QuestionNumber > 10 || QuestionNumber < 1);
    return QuestionNumber;
}
enQuestionLevel ReadQuestionLevel() {
    short Questionlevel = 0;
    do {
        cout << "what Question level you need:[1] Easy, [2] Med, [3] Hard, [4] Mix ?" << endl;
        cin >> Questionlevel;
    } while (Questionlevel > 4 || Questionlevel < 1);
    return (enQuestionLevel)Questionlevel;
}
enOperaterType ReadOperaterType() {
    short operaterType = 0;
    do {
        cout << "chooser operater type : [1] add, [2] sub, [3] mult, [4] div, [5] mix ?\n";
        cin >> operaterType;
    } while (operaterType > 5 || operaterType < 1);
    return (enOperaterType)operaterType;
}
int RandomNumber(int from, int to) {
    int RandNum = rand() % (to - from + 1) + from;
    return RandNum;
}
int SimpleCalculater(int number1, int number2, enOperaterType op) {
    switch (op) {
    case enOperaterType::Add:
        return number1 + number2;
        break;
    case enOperaterType::Sub:
        return number1 - number2;
        break;
    case enOperaterType::Mult:
        return number1 * number2;
        break;
    case enOperaterType::Div:
        return number1 / number2;
        break;
    default:
        return number2;
        break;
    }
}
stQuestion storageQuestionInTheQuiz(enQuestionLevel QuestionLevel,enOperaterType OP) {
    stQuestion Question;
    if (QuestionLevel == enQuestionLevel::Mix) {
        QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
    }
    if (OP == enOperaterType::MixOp) {
        OP = (enOperaterType)RandomNumber(1, 4);
    }
    Question.OperaterType = OP;
    switch (QuestionLevel) {
    case enQuestionLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, Question.OperaterType);
        Question.QuestionLevel = QuestionLevel;
        return Question;
    case enQuestionLevel::Med:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, Question.OperaterType);
        Question.QuestionLevel = QuestionLevel;

        return Question;
    case enQuestionLevel::Hard:
        Question.Number1 = RandomNumber(50, 500);
        Question.Number2 = RandomNumber(50, 500);
        Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, Question.OperaterType);
        Question.QuestionLevel = QuestionLevel;

        return Question;
    }
    
}
void GeneratQuizQuestion(stQuiz& Quiz) {
    for (short i = 0; i < Quiz.NumberOfQuestion; i++) {
        Quiz.QuestionList[i] = storageQuestionInTheQuiz(Quiz.QuestionLevel,Quiz.OperaterType);
    }
}
string GetOpTypeSymbol(enOperaterType op) {
    string arrOp[5] = { "+","-","*","/","mix"};
    return arrOp[op - 1];
}
void PrintTheQuestion(int i,stQuiz Quiz) {
    cout << "\n";
    cout << "Question [" << i + 1 << "/" << Quiz.NumberOfQuestion << "] \n\n";
    cout << Quiz.QuestionList[i].Number1 << endl; 
    cout << Quiz.QuestionList[i].Number2 << " ";
    cout << GetOpTypeSymbol(Quiz.QuestionList[i].OperaterType);
    cout << "\n_________" << endl;


}
int ReadPlayerAnswer() {
    int Answer = 0;
    cin >> Answer;
    return Answer;
}
void SetScreenColor(bool iscorrect) {
    if (iscorrect == true)
        system("color 2F");
    else {
        cout << "\a";
        system("color 4F");
    }
}
void CheckTheResultQuestionAndCorrect(int i,stQuiz& Quiz) {
    if (Quiz.QuestionList[i].CorrectAnswer != Quiz.QuestionList[i].PlayerAnswer) {
        Quiz.QuestionList[i].isCorrect = false;
        Quiz.NumberOFWrongAnswer++;
        cout << "Worng Answer :-( \n";
        cout << "The right answer is: "; 
        cout << Quiz.QuestionList[i].CorrectAnswer;   
        cout << "\n";
    }
    else {
        Quiz.QuestionList[i].isCorrect = true;
        Quiz.NumberOfCorrectAnswer++;
        cout << "Right answer :-( \n";
        cout << "\n";

    }
    Quiz.ispass = (Quiz.NumberOfCorrectAnswer > Quiz.NumberOFWrongAnswer);
    SetScreenColor(Quiz.QuestionList[i].isCorrect);
}
void AskAndAnswerCorrectQuestion(stQuiz& Quiz) {
    for (int i = 0; i < Quiz.NumberOfQuestion; i++) {
        PrintTheQuestion(i,Quiz);
        Quiz.QuestionList[i].PlayerAnswer = ReadPlayerAnswer();
        CheckTheResultQuestionAndCorrect(i,Quiz);
    }
}
string GetFinalResultsText(bool ispass) {
    if (ispass == true)
        return " Pass";
    else
        return" Fail ";
}
string GetQuestionLevelText(enQuestionLevel QustionLevel) {
    string arrQuestionLevel[4] = { "easy","med","hard","mix"};
    return arrQuestionLevel[QustionLevel-1];
}
void SetScreenColorResult(stQuiz Quiz) {
    if (Quiz.ispass == true)
        system("color 2F");
    else
        system("color 4F");
}
void printTheResultInTheScreen(stQuiz Quiz) {
    cout << "\n";      cout << "______________________________\n\n";
    cout << " Final Resutls is " << GetFinalResultsText(Quiz.ispass);
    cout << "\n______________________________\n\n";
    cout << "Number of Questions: " << Quiz.NumberOfQuestion << endl;
    cout << "Questions Level    : " << GetQuestionLevelText(Quiz.QuestionLevel) << endl;
    cout << "OpType             : " << GetOpTypeSymbol(Quiz.OperaterType) << endl;  
    cout << "Number of Right Answers: " << Quiz.NumberOfCorrectAnswer << endl; 
    cout << "Number of Wrong Answers: " << Quiz.NumberOFWrongAnswer << endl;
    SetScreenColorResult(Quiz);
}
void PlayMathGame() {
    stQuiz Quiz;
    Quiz.NumberOfQuestion = ReadHowManyQuestion();
    Quiz.QuestionLevel = ReadQuestionLevel();
    Quiz.OperaterType = ReadOperaterType();

    GeneratQuizQuestion(Quiz);
    AskAndAnswerCorrectQuestion(Quiz);
    printTheResultInTheScreen(Quiz);
}
void ResetScreen() {
    system("cls");
    system("color 0F");
}
void StartGame() {
    char PlayAgain = 'y';
    do {

        ResetScreen();
        PlayMathGame();
        cout << endl << "Do you want to play again ?\n";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));

    StartGame();
}

