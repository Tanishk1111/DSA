/*

Height analysis for AVL Trees -

if height is given:

    h starts from 1;

    maximum nodes n for height h = 2^h - 1;

    minimum nodes n for height h =
                N(h)= 0                        if h = 0;
                    = 1                        if h = 1;
                    = N(h-1) + N(h-2) + 1      if h > 1; 



if nodes are given :

    minimum height h = log2(n+1);

    maximum height h = look in table;
                    (approximately = [1.44log2(n+1)]);

*/

#include<bits/stdc++.h>

using namespace std;

struct Node{

    Node *lchild;
    Node *rchild;
    int data;
    int height;

}*root = NULL;

int Nodeheight(Node *p){
    int hl,hr;
    hl = (p and (p->lchild))?p->lchild->height:0; 
    hr = (p and (p->rchild))?p->rchild->height:0; 

    return hl>hr? hl+1:hr+1;
}

Node *LLrotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);

    if(root == p){
        root = pl;
    }

    return pl;

}

Node *RRrotation(Node *p){
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;

    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);
    if(root == p){
        root = pr;
    }

    return pr;
}

Node *LRrotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;
    
    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);
    plr->height = Nodeheight(plr);

    if(root == p){
        root = plr;
    }

    return plr;
}

Node *RLrotation(Node *p){
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);
    prl->height = Nodeheight(prl);

    if(root == p){
        root = prl;
    }

    return prl;


}

int Balancedfactor(Node *p){
    int hl,hr;
    hl = (p and (p->lchild))?p->lchild->height:0; 
    hr = (p and (p->rchild))?p->rchild->height:0; 
    return hl-hr;
}

Node *InsertRec(Node *p,int key){
    Node *t;
    if(p == NULL){
        t = new Node;
        t->data = key;
        t->height = 1;
        t->rchild = t->lchild = NULL;
        return t;
    }
    if(key < p->data){
        p->lchild = InsertRec(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = InsertRec(p->rchild,key);
    }

    p->height = Nodeheight(p);

    if(Balancedfactor(p) == 2 and Balancedfactor(p->lchild) == 1){
        return LLrotation(p);
    }
    else if(Balancedfactor(p) == 2 and Balancedfactor(p->lchild) == -1){
        return LRrotation(p);
    }
    else if(Balancedfactor(p) == -2 and Balancedfactor(p->rchild) == 1){
        return RLrotation(p);
    }
    else if(Balancedfactor(p) == -2 and Balancedfactor(p->rchild) == -1){
        return RRrotation(p);
    }
    

    return p;
}

void inorder(Node *root){
    if(root){
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
}   

Node *InPre(Node *p){
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
    if (p == nullptr){
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        Node* q;
        if (Nodeheight(p->lchild) > Nodeheight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
 
    // Update height
    p->height = Nodeheight(p);
 
    // Balance Factor and Rotation
    if (Balancedfactor(p) == 2 && Balancedfactor(p->lchild) == 1) {  // L1 Rotation
        return LLrotation(p);
    } 
    else if (Balancedfactor(p) == 2 && Balancedfactor(p->lchild) == -1){  // L-1 Rotation
        return LRrotation(p);
    } 
    else if (Balancedfactor(p) == -2 && Balancedfactor(p->rchild) == -1){  // R-1 Rotation
        return RRrotation(p);
    } 
    else if (Balancedfactor(p) == -2 && Balancedfactor(p->rchild) == 1){  // R1 Rotation
        return RLrotation(p);
    } 
    else if (Balancedfactor(p) == 2 && Balancedfactor(p->lchild) == 0){  // L0 Rotation
        return LLrotation(p);
    } 
    else if (Balancedfactor(p) == -2 && Balancedfactor(p->rchild) == 0){  // R0 Rotation
        return RRrotation(p);
    }
 
    return p;
}

int main(){

    root = InsertRec(root , 10);
    int arr[] = {20,30,25,28,27,5};
    for(int i = 0;i < 6; i++){
        InsertRec(root,arr[i]);
    }
    
    inorder(root);

    return 0;
}