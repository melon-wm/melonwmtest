#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>

#define LIST_SIZE 10
/************************************************************
**************************函数指针****************************
************************************************************/
// int square(int num){
//         return num*num;
//     }

// int add(int num1,int num2){
//     return num1+num2;
// }

// int subtract(int num1,int num2){
//     return num1-num2;
// }

// typedef int (*fptrOperation)(int,int);

// int compute(fptrOperation operation,int num1,int num2){
//     return operation(num1,num2);
// }

//  fptrOperation select(char opcode){
//      switch (opcode) {
//          case '+':return add;
//          case '-':return subtract;
//      }
//  }

// int evaluate(char opcode,int num1,int num2){
//     fptrOperation operation = select(opcode);
//     return operation(num1,num2);
// }
/************************************************************
*************************数组与指针***************************
************************************************************/

// void displayArray(int arr[],int size){//数组表示法
//     for(int i=0;i<size;i++){
//         printf("%d\n",arr[i]);
//     }
// }

// void displayArray1(int* arr,int size){//指针表示法
//     for(int i =0;i<size;i++){
//         printf("%d\n",*(arr+i));
//     }
// }

// void dispaly2DArray(int arr[][5],int rows){
//     for(int i =0;i<rows;i++){
//         for(int j=0;j<5;j++){
//             printf("%d\n",arr[i][j]);
//         }
//     }
// }

// void display2DArray1(int (*arr)[5],int rows){
//     //这个函数同上，一个是隐式声明，一个是显式声明
// }

// void dispaly2DArrayUnknownSize(int* arr,int rows,int cols){//这种传递二维数组的方式是使用普通的指针指向二维数组首元素！
//     for(int i=0;i<rows;i++){
//         for(int j=0;j<cols;j++){
//             printf("%d\n",*(arr+(i*cols)+j));//这里记住！！！
//         }
//     }
// }

/************************************************************
**************************结构体指针*************************
************************************************************/

typedef struct _Person{
    char* firstname;
    char* lastname;
    char* title;
    unsigned int age;
} Person;

Person* list[LIST_SIZE];

void initializeList(){
    for(int i=0;i<LIST_SIZE;i++){
        list[i]=NULL;
    }
}

void initializePerson(Person *person,const char* fn,const char* ln,const char* title,int age){
    //为结构体成员申请堆内存空间
    person->firstname=(char*)malloc(strlen(fn)+1);
    person->lastname=(char*)malloc(strlen(ln)+1);
    person->title=(char*)malloc(strlen(title)+1);
    //初始化
    strcpy(person->firstname,fn);
    strcpy(person->lastname, ln);
    strcpy(person->title, title);
    person->age=age;
}

void deallocatePerson(Person* person){
    free(person->firstname);
    free(person->lastname);
    free(person->title);
}

Person* getPerson(){//结构体池
    for(int i =0;i<LIST_SIZE;i++){
        if(list[i]!=NULL){
            Person* ptr=list[i];
            list[i]=NULL;
            return ptr;
        }
    }
    Person* person=(Person*)malloc(sizeof(Person));
    return person;
}

Person* returnPerson(Person* person){
    for(int i =0 ;i<LIST_SIZE;i++){
        if(list[i]==NULL){
            list[i]=person;
            return person;
        }
    }
    deallocatePerson(person);
    free(person);
    return NULL;
}

void processPerson(){
    //实例方法
    Person person;
    initializePerson(&person, "wang", "meng", "manager", 28);
    deallocatePerson(&person);
    printf("实例方法：结构体初始化成功并释放了内部指针\n");
    //指针方法
    Person* ptrPerson;
    ptrPerson = (Person*)malloc(sizeof(Person));
    initializePerson(ptrPerson, "melon", "wm", "boss", 30);
    deallocatePerson(ptrPerson);
    free(ptrPerson);
    printf("指针方法：结构图初始化成功并释放了内部指针以及结构体本身指针\n");
}

/************************************************************
**************************链表********************************
************************************************************/

typedef struct _emplyee{
    char name[32];
    unsigned int age;
} Employee;

typedef struct _node{
    void *data;
    struct _node* next;
} Node;

typedef struct _linkedList{
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;

typedef void (*DISPLAY)(void*);//函数指针

typedef int (*COMPARE)(void*,void*);//函数指针

int compareEmployee(Employee* e1,Employee* e2){
    return strcmp(e1->name,e2->name);
}

void displayEmployee(Employee* employee){
    printf("%s\t%d\n",employee->name,employee->age);
}

int main01(void) {
    // int (*fptr1)(int);
    // int n=5;
    // fptr1=square;
    // printf("%d\n",fptr1(n));
    // printf("%d\n",compute(add, 5, 6));
    // printf("%d\n",compute(subtract, 5, 6));
    // printf("%d\n",evaluate('+', 5, 6));
    // printf("%d\n",evaluate('-', 5, 6));
    // int vector[5]={1,2,3,4,5};
    // int* pv=vector;
    // int* pv=(int*)malloc(5*sizeof(int));
    // for(int i =0;i<5,i++){
    //     pv[i]=i+1;
    // }
    // for(int i=0;i<5;i++){
    //     *(pv+i)=i+1;
    // }
    // free(pv);//malloc是从堆上分配内存，用完释放并且最好指向null
    // pv=NULL;
    // int vector[5]={1,2,3,4,5};
    // displayArray(vector, 5);

    //数组指针
    // int* arr[5];
    // for(int i=0;i<5;i++){
    //     arr[i]=(int*)malloc(sizeof(int));//指针数组就是一个 数组，里面存的都是地址，每个地址的首地址在for循环里开辟
    //     *arr[i]=i;
    //     printf("%d\n",*arr[i]);
    // }
    // int matrix[2][5]={{1,2,3,4,5},{6,7,8,9,10}};//按行-列存储
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<5;j++){
    //         printf("%d\n",matrix[i][j]);
    //     }
    // }
    // //数组指针
    // int (*pmatrix)[5]=matrix;//声明了一个数组指针，如果括号去掉就是一个数组，数组里有5哥int型的指针
    // printf("%p\n",matrix);
    // printf("%p\n",matrix+1);
    // printf("%d\n",*(matrix[0]+1));
    // printf("%d\n",*(pmatrix)+1);//数组指针+1就是跨越整个二维数组了
    // dispaly2DArray(matrix, 2);
    // dispaly2DArrayUnknownSize((int*)matrix, sizeof(matrix)/sizeof(matrix[0]), sizeof(matrix[0])/sizeof(matrix[0][0]));
    // struct _Person{
    //     char* firstname;
    //     char* lastname;
    //     char* title;
    //     unsigned int age;
    // };
    //创建结构体实例
    // Person person;
    //申明Person指针
    // Person* ptrPerson;
    // ptrPerson = (Person*)malloc(sizeof(Person));
    // person.age=18;
    // ptrPerson->firstname="wang";
    // printf("%s",ptrPerson->firstname);
    // processPerson();
    // initializeList();
    // Person *ptrPerson;
    // ptrPerson = getPerson();
    // initializePerson(ptrPerson, "zhang", "si", "ceo", 40);
    // printf("%d\n",ptrPerson->age);
    // returnPerson(ptrPerson);
    return 0;
}