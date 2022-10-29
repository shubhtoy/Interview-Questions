#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char* c;
};

void push(struct stack*s, char x) {
    if(s->top==s->size-1) return;
    s->top++;
    s->c[s->top] = x;
}

int isEmpty(struct stack* s) {
    if(s->top<0) return 1;
    return 0;
}

void pop(struct stack*s) {
    if(isEmpty(s)) return;
    s->top--;
}

char Top(struct stack *s) {
    return s->c[s->top];
}

int parenthesisCheck(struct stack *s, char *str) {
    int i=0;
    int open=0,close=0;
    while(str[i]!='\0')   {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{') {
            push(s,str[i]);
            open++;
        }else if(str[i]==')') {
            if(s->c[s->top]=='(') {
                pop(s);
            }else{
                return 0;
            }
            close++;
        }else if(str[i]=='}') {
            if(s->c[s->top]=='{') {
                pop(s);
            }else{
                return 0;
            }
            close++;
        }else if(str[i]==']') {
            if(s->c[s->top]=='[') {
                pop(s);
            }else{
                return 0;
            }
            close++;
        }
        i++;
    }
    if(open==close) return 1;
    else return 0;
}

int main() {
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=50;
    s->top=-1;
    s->c=(char*)malloc(s->size*sizeof(char));

    char str[50];
    printf("Enter the statement\n");
    gets(str);

    if(parenthesisCheck(s,str)) {
        printf("Correctly parenthesized");
    }else{
        printf("Not correctly parenthesized");
    }


    return 0;
}
