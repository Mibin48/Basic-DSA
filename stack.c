#include<stdio.h>
static int top=-1;
int stack[50];
void push(){
    if (top == 49) {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    int n;
    printf("Enter the element:");
    scanf("%d",&n);
    stack[top]=n;
    printf("%d pushed to stack.\n", n);
}
void pop(){
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}
void display(){ 
    if(top==-1){
        printf("Stack is empty!\n");
    }
    else{
        printf("Stack:");
        for(int i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
int main(){
    while(1){
        printf("Menu\n");
        printf("1:Push\n2:Pop\n3:Display\n4:Exit\n");
        int choice;
        printf("Input the choice:");
        scanf("%d",&choice);
        if(choice==1){
            push();
        }
        else if (choice==2){
            pop();
        }
        else if(choice==3){
            display();
        }
        else{
            printf("Exiting...");
            break;
        }
    }
    return 0;
}