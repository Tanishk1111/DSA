#include <bits/stdc++.h>

using namespace std;

void dupli(char A[]){
    long long H = 0, x = 0;

    for(int i = 0; A[i] != '\0'; i++){
        x = 1;
        x = x << (A[i]-97);
        if((x&H) > 0){
            cout << A[i] << " is duplicate\n";
        }
        else{
            H = H|x;
        }
    }
}

void perm(char s[],int k){
    static int A[10] = {0};
    static char R[10];
    if(s[k] == '\0'){
        R[k] = '\0';
        cout << R << '\n';
    }
    for(int i = 0; s[i] != '\0'; i++){
        if(A[i] == 0){
            R[k] = s[i];
            A[i] = 1;
            perm(s,k+1);
            A[i] = 0;
        }
    }
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void perm2(char a[],int l,int h){

    if(l == h){
        cout << a << '\n';
    }
    for(int i = l; i <= h; i++){
        swap(a[l],a[i]);
        perm2(a,l+1,h);
        swap(a[l],a[i]);
    }
}

int main(){

    char a[] = "abcde";
    perm2(a,0,4);

    return 0;
}