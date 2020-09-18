//CIRCULAR QUEUE USING ARRAYS
#include<stdio.h>
#include<stdlib.h>
#define maxsize 5

int f = -1, r = -1, cqueue[maxsize];

int isfull() {
    
    if(f == (r+1)%maxsize ) 
        return 1;
    else
        return 0;
}

int isempty() {
    
    if(f == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(int data) {
    
    if(f == -1)
        f = 0;
    r = (r+1) % maxsize;
    cqueue[r] = data;
}
int deque() {
    int x = cqueue[f];
    if(f == r) 
        f = r = -1;
    else  {
        f = (f+1)% maxsize;
    }
    return x;

}
void display() {
    if(f == -1) {
        printf("CQUEUE IS EMPTY\n");
    }
    else {
        int i;
        for(i = f; i != r; i = (i +1)%maxsize) 
            printf("%d -> ",cqueue[i]);
        printf("%d\n",cqueue[i]);
    }
}

int main() {
    int ch, x;
    while(1) {
        printf("\n1  -  ENQUEUE\n2  -  DEQUE\n3  -  DISPLAY\n4  - EXIT");
        printf( "\nENTER YOUR CHOICE :)\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1 :if(isfull()) 
                        printf("\n CIRCULAR QUEUE OVERFLOW\n");
                    else {
                        printf("\nENTER THE DATA TO BE INSERTED\n");
                        scanf("%d",&x);
                        enqueue(x);
                    }
                    break;
            case 2 :if(isempty())
                        printf("\n CIRCULAR QUEUE UNDERFLOW\n");
                    else
                        printf(" DELETED ELEMENT IS %d \n",deque());
                        if(f == r) 
                            f = r = -1;
                    break;
            
            case 3 :display();
                    break;
            case 4 :exit(0);
                   
        }
    }
}







