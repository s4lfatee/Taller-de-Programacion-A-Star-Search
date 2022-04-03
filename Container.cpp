#include "Container.h"

Container::Container(int size){
    Container::size = size;
    arr = new int*[size];
    for(int i = 0; i < size; i++){
        arr[i] = new int[size];
        for(int j = 0; j < size; j++){
            arr[i][j] = 0;
        }
    }
}

Container::~Container(){
    for(int i = 0; i < size; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

void Container::print(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool Container::isVisited(int i, int j){
    if (arr[i][j] == 1){
        return true;
    }
    return false;
}

void Container::setVisited(int i, int j){
    arr[i][j] = 1;
}