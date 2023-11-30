#include<bits/stdc++.h>
using namespace std;

#define size 10

int Hash(int key){
    return key%size;
}

int probe(int H[],int key){
    int i = 0;
    int index = Hash(key);
    while(H[(i+index)%size] != 0){
        i++;
    }

    return (i+index)%size;
}

void Insert(int H[], int key){
    int index = Hash(key);
    if(H[index] != 0){
        index = probe(H,key);
    }
    H[index] = key;
}

int Search(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while(H[(index+i)%size] != key){
        i++;
        if(H[(index+i)%size] == 0){
            return -1;
        }
    }
    return (index+i)%size;
}

int main(){
    int HT[10] = {0};

    Insert(HT,10);
    Insert(HT,20);
    Insert(HT,13);

    cout << Search(HT,30);

    return 0;
}