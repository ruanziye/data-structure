#include <stdio.h>
#include <stdlib.h>

//��㶨��
typedef struct node{ 
    int data;
    struct node *next;
} node;

//���ж��壬����ָ��Ͷ�βָ��
typedef struct queue{ 
    node *front; //ͷָ�� 
    node *rear; //βָ��
} Queue1;

//��ʼ������
void initQueue(Queue1 *q){
    q->front = q->rear = NULL;
}

//�ж϶����Ƿ�Ϊ��
int isEmpty(Queue1 *q){
    return q->front == NULL;
}

//����
void enQueue(Queue1 *q, int data){
    node *p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    if(q->rear == NULL){
        q->front = q->rear = p;
    }else{
        q->rear->next = p;
        q->rear = p;
    }
}

//����
int deQueue(Queue1 *q){
    if(isEmpty(q)){
        printf("����Ϊ�գ��޷����У�\n");
        return -1;
    }
    node *p = q->front;
    int data = p->data;
    q->front = p->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(p);
    return data;
}

//ȡ��ͷԪ��
int getFront(Queue1 *q){
    if(isEmpty(q)){
        printf("����Ϊ�գ��޷�ȡ��ͷԪ�أ�\n");
        return -1;
    }
    return q->front->data;
}

//ȡ��βԪ��
int getRear(Queue1 *q){
    if(isEmpty(q)){
        printf("����Ϊ�գ��޷�ȡ��βԪ�أ�\n");
        return -1;
    }
    return q->rear->data;
}

//����Ӧ��
void queueApplication(){
    Queue1 q;
    initQueue(&q);
    int n, data;
    do{
        printf("\n");
        printf("*************���еĻ���������Ӧ��**************\n");
        printf("* 1  ����                                     *\n");
        printf("* 2  ����                                     *\n");
        printf("* 3  ȡ��ͷԪ��                               *\n");
        printf("* 4  ȡ��βԪ��                               *\n");
        printf("* 5  Ӧ��                                     *\n");
        printf("* 6  �˳�                                     *\n");
        printf("***********************************************\n");
        printf("��ѡ��");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("������Ҫ���е�Ԫ�أ�");
                scanf("%d", &data);
                enQueue(&q, data);
                printf("���гɹ���\n");
                break;
            case 2:
                data = deQueue(&q);
                if(data != -1){
                    printf("���гɹ�������Ԫ��Ϊ��%d\n", data);
                }
                break;
            case 3:
                data = getFront(&q);
                if(data != -1){
                    printf("��ͷԪ��Ϊ��%d\n", data);
                }
                break;
            case 4:
                data = getRear(&q);
                if(data != -1){
                    printf("��βԪ��Ϊ��%d\n", data);
                }
                break;
            case 5:
                printf("�����е�Ԫ��Ϊ��");
                while(!isEmpty(&q)){
                    printf("%d ", deQueue(&q));
                }
                printf("\n");
                break;
            case 6:
                break;
            default:
                printf("����������������룡\n");
                break;
        }
    }while(n!=6);
}

int main()
{
    queueApplication();
    return 0;
}
