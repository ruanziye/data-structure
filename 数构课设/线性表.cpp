#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;           // 数据域
    struct Node *next;  // 指针域
} Node, *LinkList;

// 创建链表
LinkList createList() {
    int n, data;
    printf("请输入链表长度：");
    scanf("%d", &n);
    LinkList head = (LinkList)malloc(sizeof(Node));  // 创建头节点
    head->next = NULL;
    LinkList tail = head;  // 定义尾指针
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个节点的值：", i + 1);
        scanf("%d", &data);
        LinkList newNode = (LinkList)malloc(sizeof(Node));  // 创建新节点
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode;  // 将新节点插入到链表尾部
        tail = newNode;        // 更新尾指针
    }
    return head;
}

// 插入元素
void insertNode(LinkList head) {
    int pos, data;
    printf("请输入要插入的位置：");
    scanf("%d", &pos);
    printf("请输入要插入的值：");
    scanf("%d", &data);
    LinkList p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;  // 找到要插入位置的前一个节点
        if (p == NULL) {
            printf("插入位置无效！\n");
            return;
        }
    }
    LinkList newNode = (LinkList)malloc(sizeof(Node));  // 创建新节点
    newNode->data = data;
    newNode->next = p->next;  // 将新节点插入到链表中
    p->next = newNode;
    printf("插入成功！\n");
}

// 删除元素
void deleteNode(LinkList head) {
    int pos;
    printf("请输入要删除的位置：");
    scanf("%d", &pos);
    LinkList p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;  // 找到要删除位置的前一个节点
        if (p == NULL || p->next == NULL) {
            printf("删除位置无效！\n");
            return;
        }
    }
    LinkList q = p->next;  // 定义要删除的节点
    p->next = q->next;     // 将要删除的节点从链表中删除
    free(q);
    printf("删除成功！\n");
}

// 查找元素
void searchNode(LinkList head) {
    int data;
    printf("请输入要查找的值：");
    scanf("%d", &data);
    LinkList p = head->next;
    int pos = 1;
    while (p != NULL && p->data != data) {
        p = p->next;
        pos++;
    }
    if (p == NULL) {
        printf("未找到该元素！\n");
    } else {
        printf("该元素在链表中的位置为：%d\n", pos);
    }
}

// 应用
//单链表的逆转置 
void reverse(LinkList head)
{
	Node *p,*q;
	p=head->next;
	head->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q->next=head->next;
		head->next=q;
	}
} 


// 主函数
int main() {
    int n;
    LinkList head = NULL;
    do {
        printf("\n");
        printf("**************线性表的基本操作及应用***************\n");
        printf("* 1  创建                                         *\n");
        printf("* 2  插入                                         *\n");
        printf("* 3  删除                                         *\n");
        printf("* 4  查找                                         *\n");
        printf("* 5  应用                                         *\n");
        printf("* 6  退出                                         *\n");
        printf("***************************************************\n");
        printf("请选择：");
        scanf("%d", &n);
        switch (n) {
            case 1:
                head = createList();
                printf("创建成功！\n");
                break;
            case 2:
                insertNode(head);
                break;
            case 3:
                deleteNode(head);
                break;
            case 4:
                searchNode(head);
                break;
            case 5:
                reverse(head);
                break;
            case 6:
                break;
            default:
                printf("ERROR!\n");
                break;
        }
    } while (n != 6);
    return 0;
}
