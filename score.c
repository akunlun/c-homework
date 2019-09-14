/*************************************************
** Դ�ļ�   : score.c
** ����˵�� : Function Definitions
** �����汾 : V1.0
/**************************************************/

/*----------------ͷ�ļ�--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"

/*----------------��������-------------*/

//1.1�ֶ�����ѧ����������
void readData(SS stu[], int N)
{

	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,ʵ��ɼ�,��ĩ�ɼ�\n");

	for (int i = 0; i < N; i++)
	{
		printf("��%d��ѧ��:", i + 1);
		scanf("%d %s %f %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].experScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------�ɼ�¼�����!--------\n");

}

//1.2���ļ����ȡѧ����������
SS* readDataFromFile(int *N)
{

	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");

	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.��ȡѧ����Ŀ
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("ѧ����ĿΪ:%d\n", count);


	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS)*2);


	//3.��ȡÿ��ѧ������Ϣ
	while ((!feof(fp)))
	{

		//�����ļ����ݵ��ڴ�	
		fscanf(fp, "%d %s %f %f %f\n", &stu[index].number, &stu[index].name, &stu[index].dailyScore, &stu[index].experScore, &stu[index].finalScore);

		//���������ѧ����Ϣ

		printf("* ѧ�ţ�%d	����:%s		ƽʱ�ɼ���%4.2f��		ʵ��ɼ���%4.2f��		��ĩ�ɼ�:%4.2f��\n", stu[index].number, stu[index].name, stu[index].dailyScore, stu[index].experScore, stu[index].finalScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{


	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.2*stu[i].experScore + 0.6*stu[i].finalScore;
		printf("* ѧ�ţ�%d	����:%s		�ܳɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}

	getchar();
}


//3.���������ɼ�����
int cmpBigtoSmall(const void *a, const void *b)
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);



	if ((*aa).generalScore < (*bb).generalScore)  return 1;

	else if ((*aa).generalScore > (*bb).generalScore)  return -1;

	else
		return 0;

}

void sortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}

//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{

	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("��%d����Ϣ ѧ�ţ�%d	����:%s		�ܳɼ�:%4.2f��\n", i + 1,stu[i].number, &(stu[i].name[0]), stu[i].generalScore);
	}

	getchar();

}

//5.����ѧ�ſɲ�ѯĳ��ѧ���ĳɼ���Ϣ
void inputNum(SS stu[], int N)
{
	printf("\n------���Ĳ�: ����ѧ�Ų�ѯĳ��ѧ���ĳɼ���Ϣ!------\n\n");
	printf("���������������ѧ��: ");
	int n;
	scanf("%d", &n);
	for (int i = 0; i < N; i++)
	{
		if( stu[i].number==n)
		{
			printf("��%d����Ϣ ѧ�ţ�%d	����:%s		�ܳɼ�:%4.2f��\n\n", i + 1, stu[i].number, &(stu[i].name[0]), stu[i].generalScore);
			break;
		}
		else {
			continue;
		}
	}
	getchar();
	getchar();

}

//6.ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����
void anaScore(SS stu[], int N)
{
	printf("\n------���岽: ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����------\n\n");

	/*�����ɼ�����*/
	float mean_value_generalScore =0;
	float variance_generalScore = 0;

	for (int i = 0; i < N; i++)
	{

		mean_value_generalScore += stu[i].generalScore;
	}
	mean_value_generalScore = mean_value_generalScore / N;
	for (int i = 0; i < N; i++)
	{

		variance_generalScore += (mean_value_generalScore -stu[i].generalScore)*(mean_value_generalScore - stu[i].generalScore);
	}
	variance_generalScore = variance_generalScore / N;
	printf("ȫ��ѧ�������ɼ��ľ�ֵ��: %f", mean_value_generalScore);
	printf("\n");
	printf("ȫ��ѧ�������ɼ��ı�׼������: %f\n", variance_generalScore);

	/*ʵ��ɼ�����*/
	float mean_value_experScore = 0;
	float variance_experScore = 0;

	for (int i = 0; i < N; i++)
	{

		mean_value_experScore += stu[i].experScore;
	}
	mean_value_experScore = mean_value_experScore / N;
	for (int i = 0; i < N; i++)
	{

		variance_experScore += (mean_value_experScore - stu[i].experScore)*(mean_value_experScore - stu[i].experScore);
	}
	variance_experScore = variance_experScore / N;
	printf("ȫ��ѧ��ʵ��ɼ��ľ�ֵ��: %f", mean_value_experScore);
	printf("\n");
	printf("ȫ��ѧ��ʵ��ɼ��ı�׼������: %f\n", variance_experScore);

	/*ƽʱ�ɼ�����*/
	float mean_value_dailyScore = 0;
	float variance_dailyScore = 0;

	for (int i = 0; i < N; i++)
	{

		mean_value_dailyScore += stu[i].dailyScore;
	}
	mean_value_dailyScore = mean_value_dailyScore / N;
	for (int i = 0; i < N; i++)
	{

		variance_dailyScore += (mean_value_dailyScore - stu[i].dailyScore)*(mean_value_dailyScore - stu[i].dailyScore);
	}
	variance_dailyScore = variance_dailyScore / N;
	printf("ȫ��ѧ��ƽʱ�ɼ��ľ�ֵ��: %f", mean_value_dailyScore);
	printf("\n");
	printf("ȫ��ѧ��ƽʱ�ɼ��ı�׼������: %f\n", variance_dailyScore);


	/*��ĩ�ɼ�����*/
	float mean_value_finalScore = 0;
	float variance_finalScore = 0;

	for (int i = 0; i < N; i++)
	{

		mean_value_finalScore += stu[i].finalScore;
	}
	mean_value_finalScore = mean_value_finalScore / N;
	for (int i = 0; i < N; i++)
	{

		variance_finalScore += (mean_value_finalScore - stu[i].finalScore)*(mean_value_finalScore - stu[i].finalScore);
	}
	variance_finalScore = variance_finalScore / N;
	printf("ȫ��ѧ����ĩ�ɼ��ľ�ֵ��: %f", mean_value_finalScore);
	printf("\n");
	printf("ȫ��ѧ����ĩ�ɼ��ı�׼������: %f\n", variance_finalScore);




	getchar();

}
