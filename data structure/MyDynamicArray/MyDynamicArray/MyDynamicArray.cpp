//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include"clsDynamicArray.h"

using namespace std;

int main()
{
    clsDynamicArray<int>MyDynamicArray(10);
    
    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);
    MyDynamicArray.SetItem(5, 60);
    MyDynamicArray.SetItem(6, 70);
    MyDynamicArray.SetItem(7, 80);
    MyDynamicArray.SetItem(8, 90);
    MyDynamicArray.SetItem(9, 100);


    cout << "\nArray Item : ";
    MyDynamicArray.PrintList();
    cout << "\n\n Is Empty : " << MyDynamicArray.IsEmpty();
    cout << "\n Array Size : " << MyDynamicArray.Size();
   
    MyDynamicArray.InsertAt(2, 500);
    cout << "\n Array Size : " << MyDynamicArray.Size() << endl;
    cout << "\n Array item after add 500 : ";
    MyDynamicArray.PrintList(); 

    MyDynamicArray.InsertAtBeginning(400);
    cout << "\n Array Size : " << MyDynamicArray.Size() << endl;
    cout << "\n Array item after Insert at beginning  400 : ";
    MyDynamicArray.PrintList();

    MyDynamicArray.InsertAfter(2,300);
    cout << "\n Array Size : " << MyDynamicArray.Size() << endl;
    cout << "\n Array item after Insert after  2 : ";
    MyDynamicArray.PrintList();

    /*MyDynamicArray.InsertBefore(2, 100);
    cout << "\n Array Size : " << MyDynamicArray.Size() << endl;
    cout << "\n Array item after Insert before  9 : ";
    MyDynamicArray.PrintList();*/

    MyDynamicArray.InsertAtEnd(200);
    cout << "\n Array Size : " << MyDynamicArray.Size() << endl;
    cout << "\n Array item after Insert at End  555 : ";
    MyDynamicArray.PrintList();

    /*MyDynamicArray.DeleteItemAt(1);
    cout << "\n Array Size : " << MyDynamicArray.Size()<<endl;
    cout << "\n Array item after delete 2 : ";
    MyDynamicArray.PrintList();*/

   /* MyDynamicArray.DeleteFirstItem();
    cout << "\n Array Size : " << MyDynamicArray.Size() << endl;
    cout << "\n Array item after delete First Item : ";
    MyDynamicArray.PrintList();*/

    /*MyDynamicArray.DeleteLastItem();
    cout << "\n Array Size : " << MyDynamicArray.Size() << endl;
    cout << "\n Array item after delete Last Item : ";
    MyDynamicArray.PrintList();*/

   /* int Index = MyDynamicArray.Find(31);
    if (Index == -1) {
        cout << "\n Item was not found:)";
    }
    else {
        cout << "\n Item 30 was found:)";
    }

    MyDynamicArray.DeleteItem(30);
    cout << "\n Array Size : " << MyDynamicArray.Size() << endl;
    cout << "\n Array item after delete  Item 30 : ";
    MyDynamicArray.PrintList();*/



    system("pause>0");
    return 0;
}