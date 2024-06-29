   #include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *lchild, *rchild;
}Node, *BiTree;

// 创建二叉树
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
        createBiTree(&((*T)->rchild));//按先序遍历输入 
    }
}

// 先序遍历
void preOrder(BiTree T){
    if(T){
        printf("%c ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

// 中序遍历
void inOrder(BiTree T){
    if(T){
        inOrder(T->lchild);
        printf("%c ", T->data);
        inOrder(T->rchild);
    }
}

// 后序遍历
void postOrder(BiTree T){
    if(T){
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c ", T->data);
    }
}

// 查找双亲
void findParent(BiTree T, char x){
    if(T){
        if(T->lchild && T->lchild->data == x || T->rchild && T->rchild->data == x){
            printf("%c的双亲是%c\n", x, T->data);
        }
        else{
            findParent(T->lchild, x);
            findParent(T->rchild, x);
        }
    }
}

// 查找兄弟
void findSibling(BiTree T, char x){
    if(T){
        if(T->lchild && T->rchild){
            if(T->lchild->data == x){
                printf("%c的兄弟是%c\n", x, T->rchild->data);
            }
            else if(T->rchild->data == x){
                printf("%c的兄弟是%c\n", x, T->lchild->data);
            }
            else{
                findSibling(T->lchild, x);
                findSibling(T->rchild, x);
            }
        }
        else{
            printf("%c没有兄弟\n", x);
        }
    }
}

// 查找孩子
void findChild(BiTree T, char x){
    if(T){
        if(T->data == x){
            if(T->lchild){
                printf("%c的左孩子是%c\n", x, T->lchild->data);
            }
            if(T->rchild){
                printf("%c的右孩子是%c\n", x, T->rchild->data);
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
        printf("**************二叉树的基本操作及应用***************\n");
        printf("* 1  创建                                         *\n");
        printf("* 2  遍历（先/中/后）                             *\n");
        printf("* 3  查找双亲                                     *\n");
        printf("* 4  查找兄弟（左/右）                            *\n");
        printf("* 5  查找孩子（左/右）                            *\n");
        printf("* 6  应用                                         *\n");
        printf("* 7  退出                                         *\n");
        printf("***************************************************\n");
        printf("请选择：");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("请输入二叉树的先序遍历序列：\n");
                getchar(); // 吃掉输入缓冲区中的回车符
                createBiTree(&T);
                break;
            case 2:
                printf("先序遍历结果为：");
                preOrder(T);
                printf("\n中序遍历结果为：");
                inOrder(T);
                printf("\n后序遍历结果为：");
                postOrder(T);
                printf("\n");
                break;
            case 3:
                printf("请输入要查找双亲的节点：");
                char x;
                getchar(); // 吃掉输入缓冲区中的回车符
                scanf("%c", &x);
                findParent(T, x);
                break;
            case 4:
                printf("请输入要查找兄弟的节点：");
                getchar(); // 吃掉输入缓冲区中的回车符
                scanf("%c", &x);
                findSibling(T, x);
                break;
            case 5:
                printf("请输入要查找孩子的节点：");
                getchar(); // 吃掉输入缓冲区中的回车符
                scanf("%c", &x);
                findChild(T, x);
                break;
            case 6:
                printf("---------应用-------");
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

