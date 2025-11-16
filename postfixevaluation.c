#include <stdio.h>
#include <stdlib.h>
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

int evaluate(char postfix[]){
    int opnd1, opnd2, x;
    struct stack s;
    s.top = -1;
    for(int i = 0; postfix[i] != '\0'; i++){
        char ch = postfix[i];
        switch (ch){
            case '+': opnd2 = pop(&s);
                        opnd1 = pop(&s);
                        push(&s, opnd1+opnd2);
                        break;
            case '-': opnd2 = pop(&s);
                        opnd1 = pop(&s);
                        push(&s, opnd1-opnd2);
                        break;
            case '*': opnd2 = pop(&s);
                        opnd1 = pop(&s);
                        push(&s, opnd1*opnd2);
                        break;
            case '/': opnd2 = pop(&s);
                        opnd1 = pop(&s);
                        push(&s, opnd1/opnd2);
                        break;
            default: push(&s, ch-'0');
        }
    }
    return(pop(&s));
}

int main(){
    char postfix[MAX];
    printf("Enter a postfix expression:");
    scanf("%s", postfix);
    int result = evaluate(postfix);
    printf("Result:%d", evaluate(postfix));
}
