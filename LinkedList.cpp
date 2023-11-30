#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *first = NULL;
Node *second = NULL;

void create(int a[],int n){
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    Node *t,*last;
    last = first;
    for(int i = 1;i < n;i++){
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(){
    Node *p = first;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

void Rdisplay(Node *p){
    if(p){
        cout << p->data << " ";
        Rdisplay(p->next);
    }
}

int counting(Node *p){
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

int Sum(Node *p){
    int sum = 0;
    while(p){
        sum += p->data;
        p=p->next;
    }
    return sum;
}

int Rsum(Node *p){
    if(p){
        return Rsum(p->next)+p->data;
    }
    else{
        return 0;
    }
}

int Maxi(Node *p){
    int maxi = INT_MIN;
    while(p){
        if(maxi < p->data){
            maxi = p->data;
        }
        p=p->next;
    }
    return maxi;
}

Node *Lsearch(Node *p,int key){
    Node *q = NULL;

    while(p){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

Node *Rsearch(Node *p,int key){
    if(!p){
        return NULL;
    }
    else{
        if(p->data == key){
            return p;
        }
        return Rsearch(p->next,key);
    }
}

void Insert(int x,int id){
    Node *t;
    t = new Node;
    t->data = x;
    if(id == 0){
        t->next = first;
        first = t;
    }
    else{
        Node *p = first;
        for(int i = 0; (i < id-1)and(p) ;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SInsert(Node *p,int k){
    Node *t = new Node;
    t->data = k;
    if(first == NULL){
        first = t;
    }
    else{
        if(p->data > k){
            t->next = p;
            first = t;
        }
        else{
            Node *q = NULL;
            while(p and p->data < k){
                q = p;
                p = p->next;
            }
            t->next = q->next;
            q->next = t;
        }
    }
}

int DDelete(int pos){
    Node *p,*t;
    int x = 0;
    if(pos == 1){
        p = first;
        x = first->data;
        first = first->next;
        delete p;
    }
    else{
        p = first;
        t = NULL;
        for(int i = 1; (i < pos) and (p);i++){
            t = p;
            p = p->next;
        }
        if(p){
            x = p->data;
            t->next = p->next;
            delete p;
        }
        else{
            cout << "bruh learn counting\n";
            x = -1;
        }
    }
    return x;
    
}

void RemoveDuplicate(Node *p){
    Node *q = p->next;
    while(q){
        if(q->data==p->data){
            p->next=q->next;
            delete q;
            q = p->next;
        }
        else{
            p = q;
            q = p->next;
        }
    }
}

void Reverse(Node *p){
    p = first;
    Node *q=NULL,*r=NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Rreverse(Node *q,Node *p){
    if(p){
        Rreverse(p,p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

Node *merge(){
    Node *p = NULL,*q = NULL;
    if(first->data <= second->data){
        p = q = first;
        first = first->next;
        p->next = NULL;
    }
    else{
        p = q = second;
        second = second->next;
        p->next = NULL;
    }
    while(first and second){
        if(first->data <= second->data){
            p->next = first;
            p = first;
            first = first->next;
            p->next = NULL;
        }
        else{
            p->next = second;
            p = second;
            second = second->next;
            p->next = NULL;
        }
    }
    if(first){
        p->next = first;
        first = NULL;
    }
    if(second){
        p->next = second;
        second = NULL;
    }
    return q;
}

int ifcon(Node *p){
    Node *a,*b;
    a=b=p;
    do{

        a = a->next;
        b = b->next;
        if(b){
            b = b->next;
        }

    }while(a and b and a!=b);
    if(a == b){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int ar[] = {10,20,30,40,50,60,70};
    create(ar,7);
    
    Node *t1,*t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next->next->next;
    t2->next = t1;

    printf("%d\n",ifcon(first));

    return 0;
}