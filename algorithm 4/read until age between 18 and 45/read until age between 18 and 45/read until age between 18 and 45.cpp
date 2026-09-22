#include <iostream>
using namespace std;
int ReadAge(string message) {
    int Age = 0;
    do {
        cout << message << endl;
        cin >> Age;
    } while (!(Age >= 18 && Age <= 45));
    return Age;

}
bool checkAgeValidateOrNot(int Age) {
    return(Age >= 18 && Age <= 45);
}
void printAgeValidateOrNot(bool check) {
    if (check == 1)
        cout << "the age is validate\n";
    else
        cout << "the age not validate\n";

}
int main()
{
    printAgeValidateOrNot(checkAgeValidateOrNot(ReadAge("please enter the age : \n")));
}


