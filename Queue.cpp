#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Queue{
    public:
        Node *front;
        Node *rear;

        Queue(){
            front = rear = NULL;
        }

        void enqueue(int x){
            Node *t = new Node;
            if(t == NULL){
                cout << "HEAP IS FULL !!!";
            }
            else{
                t->data = x;
                t->next = NULL;
                if(front == NULL){
                    front = rear = t;
                }
                else{
                    rear->next = t;
                    rear = t;
                }
            }
        }

        int dequeue(){
            int x ;
            Node *t = front;
            if(front){
                front = front->next;
                x = t->data;
                delete t;
            }
            else{
                cout << "EMPTY BRUH !!!"; 
            }
            return x;
        }

        void display(){
            Node *t = front;
            while(t){
                cout << t->data << " ";
                t = t->next;
            }
        }
};

int main(){
    Queue qt;
    
    qt.display();
}