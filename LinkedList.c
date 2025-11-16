// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct listnode{
    int data;
    struct listnode* link;
};
typedef struct listnode * listptr;

listptr getnode(){
    listptr temp = (listptr)malloc(sizeof(struct listnode));
    temp->link = NULL;
    return temp;
}

listptr insertend(listptr start, int ele){
    listptr temp = getnode();
    temp->data = ele;
    if (start == NULL){
        return temp;
    }else{
        listptr p;
        for ( p = start; p->link != NULL; p = p->link);
        p->link = temp;
        return start;
    }
}

listptr create(){
    int n, ele;
    listptr start = NULL;
    printf("Enter number of nodes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter the value for the node:");
        scanf("%d", &ele);
        start = insertend(start, ele);
    }
    return start;
}

listptr insertfront(listptr start, int ele){
    listptr temp = getnode();
    temp->data = ele;
    temp->link = start;
    start = temp;
    return start;
}

listptr delfront(listptr start){
    if (start == NULL){
        return NULL;
    }else{
        listptr p = start;
        start = start->link;
        printf("Popped element: %d", p->data);
        free(p);
        return start;
    }
}

void display(listptr start){
    if (start == NULL){
        printf("Linked list empty");
    }else{
        for (listptr p = start; p!=NULL; p=p->link){
            printf("%d\t", p->data);
        }
    }
}

void Stack(){
    int ch, ele;
    listptr start = NULL;
    while(1){
        printf("1->Push\n2->Pop\n3->Display\n4->Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter the node value:");
                    scanf("%d", &ele);
                    start = insertfront(start, ele);
                    break;
            case 2: start = delfront(start);
                    break;
            case 3: display(start);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }
}

void Queue(){
    int ch, ele;
    listptr start = NULL;
    while(1){
        printf("1->Insert\n2->Delete\n3->Display\n4->Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter the node value:");
                    scanf("%d", &ele);
                    start = insertend(start, ele);
                    break;
            case 2: start = delfront(start);
                    break;
            case 3: display(start);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }
}

int main() {
    // Write C code here
    int ch, ele;
    listptr start = NULL;
    while (1){
        printf("1->Insert Node\n2->Display\n 3-> Stack Implementation \n 4-> Queue Implementation\n 5-> Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch){
            case 1: start = create();
                    break;
            case 2: display(start);
                    break;
            case 3: Stack();
                    break;
            case 4: Queue();
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
}
