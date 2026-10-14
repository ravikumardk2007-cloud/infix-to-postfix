#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
int top = -1;
char Stack[MAX];
void push(char ele){
    Stack[++top] = ele;
}
int pop(){
    return Stack[top--];
}
int pr(char symbol){
    if(symbol == '^'){
        return 3;
    }else if (symbol == '*' || symbol == '/'){
        return 2;
    }else if(symbol == '+' || symbol == '-'){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    char infix[20],postfix[20],c,ele;
    int i=0,k=0;
    printf("Enter the infix Expression:\n");
    scanf("%s",infix);
    push('#');
    while ((c = infix[i++]) != '\0'){
        if (c =='('){
            push(c);
        }else {
            if(isalnum(c)){
                postfix[k++] = c;
            }else {
                if (c ==')'){
                    while (Stack[top] != '('){
                        postfix[k++] = pop();
                    }
                    ele = pop();
                }else {
                    while(pr(Stack[top]) >= pr(c)){
                        postfix[k++] = pop();

                    } push(c);
                }
            }
        }
    }
    while (Stack[top] !='#'){
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("Postfix Expression :%s",postfix);
    return 0;
}
