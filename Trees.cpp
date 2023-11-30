/*

# Binary Trees

n = number of nodes;
T(n) = number of unlabelled binary trees which can be generated from those nodes;

T(n) = (2n C n)/(n+1);        #Catalan Number

L(n) = number of unlabelled binary trees having maximum heights;

L(n) = 2^(n-1);

for labelled nodes just multiply n! everywhere ;)

*/

#include <bits/stdc++.h>
#include "queue.h"

using namespace std;

struct Node *root=NULL;

void Treecreate()
{
    Node *p,*t;
    int x;
    Queue q;
    create(&q,100);

    cout << "Enter root value ";
    cin >> x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        cout << "enter left child of " << p->data << " ";
        cin >> x;
        if(x!=-1)
        {
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        cout << "enter right child of " << p->data << " ";
        cin >> x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void Preorder(struct Node *p)
{
    if(p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }   
}

int height(Node *root){
    int x = 0,y = 0;
    if(root == 0){
        return 0;
    }
    x = height(root->lchild);
    y = height(root->rchild);
    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}

int count(Node *root)
{
    if(root) return count(root->lchild)+count(root->rchild)+1;
    return 0;
}

int countleaf(Node *root){
    int x = 0,y = 0;
    if(root){
        x = countleaf(root->lchild);
        y = countleaf(root->rchild);
        if(!root->lchild and !root->rchild){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}

int countbi(Node *root){
    int x = 0,y = 0;
    if(root){
        x = countbi(root->lchild);
        y = countbi(root->rchild);
        if(root->lchild and root->rchild){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}

int countdeg1(Node *root){
    int x = 0,y = 0;
    if(root){
        x = countdeg1(root->lchild);
        y = countdeg1(root->rchild);
        if((root->lchild == NULL)^(root->rchild == NULL)){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}

void InsertBi(Node *t,int key){
    Node *r=NULL,*p;
    if(root == NULL){
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t){
        r = t;
        if(key == t->data){
            return;
        }
        else if(key > t->data){
            t = t->rchild;
        }
        else{
            t = t->lchild;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(r->data > p->data){
        r->lchild = p;
    } 
    else{
        r->rchild = p;
    }
}

Node *InsertRec(Node *p,int key){
    Node *t;
    if(p == NULL){
        t = new Node;
        t->data = key;
        t->rchild = t->lchild = NULL;
        return t;
    }
    if(key < p->data){
        p->lchild = InsertRec(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = InsertRec(p->rchild,key);
    }
    return p;
}

Node *Inpre(Node *p){
    while(p and p->rchild){
        p = p->rchild;
    }
    return p;
}

Node *InSucc(Node *p){
    while(p and p->lchild){
        p = p->lchild;
    }
    return p;
}

Node *Delete(Node *p,int key){
    if(p == NULL){
        return NULL;
    }
    if(p->lchild == NULL and p->rchild == NULL){
        if(p == root){
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if(key > p->data){
        p->rchild = Delete(p->rchild,key);
    }
    else if(key < p->data){
        p->lchild = Delete(p->lchild,key);
    }
    else{
        if(height(p->lchild) > height(p->rchild)){
            Node *q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }
        else{
            Node *q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
    }
    return p;
}

void createPre(int pre[],int n){
    // Create root node
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = nullptr;
    root->rchild = nullptr;
 
    // Iterative steps
    Node* t;
    Node* p = root;
    stack<Node*> stk;
 
    while(i < n){
        if (pre[i] < p->data){
            t = new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p = t;
        } else {
            // Right child cases
            if (pre[i] > p->data && pre[i] < (stk.empty() ? 32767 : stk.top()->data)){
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            } 
            else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

int main()
{
    int ar[] = {30, 20, 10, 15, 25, 40, 50, 45};
    createPre(ar,8);
    Inorder(root);

    return 0;
}


