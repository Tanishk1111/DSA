#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *head;

        void create(int A[],int n){
            Node *t,*last;
            head = new Node;
            head->data = A[0];
            head->next = head;
            last = head;

            for(int i = 1;i < n;i++){
                t = new Node;
                t->data = A[i];
                last->next = t;
                last = t;
            }
            last->next = head;
        }   

        void display(){
            Node *p;
            p = head;
            do{
                cout << p->data << " ";
                p = p->next;
            }while(p!=head);
        } 

        void Rdisplay(Node *h){
            static int flag = 0;
            if(flag == 0 or h!=head){
                flag = 1;
                cout << h->data << " ";
                Rdisplay(h->next);
            }
            flag = 0;

        }

        void Insert(int index,int x){
            Node *t = new Node;
            Node *p = head;
            t->data = x;
            if(index == 0){
                if(head == NULL){
                    head = t;
                    head->next = head;
                }
                else{
                    while(p->next != head){
                        p = p->next;
                    }
                    p->next = t;
                    t->next = head;
                    head = t;
                }
            
            }
            else{
                for(int i = 0; i < index-1; i++){
                    p = p->next;
                }
                t->next = p->next;
                p->next = t;

            }
        }

};


int main(){

    Node p;
    // Node *t;
    int A[] = {11,22,33,44,55};
    p.create(A,5);
    p.Insert(0,2);
    p.display();


    return 0;
}