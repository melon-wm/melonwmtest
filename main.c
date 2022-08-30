#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#ifndef MAX 20
#define MAX 20
#endif
int main() {
    struct student{
        int name;
        int age;
        short int score;
    }Student;
    Student.age=18;
    Student.name=2;
    Student.score=100;
    int a = MAX;
    printf("%d\n",a<0);
    return 0;
}
