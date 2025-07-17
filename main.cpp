#include <iostream>
#include <string>
#include "DynamicArray.h"

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

    return 0;
}