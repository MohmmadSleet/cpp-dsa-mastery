// power of m.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
struct strinfotofindpower {
    int numbers;
    int power;
};
strinfotofindpower readinfo(){
    strinfotofindpower info;
    cout << "please enter the number : \n";
    cin >> info.numbers;
    cout << "please enter the power : \n";
    cin >> info.power;
    return info;

}
int calculateresult(strinfotofindpower info) {
    int result=1;
    for (int counter = 1; counter <= info.power; counter++) {
        result = result * info.numbers;
    }
    return result;
 }
void printresult(float result) {
    cout << "power of numbers = \a" << result << endl;

}

int main()
{
    printresult(calculateresult(readinfo()));
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
