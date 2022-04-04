#include "Mark.h"

Mark::Mark(int size){
    Mark::size = size;
    arr = new int*[size];
    for(int i = 0; i < size; i++){
        arr[i] = new int[size];
        for(int j = 0; j < size; j++){
            arr[i][j] = 0;
        }
    }
}

Mark::~Mark(){
    for(int i = 0; i < size; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

void Mark::print(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool Mark::isVisited(int i, int j){
    if (arr[i][j] == 1){
        return true;
    }
    return false;
}

void Mark::setVisited(int i, int j){
    arr[i][j] = 1;
}