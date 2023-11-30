#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
}*top = NULL;

void push(int val){
    Node *t = new Node;
    if(t == NULL){
        cout << "STACK OVERFLOW\n";
    }
    else{
        t->data = val;
        t->next = top;
        top = t;
    }
}

int pop(){
    int x = -1;
    Node *t = top;
    if(t == NULL){
        cout << "STACK UNDERFLOW\n";
    }
    else{
        top = t->next;
        x = t->data;
        delete t;
    }

    return x;
}

void display(){
    Node *t = top;
    while(t){
        cout << t->data << " ";
        t = t->next;
    }
}

int isoperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int outpre(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inpre(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}

char *into(char *infix){
    int i = 0,j=0;;
    char *postfix = new char[strlen(infix)+1];
    while(infix[i] != '\0'){
        if(isoperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(top == NULL || outpre(infix[i]) > inpre(top->data)){
                push(infix[i]);
                i++;
            }
            else if(outpre(infix[i]) == inpre(top->data)){
                pop();
            }
            else{
                postfix[j++] = pop();
            }
        }
    }
    while(top and top->data != ')'){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int Eval(char *infix){
    int x1,x2,r;
    for(int i = 0;infix[i]!= '\0'; i++){
        if(isoperand(infix[i])){
            push(infix[i] - '0');
        }
        else{
            x2 = pop();
            x1 = pop();
            switch (infix[i])
            {
            case '+': r = x1+x2; break;

            case '-': r = x1-x2; break;
            
            case '*': r = x1*x2; break;
            
            case '/': r = x1/x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main(){
    char infix[] = "35*62/+4-";
    cout << Eval(infix);

    return 0;
}