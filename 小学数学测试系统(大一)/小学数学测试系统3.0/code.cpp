#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//被调的函数说明
void menuOne();														    //一级界面
void menuTwo(char chooseOne, char *str);								//二级界面
void examHub(char chooseOne, char two);										//调用测试函数枢纽

void addIntegerExam();															//加法_整数测试
void addFloatExam();															//加法_小数测试
void addMixExam();															//加法_混合测试

void subIntegerExam();														    //减法_整数测试
void subFloatExam();															//减法_小数测试
void subMixExam();															    //减法_混合测试

void mulIntegerExam();															//乘法_整数测试
void mulFloatExam();															//乘法_小数测试
void mulMixExam();															    //乘法_混合测试

void divIntegerExam();															//除法_整数测试
void divFloatExam();															//除法_小数测试
void divMixExam();															   //除法_混合测试


void entrieMixExam();															//整体测试

int chooseExamNumber();													      //选择测试出题数目

//整数
void createAddIntegerNumber(struct integerExamList *node);	                        //生成加法单个整数试题	
void createSubIntegerNumber(struct integerExamList *node);	                        //生成减法单个整数试题
void createMulIntegerNumber(struct integerExamList *node);	                        //生成乘法单个整数试题
void createDivIntegerNumber(struct integerExamList *node);	                        //生成除法单个整数试题
void createIntegerNumberHub(struct integerExamList *node, char op);				//生成单个整数试题枢纽
struct integerExamList *createIntegerExamList(int testNumber, char op);			//生成整张试卷					
void startIntegerExam(struct integerExamList *start, char op);				    //开始测试并录入用户输入的答案
void appraiseIntegerExam(struct integerExamList *start);					//评价用户做题结果
void writeIntegerData(struct integerExamList *start,char *p,char op);								//将数据写入文件


//小数
void createAddFloatNumber(struct floatExamList *node);	                        //生成加法单个小数试题	
void createSubFloatNumber(struct floatExamList *node);	                        //生成减法单个小数试题
void createMulFloatNumber(struct floatExamList *node);	                        //生成乘法单个小数试题
void createDivFloatNumber(struct floatExamList *node);	                        //生成除法单个小数试题
void createFloatNumberHub(struct floatExamList *node, char op);               //生成单个小数试题枢纽
struct floatExamList *createFloatExamList(int testNumber, char op);			//生成整张试卷					
void startFloatExam(struct floatExamList *start, char op);				    //开始测试并录入用户输入的答案 
void appraiseFloatExam(struct floatExamList *start);					//评价用户做题结果
void writeFloatData(struct floatExamList *start, char *p,char op);

//加减乘除模块内混合部分
void createAddMixNumber(struct mixExamList *node);	                        //生成加法单个小数试题	
void createSubMixNumber(struct mixExamList *node);	                        //生成减法单个小数试题
void createMulMixNumber(struct mixExamList *node);	                        //生成乘法单个小数试题
void createDivMixNumber(struct mixExamList *node);	                        //生成除法单个小数试题
void createMixNumberHub(struct mixExamList *node, char op);               //生成单个小数试题枢纽
struct mixExamList *createMixExamList(int testNumber, char op);			//生成整张试卷					
void startMixExam(struct mixExamList *start, char op);				    //开始测试并录入用户输入的答案
void appraiseMixExam(struct mixExamList *start);					//评价用户做题结果
void writeMixData(struct mixExamList *start, char *url,char op);

//整体混合
void createEntireMixNumber(struct entireMixExamList *node);
struct entireMixExamList* createEntireMixExamList(int testNumber);
void createRandomOperate(struct entireMixExamList *node);
void startEntireMixExam(struct entireMixExamList *start);
void appraiseEntireMixExam(struct entireMixExamList *start);
double returnComputerResult(struct entireMixExamList *start);
void writeEntireMixData(struct entireMixExamList *start, char *url);

//释放申请的堆内存
void releaseIntegerExamList(struct integerExamList *start);
void releaseFloatExamList(struct floatExamList *start);
void releaseMixExamList(struct mixExamList *start);
void releaseEntireMixExamList(struct entireMixExamList *start);

																					
//主函数
int main()
{
	menuOne();											//调用一级界面
	return 0;
}

/*界面菜单开始*/
//一级界面
void menuOne()
{
	char  chooseOne = '\0', yes_no = '\0', str[5] = "";
	do {
		fflush(stdin);
		system("cls");
		printf("\t\t\t\t\t**************************************\n");
		printf("\t\t\t\t\t*******欢迎来到小学数学测试系统*******\n");
		printf("\t\t\t\t\t**************************************\n");
		printf("\t\t\t\t\t*            1、加法测试             *\n");
		printf("\t\t\t\t\t*            2、减法测试             *\n");
		printf("\t\t\t\t\t*            3、乘法测试             *\n");
		printf("\t\t\t\t\t*            4、除法测试             *\n");
		printf("\t\t\t\t\t*            5、混合测试             *\n");
		printf("\t\t\t\t\t*            0、退出                 *\n");
		printf("\t\t\t\t\t**************************************\n");
		printf("\t\t\t\t\t请输入选项编号(0-5):");
		chooseOne = _getche();
		switch (chooseOne)
		{
		case '1':strcpy_s(str, "加法"); menuTwo(chooseOne, str); break;		//调用加法二级界面
		case '2':strcpy_s(str, "减法"); menuTwo(chooseOne, str); break;		//调用减法二级界面				
		case '3':strcpy_s(str, "乘法"); menuTwo(chooseOne, str); break;		//调用乘法二级界面				
		case '4':strcpy_s(str, "除法"); menuTwo(chooseOne, str); break;		//调用除法二级界面			
		case '5':entrieMixExam(); break;		//调用混合测试
		case '0':exit(0);
		default:printf("\n\t%c为非法字符", chooseOne);
		}
		printf("\n\t\t\t\t\t要继续选择吗(Y/N)？\n");
		do {
			yes_no = _getche();
		} while (yes_no != 'Y'&&yes_no != 'y'&&yes_no != 'N'&&yes_no != 'n');

	} while (yes_no == 'Y' || yes_no == 'y');
}
//二级界面	
void menuTwo(char chooseOne, char *str)
{
	char choose_two = '\0', yes_no = '\0';
	do {
		fflush(stdin);
		system("cls");
		printf("\t\t\t\t\t****************************************\n");
		printf("\t\t\t\t\t**********你的选择是: %s测试**********\n", str);
		printf("\t\t\t\t\t****************************************\n");
		printf("\t\t\t\t\t*             1、整数测试              *\n");
		printf("\t\t\t\t\t*             2、小数测试              *\n");
		printf("\t\t\t\t\t*             3、混合测试              *\n");
		printf("\t\t\t\t\t*             4、返回                  *\n");
		printf("\t\t\t\t\t*             0、退出                  *\n");
		printf("\t\t\t\t\t****************************************\n");
		printf("\t\t\t\t\t请输入选项编号(0-4):");
		choose_two = _getche();
		switch (choose_two)
		{
		case '1':
		case '2':
		case '3':examHub(chooseOne, choose_two); break;
		case '4':printf("\n\t\t\t\t\t已退出该模块，要返回之前的界面吗？"); return;
		case '0':exit(0);
		default:printf("\n\t%c为非法字符", choose_two);
		}
		printf("\n\t\t\t\t\t要继续选择吗(Y/N)？\n");
		do {
			yes_no = _getche();
		} while (yes_no != 'Y'&&yes_no != 'y'&&yes_no != 'N'&&yes_no != 'n');

	} while (yes_no == 'Y' || yes_no == 'y');
	printf("\n\t\t\t\t\t已退出该模块，要返回之前的界面吗？");
}
//调用测试函数枢纽
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
/*界面菜单结束*/

//选择出题数目
int chooseExamNumber() {
	int testNumber = 0;
	printf("请输入您挑战的整数题数(按回车键确认):");
	scanf_s("%d", &testNumber);
	return testNumber;
}

/*测试函数开始*/
void addIntegerExam()
{
	system("cls");
	printf("正在进行加法整数测试:\n");
	int examNumber = chooseExamNumber();			 //选择测试出题数目
	struct integerExamList *start;
	char op = '+';
	start = createIntegerExamList(examNumber, op);	//生成试卷
	startIntegerExam(start, op);					//开始测试
	appraiseIntegerExam(start);						//评价测试结果
	char *url = "D:\\addIntegerData.txt";			//保存路径及文件名
	writeIntegerData(start, url, op);				//保存数据
	releaseIntegerExamList(start);					//释放堆内存
}
void addFloatExam()
{
	system("cls");
	printf("正在进行加法小数测试:\n");
	int examNumber = chooseExamNumber();			 //选择测试出题数目
	struct floatExamList *start;
	char op = '+';
	start = createFloatExamList(examNumber, op);	//生成试卷
	startFloatExam(start, op);						//开始测试
	appraiseFloatExam(start);						//评价测试结果
	char *url = "D:\\addFloatData.txt";				//保存路径及文件名
	writeFloatData(start, url, op);					//保存数据
	releaseFloatExamList(start);					//释放堆内存
}
void addMixExam()
{
	system("cls");
	printf("正在进行加法混合测试:\n");
	int examNumber = chooseExamNumber();		    //选择测试出题数目
	struct mixExamList *start;					
	char op = '+';
	start = createMixExamList(examNumber, op);	   //生成试卷
	startMixExam(start, op);					   //开始测试
	appraiseMixExam(start);						   //评价测试结果
	char *url = "D:\\addMixData.txt";			   //保存路径及文件名
	writeMixData(start, url,op);                      //保存数据
	releaseMixExamList(start);					   //释放堆内存
}
void subIntegerExam()
{
	system("cls");
	printf("正在进行减法整数测试:\n");
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
	printf("正在进行减法小数测试:\n");
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
	printf("正在进行减法混合测试:\n");
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
	printf("正在进行乘法整数测试:\n");
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
	printf("正在进行乘法小数测试:\n");
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
	printf("正在进行乘法混合测试:\n");
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
	printf("正在进行除法整数测试('/'为除号):\n");
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
	printf("正在进行除法小数测试:\n");
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
	printf("正在进行除法混合测试:\n");
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
	printf("正在进行整体混合测试:\n");
	int examNumber = chooseExamNumber();
	struct entireMixExamList *start;
	start = createEntireMixExamList(examNumber);
	startEntireMixExam(start);
	appraiseEntireMixExam(start);
	char *url = "D:\\entrieMixData.txt";
	writeEntireMixData(start, url);  
	releaseEntireMixExamList(start);  
}
/*测试函数结束*/


/*整数部分开始*/
//创建整数试题结构体
struct integerNumber
{
	int numberA;
	int numberB;
	int userResult;
	int computerResult;				   //计算机计算的结果——正确答案
	
};
//创建整数试卷链表
struct integerExamList
{
	struct integerNumber data;
	struct integerExamList *next;
};
//生成整数整张试卷
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
//随机生成单个整数试题，并将它保存到链表节点数据域中
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
	node->data.numberA = node->data.numberA + node->data.numberB;     //被减数大于减数
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
	node->data.numberA = node->data.numberA * node->data.numberB;				//被除数能被整除     
	node->data.computerResult = node->data.numberA / node->data.numberB;
}
//生成单个整数试题枢纽
void createIntegerNumberHub(struct integerExamList *node, char op) {
	switch (op)
	{
	case '+':createAddIntegerNumber(node); break;
	case '-':createSubIntegerNumber(node); break;
	case '*':createMulIntegerNumber(node); break;
	case '/':createDivIntegerNumber(node); break;
	}
}
//开始整数考试
void startIntegerExam(struct integerExamList *start, char op)
{
	while (start->next != NULL)
	{
		printf("%d%c%d=", start->data.numberA, op, start->data.numberB);       
		scanf_s("%d", &start->data.userResult);
		start = start->next;
	}
}
//评价用户整数做题结果
void appraiseIntegerExam(struct integerExamList *start)
{

	int nowTestNumber = 0;					    	 //当前题数
	int trueCount = 0;								 //做对题数
	while (start->next != NULL)
	{
		
		if (start->data.computerResult == start->data.userResult)
		{
			trueCount++;
			printf("第 %d 题正确\n", ++nowTestNumber);
		}
		else {
			printf("第 %d 题错误\t正确值为：%d\n", ++nowTestNumber, start->data.computerResult);
		}
		start = start->next;
	}
	printf("您答对题数为：%d\t\t得分为(每题10分)：%d\n", trueCount, trueCount * 10);
}
//将整型数据写入文件
void writeIntegerData(struct integerExamList *start, char *url,char op) {
	int count = 0;
	FILE *fp = NULL;
	fopen_s(&fp, url , "a");
	while (start->next != NULL)
	{
		fprintf(fp,"第%d题:%8d%7c%8d\t=%8d", ++count,start->data.numberA,op, start->data.numberB,start->data.userResult);
		fprintf(fp, "\t正确答案:%8d\n", start->data.computerResult);
		start = start->next;
	} 	
}
/*整数部分结束*/


/*小数部分开始*/
//创建小数试题结构体
struct floatNumber
{
	double numberA;
	double numberB;
	double userResult;
	double computerResult;							 //计算机计算的结果——正确答案
};
//创建小数试卷链表
struct floatExamList
{
	struct floatNumber data;
	struct floatExamList *next;
};
//生成小数整张试卷
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
//生成单个小数试题枢纽
void createFloatNumberHub(struct floatExamList *node, char op) {
	switch (op)
	{
	case '+':createAddFloatNumber(node); break;
	case '-':createSubFloatNumber(node); break;
	case '*':createMulFloatNumber(node); break;
	case '/':createDivFloatNumber(node); break;
	}
}
//随机生成单个小数试题，并将它保存到链表节点数据域中
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
//开始小数考试
void startFloatExam(struct floatExamList *start, char op)
{
	while (start->next != NULL)
	{
		printf("%.2lf%c%.2lf=", start->data.numberA, op, start->data.numberB);
		scanf_s("%lf", &start->data.userResult);
		start = start->next;
	}
}
//评价用户小数做题结果
void appraiseFloatExam(struct floatExamList *start)
{
	int nowTestNumber = 0;					    	 //当前题数
	int trueCount = 0;								 //做对题数
	while (start->next != NULL)
	{
		
		if (fabs(start->data.computerResult - start->data.userResult) < 0.000001)
		{
			trueCount++;
			printf("第 %d 题正确\n", ++nowTestNumber);
		}
		else {
			printf("第 %d 题错误\t正确值为：%.2lf\n", ++nowTestNumber, start->data.computerResult);
		}
		start = start->next;
	}
	printf("您答对题数为：%d\t\t得分为(每题10分)：%d\n", trueCount, trueCount * 10);
}
//将小数数据写入文件
void writeFloatData(struct floatExamList *start, char *url,char op) {
	int count = 0;
	FILE *fp = NULL;
	fopen_s(&fp, url, "a");
	while (start->next != NULL)
	{
		fprintf(fp, "第%d题:%8.2lf%7c%8.2lf\t=%8.2lf", ++count,start->data.numberA,op,start->data.numberB, start->data.userResult);
		fprintf(fp, "\t正确答案:%8.2lf\n", start->data.computerResult);
		start = start->next;
	}
	fclose(fp);
}
/*小数部分结束*/


/*加减乘除模块内混合部分开始*/
//创建试题结构体
struct mixNumber
{
	double numberA;
	int numberB;
	double userResult;
	double computerResult;							 //计算机计算的结果——正确答案
};
//创建试卷链表
struct mixExamList
{
	struct mixNumber data;
	struct mixExamList *next;
};
//生成整张试卷
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
//生成单个试题枢纽
void createMixNumberHub(struct mixExamList *node, char op) {
	switch (op)
	{
	case '+':createAddMixNumber(node); break;
	case '-':createSubMixNumber(node); break;
	case '*':createMulMixNumber(node); break;
	case '/':createDivMixNumber(node); break;
	}
}
//随机生成单个试题，并将它保存到链表节点数据域中
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
//开始考试
void startMixExam(struct mixExamList *start, char op)
{
	while (start->next != NULL)
	{
		printf("%0.2lf%c%d=", start->data.numberA, op, start->data.numberB);
		scanf_s("%lf", &start->data.userResult);
		start = start->next;
	}
}
//评价用户做题结果
void appraiseMixExam(struct mixExamList *start)
{
	int nowTestNumber = 0;					    	 //当前题数
	int trueCount = 0;								 //做对题数
	while (start->next != NULL)
	{
		if (fabs(start->data.computerResult - start->data.userResult) < 0.000001)
		{
			trueCount++;
			printf("第 %d 题正确\n", ++nowTestNumber);
		}
		else {
			printf("第 %d 题错误\t正确值为：%.2lf\n", ++nowTestNumber, start->data.computerResult);
		}
		start = start->next;
	}
	printf("您答对题数为：%d\t\t得分为(每题10分)：%d\n", trueCount, trueCount * 10);
}
//将加减乘除模块内混合数据写入文件
void writeMixData(struct mixExamList *start, char *url,char op) {
	int count = 0;
	FILE *fp = NULL;
	fopen_s(&fp, url, "a");
	while (start->next != NULL)
	{
		fprintf(fp, "第%d题:%8.2lf%7c%8d\t=%8.2lf", ++count, start->data.numberA, op, start->data.numberB, start->data.userResult);
		fprintf(fp, "\t正确答案:%8.2lf\n", start->data.computerResult);
		start = start->next;
	}
	fclose(fp);
}

/*加减乘除模块内混合部分结束*/

/*整体混合模块开始*/
//创建试题结构体
struct entireMixNumber {
	double number1; 
	int number2;
	double number3;
	int number4;
	double number5;
	char op[6];											//运算符
	double userResult;									//用户结果
	double computerResult;							 //计算机计算的结果——正确答案
	
};
//创建试卷链表
struct entireMixExamList
{
	struct entireMixNumber data;
	struct entireMixExamList *next;
};
//生成整张试卷
struct entireMixExamList* createEntireMixExamList(int testNumber)
{
	
	srand((unsigned)time(NULL));
	struct entireMixExamList *head, *p;
	head = (struct entireMixExamList*)malloc(sizeof(struct entireMixExamList));
	head->next = NULL;
	for (int i = 0; i<testNumber; i++)
	{
		p = (struct entireMixExamList*)malloc(sizeof(struct entireMixExamList));
		createRandomOperate(p);         // 生成随机运算符
		createEntireMixNumber(p);
		p->next = head;
		head = p;
	}
	return head;
}
//生成随机运算符
void createRandomOperate(struct entireMixExamList *node) {
	char a[4] = { '+','-','*','/' };
	int i,op;
	for (i = 0; i < 4; i++) {
		op = rand() % 4;
		node->data.op[i] = a[op];
	}
	node->data.op[4] = '=';

}
//生成单个试题数据
void createEntireMixNumber(struct entireMixExamList *node) {
	node->data.number1 = rand() % 100 * 0.1 + 1;
	node->data.number2 = rand() % 100 + 1;
	node->data.number3 = rand() % 100 * 0.1 + 1;
	node->data.number4 = rand() % 100 + 1;
	node->data.number5 = rand() % 100 * 0.1 + 1;
	node->data.computerResult = returnComputerResult(node);

}
//计算正确结果
double returnComputerResult(struct entireMixExamList *start) {
	int i = 0, j = 1;
	double a1, a2, a3;
	char op1, op2, op3;

	//为了保证结构，在最开始加上一个0 ，+  
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


		//计算乘除  
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
			op2 = op3;    //此处注意 
			j++;
			i++;
		}
		//将两项相加（减）  
		if (op1 == '+')
			a1 += a2;
		else if (op1 == '-')
			a1 -= a2;
		op1 = op2;    //此处注意  
		i++;
		j++;
	}
	return a1;
}
//开始考试
void startEntireMixExam(struct entireMixExamList *start)
{
	
	while (start->next != NULL)
	{
		printf("%0.2lf%c%d%c%0.2lf%c%d%c%0.2lf=", start->data.number1, start->data.op[0], start->data.number2, start->data.op[1], start->data.number3, start->data.op[2], start->data.number4, start->data.op[3], start->data.number5);
		scanf_s("%lf", &start->data.userResult);
		start = start->next;
	}
}
//评价用户做题结果
void appraiseEntireMixExam(struct entireMixExamList *start)
{
	int nowTestNumber = 0;					    	 //当前题数
	int trueCount = 0;								 //做对题数
	while (start->next != NULL)
	{
		if (fabs(start->data.computerResult - start->data.userResult) < 0.000001)
		{
			trueCount++;
			printf("第 %d 题正确\n", ++nowTestNumber);
		}
		else {
			printf("第 %d 题错误\t正确值为：%.2lf\n", ++nowTestNumber, start->data.computerResult);
		}
		start = start->next;
	}
	printf("您答对题数为：%d\t\t得分为(每题10分)：%d\n", trueCount, trueCount * 10);
}
//将整体混合数据写入文件
void writeEntireMixData(struct entireMixExamList *start, char *url) {
	FILE *fp = NULL;
	fopen_s(&fp, url, "a");
	while (start->next != NULL)
	{
		fprintf(fp, "%8.2lf%6c%8d%6c%8.2lf%6c%8d%6c%8.2lf\t=%8.2lf", start->data.number1, start->data.op[0], start->data.number2, start->data.op[1], start->data.number3, start->data.op[2], start->data.number4, start->data.op[3], start->data.number5, start->data.userResult);
		fprintf(fp, "\t正确答案:%8.2lf\n", start->data.computerResult);
		start = start->next;
	}
	fclose(fp);
}
/*整体混合模块结束*/


//释放申请的堆内存
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
