#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct cqueue{
    int front;
    int item[MAX];
    int rear;
};

void cqinsert(struct cqueue* q, int ele){
    if ((q->rear+1)%MAX == q->front){
        printf("Queue overflow");
    }else{
        q->rear = (q->rear+1)%MAX;
        q->item[q->rear] = ele;
    }
}

void cqdelete(struct cqueue* q){
    if (q->rear == q->front){
        printf("Queue underflow");
    }else{
        q->front = q->item[(q->front+1)%MAX];
        printf("Deleted item: %d", q->item[q->front]);
    }
}

void cqdisplay(struct cqueue *q){
    if(q->rear == q->front){
        printf("Queue underflow");
    }else{
        printf("Displaying queue items:");
        if(q->rear > q->front){
            for(int i = q->front+1; i<=q->rear; i++){
                printf("%d\t", q->item[i]);
            }
        }else{
            for(int i = q->front+1; i<=MAX-1; i++){
                printf("%d\t", q->item[i]);
            }
            for(int i = 0; i<=q->rear; i++){
                printf("%d\t", q->item[i]);
            }
        }
    }
}

int main(){
    struct cqueue q;
    int ch, ele;
    q.front = q.rear = 0;
    while (1){
        printf("1->insert\n2->delete\n3->display\n4->exit");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter element to insert:");
                    scanf("%d", &ele);
                    cqinsert(&q, ele);
                    break;
            case 2: cqdelete(&q);
                    break;
            case 3: cqdisplay(&q);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }
}
