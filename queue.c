#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct queue{
    int front;
    int item[MAX];
    int rear;
};

void qinsert(struct queue* q, int ele){
    if (q->rear == MAX-1){
        printf("Queue overflow");
    }else{
        q->item[++q->rear] = ele;
    }
}

void qdelete(struct queue* q){
    if (q->rear == q->front){
        printf("Queue underflow");
    }else{
        int x = q->item[++q->front];
        printf("Deleted item: %d", x);
    }
}

void qdisplay(struct queue *q){
    if(q->rear == q->front){
        printf("Queue underflow");
    }else{
        printf("Displaying queue items\n");
        for(int i = q->front+1; i<=q->rear; i++){
            printf("%d\t", q->item[i]);
        }
    }
}

int main(){
    struct queue q;
    int ch, ele;
    q.front = q.rear = -1;
    while (1){
        printf("1->insert\n2->delete\n3->display\n4->exit");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter element to insert:");
                    scanf("%d", &ele);
                    qinsert(&q, ele);
                    break;
            case 2: qdelete(&q);
                    break;
            case 3: qdisplay(&q);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }
}
