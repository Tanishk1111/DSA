#include <bits/stdc++.h>

using namespace std;

struct Stack{
    int size;
    char top;
    char *S;
};

void create(Stack *stk,int size){

    stk->S = new char[size];
    
    stk->top = -1;
}

void display(Stack stk){
    int i = stk.top;
    while(i != -1){
        cout << stk.S[i--] << '\n';
    }
}

void push(Stack *stk, char k){
    if(stk->top != stk->size-1){
        stk->top++;
        stk->S[stk->top] = k;
    }
    else{
        cout << "**************STACK OVERFLOW**************\n";
    }
}

char pop(Stack *stk){
    char x;
    if(stk->top != -1){
        x = stk->S[stk->top];
        stk->top--;
    }
    else{
        cout << "**************STACK UNDERFLOW**************\n";
    }

    return x;
}

int peek(Stack stk, int index){
    if((stk.top - index +1) > -1){
        return stk.S[stk.top - index +1];
    }
    return -1;
}
 
int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    else{
        return 1;
    }
}

int pre(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '*' || x == '/'){
        return 2;
    }
    return -1;
}

char *convert(char *infix){
    Stack st;
    create(&st,strlen(infix)+1);
    char *postfix = new char[strlen(infix)+1];
    int j = 0,i=0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(st.S[st.top]) < pre(infix[i])){
                push(&st,infix[i++]);
            }
            else{
                postfix[j++] = pop(&st);
            }

        }
    }
    while(st.top!=-1){
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';

    return postfix;
}

int main(){

    char infix[] = "a+b-c/d*e";
    char *o = convert(infix);
    for(int i = 0; i < strlen(infix);i++){
        cout << o[i];
    }
    return 0;
}