   #include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *lchild, *rchild;
}Node, *BiTree;

// ����������
void createBiTree(BiTree *T){
    char ch;
    scanf("%c", &ch);
    if(ch == '#'){
        *T = NULL;
    }
    else{
        *T = (Node*)malloc(sizeof(Node));
        (*T)->data = ch;
        createBiTree(&((*T)->lchild));
        createBiTree(&((*T)->rchild));//������������� 
    }
}

// �������
void preOrder(BiTree T){
    if(T){
        printf("%c ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

// �������
void inOrder(BiTree T){
    if(T){
        inOrder(T->lchild);
        printf("%c ", T->data);
        inOrder(T->rchild);
    }
}

// �������
void postOrder(BiTree T){
    if(T){
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c ", T->data);
    }
}

// ����˫��
void findParent(BiTree T, char x){
    if(T){
        if(T->lchild && T->lchild->data == x || T->rchild && T->rchild->data == x){
            printf("%c��˫����%c\n", x, T->data);
        }
        else{
            findParent(T->lchild, x);
            findParent(T->rchild, x);
        }
    }
}

// �����ֵ�
void findSibling(BiTree T, char x){
    if(T){
        if(T->lchild && T->rchild){
            if(T->lchild->data == x){
                printf("%c���ֵ���%c\n", x, T->rchild->data);
            }
            else if(T->rchild->data == x){
                printf("%c���ֵ���%c\n", x, T->lchild->data);
            }
            else{
                findSibling(T->lchild, x);
                findSibling(T->rchild, x);
            }
        }
        else{
            printf("%cû���ֵ�\n", x);
        }
    }
}

// ���Һ���
void findChild(BiTree T, char x){
    if(T){
        if(T->data == x){
            if(T->lchild){
                printf("%c��������%c\n", x, T->lchild->data);
            }
            if(T->rchild){
                printf("%c���Һ�����%c\n", x, T->rchild->data);
            }
        }
        else{
            findChild(T->lchild, x);
            findChild(T->rchild, x);
        }
    }
}

int main(){
    BiTree T = NULL;
    int n;
    do{
        printf("\n");
        printf("**************�������Ļ���������Ӧ��***************\n");
        printf("* 1  ����                                         *\n");
        printf("* 2  ��������/��/��                             *\n");
        printf("* 3  ����˫��                                     *\n");
        printf("* 4  �����ֵܣ���/�ң�                            *\n");
        printf("* 5  ���Һ��ӣ���/�ң�                            *\n");
        printf("* 6  Ӧ��                                         *\n");
        printf("* 7  �˳�                                         *\n");
        printf("***************************************************\n");
        printf("��ѡ��");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("�����������������������У�\n");
                getchar(); // �Ե����뻺�����еĻس���
                createBiTree(&T);
                break;
            case 2:
                printf("����������Ϊ��");
                preOrder(T);
                printf("\n����������Ϊ��");
                inOrder(T);
                printf("\n����������Ϊ��");
                postOrder(T);
                printf("\n");
                break;
            case 3:
                printf("������Ҫ����˫�׵Ľڵ㣺");
                char x;
                getchar(); // �Ե����뻺�����еĻس���
                scanf("%c", &x);
                findParent(T, x);
                break;
            case 4:
                printf("������Ҫ�����ֵܵĽڵ㣺");
                getchar(); // �Ե����뻺�����еĻس���
                scanf("%c", &x);
                findSibling(T, x);
                break;
            case 5:
                printf("������Ҫ���Һ��ӵĽڵ㣺");
                getchar(); // �Ե����뻺�����еĻس���
                scanf("%c", &x);
                findChild(T, x);
                break;
            case 6:
                printf("---------Ӧ��-------");
                break;
            case 7:
                break;
            default:
                printf("ERROR!");
                break;
        }
    }while(n!=7);
    return 0;
}

