// power of 2,3,4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;
int readnumber(string message) {
    int number = 0;
    cout << message << endl;
    cin >> number;
    return number;
}
void calculatepowerof2_3_4(int number) {
    float calculatepower_2 = number * number;
    float calculatepower_3 = number * number * number;
    float calculatepower_4 = number * number * number * number;

    cout << "power of 2 = " << calculatepower_2 << endl;
    cout << "power of 3 = " << calculatepower_3 << endl;
    cout << "power of 4 = " << calculatepower_4 << endl;

 }


int main()
{
   calculatepowerof2_3_4(readnumber("please enter the number : "));
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
