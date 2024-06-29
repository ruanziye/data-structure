#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKS 100

typedef struct 
{
    time_t time; // time_t time����ʾ����ִ�е�ʱ��㣬time_t��C�����е�ʱ������
    void (*func)(void); // void (*func)(void)����ʾһ������ָ�룬ָ��һ���޷���ֵ���޲����ĺ������������ָ�����ָ���κη�����������ĺ��������ڱ�ʾ������Ҫִ�еĺ���
} Work;

Work works[MAX_WORKS];
int num_works = 0;//��ʼ����������Ϊ0 

void add_work(time_t time, void (*func)(void)) 
{
    if (num_works >= MAX_WORKS) {
        printf("���������࣡\n");
        return;
    }
    works[num_works].time = time;//��works�������±�Ϊnum_works��Ԫ�ص�time��Ա��ֵΪtime����
    works[num_works].func = func;//��works�������±�Ϊnum_works��Ԫ�ص�func��Ա��ֵΪfunc����
    num_works++;//��������+1 
}

void run_works() 
{
    time_t now = time(NULL);
    while (num_works > 0 && works[0].time <= now) 
	{
        Work work = works[0];
        work.func();
        // ɾ�����еĸ��ڵ�
        num_works--;
        works[0] = works[num_works];
        int i = 0;
        while (i * 2 + 1 < num_works) 
		{
            int c = i * 2 + 1;//���ӽڵ� 
            if (c + 1 < num_works && works[c + 1].time < works[c].time) //�ж������ӽڵ��Ƿ���ڣ�������������ӽڵ��ʱ������ӽڵ��ʱ���С����c����Ϊ���ӽڵ���±�
			{
                c++;
            }
            if (works[c].time < works[i].time) //�����ǰ�ڵ�i��ʱ������ӽڵ�����С���Ǹ���Ҫ���������ӽڵ�����С���Ǹ�����λ��
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
    printf("Work 1 ��ʼ������\n");
}

void work2() {
    printf("Work 2 ��ʼ������\n");   
}

void work3() {
    printf("Work 3 ��ʼ������\n");   
}

int main() {
    add_work(time(NULL) + 5, work1);
    add_work(time(NULL) + 10, work2);
    add_work(time(NULL) + 15, work3);
    while (1) {
        run_works();
        // �ȴ�1��
        struct timespec ts = {1, 0};//struct timespec һ���ṹ�壬������ʾʱ���������������  ts ����ʼ��Ϊ1��0����
        nanosleep(&ts, NULL);//ʵ�ֳ�����ͣһ��ʱ��Ĺ���
    }
    return 0;
}
