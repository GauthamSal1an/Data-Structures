// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* llink;
    struct node* rlink;
};
typedef struct node * listptr;

listptr getnode(){
    listptr temp = (listptr)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    return temp;
}

listptr insertfront(listptr start, int ele){
    listptr temp = getnode();
    temp->data = ele;
    if  (start == NULL){
        return temp;
    }else{
        temp->rlink = start;
        start->llink = temp;
        start = temp;
        return start;
    }
}

listptr create(){
    int n, ele;
    listptr start = NULL;
    printf("Enter no of nodes:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter node value:");
        scanf("%d", &ele);
        start = insertfront(start, ele);
    }
    return start;
}

listptr insertend(listptr start, int ele){
    listptr temp = getnode();
    temp->data = ele;
    if (start == NULL){
        return temp;
    }else{
        listptr  p;
        for(p = start; p->rlink != NULL; p=p->rlink);
        p->rlink = temp;
        temp->llink = p;
        return start;
    }
}

listptr delend(listptr start){
    listptr p;
    if(start ==  NULL){
        printf("DLL EMPTY");
        return start;
    }else{
        for(p = start; p->rlink != NULL; p=p->rlink);
        listptr q = p->llink;
        q->rlink = NULL;
        p->llink = NULL;
        printf("deleted node value: %d", p->data);
        free(p);
        return start;
    }
}

listptr delfront(listptr start){
    if (start == NULL){
        printf("EMPTY DLL");
        return start;
    }else{
        listptr p = start;
        start = start->rlink;
        if (start!= NULL)
            start->llink = NULL;
        printf("deleted node value: %d", p->data);
        free(p);
        return start;
    }
}

void display(listptr start){
    if (start==NULL){
        printf("Empty dll");
    }else{
        int count = 0;
        printf("DLL Node are:");
        for(listptr p = start; p != NULL; p= p->rlink){
            printf("%d\t", p->data);
            count++;
        }
        printf("no of nodes: %d", count);
    }
}

int main() {
    // Write C code here
    listptr start = NULL;
    int ch, ele;
    char c;
    while(1){
        printf("1-> create\n 2-> insert and delete at front of list\n 3->insert and delete at end of list\n 4-> display linked list \n 5-> exit");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: start = create();
                    break;
            case 2: printf("enter i to insert or d  for delete:");
                    getchar();
                    scanf("%c", &c);
                    if(c == 'i'){
                        printf("Enter node value to insert:");
                        scanf("%d", &ele);
                        start = insertfront(start, ele);
                    }else{
                        start = delfront(start);
                    }
                    break;
            case 3: printf("enter i to insert d for delete:");
                    getchar();
                    scanf("%c", &c);
                    if(c == 'i'){
                        printf("Enter node value to insert");
                        scanf("%d", &ele);
                        start = insertend(start, ele);
                    }else{
                        start = delend(start);
                    }
                    break;
            case 4: display(start);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice");
                    break;
        }
    }
}
