// My Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"clsMyQueue.h"
using namespace std;

int main()
{
	clsMyQueue<int>MyQueue;
	MyQueue.Push(10);
	MyQueue.Push(20);
	MyQueue.Push(30);
	MyQueue.Push(40);
	MyQueue.Push(50);


	cout << "\n Queue : ";
	MyQueue.Print();

	cout << "\n Queue Size : " << MyQueue.Size();
	cout << "\n Queue Front : " << MyQueue.Front();
	cout << "\n Queue Back : " << MyQueue.Back();

	cout << "\n Is Empty : " << MyQueue.IsEmpty();

	cout << "\n Item(0) : " << MyQueue.GetItem(0) << endl;
	
	MyQueue.Reverse();
	cout << "Queue after reverse : ";
    MyQueue.Print();

	MyQueue.UpdateItem(2, 35);
	cout << "Queue after update item 2 = ";
	MyQueue.Print();

	MyQueue.InsertAfter(2, 500);
	cout << "Queue after Insert item 2 = ";
	MyQueue.Print();


	MyQueue.InsertAtFront(500);
	cout << "Queue after Insert Front 500 = ";
	MyQueue.Print();

	MyQueue.InsertAtBack(1000);
	cout << "Queue after Insert Back 1000 = ";
	MyQueue.Print();


	MyQueue.Clear();
	cout << "Queue after Clear : ";
	MyQueue.Print();

	system("pause>0");
	return 0;
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
