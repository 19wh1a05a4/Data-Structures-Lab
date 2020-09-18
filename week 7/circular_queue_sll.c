#include<stdio.h>
#include<stdlib.h>
struct node {
    
    int data;
    struct node*link;
};

struct node*f = NULL, *r = NULL, *cur;

void enqueue() {
    
    cur = (struct node*)malloc(sizeof(struct node));
    printf("\nENTER THE DATA TO BE INSERTED\n");
    scanf("%d",&cur->data);
    if(f == NULL) {
        
        cur->link = cur;
        f = r = cur;
    }
    else{
        r->link = cur;
        cur->link = f;
        r = cur;
    }
    
}
void dequeue() {
    
    if(f == NULL) 
        printf("\nQUEUE UNDERFLOW\n");
    else if(f == r) {
        printf("\nDELETED DATA %d\n", f->data);
        f = r = NULL;
    }
    else {
        cur = f;
        f = f->link;
        r->link = f;
        printf("\nDELETED DATA IS  %d\n", cur->data);
        free(cur);
    }
}
int isempty() {
    
    if(f == NULL) 
        return 1;
    else 
        return 0;
}
void display() {
    if(f == NULL) 
        printf("\nQUEUE IS EMPTY\n");
    else {
        cur = f;
        while(cur->link != f) {
            printf("%d -> ",cur->data);
            cur = cur->link;
        }
        printf("%d ->",cur->data);
    }
}

int main() {
    int ch;
    while(1) {
        printf("\n1  -  ENQUEUE\n2  -  DEQUE\n3  -  DISPLAY\n4  - EXIT");
        printf( "\nENTER YOUR CHOICE :)\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1 :enqueue();
                    break;
                    
            case 2 :dequeue();
                    break;
            
            case 3 :display();
                    break;
            case 4 :exit(0);
                   
        }
    }
}


