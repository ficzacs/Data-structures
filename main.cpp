#include <iostream>
#include <string>
#include "DynamicArray.h"


template<typename T> void printVector(const DynamicArray<T>& vector){
    for(size_t i = 0; i< vector.Size(); i++){
        std::cout << vector[i] << " ";
    }
}

int main(){
    DynamicArray<std::string> m;


    m.PushBack("asd");
    m.PushBack("dsa");
    m.PushBack("qwe");

    printVector(m);


    return 0;
}