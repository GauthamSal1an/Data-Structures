// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int n;

void create(int a[]){
    printf("Enter length of array:");
    scanf("%d", &n);
    printf("Enter array elements:");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

void display(int a[]){
    if (n==0){
        printf("Empty list");
    }else{
        printf("Displaying array elements:");
        for(int i = 0; i < n; i++){
            printf("%d", a[i]);
        }
    }
}

void insert(int a[], int ele, int pos){
    if (n== MAX){
        printf("array is full");
    }
    if(pos > n || pos < 0){
        printf("invalid index");
    }else{
        for(int i = n-1; i >= pos; i++){
            a[i+1] = a[i];
        }
        a[pos] = ele;
        n++;
    }
}

void del(int a[], int pos){
    if(pos >= n || pos < 0){
        printf("Invalid index");
    }else{
        for(int i = pos; i < n-1; i++){
            a[i] = a[i+1];
        }
        a[n-1] = 0;
        n--;
    }
}

int main(){
    int ch, a[MAX], ele, pos;
    while (1){
        printf("1-> Create\n2-> Display\n3-> Insert\n4-> Delete\n5-> Exit");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(a);
                    break;
            case 2: display(a);
                    break;
            case 3: printf("Enter element:");
                    scanf("%d", &ele);
                    printf("Enter index:");
                    scanf("%d", &pos);
                    insert(a, ele, pos);
                    break;
            case 4: printf("Enter index:");
                    scanf("%d", &pos);
                    del(a, pos);
                    break;
            case 5: exit(0);
            default: printf("INVALID CHOICE");
        }
    }
}
