#include<stdio.h>
struct polynomial
{
    int coeff[10];
    int exp[10];
    int size;
}p[3];
void read(int n,int i){
    p[i].size=n;
    printf("\nEnter terms in descending order:\n");
    for(int j=0;j<n;j++){
        printf("Coefficient: ");
        scanf("%d", &p[i].coeff[j]);
        printf("Exponent: ");
        scanf("%d", &p[i].exp[j]);
    }
}
void display(int i){
    for(int j=0;j<p[i].size;j++){
        printf("%dx^%d",p[i].coeff[j],p[i].exp[j]);
        if(j<p[i].size-1){
            printf("+");
        }
    }
    printf("\n");
}
void add(int i){
    int j;
    for(j=0; j<p[0].size && j<p[1].size;j++){
        if(p[0].exp[j]==p[1].exp[j]){
            p[2].coeff[j]=p[0].coeff[j]+p[1].coeff[j];
            p[2].exp[j]=p[0].exp[j];
        }
        else if(p[0].exp[j]>p[1].exp[j]){
            p[2].coeff[j]=p[0].coeff[j];
            p[2].exp[j]=p[0].exp[j];
        }
        else{
            p[2].coeff[j]=p[1].coeff[j];
            p[2].exp[j]=p[1].exp[j];
        }
    }
    for(int k=j;k<p[0].size;k++){
        p[2].coeff[k]=p[0].coeff[k];
        p[2].exp[k]=p[0].exp[k];
        j++;
    }
    for(int k=j;k<p[1].size;k++){
        p[2].coeff[k]=p[1].coeff[k];
        p[2].exp[k]=p[1].exp[k];
        j++;
    }
    p[2].size=j;
}
int main(){
    int n;
    printf("Enter the no. of terms in first polynomial:");
    scanf("%d",&n);
    printf("Enter the first polynomial:");
    read(n,0);
    printf("Enter the no. of terms in second polynomial:");
    scanf("%d",&n);
    printf("Enter the second polynomial:");
    read(n,1);
    add(2);
    printf("\nFirst Polynomial: ");
    display(0);
    printf("Second Polynomial: ");
    display(1);
    printf("Sum Polynomial: ");
    display(2);
}