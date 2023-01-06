#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct _snode Node;
typedef struct _stack Stack;

struct _snode{
    //char ch;
    double data;
    Node* next;
};

struct _stack{
    Node* top;
};

Stack* Create(){
    Stack *s;
    s=(Stack*)malloc(sizeof(Stack));
    if (s==NULL) {
    return NULL; // No memory
    }
    s->top=NULL;
    return s;
}

void push(Stack* s, /*char ch*/ double data){
    Node* node;
    node=(Node*)malloc(sizeof(Node));
    if(node==NULL){
        printf("full stack");
        return;
    }
    //node->ch=ch;
    node->data=data;
    node->next=s->top;
    s->top=node;
}

void pop(Stack* stack){
    if(stack->top==NULL){
        return;
    }
    else{
        stack->top=stack->top->next;
    }
}

double get_pop(Stack* stack){
    double retr;
    if(stack->top==NULL){
        return 0;
    }
    else{
        retr=stack->top->data;
        stack->top=stack->top->next;
    }
    return retr;
}

int is_empty(Stack* s){
    return (s->top==NULL);
}

void display(Stack* stack){
    Node* temp=stack->top;
    while(temp!=NULL){
        //printf("%c",temp->ch);
        printf("%lf ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//parentheses validation
/*
int main(){
    Stack* stack=Create();
    int t; scanf("%d",&t);
    if(t&2){
        printf("Khong hop le");
        return 0;
    }
    getchar();
    while(t--){
        char ch;
        scanf("%c",&ch);
        getchar();
        if(ch=='('||ch=='['||ch=='{'){
            push(stack,ch);
        }
        else{
            if(ch==')'&&stack->top->ch=='('){
                pop(stack);
            }
            else if(ch==']'&&stack->top->ch=='['){
                pop(stack);
            }
            else if(ch=='}'&&stack->top->ch=='{'){
                pop(stack);
            }
            else{
                printf("Khong hop le");
                return 0;
            }
        }
    }
    if(is_empty(stack)){
        printf("Hop le");
    }
    else{
        printf("Khong hop le");
    }
}
*/

//postfix_notation
double calc(char token, double x, double y){
    double res;
    switch(token){
        case '+': res=x+y; break;
        case '-': res=x-y; break;
        case '*': res=x*y; break;
        case '/': res=x/y; break;
        case '%': res=((int)x)%((int)y); break;
        case '^': res=pow(x,y); break;
        default: res=0; break;
    }
    return res;
}

double postfix_calc(char string[]){
    Stack* s=Create();
    int len=strlen(string);
    for(int i=0;i<len;i++){
        if(string[i]=='+'||string[i]=='-'||string[i]=='*'||string[i]=='/'||string[i]=='%'||string[i]=='^'){
            double y=get_pop(s);
            double x=get_pop(s);
            double z=calc(string[i],x,y);
            push(s,z);
        }
        else{
            push(s,(double)string[i]-'0');
        }
    }
    return get_pop(s);
}

int main(){
    char s[6]={'2','2','3','^','*'};
    double test=postfix_calc(s);
    printf("%lf",test);
}