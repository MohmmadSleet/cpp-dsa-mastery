#include <iostream>
#include<cstdlib>
using namespace std;
int RandomNumber(int from, int to) {
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}

void fillarraywithrandomnumber(int arr[100], int& arrlength) {
    cout << "\n Enter array element \n";
    cin >> arrlength;
    for (int i = 0; i < arrlength; i++) {
        arr[i] = RandomNumber(-100, 100);
    }
}

void printarrayynumber(int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        cout << arr[i] << "  ";
    }
}
int countnegativenumberinarray(int arr[100], int arrlength) {
    int count = 0;
    for (int i = 0; i < arrlength; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}
int main()
{

    srand((unsigned)time(NULL));
    int arr[100], arrlength;
    fillarraywithrandomnumber(arr, arrlength);
    cout << "\nArray 1 Element : \n";
    printarrayynumber(arr, arrlength);

    cout << "\nnegative number count is = ";
    cout << countnegativenumberinarray(arr, arrlength);
}

