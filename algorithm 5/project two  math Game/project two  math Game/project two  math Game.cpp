// project two  math Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<math.h>
#include<cstdlib>
using namespace std;
enum enQuestionLevel{Easy=1,Med=2,Hard=3,Mix=4};
enum enOperatingType{Add=1,Sub=2,Mult=3,Div=4,MixOp=5};
struct stQuestion {
    int Number1 = 0;
    int Number2 = 0;
    enOperatingType OpertingType;
    enQuestionLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};
struct stQuizz {
    stQuestion QuestionList[100];
    short NumberOfQustion = 0;
    enQuestionLevel QustionLevel;
    enOperatingType OpertingType;
    int NumberOfWrongAnswer=0;
    int NumberOfCorrectAnswer=0;
    bool ispass = false;
};
short ReadHowManyQuestion() {
    short manyQuestion;
    do {
        cout << "How many qustion you need ? from 1 To 10" << endl;
        cin >> manyQuestion;

    } while (manyQuestion > 10 || manyQuestion < 1);
    return manyQuestion;
}
enQuestionLevel ReadQuestionLevel() {
    short Questionlevel=0;
    do {
        cout << "\nplease enter the question level ? [1] easy,[2] med,[3]hard,[4]mix \n";
        cin >> Questionlevel;
    } while (Questionlevel > 4 || Questionlevel < 1);
    return enQuestionLevel(Questionlevel);

}
enOperatingType ReadOp() {
    short OP;
    do {
        cout << "\n please enter the operatin type ? [1] Add, [2] Sub, [3] Mult, [4] Div, [5] Mixop \n";
        cin >> OP;
    } while (OP > 5 || OP < 1);
    return enOperatingType(OP);
}
int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
int SimpleCalculator(int Number1, int Number2, enOperatingType OP) {

    switch (OP) {
    case enOperatingType::Add:
        return (Number1 + Number2);
    case enOperatingType::Sub:
        return (Number1 - Number2);
    case enOperatingType::Mult:
        return (Number1 * Number2);
    case enOperatingType::Div:
        return (Number1 / Number2);
    default:
        return (Number1 / Number2);
    }
}
stQuestion GenerateQuestion(enQuestionLevel QustionLevel, enOperatingType OperatingType) {
    stQuestion Question;
    if (QustionLevel == enQuestionLevel::Mix) {
        QustionLevel = enQuestionLevel(RandomNumber(1, 3));
    }
    if (OperatingType == enOperatingType::MixOp) {
        OperatingType = enOperatingType(RandomNumber(1, 4));
    }
    Question.OpertingType = OperatingType;
    switch (QustionLevel) {
    case enQuestionLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpertingType);
        Question.QuestionLevel = QustionLevel;
        return Question;
        break;

    case enQuestionLevel::Med:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpertingType);
        Question.QuestionLevel = QustionLevel;
        return Question;
        break;
    case enQuestionLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpertingType);
        Question.QuestionLevel = QustionLevel;
        return Question;
        break;
    }
    return Question;
}
void GenerateQuizQuestion(stQuizz& Quizz) {
    for (short Question = 0; Question < Quizz.NumberOfQustion; Question++) {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QustionLevel, Quizz.OpertingType);
    }
}
string  GetOpTypeSymbol(enOperatingType OP) {
    string arrTypeSymbol[5] = { "+","-","*","/","mix"};
    return arrTypeSymbol[OP - 1];
}
void PrintTheQuestion(stQuizz& Quizz, short Question) {
    cout << "\n"; 
    
    cout << "Question [" << Question + 1 << "/" << Quizz.NumberOfQustion << "] \n\n";
    cout << Quizz.QuestionList[Question].Number1 << endl;
    cout << Quizz.QuestionList[Question].Number2 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionList[Question].OpertingType); 
    cout << "\n_________" << endl;
}
int ReadAnswerQuestion() {
    int Answer = 0;
    cin >> Answer;
    return Answer;
}
void SetScreenColorList(bool AnswerResult) {
    if (AnswerResult == true)
        system("color 2F");
    else
        system("color 4F");
}
void CorrectTheQuestionAnswer(stQuizz& Quizz, short Question) {
    if (Quizz.QuestionList[Question].PlayerAnswer != Quizz.QuestionList[Question].CorrectAnswer) {
        Quizz.QuestionList[Question].AnswerResult = false;
        cout << "Wrong Answer :-(\n";
        cout << "The right answer is = ";
        cout<<Quizz.QuestionList[Question].CorrectAnswer;
        cout << "\n";
        Quizz.NumberOfWrongAnswer++;

    }
    else {
        Quizz.QuestionList[Question].AnswerResult = true; 
        cout << "Right answer:-)\n";
        Quizz.NumberOfCorrectAnswer++;
    }
    cout << endl;
    SetScreenColorList(Quizz.QuestionList[Question].AnswerResult);
}

void AskAndCorrectQuestionListAnswer(stQuizz& Quizz) {
    for (short Question = 0; Question < Quizz.NumberOfQustion; Question++) {
        PrintTheQuestion(Quizz, Question);
        Quizz.QuestionList[Question].PlayerAnswer = ReadAnswerQuestion();
        CorrectTheQuestionAnswer(Quizz, Question);
    }
    Quizz.ispass = (Quizz.NumberOfCorrectAnswer >= Quizz.NumberOfWrongAnswer);

}
string GetFinalResultsText(bool isPass) {
    if (isPass == true)
        return "Pass :-(";
    else
        return "Fail :)-";
}
string GetQuestionLevelText(enQuestionLevel QuestionLevel) {
    string arrQuestionLevel[4] = { "easy","med","hard","mix" };
    return arrQuestionLevel[QuestionLevel - 1];
}
void PrintQuizResult(stQuizz Quizz) {
    cout << "\n";
    cout << "______________________________\n\n";
    cout << " Final Resutls is " << GetFinalResultsText(Quizz.ispass);
    cout << "\n______________________________\n\n"; 
    cout << "Number of Questions: " << Quizz.NumberOfQustion << endl; 
    cout << "Questions Level    : " << GetQuestionLevelText(Quizz.QustionLevel) << endl;
    cout << "OpType             : " << GetOpTypeSymbol(Quizz.OpertingType) << endl;
    cout << "number of correct answer = " << Quizz.NumberOfCorrectAnswer << endl;
    cout << "number of wrong answer = " << Quizz.NumberOfWrongAnswer << endl;
}
void PlayMathGame() {
    stQuizz Quizz;
    Quizz.NumberOfQustion = ReadHowManyQuestion();
    Quizz.QustionLevel = ReadQuestionLevel();
    Quizz.OpertingType = ReadOp();

    GenerateQuizQuestion(Quizz);
    AskAndCorrectQuestionListAnswer(Quizz);
    
    PrintQuizResult(Quizz);
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
        cout << endl<< "Do you want to play again ? " << endl;
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));

    StartGame();
    return 0;

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
