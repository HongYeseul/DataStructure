#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
//arr.emplace_back(i)
//모던 C ++


int main(int argc, char* argv[]){
    vector<int> arr; // int 형 담는 동적 배열
    arr.push_back(10);

    for(int i=0 ; i<10 ; i ++){
        arr.push_back(i);
    }
    for(int i=0 ; i< arr.size() ; i ++){
        printf("%d ", arr[i]);
    }
    cout << endl;
    printf("\n");

    return 0;
}
