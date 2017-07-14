#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//�����ĺ���˵��
void menuOne();														    //һ������
void menuTwo(char chooseOne, char *str);								//��������
void examHub(char chooseOne, char two);										//���ò��Ժ�����Ŧ

void addIntegerExam();															//�ӷ�_��������
void addFloatExam();															//�ӷ�_С������
void addMixExam();															//�ӷ�_��ϲ���

void subIntegerExam();														    //����_��������
void subFloatExam();															//����_С������
void subMixExam();															    //����_��ϲ���

void mulIntegerExam();															//�˷�_��������
void mulFloatExam();															//�˷�_С������
void mulMixExam();															    //�˷�_��ϲ���

void divIntegerExam();															//����_��������
void divFloatExam();															//����_С������
void divMixExam();															   //����_��ϲ���


void entrieMixExam();															//�������

int chooseExamNumber();													      //ѡ����Գ�����Ŀ

//����
void createAddIntegerNumber(struct integerExamList *node);	                        //���ɼӷ�������������	
void createSubIntegerNumber(struct integerExamList *node);	                        //���ɼ���������������
void createMulIntegerNumber(struct integerExamList *node);	                        //���ɳ˷�������������
void createDivIntegerNumber(struct integerExamList *node);	                        //���ɳ���������������
void createIntegerNumberHub(struct integerExamList *node, char op);				//���ɵ�������������Ŧ
struct integerExamList *createIntegerExamList(int testNumber, char op);			//���������Ծ�					
void startIntegerExam(struct integerExamList *start, char op);				    //��ʼ���Բ�¼���û�����Ĵ�
void appraiseIntegerExam(struct integerExamList *start);					//�����û�������
void writeIntegerData(struct integerExamList *start,char *p,char op);								//������д���ļ�


//С��
void createAddFloatNumber(struct floatExamList *node);	                        //���ɼӷ�����С������	
void createSubFloatNumber(struct floatExamList *node);	                        //���ɼ�������С������
void createMulFloatNumber(struct floatExamList *node);	                        //���ɳ˷�����С������
void createDivFloatNumber(struct floatExamList *node);	                        //���ɳ�������С������
void createFloatNumberHub(struct floatExamList *node, char op);               //���ɵ���С��������Ŧ
struct floatExamList *createFloatExamList(int testNumber, char op);			//���������Ծ�					
void startFloatExam(struct floatExamList *start, char op);				    //��ʼ���Բ�¼���û�����Ĵ� 
void appraiseFloatExam(struct floatExamList *start);					//�����û�������
void writeFloatData(struct floatExamList *start, char *p,char op);

//�Ӽ��˳�ģ���ڻ�ϲ���
void createAddMixNumber(struct mixExamList *node);	                        //���ɼӷ�����С������	
void createSubMixNumber(struct mixExamList *node);	                        //���ɼ�������С������
void createMulMixNumber(struct mixExamList *node);	                        //���ɳ˷�����С������
void createDivMixNumber(struct mixExamList *node);	                        //���ɳ�������С������
void createMixNumberHub(struct mixExamList *node, char op);               //���ɵ���С��������Ŧ
struct mixExamList *createMixExamList(int testNumber, char op);			//���������Ծ�					
void startMixExam(struct mixExamList *start, char op);				    //��ʼ���Բ�¼���û�����Ĵ�
void appraiseMixExam(struct mixExamList *start);					//�����û�������
void writeMixData(struct mixExamList *start, char *url,char op);

//������
void createEntireMixNumber(struct entireMixExamList *node);
struct entireMixExamList* createEntireMixExamList(int testNumber);
void createRandomOperate(struct entireMixExamList *node);
void startEntireMixExam(struct entireMixExamList *start);
void appraiseEntireMixExam(struct entireMixExamList *start);
double returnComputerResult(struct entireMixExamList *start);
void writeEntireMixData(struct entireMixExamList *start, char *url);

//�ͷ�����Ķ��ڴ�
void releaseIntegerExamList(struct integerExamList *start);
void releaseFloatExamList(struct floatExamList *start);
void releaseMixExamList(struct mixExamList *start);
void releaseEntireMixExamList(struct entireMixExamList *start);

																					
//������
int main()
{
	menuOne();											//����һ������
	return 0;
}

/*����˵���ʼ*/
//һ������
void menuOne()
{
	char  chooseOne = '\0', yes_no = '\0', str[5] = "";
	do {
		fflush(stdin);
		system("cls");
		printf("\t\t\t\t\t**************************************\n");
		printf("\t\t\t\t\t*******��ӭ����Сѧ��ѧ����ϵͳ*******\n");
		printf("\t\t\t\t\t**************************************\n");
		printf("\t\t\t\t\t*            1���ӷ�����             *\n");
		printf("\t\t\t\t\t*            2����������             *\n");
		printf("\t\t\t\t\t*            3���˷�����             *\n");
		printf("\t\t\t\t\t*            4����������             *\n");
		printf("\t\t\t\t\t*            5����ϲ���             *\n");
		printf("\t\t\t\t\t*            0���˳�                 *\n");
		printf("\t\t\t\t\t**************************************\n");
		printf("\t\t\t\t\t������ѡ����(0-5):");
		chooseOne = _getche();
		switch (chooseOne)
		{
		case '1':strcpy_s(str, "�ӷ�"); menuTwo(chooseOne, str); break;		//���üӷ���������
		case '2':strcpy_s(str, "����"); menuTwo(chooseOne, str); break;		//���ü�����������				
		case '3':strcpy_s(str, "�˷�"); menuTwo(chooseOne, str); break;		//���ó˷���������				
		case '4':strcpy_s(str, "����"); menuTwo(chooseOne, str); break;		//���ó�����������			
		case '5':entrieMixExam(); break;		//���û�ϲ���
		case '0':exit(0);
		default:printf("\n\t%cΪ�Ƿ��ַ�", chooseOne);
		}
		printf("\n\t\t\t\t\tҪ����ѡ����(Y/N)��\n");
		do {
			yes_no = _getche();
		} while (yes_no != 'Y'&&yes_no != 'y'&&yes_no != 'N'&&yes_no != 'n');

	} while (yes_no == 'Y' || yes_no == 'y');
}
//��������	
void menuTwo(char chooseOne, char *str)
{
	char choose_two = '\0', yes_no = '\0';
	do {
		fflush(stdin);
		system("cls");
		printf("\t\t\t\t\t****************************************\n");
		printf("\t\t\t\t\t**********���ѡ����: %s����**********\n", str);
		printf("\t\t\t\t\t****************************************\n");
		printf("\t\t\t\t\t*             1����������              *\n");
		printf("\t\t\t\t\t*             2��С������              *\n");
		printf("\t\t\t\t\t*             3����ϲ���              *\n");
		printf("\t\t\t\t\t*             4������                  *\n");
		printf("\t\t\t\t\t*             0���˳�                  *\n");
		printf("\t\t\t\t\t****************************************\n");
		printf("\t\t\t\t\t������ѡ����(0-4):");
		choose_two = _getche();
		switch (choose_two)
		{
		case '1':
		case '2':
		case '3':examHub(chooseOne, choose_two); break;
		case '4':printf("\n\t\t\t\t\t���˳���ģ�飬Ҫ����֮ǰ�Ľ�����"); return;
		case '0':exit(0);
		default:printf("\n\t%cΪ�Ƿ��ַ�", choose_two);
		}
		printf("\n\t\t\t\t\tҪ����ѡ����(Y/N)��\n");
		do {
			yes_no = _getche();
		} while (yes_no != 'Y'&&yes_no != 'y'&&yes_no != 'N'&&yes_no != 'n');

	} while (yes_no == 'Y' || yes_no == 'y');
	printf("\n\t\t\t\t\t���˳���ģ�飬Ҫ����֮ǰ�Ľ�����");
}
//���ò��Ժ�����Ŧ
void examHub(char chooseOne, char choose_two)
{
	fflush(stdin);
	switch (chooseOne)
	{
	case '1':
		switch (choose_two)
		{
		case '1':addIntegerExam(); break;
		case '2':addFloatExam(); break;
		case '3':addMixExam(); break;
		}
		break;
	case '2':
		switch (choose_two)
		{
		case '1':subIntegerExam(); break;
		case '2':subFloatExam(); break;
		case '3':subMixExam(); break;
		}
		break;
	case '3':
		switch (choose_two)
		{
		case '1':mulIntegerExam(); break;
		case '2':mulFloatExam(); break;
		case '3':mulMixExam(); break;
		}
		break;
	case '4':
		switch (choose_two)
		{
		case '1':divIntegerExam(); break;
		case '2':divFloatExam(); break;
		case '3':divMixExam(); break;
		}
		break;
	}
}
/*����˵�����*/

//ѡ�������Ŀ
int chooseExamNumber() {
	int testNumber = 0;
	printf("����������ս����������(���س���ȷ��):");
	scanf_s("%d", &testNumber);
	return testNumber;
}

/*���Ժ�����ʼ*/
void addIntegerExam()
{
	system("cls");
	printf("���ڽ��мӷ���������:\n");
	int examNumber = chooseExamNumber();			 //ѡ����Գ�����Ŀ
	struct integerExamList *start;
	char op = '+';
	start = createIntegerExamList(examNumber, op);	//�����Ծ�
	startIntegerExam(start, op);					//��ʼ����
	appraiseIntegerExam(start);						//���۲��Խ��
	char *url = "D:\\addIntegerData.txt";			//����·�����ļ���
	writeIntegerData(start, url, op);				//��������
	releaseIntegerExamList(start);					//�ͷŶ��ڴ�
}
void addFloatExam()
{
	system("cls");
	printf("���ڽ��мӷ�С������:\n");
	int examNumber = chooseExamNumber();			 //ѡ����Գ�����Ŀ
	struct floatExamList *start;
	char op = '+';
	start = createFloatExamList(examNumber, op);	//�����Ծ�
	startFloatExam(start, op);						//��ʼ����
	appraiseFloatExam(start);						//���۲��Խ��
	char *url = "D:\\addFloatData.txt";				//����·�����ļ���
	writeFloatData(start, url, op);					//��������
	releaseFloatExamList(start);					//�ͷŶ��ڴ�
}
void addMixExam()
{
	system("cls");
	printf("���ڽ��мӷ���ϲ���:\n");
	int examNumber = chooseExamNumber();		    //ѡ����Գ�����Ŀ
	struct mixExamList *start;					
	char op = '+';
	start = createMixExamList(examNumber, op);	   //�����Ծ�
	startMixExam(start, op);					   //��ʼ����
	appraiseMixExam(start);						   //���۲��Խ��
	char *url = "D:\\addMixData.txt";			   //����·�����ļ���
	writeMixData(start, url,op);                      //��������
	releaseMixExamList(start);					   //�ͷŶ��ڴ�
}
void subIntegerExam()
{
	system("cls");
	printf("���ڽ��м�����������:\n");
	int examNumber = chooseExamNumber();
	struct integerExamList *start;
	char op = '-';
	start = createIntegerExamList(examNumber, op);
	startIntegerExam(start, op);
	appraiseIntegerExam(start);
	char *url = "D:\\subIntegerData.txt";
	writeIntegerData(start, url,op);
	releaseIntegerExamList(start);  
}
void subFloatExam()
{
	system("cls");
	printf("���ڽ��м���С������:\n");
	int examNumber = chooseExamNumber();
	struct floatExamList *start;
	char op = '-';
	start = createFloatExamList(examNumber, op);
	startFloatExam(start, op);
	appraiseFloatExam(start);
	char *url = "D:\\subFloatData.txt";
	writeFloatData(start, url, op);
	releaseFloatExamList(start);  
}
void subMixExam()
{
	system("cls");
	printf("���ڽ��м�����ϲ���:\n");
	int examNumber = chooseExamNumber();
	struct mixExamList *start;
	char op = '-';
	start = createMixExamList(examNumber, op);
	startMixExam(start, op);
	appraiseMixExam(start);
	char *url = "D:\\subMixData.txt";
	writeMixData(start, url,op);
	releaseMixExamList(start); 
}
void mulIntegerExam()
{
	system("cls");
	printf("���ڽ��г˷���������:\n");
	int examNumber = chooseExamNumber();
	struct integerExamList *start;
	char op = '*';
	start = createIntegerExamList(examNumber, op);
	startIntegerExam(start, op);
	appraiseIntegerExam(start);
	char *url = "D:\\mulIntegerData.txt";
	writeIntegerData(start, url,op);
	releaseIntegerExamList(start);  
}
void mulFloatExam()
{
	system("cls");
	printf("���ڽ��г˷�С������:\n");
	int examNumber = chooseExamNumber();
	struct floatExamList *start;
	char op = '*';
	start = createFloatExamList(examNumber, op);
	startFloatExam(start, op);
	appraiseFloatExam(start);
	char *url = "D:\\mulFloatData.txt";
	writeFloatData(start, url, op);
	releaseFloatExamList(start);  
}
void mulMixExam()
{
	system("cls");
	printf("���ڽ��г˷���ϲ���:\n");
	int examNumber = chooseExamNumber();
	struct mixExamList *start;
	char op = '*';
	start = createMixExamList(examNumber, op);
	startMixExam(start, op);
	appraiseMixExam(start);
	char *url = "D:\\mulMixData.txt";
	writeMixData(start, url,op);
	releaseMixExamList(start);  
}
void divIntegerExam()
{
	system("cls");
	printf("���ڽ��г�����������('/'Ϊ����):\n");
	int examNumber = chooseExamNumber();
	struct integerExamList *start;
	char op = '/';
	start = createIntegerExamList(examNumber,op);
	startIntegerExam(start, op);
	appraiseIntegerExam(start);
	char *url = "D:\\divIntegerData.txt";
	writeIntegerData(start, url,op);
	releaseIntegerExamList(start);  
}
void divFloatExam()
{
	system("cls");
	printf("���ڽ��г���С������:\n");
	int examNumber = chooseExamNumber();
	struct floatExamList *start;
	char op = '/';
	start = createFloatExamList(examNumber, op);
	startFloatExam(start, op);
	appraiseFloatExam(start);
	char *url = "D:\\divFloatData.txt";
	writeFloatData(start, url, op);
	releaseFloatExamList(start);  
}
void divMixExam()
{
	system("cls");
	printf("���ڽ��г�����ϲ���:\n");
	int examNumber = chooseExamNumber();
	struct mixExamList *start;
	char op = '/';
	start = createMixExamList(examNumber, op);
	startMixExam(start, op);
	appraiseMixExam(start);
	char *url = "D:\\divMixData.txt";
	writeMixData(start, url,op);
	releaseMixExamList(start); 
}
void entrieMixExam() {
	system("cls");
	printf("���ڽ��������ϲ���:\n");
	int examNumber = chooseExamNumber();
	struct entireMixExamList *start;
	start = createEntireMixExamList(examNumber);
	startEntireMixExam(start);
	appraiseEntireMixExam(start);
	char *url = "D:\\entrieMixData.txt";
	writeEntireMixData(start, url);  
	releaseEntireMixExamList(start);  
}
/*���Ժ�������*/


/*�������ֿ�ʼ*/
//������������ṹ��
struct integerNumber
{
	int numberA;
	int numberB;
	int userResult;
	int computerResult;				   //���������Ľ��������ȷ��
	
};
//���������Ծ�����
struct integerExamList
{
	struct integerNumber data;
	struct integerExamList *next;
};
//�������������Ծ�
struct integerExamList* createIntegerExamList(int testNumber, char op)
{
	srand((unsigned)time(NULL));
	struct integerExamList *head, *p;
	head = (struct integerExamList*)malloc(sizeof(struct integerExamList));
	head->next = NULL;
	for (int i = 0; i<testNumber; i++)
	{
		p = (struct integerExamList*)malloc(sizeof(struct integerExamList));
		createIntegerNumberHub(p,op);
		p->next = head;
		head = p;
	}
	return head;
}
//������ɵ����������⣬���������浽����ڵ���������
void createAddIntegerNumber(struct integerExamList *node)
{
	node->data.numberA = rand() % 100;
	node->data.numberB = rand() % 100;
	node->data.computerResult = node->data.numberA + node->data.numberB;
}
void createSubIntegerNumber(struct integerExamList *node)
{
	node->data.numberA = rand() % 100;
	node->data.numberB = rand() % 100;
	node->data.numberA = node->data.numberA + node->data.numberB;     //���������ڼ���
	node->data.computerResult = node->data.numberA - node->data.numberB;
}
void createMulIntegerNumber(struct integerExamList *node)
{
	node->data.numberA = rand() % 100;
	node->data.numberB = rand() % 100;
	node->data.computerResult = node->data.numberA * node->data.numberB;
}
void createDivIntegerNumber(struct integerExamList *node)
{
	node->data.numberA = rand() % 10;
	node->data.numberB = rand() % 10 + 1;
	node->data.numberA = node->data.numberA * node->data.numberB;				//�������ܱ�����     
	node->data.computerResult = node->data.numberA / node->data.numberB;
}
//���ɵ�������������Ŧ
void createIntegerNumberHub(struct integerExamList *node, char op) {
	switch (op)
	{
	case '+':createAddIntegerNumber(node); break;
	case '-':createSubIntegerNumber(node); break;
	case '*':createMulIntegerNumber(node); break;
	case '/':createDivIntegerNumber(node); break;
	}
}
//��ʼ��������
void startIntegerExam(struct integerExamList *start, char op)
{
	while (start->next != NULL)
	{
		printf("%d%c%d=", start->data.numberA, op, start->data.numberB);       
		scanf_s("%d", &start->data.userResult);
		start = start->next;
	}
}
//�����û�����������
void appraiseIntegerExam(struct integerExamList *start)
{

	int nowTestNumber = 0;					    	 //��ǰ����
	int trueCount = 0;								 //��������
	while (start->next != NULL)
	{
		
		if (start->data.computerResult == start->data.userResult)
		{
			trueCount++;
			printf("�� %d ����ȷ\n", ++nowTestNumber);
		}
		else {
			printf("�� %d �����\t��ȷֵΪ��%d\n", ++nowTestNumber, start->data.computerResult);
		}
		start = start->next;
	}
	printf("���������Ϊ��%d\t\t�÷�Ϊ(ÿ��10��)��%d\n", trueCount, trueCount * 10);
}
//����������д���ļ�
void writeIntegerData(struct integerExamList *start, char *url,char op) {
	int count = 0;
	FILE *fp = NULL;
	fopen_s(&fp, url , "a");
	while (start->next != NULL)
	{
		fprintf(fp,"��%d��:%8d%7c%8d\t=%8d", ++count,start->data.numberA,op, start->data.numberB,start->data.userResult);
		fprintf(fp, "\t��ȷ��:%8d\n", start->data.computerResult);
		start = start->next;
	} 	
}
/*�������ֽ���*/


/*С�����ֿ�ʼ*/
//����С������ṹ��
struct floatNumber
{
	double numberA;
	double numberB;
	double userResult;
	double computerResult;							 //���������Ľ��������ȷ��
};
//����С���Ծ�����
struct floatExamList
{
	struct floatNumber data;
	struct floatExamList *next;
};
//����С�������Ծ�
struct floatExamList* createFloatExamList(int testNumber, char op)
{
	srand((unsigned)time(NULL));
	struct floatExamList *head, *p;
	head = (struct floatExamList*)malloc(sizeof(struct floatExamList));
	head->next = NULL;
	for (int i = 0; i<testNumber; i++)
	{
		p = (struct floatExamList*)malloc(sizeof(struct floatExamList));
		createFloatNumberHub(p, op);
		p->next = head;
		head = p;
	}
	return head;
}
//���ɵ���С��������Ŧ
void createFloatNumberHub(struct floatExamList *node, char op) {
	switch (op)
	{
	case '+':createAddFloatNumber(node); break;
	case '-':createSubFloatNumber(node); break;
	case '*':createMulFloatNumber(node); break;
	case '/':createDivFloatNumber(node); break;
	}
}
//������ɵ���С�����⣬���������浽����ڵ���������
void createAddFloatNumber(struct floatExamList *node)
{
	node->data.numberA = rand() % 100 * 0.1;
	node->data.numberB = rand() % 100 * 0.1;
	node->data.computerResult = node->data.numberA + node->data.numberB;
}
void createSubFloatNumber(struct floatExamList *node)
{
	node->data.numberA = rand() % 100 * 0.1;
	node->data.numberB = rand() % 100 * 0.1;
	node->data.numberA = node->data.numberA + node->data.numberB;
	node->data.computerResult = node->data.numberA - node->data.numberB;
}
void createMulFloatNumber(struct floatExamList *node)
{
	node->data.numberA = rand() % 100 * 0.1;
	node->data.numberB = rand() % 100 * 0.1;
	node->data.computerResult = node->data.numberA * node->data.numberB;
}
void createDivFloatNumber(struct floatExamList *node)
{
	node->data.numberA = rand() % 100 * 0.1;
	node->data.numberB = rand() % 100 * 0.1 + 1;
	node->data.numberA = node->data.numberA * node->data.numberB;
	node->data.computerResult = node->data.numberA / node->data.numberB;
}
//��ʼС������
void startFloatExam(struct floatExamList *start, char op)
{
	while (start->next != NULL)
	{
		printf("%.2lf%c%.2lf=", start->data.numberA, op, start->data.numberB);
		scanf_s("%lf", &start->data.userResult);
		start = start->next;
	}
}
//�����û�С��������
void appraiseFloatExam(struct floatExamList *start)
{
	int nowTestNumber = 0;					    	 //��ǰ����
	int trueCount = 0;								 //��������
	while (start->next != NULL)
	{
		
		if (fabs(start->data.computerResult - start->data.userResult) < 0.000001)
		{
			trueCount++;
			printf("�� %d ����ȷ\n", ++nowTestNumber);
		}
		else {
			printf("�� %d �����\t��ȷֵΪ��%.2lf\n", ++nowTestNumber, start->data.computerResult);
		}
		start = start->next;
	}
	printf("���������Ϊ��%d\t\t�÷�Ϊ(ÿ��10��)��%d\n", trueCount, trueCount * 10);
}
//��С������д���ļ�
void writeFloatData(struct floatExamList *start, char *url,char op) {
	int count = 0;
	FILE *fp = NULL;
	fopen_s(&fp, url, "a");
	while (start->next != NULL)
	{
		fprintf(fp, "��%d��:%8.2lf%7c%8.2lf\t=%8.2lf", ++count,start->data.numberA,op,start->data.numberB, start->data.userResult);
		fprintf(fp, "\t��ȷ��:%8.2lf\n", start->data.computerResult);
		start = start->next;
	}
	fclose(fp);
}
/*С�����ֽ���*/


/*�Ӽ��˳�ģ���ڻ�ϲ��ֿ�ʼ*/
//��������ṹ��
struct mixNumber
{
	double numberA;
	int numberB;
	double userResult;
	double computerResult;							 //���������Ľ��������ȷ��
};
//�����Ծ�����
struct mixExamList
{
	struct mixNumber data;
	struct mixExamList *next;
};
//���������Ծ�
struct mixExamList* createMixExamList(int testNumber, char op)
{
	srand((unsigned)time(NULL));
	struct mixExamList *head, *p;
	head = (struct mixExamList*)malloc(sizeof(struct mixExamList));
	head->next = NULL;
	for (int i = 0; i<testNumber; i++)
	{
		p = (struct mixExamList*)malloc(sizeof(struct mixExamList));
		createMixNumberHub(p, op);
		p->next = head;
		head = p;
	}
	return head;
}
//���ɵ���������Ŧ
void createMixNumberHub(struct mixExamList *node, char op) {
	switch (op)
	{
	case '+':createAddMixNumber(node); break;
	case '-':createSubMixNumber(node); break;
	case '*':createMulMixNumber(node); break;
	case '/':createDivMixNumber(node); break;
	}
}
//������ɵ������⣬���������浽����ڵ���������
void createAddMixNumber(struct mixExamList *node)
{
	node->data.numberA = rand() % 100 * 0.1;
	node->data.numberB = rand() % 100;
	node->data.computerResult = node->data.numberA + node->data.numberB;
}
void createSubMixNumber(struct mixExamList *node)
{
	node->data.numberA = rand() % 100 * 0.1;
	node->data.numberB = rand() % 100;
	node->data.numberA = node->data.numberA + node->data.numberB;
	node->data.computerResult = node->data.numberA - node->data.numberB;
}
void createMulMixNumber(struct mixExamList *node)
{
	node->data.numberA = rand() % 100 * 0.1;
	node->data.numberB = rand() % 100;
	node->data.computerResult = node->data.numberA * node->data.numberB;
}
void createDivMixNumber(struct mixExamList *node)
{
	node->data.numberA = rand() % 100 * 0.1;
	node->data.numberB = rand() % 100;
	node->data.numberA = node->data.numberA * node->data.numberB;
	node->data.computerResult = node->data.numberA / node->data.numberB;
}
//��ʼ����
void startMixExam(struct mixExamList *start, char op)
{
	while (start->next != NULL)
	{
		printf("%0.2lf%c%d=", start->data.numberA, op, start->data.numberB);
		scanf_s("%lf", &start->data.userResult);
		start = start->next;
	}
}
//�����û�������
void appraiseMixExam(struct mixExamList *start)
{
	int nowTestNumber = 0;					    	 //��ǰ����
	int trueCount = 0;								 //��������
	while (start->next != NULL)
	{
		if (fabs(start->data.computerResult - start->data.userResult) < 0.000001)
		{
			trueCount++;
			printf("�� %d ����ȷ\n", ++nowTestNumber);
		}
		else {
			printf("�� %d �����\t��ȷֵΪ��%.2lf\n", ++nowTestNumber, start->data.computerResult);
		}
		start = start->next;
	}
	printf("���������Ϊ��%d\t\t�÷�Ϊ(ÿ��10��)��%d\n", trueCount, trueCount * 10);
}
//���Ӽ��˳�ģ���ڻ������д���ļ�
void writeMixData(struct mixExamList *start, char *url,char op) {
	int count = 0;
	FILE *fp = NULL;
	fopen_s(&fp, url, "a");
	while (start->next != NULL)
	{
		fprintf(fp, "��%d��:%8.2lf%7c%8d\t=%8.2lf", ++count, start->data.numberA, op, start->data.numberB, start->data.userResult);
		fprintf(fp, "\t��ȷ��:%8.2lf\n", start->data.computerResult);
		start = start->next;
	}
	fclose(fp);
}

/*�Ӽ��˳�ģ���ڻ�ϲ��ֽ���*/

/*������ģ�鿪ʼ*/
//��������ṹ��
struct entireMixNumber {
	double number1; 
	int number2;
	double number3;
	int number4;
	double number5;
	char op[6];											//�����
	double userResult;									//�û����
	double computerResult;							 //���������Ľ��������ȷ��
	
};
//�����Ծ�����
struct entireMixExamList
{
	struct entireMixNumber data;
	struct entireMixExamList *next;
};
//���������Ծ�
struct entireMixExamList* createEntireMixExamList(int testNumber)
{
	
	srand((unsigned)time(NULL));
	struct entireMixExamList *head, *p;
	head = (struct entireMixExamList*)malloc(sizeof(struct entireMixExamList));
	head->next = NULL;
	for (int i = 0; i<testNumber; i++)
	{
		p = (struct entireMixExamList*)malloc(sizeof(struct entireMixExamList));
		createRandomOperate(p);         // ������������
		createEntireMixNumber(p);
		p->next = head;
		head = p;
	}
	return head;
}
//������������
void createRandomOperate(struct entireMixExamList *node) {
	char a[4] = { '+','-','*','/' };
	int i,op;
	for (i = 0; i < 4; i++) {
		op = rand() % 4;
		node->data.op[i] = a[op];
	}
	node->data.op[4] = '=';

}
//���ɵ�����������
void createEntireMixNumber(struct entireMixExamList *node) {
	node->data.number1 = rand() % 100 * 0.1 + 1;
	node->data.number2 = rand() % 100 + 1;
	node->data.number3 = rand() % 100 * 0.1 + 1;
	node->data.number4 = rand() % 100 + 1;
	node->data.number5 = rand() % 100 * 0.1 + 1;
	node->data.computerResult = returnComputerResult(node);

}
//������ȷ���
double returnComputerResult(struct entireMixExamList *start) {
	int i = 0, j = 1;
	double a1, a2, a3;
	char op1, op2, op3;

	//Ϊ�˱�֤�ṹ�����ʼ����һ��0 ��+  
	a1 = 0;
	op1 = '+';
	while (op1 != '=')
	{
		if (i == 0) {
			a2 = start->data.number1;
			op2 = start->data.op[i];
		}
		if (i == 1) {
			a2 = (double)start->data.number2;
			op2 = start->data.op[i];
		}
		if (i == 2) {
			a2 = start->data.number3;
			op2 = start->data.op[i];
		}
		if (i == 3) {
			a2 = (double)start->data.number4;
			op2 = start->data.op[i];
		}
		if (i == 4) {
			a2 = (double)start->data.number5;
			op2 = start->data.op[i];
		}


		//����˳�  
		while (op2 == '*' || op2 == '/')
		{
			if (j == 1) {
				a3 = (double)start->data.number2;
				op3 = start->data.op[j];
			}
			if (j == 2) {
				a3 = (double)start->data.number3;
				op3 = start->data.op[j];
			}
			if (j == 3) {
				a3 = (double)start->data.number4;
				op3 = start->data.op[j];
			}
			if (j == 4) {
				a3 = (double)start->data.number5;
				op3 = start->data.op[j];
			}

			if (op2 == '*')
				a2 *= a3;
			else if (op2 == '/')
				a2 /= a3;
			op2 = op3;    //�˴�ע�� 
			j++;
			i++;
		}
		//��������ӣ�����  
		if (op1 == '+')
			a1 += a2;
		else if (op1 == '-')
			a1 -= a2;
		op1 = op2;    //�˴�ע��  
		i++;
		j++;
	}
	return a1;
}
//��ʼ����
void startEntireMixExam(struct entireMixExamList *start)
{
	
	while (start->next != NULL)
	{
		printf("%0.2lf%c%d%c%0.2lf%c%d%c%0.2lf=", start->data.number1, start->data.op[0], start->data.number2, start->data.op[1], start->data.number3, start->data.op[2], start->data.number4, start->data.op[3], start->data.number5);
		scanf_s("%lf", &start->data.userResult);
		start = start->next;
	}
}
//�����û�������
void appraiseEntireMixExam(struct entireMixExamList *start)
{
	int nowTestNumber = 0;					    	 //��ǰ����
	int trueCount = 0;								 //��������
	while (start->next != NULL)
	{
		if (fabs(start->data.computerResult - start->data.userResult) < 0.000001)
		{
			trueCount++;
			printf("�� %d ����ȷ\n", ++nowTestNumber);
		}
		else {
			printf("�� %d �����\t��ȷֵΪ��%.2lf\n", ++nowTestNumber, start->data.computerResult);
		}
		start = start->next;
	}
	printf("���������Ϊ��%d\t\t�÷�Ϊ(ÿ��10��)��%d\n", trueCount, trueCount * 10);
}
//������������д���ļ�
void writeEntireMixData(struct entireMixExamList *start, char *url) {
	FILE *fp = NULL;
	fopen_s(&fp, url, "a");
	while (start->next != NULL)
	{
		fprintf(fp, "%8.2lf%6c%8d%6c%8.2lf%6c%8d%6c%8.2lf\t=%8.2lf", start->data.number1, start->data.op[0], start->data.number2, start->data.op[1], start->data.number3, start->data.op[2], start->data.number4, start->data.op[3], start->data.number5, start->data.userResult);
		fprintf(fp, "\t��ȷ��:%8.2lf\n", start->data.computerResult);
		start = start->next;
	}
	fclose(fp);
}
/*������ģ�����*/


//�ͷ�����Ķ��ڴ�
void releaseIntegerExamList(struct integerExamList *start)
{
	struct integerExamList *next = NULL;
	while (start->next != NULL)
	{
		next = start->next;
		free(start);
		start = next;
	}
}
void releaseFloatExamList(struct floatExamList *start)
{
	struct floatExamList *next = NULL;
	while (start->next != NULL)
	{
		next = start->next;
		free(start);
		start = next;
	}
}
void releaseMixExamList(struct mixExamList *start)
{
	struct mixExamList *next = NULL;
	while (start->next != NULL)
	{
		next = start->next;
		free(start);
		start = next;
	}
}
void releaseEntireMixExamList(struct entireMixExamList *start)
{
	struct entireMixExamList *next = NULL;
	while (start->next != NULL)
	{
		next = start->next;
		free(start);
		start = next;
	}
}
