#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct stack{
    int top;
    int arr[MAX];
};

void push(struct stack* s, int ele){
    if (s->top == MAX-1){
        printf("Stack overflow");
    }else{
        s->arr[++s->top] =ele;
        printf("Successfully inserted.");
    }
}

void pop(struct stack *s){
    if(s->top == -1){
        printf("Stack Underflow");
    }else{
        int x = s->arr[s->top--];
        printf("Popped element:%d", x);
    }
}

void display(struct stack *s){
    if(s->top == -1){
        printf("Stack underflow");
    }else{
        printf("Stack elements are:\n");
        for(int i = s->top; i >=0; i--){
            printf("%d\t", s->arr[i]);
        }
    }
}

int main(){
    struct stack s;
    s.top=-1;
    int ch, ele;
    while(1){
        printf("1->Push\n2->Pop\n3->Display\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter the element to insert:\n");
                    scanf("%d", &ele);
                    push(&s, ele);
                    break;
            case 2: pop(&s);
                    break;
            case 3: display(&s);
                    break;
            default: printf("Invalid choice");
                    break;
        }
    }
}
