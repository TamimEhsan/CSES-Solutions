#include<stdio.h>

struct ME{
    int marks1:5;
    int marks2:10;
};

int main(){
    struct ME xm;
    int a,b;
    scanf("%d %d",&a,&b);
    xm.marks1 = a;
    xm.marks2 = b;
    printf("%d is the total marks",xm.marks1+xm.marks2);
}
