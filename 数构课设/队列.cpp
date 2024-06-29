#include <stdio.h>
#include <stdlib.h>

//结点定义
typedef struct node{ 
    int data;
    struct node *next;
} node;

//队列定义，队首指针和队尾指针
typedef struct queue{ 
    node *front; //头指针 
    node *rear; //尾指针
} Queue1;

//初始化队列
void initQueue(Queue1 *q){
    q->front = q->rear = NULL;
}

//判断队列是否为空
int isEmpty(Queue1 *q){
    return q->front == NULL;
}

//入列
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

//出列
int deQueue(Queue1 *q){
    if(isEmpty(q)){
        printf("队列为空，无法出列！\n");
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

//取队头元素
int getFront(Queue1 *q){
    if(isEmpty(q)){
        printf("队列为空，无法取队头元素！\n");
        return -1;
    }
    return q->front->data;
}

//取队尾元素
int getRear(Queue1 *q){
    if(isEmpty(q)){
        printf("队列为空，无法取队尾元素！\n");
        return -1;
    }
    return q->rear->data;
}

//队列应用
void queueApplication(){
    Queue1 q;
    initQueue(&q);
    int n, data;
    do{
        printf("\n");
        printf("*************队列的基本操作及应用**************\n");
        printf("* 1  入列                                     *\n");
        printf("* 2  出列                                     *\n");
        printf("* 3  取队头元素                               *\n");
        printf("* 4  取队尾元素                               *\n");
        printf("* 5  应用                                     *\n");
        printf("* 6  退出                                     *\n");
        printf("***********************************************\n");
        printf("请选择：");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("请输入要入列的元素：");
                scanf("%d", &data);
                enQueue(&q, data);
                printf("入列成功！\n");
                break;
            case 2:
                data = deQueue(&q);
                if(data != -1){
                    printf("出列成功，出列元素为：%d\n", data);
                }
                break;
            case 3:
                data = getFront(&q);
                if(data != -1){
                    printf("队头元素为：%d\n", data);
                }
                break;
            case 4:
                data = getRear(&q);
                if(data != -1){
                    printf("队尾元素为：%d\n", data);
                }
                break;
            case 5:
                printf("队列中的元素为：");
                while(!isEmpty(&q)){
                    printf("%d ", deQueue(&q));
                }
                printf("\n");
                break;
            case 6:
                break;
            default:
                printf("输入错误，请重新输入！\n");
                break;
        }
    }while(n!=6);
}

int main()
{
    queueApplication();
    return 0;
}
