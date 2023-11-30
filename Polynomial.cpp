#include <bits/stdc++.h>

using namespace std;

struct terms{
    int c;
    int e;
};

struct poly{
    int n;
    terms *t;
};

void create(poly *p){
    cout << "enter n:\n";
    cin >> p->n;
    p->t = new terms[p->n];
    cout << "enter coeff and their expo: \n";
    for(int i = 0; i < p->n; i++){
        cin >> p->t[i].c >> p->t[i].e;
    }
}

void display(poly p){
    for(int i = 0;i < p.n;i++){
        cout << p.t[i].c << 'x' << p.t[i].e;
        if(i!=p.n-1){
            cout << " + ";
        }
    }
}

poly *Sum(poly p1,poly p2){
    poly *sum;
    sum = new poly;
    sum->t = new terms[p1.n+p2.n];
    int i,j,k;
    i=j=k=0;
    while(i < p1.n and j < p2.n){
        if(p1.t[i].e > p2.t[j].e){
            sum->t[k++] = p1.t[i++];
        }
        else if(p1.t[i].e < p2.t[j].e){
            sum->t[k++] = p2.t[j++];
        }
        else{
            sum->t[k].e = p1.t[i].e;
            sum->t[k++].c = p1.t[i++].c+p2.t[j++].c; 
        }
    }
    for(;i < p1.n; i++) sum->t[k++] = p1.t[i++];
    for(;j < p2.n; j++) sum->t[k++] = p2.t[j++];
    sum->n = k;
    return sum;
}

int main(){

    poly p1,p2,*p3;
    create(&p1);
    create(&p2);
    p3 = Sum(p1,p2);
    display(*p3);

    return 0;
}