//QUEUE USING SLL
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
    cur->link = NULL;
    if(f == NULL)
        f = r = cur;
    else{
        r->link = cur;
        r = cur;
    }
    
}
void dequeue() {
    
    if(f == NULL) 
        printf("\nQUEUE UNDERFLOQ\n");
    else if(f == r) {
        printf("\nDELETED DATA %d\n", f->data);
        f = r = NULL;
    }
    else {
        cur = f;
        f = f->link;
        printf("\nDELETED DATA ID  %d\n", cur->data);
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
        while(cur != NULL) {
            printf("%d -> ",cur->data);
            cur = cur->link;
        }
    }
}

int main() {
    int ch,x;
    while(1) {
        printf("\n1  -  ENQUEUE\n2  -  DEQUE\n3  -  DISPLAY\n4  - EXIT");
        printf( "\nENTER YOUR CHOICE :)\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1 :enqueue(x);
                    break;
                    
            case 2 :if(isempty())
                        printf("\nSTACK UNDERFLOW\n");
                    else
                        dequeue();
                    break;
            
            case 3 :display();
                    break;
            case 4 :exit(0);
                   
        }
    }
}


