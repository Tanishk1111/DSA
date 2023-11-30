#include <bits/stdc++.h>

using namespace std;

class LowerTri{
    private:
        int n;
        int *A;
    public:
        LowerTri(){
            n = 2;
            A = new int[3];
        }
        LowerTri(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }
        void Set(int i,int j, int k);
        int Get(int i,int j);
        void Display();
        ~LowerTri(){
            delete []A;
        }
};

void LowerTri::Set(int i,int j, int k){
    if(i>=j){
        A[i*(i-1)/2 + j-1] = k;
    }
}

int LowerTri::Get(int i,int j){
    if(i >= j){
        return A[i*(i-1)/2 + j-1];
    }
    else{
        return 0;
    }
}

void LowerTri::Display(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n; j++){
            if(i>=j){
                cout << A[i*(i-1)/2 + j-1] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << '\n';
    }
}


int main(){

    LowerTri mat(5);
    mat.Set(0,0,1);
    mat.Set(1,1,2);
    mat.Set(2,2,3);
    mat.Set(3,3,4);
    mat.Set(4,4,5);

    mat.Display();


    return 0;
}