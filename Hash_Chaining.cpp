#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class Hashtable{
    public:
        Node** HT;
        Hashtable();
        int hash(int key);
        void Insert(int key);
        int Search(int key);
        ~Hashtable();
};

Hashtable::Hashtable(){
    HT = new Node *[10];
    for(int i = 0; i < 10; i++){
        HT[i] = NULL;
    }
}

int Hashtable::hash(int key){
    return key%10;
}

void Hashtable::Insert(int key){
    Node *t = new Node;
    t->value = key;
    t->next = NULL;

    if(HT[hash(key)] == NULL){
        HT[hash(key)] = t;
    }
    else{
        Node *p = HT[hash(key)];
        Node *q = NULL;
        while(p and p->value < key){
            q = p;
            p = p->next;
        }
        if(q == NULL){
            t->next = HT[hash(key)];
            HT[hash(key)] = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int Hashtable::Search(int key){
    Node *p = HT[hash(key)];
    while(p and p->value <= key){
        if(p->value == key){
            return p->value;
        }
        p = p->next;
    }
    return -1;

}

Hashtable::~Hashtable(){
    for(int i = 0; i < 10; i++){
        Node *p = HT[i];
        while(HT[i]){
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    
    delete [] HT;
}

int main(){

    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
    Hashtable H;
    for(int i = 0; i < n; i++){
        H.Insert(A[i]);
    }
    cout << H.Search(51) ;

    return 0;
}