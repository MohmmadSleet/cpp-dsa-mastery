// revision project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;

/*void printtableheader() {
    cout << "\n\n\n\n\t\t\t\t  multiplication table from 1 to 10 \n\n";
    for (int i = 1; i <= 10; i++) {
        cout << "\t " << i;
    }
    cout << "\n_________________________________________________________________________________________\n";
}
string columoperater(int i) {
    if (i < 10)
        return "  |";
    else
        return " |";
}

    void printnultiplicationtablefrom1to10() {
    printtableheader();

    for (int i = 1; i <= 10; i++) {
        cout << i << columoperater(i);
        for (int j = 1; j <= 10; j++) {
            cout << "\t" << i * j<<columoperater(i);
        }
        cout << endl;
    }

    
}*/
/*enum enprimeornot { prime = 1, notprime = 2 };
int Readposintivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);
    return number;

}
enprimeornot checknumber(int i) {
    for (int counter = 2; counter < i; counter++) {
        if (i % counter == 0)
            return enprimeornot::notprime;
    }
    return prime;
}

void printallprimenumberfrom1ton(int number) {
    for (int i = 1; i <= number; i++) {
        if (checknumber(i) == enprimeornot::prime)
            cout << i << endl;
    
    }
}

*/
/*
int Readposintivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);
    return number;

}
enum enperfectorot{perfect=1,notperfect=2};
enperfectorot checknumber(int number) {
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0)
            sum += i;
    }
    if (sum == number)
        return enperfectorot::perfect;
    else
        return enperfectorot::notperfect;
}
void printperfrectnum(int number) {
    for (int counter = 1; counter <= number; counter++) {
        if (checknumber(counter) == enperfectorot::perfect)
            cout << counter << "  the number is perfect \n";
    }
}*/
/*int Readposintivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);
    return number;

}
void printdigitinareveredorde(int number) {
    int remainder = 0;
    while (number != 0) {
        remainder = number % 10;
        number = number / 10;
        cout << remainder << endl;
    }

}

*/

/*int Readposintivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);
    return number;

}
void sumdigitsrevered(int number) {
    int remainder = 0,sum=0;
    while (number != 0) {
        remainder = number % 10;
        number = number / 10;
        sum += remainder;
    }
    cout << "sum of digits = " << sum << endl;
}
*/
/*int Readposintivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);
    return number;

}
void printsamenumber(int number) {
    int remainder = 0, number2 = 0;
    while (number != 0) {
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
        cout << remainder;
    }
    
}*/
/*
int Readposintivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);
    return number;
}
    int checkfrequencynum(int number, int numfreq) {
        int remainder = 0,freq=0;
        while (number != 0) {
            remainder = number % 10;
            number = number / 10;
            if (numfreq == remainder)
                freq++;
        }
        return freq;
    }
    */
/*int Readposintivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);
    return number;
}
int checkfrequencynum(int number, int i) {
    int remainder = 0, freq = 0;
    while (number != 0) {
        remainder = number % 10;
        number = number / 10;
        if (i == remainder)
            freq++;
    }
    return freq;
}
void printalldigitnumber(int number) {
    for (int i = 0; i <= 9; i++) {
        short digitfreq = checkfrequencynum(number, i);
        if(digitfreq>0)
        cout << " Digit " << i << " frequency is " << digitfreq<<endl;
    }

}*/

int ReadPositiveNumber(string message) {
    int numbers = 0;
    do{
        cout << message << endl;
        cin >> numbers;

    }while (numbers < 0);
    return numbers;
}
int printreversenumber(int numbers)
{
    int remainder = 0, nmber2 = 0;
    while (numbers != 0) {
        remainder = numbers % 10;
        numbers = numbers / 10;
        nmber2 = nmber2 * 10 + remainder;
    }
    return nmber2;
}
void printnumber(int numbers)
{
    int remainder = 0,nmber2=0;
    while (numbers != 0) {
        remainder = numbers % 10;
        numbers = numbers / 10;
        cout << remainder << endl;
    }
   
}

int main()
{
    printnumber(printreversenumber(ReadPositiveNumber("please enter the positive number ?")));


    /*
    
    long long number = Readposintivenumber("please enter the number ?");
        printalldigitnumber(number);*/



    /*long long number = Readposintivenumber("please enter the number ?");
    int numfreq = Readposintivenumber("please enter the digit to check how to frequency"); 
    cout << " Digit " << numfreq << " frequency is " << checkfrequencynum(number, numfreq);*/
    //printsamenumber(Readposintivenumber("please enter the number ?"));
    //sumdigitsrevered(Readposintivenumber("please enter the number ?"));
    //printdigitinareveredorde(Readposintivenumber("please enter the number ?"));
    //printperfrectnum(Readposintivenumber("please enter the number ?"));
    //printallprimenumberfrom1ton(Readposintivenumber("please enter the number ?"));
   // printnultiplicationtablefrom1to10();
}



