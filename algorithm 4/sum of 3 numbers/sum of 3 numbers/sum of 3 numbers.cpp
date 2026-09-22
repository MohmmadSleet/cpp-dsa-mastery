// sum of 3 numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct stnumbers {
    int number1;
    int number2;
    int number3;
};
stnumbers read3numbers() {
    stnumbers numbers;
    cout << "plesae enter the number 1 : \n";
    cin >> numbers.number1;
    cout << "plesae enter the number 2 : \n";
    cin >> numbers.number2;
    cout << "plesae enter the number 3 : \n";
    cin >> numbers.number3;
    return numbers;
}
int calculatesum(stnumbers numbers) {
    return numbers.number1 + numbers.number2 + numbers.number3;
}
void printsumof3numbers(int calculate) {
    cout << "\aThe sum of three numbers = " << calculate << endl;

}
int main()
{
    printsumof3numbers(calculatesum(read3numbers()));
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
