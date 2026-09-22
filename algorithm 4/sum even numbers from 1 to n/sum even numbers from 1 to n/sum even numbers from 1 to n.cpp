// sum even numbers from 1 to n.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
enum enoddoreven { odd = 1, even = 2 };

int readnumbers() {
    int numbers = 0;
    cout << "please enter the number : \n";
    cin >> numbers;
    return numbers;
}

int sumnumbersevenornot(int numbers) {
    int sum = 0;
    for (int counter = 1; counter <= numbers; counter++)
    {
        if (counter % 2 == 0)
            sum = sum + counter;

    }
    return sum;
}
void printsumevennumbersfrom1ton(int sum) {
    cout << "sum odd numbers from 1 to n = " << sum;

}

int main()
{
    printsumevennumbersfrom1ton(sumnumbersevenornot(readnumbers()));
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
