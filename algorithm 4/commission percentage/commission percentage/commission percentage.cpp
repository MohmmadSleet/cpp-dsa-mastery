// commission percentage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int ReadTotalSales() {
    int TotalSales = 0;
    cout << "please enter the total sales : \n";
    cin >> TotalSales;
    return TotalSales;
}
float  getcalculatepercentage(int totalsales) {
    if (totalsales >= 1000000)
        return 0.01;
    else if (totalsales >= 500000)
        return 0.02;
    else if (totalsales >= 100000)
        return 0.03;
    else if (totalsales >= 50000)
        return 0.05;
    else
        return 0;
}

float totalcommision(int totalsales) {
    return (getcalculatepercentage(totalsales) * totalsales);
}

int main()
{
    int totalsales = ReadTotalSales();
    
     cout<<endl<<"commision percentage = "<<getcalculatepercentage(totalsales);
     cout << endl << "total commision = "<<totalcommision(totalsales) << endl;
    
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
