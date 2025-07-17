#include <iostream>
#include <string>
#include <list>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "HashTable.h"

int main(){
    DynamicArray<std::string> arr1;

    arr1.PushBack("asd");
    arr1.PushBack("dsa");
    arr1.PushBack("qwe");
    arr1.PushBack("qwe");
    arr1.PushBack("qwe");

    arr1.PopBack();
    arr1.PopBack();
    arr1.PopBack();
    arr1.PopBack();

    arr1.printArray();

    DynamicArray<int> arr2;

    arr2.PushBack(11);
    arr2.PushBack(3);
    arr2.PushBack(44);

    arr2.PopBack();

    arr2.printArray();


    LinkedList<std::string> l1;

    l1.AppendNode("asd");
    l1.AppendNode("dsa");

    l1.PrintList();


    LinkedList<int> l2;

    l2.AppendNode(1111);
    l2.AppendNode(2111);

    l2.PrintList();

    HashMap<int,int> m;

    m.InsertItem(5,5);
    m.InsertItem(55,55);
    m.InsertItem(6,6);
    m.InsertItem(7,7);

    m.printTable();

    return 0;
}