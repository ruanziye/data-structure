#include <stdio.h>
#define MAXSIZE 100

int stack[MAXSIZE]; // 定义栈
int top = -1; // 栈顶指针初始化为-1

// 进栈操作
void push(int x){
    if(top == MAXSIZE-1){
        printf("栈已满，无法进栈！\n");
        return;
    }
    stack[++top] = x;
    printf("成功进栈：%d\n", x);
}

// 出栈操作
void pop(){
    if(top == -1){
        printf("栈已空，无法出栈！\n");
        return;
    }
    printf("成功出栈：%d\n", stack[top--]);
}

// 取栈顶元素
void getTop(){
    if(top == -1){
        printf("栈为空！\n");
        return;
    }
    printf("栈顶元素为：%d\n", stack[top]);
}

// 应用
// 栈的应用：括号模式匹配
void application()
{
	printf("此处为应用！\n");
}
    
// 栈的基本操作菜单
void Stack(){ 
    int n;
    do{
        printf("\n");
        printf("****************栈的基本操作及应用*****************\n");
        printf("* 1  进栈                                         *\n");
        printf("* 2  出栈                                         *\n");
        printf("* 3  取栈顶元素                                   *\n");
        printf("* 4  应用                                         *\n");
        printf("* 5  退出                                         *\n");
        printf("***************************************************\n");
        printf("请选择：");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("请输入要进栈的元素：");
                int x;
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                getTop();
                break;
            case 4:
                application();
                break;
            case 5:
                break;
            default:
                printf("输入错误，请重新选择！\n");
                break;
        }
    }while(n!=5);
}

int main(){
    Stack();
    return 0;
}
