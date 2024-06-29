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
        printf("ҳ��洢�������������\n");
        return;
    }
    s->information[++s->top] = x;//top��ʾջ��Ԫ�ص��±꣬��ô++s->top��ʾ�Ƚ�ջ��ָ��top��1��Ȼ�󷵻��µ�ջ��ָ��
}

int pop(stack *s) 
{
    if (Empty(s)) 
	{
        printf("��ǰҳ����Ϊ�գ�\n");
        return 1;
    }
    return s->information[s->top--];//s->top-- ����ջ��Ԫ�ص��±��1����ʾ����ջ��Ԫ��
                                    //����ջ��Ԫ�ص��±꣬��ȡջ��Ԫ�ص�ֵ
}

int main() 
{
    stack back, forward;
    char now_page = 0;//���ڴ洢��ǰҳ��ı��
    init(&back);
    init(&forward);
    push(&back, now_page);//���� init ������ʼ�� back �� forward ջ��������ǰҳ���� push �� back ջ��

    while (1) 
	{
        printf("��ǰҳ��: %s\n", &now_page);
        printf("1. ҳ�����\n"); 
        printf("2. ҳ��ǰ��\n");
        printf("3. ����һ����ҳ��\n");
        printf("4. �˳�\n");
        int n;
        scanf("%d", &n);
        switch (n) 
		{
            case 1:
                if (!Empty(&back)) 
				{
                    push(&forward, now_page);//�����������ҳ��ѹ��ǰ��ջ���� 
                    now_page = pop(&back);//�Ѻ���ջ���ջ��Ԫ�ص�����������ǰҳ�� 
                }
                break;
            case 2:
                if (!Empty(&forward)) 
				{
                    push(&back, now_page);//�����������ҳ��ѹ������ջ���� 
                    now_page = pop(&forward);//��ǰ��ջ���ջ��Ԫ�ص�����������ǰҳ��
                    
                }
                break;
            case 3:
                push(&back, now_page);//�����������ҳ��ѹ������ջ����
                printf("��������ҳ����: ");
                scanf("%s", &now_page);
                while (!Empty(&forward))//���ǰ��ջ 
				{
                    pop(&forward);
                }
                break;
            case 4:
                return 0;
            default:
                printf("ѡ����Ч��\n");
        }
    }

    return 0;
}
