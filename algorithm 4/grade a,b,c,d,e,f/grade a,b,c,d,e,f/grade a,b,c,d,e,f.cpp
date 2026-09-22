// grade a,b,c,d,e,f.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
enum engrade{a=1,b=2,c=3,d=4,e=5,f=6};
int readmark(string message) {
    int mark = 0;
    do {
        cout << message;
        cin >> mark;
    } while (!(mark >= 0 && mark <= 100));
    return mark;
}
engrade checkmark(int mark) {
    if (mark >= 90)
        return engrade::a;
    else if (mark >= 80)
        return engrade::b;
    else if (mark >= 70)
        return engrade::c;
    else if (mark >= 60)
        return engrade::d;
    else if (mark >= 50)
        return engrade::e;
    else
        return engrade::f;

}
void printmark(engrade grade) {
    if (grade == engrade::a)
        cout << "\n a \a";
    else if (grade == engrade::b)
        cout << "\n b \a";
    else if (grade == engrade::c)
        cout << "\n c \a";
    else if (grade == engrade::d)
        cout << "\n d \a";
    else if (grade == engrade::e)
        cout << "\n e \a";
    else  
        cout << "\n f \a";
 }
int main()
{
    printmark(checkmark(readmark("please enter the mark validate 0 and 100: \n")));
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
