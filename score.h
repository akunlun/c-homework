/*************************************************
* Head File   : SCORE.h
* File Usage  : ѧ������ϵͳͷ�ļ�
/**************************************************/

#ifndef __SCORE_H__
#define __SCORE_H__


#include <stdio.h>

/*----------------------------------*
	Function Declaration
*-----------------------------------*/

typedef struct student
{
	int number;  //ѧ��
	char name[10];    //����
	float dailyScore;   //ƽʱ�ɼ�
	float experScore;   //ʵ��ɼ�
	float finalScore;   //��ĩ�ɼ�
	float generalScore; //�����ɼ�

}SS;


/*---------------��������-------------------*/

//1.��ȡѧ����������
void readData(SS stu[], int N);
SS* readDataFromFile(int *N);

//2.����N��ѧ�������ܳɼ�
void calcuScore(SS stu[], int N);


//3.���������ɼ�����
void sortScore(SS stu[], int N);


//4.����һ���ĸ�ʽ���N��ѧ����������Ϣ
void printOut(SS stu[], int N);

//5.����ѧ�ſɲ�ѯĳ��ѧ���ĳɼ���Ϣ
void inputNum(SS stu[],int N);

//6.ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����
void anaScore(SS stu[],int N);

#endif