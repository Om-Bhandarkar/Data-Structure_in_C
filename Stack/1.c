#include<stdio.h>
int top = -1;
int arr[5];
void push(int data){
    top++;
    arr[top] = data;
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    for(int i=top;i>=0;i--){
        printf("|%d|\n",arr[i]);
    }
    return 0;
}