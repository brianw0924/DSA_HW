#include <stdio.h>
#include<stdint.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef struct stack{
    int top;
    int start;
    char *array;
} Stack;

char Pop(Stack *stack){
    return(stack->array[stack->top--]);
}

int StackEmpty(Stack *stack){
    return (stack->top == -1);
}

void Push(Stack *stack , char digit){
    stack->array[++(stack->top)]=digit;
}



int main(void){


    int k,ans=0;
    char *num=(char*)malloc(sizeof(char)*100000000);
    scanf("%s%d",num,&k);
    
    Stack *S=(Stack*)malloc(sizeof(Stack));
    S->top=-1;
    S->start=0;
    S->array=(char*)malloc(sizeof(char)*100000000);
    
    int i=0;
    while(i<strlen(num)){

        if(StackEmpty(S))//空的直接push
            Push(S,num[i++]);

        else if(S->array[S->top] < num[i] )
            Push(S,num[i++]);
            
        else{//當前數字比stack頂還小

            while( num[i] < S->array[S->top] && (!StackEmpty(S)) && (k!=0) && (num[i]!='0' || S->top!=0) ){
                    Pop(S);
                    k--;
            }

            if( (num[i]=='0' && S->top==0) ){//現在刪掉可能會有leading zeros
                    int countZero=0,temp=i;
                    while(num[temp]=='0'){
                        countZero++;
                        temp++;
                    }//現在temp指在第一個非零的
                
                    if( (S->array[S->start] > num[temp]) && (k-1 > countZero ) ){
                        Pop(S);
                        i+=(countZero);
                        k-=(countZero+1);
                    }
                }
            
            Push(S,num[i++]);
            }
        
    }
        
        
    
    i--;

    while(k!=0){
            Pop(S);
            k--;
            i--;
        }
    
    
    while(S->start<=S->top){
        putchar(S->array[S->start++]);
    }

    free(num);
    free(S->array);
    


    return 0;
}
