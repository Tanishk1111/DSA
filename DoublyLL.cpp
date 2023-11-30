#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next; 
}*first;

void create(int A[],int n){
    Node *t,*last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;
    for(int i = 1;i < n; i++){
        t = new Node;
        t->data = A[i];
        last->next = t;
        t->prev = last;
        last = t;
        t->next = NULL;
    }

}

void display(Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

void Insert(Node *p,int index,int x,int n){
    Node *t = new Node;
    t->data = x;
    if(index == 0){
        t->next = first;
        first->prev = t;
        first = t;
        first->prev = NULL;
    }
    else{
        Node *p = first;
        for(int i = 0;i < index-1;i++){
            p = p->next;
        }

        t->next = p->next;
        t->prev = p;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
}

int length(Node *p){
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }

    return count;
}

int Delete(Node *p,int index){
    Node *q = NULL;
    int x;
    if(index < 1 or index > length(p)){
        return -1;
    }
    if(index == 1){
        q = first;
        first = first ->next;
        if(first){
            first->prev = NULL;
        }
        x = q->data;
        delete q;
    }
    else{
        for(int i = 0;i<index-1;i++){
            p = p->next;
        }
        q = p->prev;
        q->next = p->next;
        if(p->next){
            p->next->prev = q;
        }
        x = p->data;
        delete p;
    }
    return x;
}

void Reverse(Node *p){

    while(p){
        if(p->next == NULL){
            first = p;
        }
        Node *temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
    }
}

int main(){

    int A[] = {1,2,3,4,5,6};
    create(A,6);
    Reverse(first);
    display(first);

    return 0;
}