#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
typedef struct Node {
    int data;           // ������
    struct Node *next;  // ָ����
} Node, *LinkList;

// ��������
LinkList createList() {
    int n, data;
    printf("�����������ȣ�");
    scanf("%d", &n);
    LinkList head = (LinkList)malloc(sizeof(Node));  // ����ͷ�ڵ�
    head->next = NULL;
    LinkList tail = head;  // ����βָ��
    for (int i = 0; i < n; i++) {
        printf("�������%d���ڵ��ֵ��", i + 1);
        scanf("%d", &data);
        LinkList newNode = (LinkList)malloc(sizeof(Node));  // �����½ڵ�
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode;  // ���½ڵ���뵽����β��
        tail = newNode;        // ����βָ��
    }
    return head;
}

// ����Ԫ��
void insertNode(LinkList head) {
    int pos, data;
    printf("������Ҫ�����λ�ã�");
    scanf("%d", &pos);
    printf("������Ҫ�����ֵ��");
    scanf("%d", &data);
    LinkList p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;  // �ҵ�Ҫ����λ�õ�ǰһ���ڵ�
        if (p == NULL) {
            printf("����λ����Ч��\n");
            return;
        }
    }
    LinkList newNode = (LinkList)malloc(sizeof(Node));  // �����½ڵ�
    newNode->data = data;
    newNode->next = p->next;  // ���½ڵ���뵽������
    p->next = newNode;
    printf("����ɹ���\n");
}

// ɾ��Ԫ��
void deleteNode(LinkList head) {
    int pos;
    printf("������Ҫɾ����λ�ã�");
    scanf("%d", &pos);
    LinkList p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;  // �ҵ�Ҫɾ��λ�õ�ǰһ���ڵ�
        if (p == NULL || p->next == NULL) {
            printf("ɾ��λ����Ч��\n");
            return;
        }
    }
    LinkList q = p->next;  // ����Ҫɾ���Ľڵ�
    p->next = q->next;     // ��Ҫɾ���Ľڵ��������ɾ��
    free(q);
    printf("ɾ���ɹ���\n");
}

// ����Ԫ��
void searchNode(LinkList head) {
    int data;
    printf("������Ҫ���ҵ�ֵ��");
    scanf("%d", &data);
    LinkList p = head->next;
    int pos = 1;
    while (p != NULL && p->data != data) {
        p = p->next;
        pos++;
    }
    if (p == NULL) {
        printf("δ�ҵ���Ԫ�أ�\n");
    } else {
        printf("��Ԫ���������е�λ��Ϊ��%d\n", pos);
    }
}

// Ӧ��
//���������ת�� 
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


// ������
int main() {
    int n;
    LinkList head = NULL;
    do {
        printf("\n");
        printf("**************���Ա�Ļ���������Ӧ��***************\n");
        printf("* 1  ����                                         *\n");
        printf("* 2  ����                                         *\n");
        printf("* 3  ɾ��                                         *\n");
        printf("* 4  ����                                         *\n");
        printf("* 5  Ӧ��                                         *\n");
        printf("* 6  �˳�                                         *\n");
        printf("***************************************************\n");
        printf("��ѡ��");
        scanf("%d", &n);
        switch (n) {
            case 1:
                head = createList();
                printf("�����ɹ���\n");
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
