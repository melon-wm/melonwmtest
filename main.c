#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct {
    unsigned int age;
}xiaoxuesheng;

typedef struct {
    unsigned int age;
    xiaoxuesheng wuxuhan;
}xuesheng;

typedef struct _employee{
    char name[32];
    unsigned int age;
}Employee;

int compareEmployee(Employee* e1,Employee* e2){
    return strcmp(e1->name,e2->name);
}

void displayEmployee(Employee* employee){
    printf("%s\t%d\n",employee->name,employee->age);
}

//函数指针
typedef void (*DISPLAY)(void*);
typedef int (*COMPARE)(void*,void*);

typedef struct _jiedian{
    void* data;
    struct _jiedian* next//下一个节点的地址
} Jiedian;

typedef struct _lianjieliebiao{
    Jiedian* head;
    Jiedian* tail;
    Jiedian* current;
} Lianjieliiebiao;


void initializeList(Lianjieliiebiao*);                   // 初始化列表
void addHead(Lianjieliiebiao*,void*);                    //给链表的头节点添加数据
void addTail(Lianjieliiebiao*,void*);                    //给链表的尾节点添加数据
void delete(Lianjieliiebiao*,Jiedian*);                  //从链表删除节点
Jiedian* getJiedian(Lianjieliiebiao*,COMPARE,void*);     //返回包含指定数据的节点指针
void displayLianjieliebiao(Lianjieliiebiao*,DISPLAY);    //打印链表

void initializeList(Lianjieliiebiao* list){
    list->head=NULL;
    list->tail=NULL;
    list->current=NULL;
}

void addHead(Lianjieliiebiao* list,void* data){
    Jiedian* jiedian=(Jiedian*) malloc(sizeof(Jiedian));
    jiedian->data=data;
    if(list->head==NULL){
        list->tail=jiedian;
        jiedian->next=NULL;
    } else{
        jiedian->next=list->head;
    }
    list->head=jiedian;
}

int *dowork() {
    int a = 10;
    int *p = &a;
    return p;
}

void test01() {
    char *p = NULL;
    double *m = NULL;
    printf("%d\n", p);
    printf("%d\n", p + 1);
    printf("%d\n", m);
    printf("%d\n", m + 1);
}

void test02() {
    char buf[1024] = {0};
    int a = 1000;
    memcpy(buf + 1, &a, sizeof(int));
    char *p = buf;
    printf("%d", *(int *) (p + 1));
}

void func(char *p) {
    strcpy(p, "hello world");
}

void test03() {
    //在栈上分配内存
    char buf[1024] = {0};
    func(buf);
    printf("%s\n", buf);
}

void printString(char *str) {
    printf("%s", str);
}

void test04() {
    //在堆区域分配内存
    char *p = malloc(sizeof(char) * 64);
    memset(p, 0, 64);
    strcpy(p, "hello world");
    //在被调函数种，输出hello world
    printString(p);
    free(p);
    p = NULL;
}

void allocateSpace(char **p) {
    char *tmp = malloc(sizeof(char) * 64);
    memset(tmp, 0, 64);
    strcpy(tmp, "hello c");
    *p = tmp;
}

void test05() {
    char *p = NULL;
    allocateSpace(&p);
    printf("%s", p);
}

void test06() {
    char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", str);
    char str1[] = "hello";
    printf("%d\n", sizeof(str1));//默认计算'\0'
    printf("%d\n", strlen(str1));
    char str2[] = "hello\0world";
    printf("%s\n", str2);
    printf("%d\n", sizeof(str2));
    printf("%d\n", strlen(str2));
    char str3[] = "hello\012world";//\012代表8进制数字，转化为十进制为10，代表换行
    printf("%s\n", str3);
    printf("%d\n", sizeof(str3));
    printf("%d\n", strlen(str3));
}

int main() {
    /*****************一：野指针与空指针************/
    //野指针三种情况
    //情况1：申明未初始化指针
    //int* p;

    //情况2：malloc后free的指针
//    int* p=malloc(sizeof(int));
//    *p=100;
//    printf("%d\n",*p);
//    free(p);
//    printf("%d\n",*p);
//    *p=1000;//不要这样操作，有概率会出错
//    printf("%d\n",*p);

    //情况3：指针变量超出作用域
//      int *p2=dowork();
//      printf("%d\n",*p2);
//      printf("%d\n",*p2);
    //空指针可以重复释放，野指针不可以重复释放

    /********二：指针步长**************************/
    //1.指针变量+1后跳跃的字节数
    //test01();
    //2.在解引时，取出的字节数
    //test02();

    /********三：指针的意义——————间接赋值************/
//    int a=10;
//    int* p=&a;
//    *p=1000;
//
    /********四：指针作为函数参数********************/
    //作为输入，在主调函数分配内存，在被调函数使用
    //test03();
    //test04();
    //作为输出，在被调函数分配内存
    //test05();
    /********五：字符串指针强化*********************/
    //test06();
    /*xuesheng* ptr=(xuesheng*) malloc(sizeof(xuesheng));
    ptr->wuxuhan.age=18;
    printf("%d\n",ptr->wuxuhan.age);*/
    /*******六：链表******************************/
    Lianjieliiebiao lianjieliiebiao;

    Employee* samuel=(Employee*)malloc(sizeof(Employee));
    strcpy(samuel->name,"Susan");
    samuel->age=32;

    Employee* sally=(Employee*)malloc(sizeof(Employee));
    strcpy(sally->name,"Sally");
    sally->age=28;

    Employee* susan=(Employee*)malloc(sizeof(Employee));
    strcpy(susan->name,"Susan");
    susan->age=45;

    initializeList(&lianjieliiebiao);
    addHead(&lianjieliiebiao,samuel);
    addHead(&lianjieliiebiao,sally);
    addHead(&lianjieliiebiao,susan);

    return 0;
}
