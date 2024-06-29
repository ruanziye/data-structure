#include <stdio.h>
#include <stdlib.h>

#define maxsize 100

typedef struct 
{
    char information[maxsize];
    int top;
}stack;

void init(stack *s) 
{
    s->top = -1;
}

int Empty(stack *s) 
{
    return s->top == -1;
}

int Full(stack *s) 
{
    return s->top == maxsize - 1;
}

void push(stack *s, int x) 
{
    if (Full(s)) {
        printf("页面存储最大数量已满！\n");
        return;
    }
    s->information[++s->top] = x;//top表示栈顶元素的下标，那么++s->top表示先将栈顶指针top加1，然后返回新的栈顶指针
}

int pop(stack *s) 
{
    if (Empty(s)) 
	{
        printf("当前页面数为空！\n");
        return 1;
    }
    return s->information[s->top--];//s->top-- ：将栈顶元素的下标减1，表示弹出栈顶元素
                                    //根据栈顶元素的下标，获取栈顶元素的值
}

int main() 
{
    stack back, forward;
    char now_page = 0;//用于存储当前页面的编号
    init(&back);
    init(&forward);
    push(&back, now_page);//调用 init 函数初始化 back 和 forward 栈，并将当前页面编号 push 到 back 栈中

    while (1) 
	{
        printf("当前页面: %s\n", &now_page);
        printf("1. 页面回退\n"); 
        printf("2. 页面前进\n");
        printf("3. 访问一个新页面\n");
        printf("4. 退出\n");
        int n;
        scanf("%d", &n);
        switch (n) 
		{
            case 1:
                if (!Empty(&back)) 
				{
                    push(&forward, now_page);//把现在浏览的页面压到前进栈里面 
                    now_page = pop(&back);//把后退栈里的栈顶元素弹出来当作当前页面 
                }
                break;
            case 2:
                if (!Empty(&forward)) 
				{
                    push(&back, now_page);//把现在浏览的页面压到后退栈里面 
                    now_page = pop(&forward);//把前进栈里的栈顶元素弹出来当作当前页面
                    
                }
                break;
            case 3:
                push(&back, now_page);//把现在浏览的页面压到后退栈里面
                printf("请输入新页面编号: ");
                scanf("%s", &now_page);
                while (!Empty(&forward))//清空前进栈 
				{
                    pop(&forward);
                }
                break;
            case 4:
                return 0;
            default:
                printf("选择无效！\n");
        }
    }

    return 0;
}
