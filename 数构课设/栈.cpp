#include <stdio.h>
#define MAXSIZE 100

int stack[MAXSIZE]; // ����ջ
int top = -1; // ջ��ָ���ʼ��Ϊ-1

// ��ջ����
void push(int x){
    if(top == MAXSIZE-1){
        printf("ջ�������޷���ջ��\n");
        return;
    }
    stack[++top] = x;
    printf("�ɹ���ջ��%d\n", x);
}

// ��ջ����
void pop(){
    if(top == -1){
        printf("ջ�ѿգ��޷���ջ��\n");
        return;
    }
    printf("�ɹ���ջ��%d\n", stack[top--]);
}

// ȡջ��Ԫ��
void getTop(){
    if(top == -1){
        printf("ջΪ�գ�\n");
        return;
    }
    printf("ջ��Ԫ��Ϊ��%d\n", stack[top]);
}

// Ӧ��
// ջ��Ӧ�ã�����ģʽƥ��
void application()
{
	printf("�˴�ΪӦ�ã�\n");
}
    
// ջ�Ļ��������˵�
void Stack(){ 
    int n;
    do{
        printf("\n");
        printf("****************ջ�Ļ���������Ӧ��*****************\n");
        printf("* 1  ��ջ                                         *\n");
        printf("* 2  ��ջ                                         *\n");
        printf("* 3  ȡջ��Ԫ��                                   *\n");
        printf("* 4  Ӧ��                                         *\n");
        printf("* 5  �˳�                                         *\n");
        printf("***************************************************\n");
        printf("��ѡ��");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("������Ҫ��ջ��Ԫ�أ�");
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
                printf("�������������ѡ��\n");
                break;
        }
    }while(n!=5);
}

int main(){
    Stack();
    return 0;
}
