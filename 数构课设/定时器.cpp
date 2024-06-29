#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKS 100

typedef struct 
{
    time_t time; // time_t time：表示任务执行的时间点，time_t是C语言中的时间类型
    void (*func)(void); // void (*func)(void)：表示一个函数指针，指向一个无返回值、无参数的函数。这个函数指针可以指向任何符合这个条件的函数，用于表示任务需要执行的函数
} Work;

Work works[MAX_WORKS];
int num_works = 0;//初始化任务数量为0 

void add_work(time_t time, void (*func)(void)) 
{
    if (num_works >= MAX_WORKS) {
        printf("任务量过多！\n");
        return;
    }
    works[num_works].time = time;//将works数组中下标为num_works的元素的time成员赋值为time参数
    works[num_works].func = func;//将works数组中下标为num_works的元素的func成员赋值为func参数
    num_works++;//任务数量+1 
}

void run_works() 
{
    time_t now = time(NULL);
    while (num_works > 0 && works[0].time <= now) 
	{
        Work work = works[0];
        work.func();
        // 删除堆中的根节点
        num_works--;
        works[0] = works[num_works];
        int i = 0;
        while (i * 2 + 1 < num_works) 
		{
            int c = i * 2 + 1;//左子节点 
            if (c + 1 < num_works && works[c + 1].time < works[c].time) //判断其右子节点是否存在，如果存在且右子节点的时间比左子节点的时间更小，则将c更新为右子节点的下标
			{
                c++;
            }
            if (works[c].time < works[i].time) //如果当前节点i的时间比其子节点中最小的那个还要大，则将它与子节点中最小的那个交换位置
			{
                Work temp = works[i];
                works[i] = works[c];
                works[c] = temp;
                i = c;
            } else {
                break;
            }
        }
    }
}

void work1() {
    printf("Work 1 开始工作！\n");
}

void work2() {
    printf("Work 2 开始工作！\n");   
}

void work3() {
    printf("Work 3 开始工作！\n");   
}

int main() {
    add_work(time(NULL) + 5, work1);
    add_work(time(NULL) + 10, work2);
    add_work(time(NULL) + 15, work3);
    while (1) {
        run_works();
        // 等待1秒
        struct timespec ts = {1, 0};//struct timespec 一个结构体，用来表示时间的秒数和纳秒数  ts 被初始化为1秒0纳秒
        nanosleep(&ts, NULL);//实现程序暂停一段时间的功能
    }
    return 0;
}
