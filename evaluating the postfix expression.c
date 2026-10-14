#include<stdio.h>
#include<string.h>
#include<ctype.h>
# define MAX 10
int top = -1;
int stack[MAX];
void push(int ele){
    stack[++top] = ele;
}
int pop(){
    return stack[top--];
}
int main(){
char exp[20],c;
int i = 0;
int n1,n2,n3,num;
printf("Enter the postfix expression to evaluate :");
scanf("%[^\n]",exp);
while((c = exp[i++]) != '\0'){
    if (isdigit(c)){
        num = c - 48 ;
        push(num);
    }else{
        n1 = pop();
        n2 = pop();
        switch (c){
            case '+':
                n3 = n2 + n1;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '*':
                n3 = n2*n1;
                break;
            case '/':
                n3 = n2/n1;
                break;

        }
        push(n3);
    }
}
printf("\nThe value of the postfix expression %s is %d",exp,pop());
return 0;
}
