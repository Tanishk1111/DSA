#include <bits/stdc++.h>

using namespace std;


class element{
    public:
    int i;
    int j;
    int x;
};

class Sparse{
    private:
        int n;
        int m;
        int num;
        element *ele;

    public:
        Sparse(int n,int m,int num){
            this->n = n;
            this->m = m;
            this->num = num;
            ele = new element[this->num];
        }

        ~Sparse(){
            delete []ele;
        }
        Sparse operator+(Sparse &s);
        friend istream & operator>>(istream &is, Sparse &s);
        friend ostream & operator<<(ostream &os, Sparse &s);
};        

istream & operator>>(istream &is, Sparse &s){
    cout << "**************enter the numbers*****************\n";
    for(int o = 0;o < s.num; o++){
        cin >> s.ele[o].i >> s.ele[o].j >> s.ele[o].x;
    }
    return is;
}

ostream & operator<<(ostream &os, Sparse &s){
    int k = 0;
    for(int i = 0; i < s.n; i++){
        for(int j = 0; j < s.m; j++){
            if(s.ele[k].i == i and s.ele[k].j == j){
                cout << s.ele[k++].x << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << '\n';
    }
    return os; 
}
Sparse Sparse::operator+(Sparse &s){
    Sparse *s3;
    s3 = new Sparse(m,n,num+s.num);
    if((n == s.n) and (m == s.m)){
        int i=0,j=0,k=0;
        while(i < num and j < s.num){
            if(ele[i].i < s.ele[j].i){
                s3->ele[k++] = ele[i++];
            }
            else if(ele[i].i > s.ele[j].i){
                s3->ele[k++] = s.ele[j++];
            }
            else{
                if(ele[i].j == s.ele[j].j){
                    s3->ele[k].i = ele[i].i;
                    s3->ele[k].j = ele[i].j;
                    s3->ele[k++].x = ele[i++].x+s.ele[j++].x;
                    
                }
                else if(ele[i].j < s.ele[j].j){
                    s3->ele[k++] = ele[i++];
                }
                else{
                    s3->ele[k++] = s.ele[j++];
                }
            }
        }
        for(;i < num;i++) s3->ele[k++] = ele[i];
        for(;j < s.num;j++) s3->ele[k++] = s.ele[j];
        s3->num = k;
    }

    return *s3;
}



int main(){

    Sparse s1(5,5,5);
    Sparse s2(5,5,5);
    cin >> s1;
    cin >> s2;

    Sparse sum = s1+s2;
    cout << s1 << '\n' << s2 << '\n' << sum;

    return 0;
}