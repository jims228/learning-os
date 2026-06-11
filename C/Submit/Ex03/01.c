#include<stdio.h>
int stack[200];
int top = 0;

void push(int x){
    top++;
    stack[top] = x;
}

int pop(){
    int x = stack[top];
    top--;
    return x;
}

int main(){
    char s[100];
    int a,b,i,num;

    while(scanf("%s",s) != EOF){
        if(s[0] == '+'){
            b = pop();
            a = pop();
            push(a+b);
        }
        else if(s[0] == '-'){
            b = pop();
            a = pop();
            push(a-b);
        }
        else if(s[0] == '*'){
            b = pop();
            a = pop();
            push(a*b);
        }
        else{
            num = 0;
            i = 0;
            while(s[i] != '\0'){
                num = num*10 + (s[i] - '0');
                i++;
            }
            push(num);
        }
        if(getchar() == '\0'){
            break;
        }
    }
    printf("%d\n", stack[top]);
    return 0;
}