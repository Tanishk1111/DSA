#include<bits/stdc++.h>

using namespace std;

void Insert(vector<int> &v,int key){
    // O(logn)
    auto i = v.size();
    v.emplace_back(key);
    while(i > 0 and key > v[i%2 == 0 ? (i/2)-1:i/2]){
        v[i] = v[i%2 == 0 ? (i/2)-1:i/2];
        i = i%2 == 0 ? (i/2)-1:i/2;
    }
    v[i] = key;
}

void createHeap(vector<int> &v,int A[],int n){
    // O(nlogn)
    for(int i = 0;i < n;i++){
        Insert(v,A[i]);
    }
}

void Print(vector<int> &v,int n, char c){
    cout << c << " : [";
    for(int i = 0;i < n; i++){
        cout << v[i];
        if(i < n-1){
            cout << ", ";
        }
    }
    cout << "]";
}

int Delete(int v[], int n){
    // O(logn)
    int temp = v[n];
    v[n] = v[1];
    v[1] = temp;

    int i = 1, j = 2*i;
    
    while(j < n-1){
        if(v[j+1] > v[j]){
            j++;
        }
        if(v[i] < v[j]){
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
            i = j;
            j = 2*j;
        }
        else{
            break;
        }
    }
    return v[n];
}

void Heapify(int A[],int n){
    // O(n);
    for(int i = n/2; i >= 1; i--){
        int j = 2*i;
        while(j < n){
            if(A[j] < A[j+1]){
                j++;
            }
            if(A[i] < A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i = j;
                j = 2*j;
            }
            else{
                break;
            }
        }
    }

}

int main(){
    vector<int> v;
    int ar[] = {0,5,10,30,20,35,40,15};
    
    Heapify(ar,8);
    
    for(int i = 1; i < 8; i++){
        cout << ar[i] << " ";
    }
    return 0;
}