#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 20

struct stack{
    int top;
    int arr[MAX];
};

void push(struct stack* s, int ele){
    if (s->top == MAX-1){
        printf("Stack overflow");
    }else{
        s->arr[++s->top] =ele;
    }
}

int pop(struct stack *s){
    if(s->top == -1){
        printf("Stack Underflow");
    }else{
        int x = s->arr[s->top--];
        return(x);
    }
}

int prcd(char opnd){
    switch (opnd){
        case '(': return 5;
        case '$': return 4;
        case '*':
        case '/':
        case '%': return 3;
        case '+':
        case '-': return 2;
        case '#': return 1;
        default: printf("Invalid");
    }
}

void convert(struct stack *s, char postfix[], char infix[]){
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++){
        char c = infix[i];
        if(isalnum(c)){
            push(s, c);
        }else if (c == '('){
            push(s, c);
        }else if(c == ')'){
            while(s->arr[s->top] != '('){
                postfix[j++] = pop(s);
            }
            pop(s);
        }else {
            while(prcd(s->arr[s->top]) >= prcd(c)){
                postfix[j++] = pop(s);
            }
            push(s, c);
        }
    }
    while(s->arr[s->top] != '#'){
        postfix[j++] = pop(s);
    }
}

int main(){
    struct stack  s;
    s.top = -1;
    s.arr[++s.top] = '#';
    char postfix[MAX], infix[MAX];
    printf("Enter a infix expression:");
    scanf("%s", infix);
    convert(&s, postfix, infix);
    printf("The postfix operation is: %s", postfix);
}
