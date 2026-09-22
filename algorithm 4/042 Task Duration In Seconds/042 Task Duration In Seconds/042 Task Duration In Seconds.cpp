// 042 Task Duration In Seconds.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
struct strtaskduration {
    int days;
    int hours;
    int minutes;
    int second;
};
strtaskduration readtaskduration() {
    strtaskduration taskduration;
    cout << "please enter the task duration in days : \n";
    cin >> taskduration.days;
    cout << "please enter the task duration in hours : \n";
    cin >> taskduration.hours;
    cout << "please enter the task duration in minutes : \n";
    cin >> taskduration.minutes;
    cout << "please enter the task duration in seconds : \n";
    cin >> taskduration.second;
    return taskduration;
}

float  calculatetaskduration(strtaskduration taskduration) {
    float taskdurationinsecond = (taskduration.days * 24 * 60 * 60) + (taskduration.hours * 60 * 60)
        + (taskduration.minutes * 60) + (taskduration.second * 1);
    return taskdurationinsecond;
}
void prinvaluetaskduration(float calculae) {
    cout << "task duraion in second = " << calculae << endl;
}
int main()
{
      prinvaluetaskduration(calculatetaskduration( readtaskduration()));

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
