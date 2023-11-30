#include<bits/stdc++.h>

using namespace std;

#define size 10
#define prime 7

int Hash(int key){
    return key%size;
}

int PrimeHash(int key){
    return prime - (key%prime);
}

int DoubleHash(int H[], int key){
    int i = 0;
    int index = Hash(key);
    while(H[(index + i*PrimeHash(key))%size] != 0){
        i++;
    }
    return (index + i*PrimeHash(key))%size;
}

void Insert(int H[], int key){
    int index = Hash(key);
    if(H[index] != 0){
        index = DoubleHash(H,key);
    }
    H[index] = key;
}

int search(int H[], int key){
    int index = Hash(key);
    int i = 0;

    while(H[(index + i*PrimeHash(key))%size] != key){
        i++;
        if(H[(index + i*PrimeHash(key))%size] == 0){
            return -1;
        }
    }
    return (index + i*PrimeHash(key))%size;
}

int main(){

    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A)/sizeof(A[0]);
    
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }

    

    int index = search(HT, 25);
    cout << "key found at: " << index << endl;
 
    index = search(HT, 35);
    cout << "key found at: " << index << endl;

    return 0;
}