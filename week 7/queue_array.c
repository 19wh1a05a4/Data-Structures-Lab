#include<stdio.h>
#include<stdlib.h>
#define maxsize 5

int f = -1, r = -1, queue[maxsize];

int isfull() {
    
    if(r == maxsize - 1) 
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
    //else
    queue[++r] = data;
}
void deque() {
    
    if(f == r) 
        f = r = -1;
    else  {
        printf("\nDELETED ELEMENT IS :%d\n",queue[f]);
    }
        f++;
    
}
void display() {
	int i;
    for( i = f; i <= r; i ++) 
        printf("%d ->",queue[i]);
}

int main() {
    int ch, x;
    while(1) {
        printf("\n1  -  ENQUEUE\n2  -  DEQUE\n3  -  DISPLAY\n4  - EXIT");
        printf( "\nENTER YOUR CHOICE :)\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1 :if(isfull()) 
                        printf("\nQUEUE OVERFLOW\n");
                    else {
                        printf("\nENTER THE DATA TO BE INSERTED\n");
                        scanf("%d",&x);
                        enqueue(x);
                    }
                    break;
            case 2 :if(isempty())
                        printf("\nSTACK UNDERFLOW\n");
                    else
                        deque();
                    break;
            
            case 3 :display();
                    break;
            case 4 :exit(0);
                   
        }
    }
}







