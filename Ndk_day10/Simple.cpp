#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>



/*// �ַ�����ȡ
char* substr(char *str, int start, int end){

	// 1. ����һ���ַ��������ڴ洢���ǵ�����
	// ����Ҫ���ַ����ĳ���
	// char sub[end - start];  // ���ֲ���
	int len = end - start;
	char *sub = (char*)malloc(len * sizeof(char)+1);  // ����ǵ�+1����Android Studio�� NDK��һ�����þ�̬������洢���� char sub[len]

	// 2. Ȼ�������ֵ
	str += start; // ָ��++
	int i = 0;
	for (; i < len; i++){
		sub[i] = *str;  // *str:��ʾȡֵ
		str++;  // ָ������Ų��һλ
	}

	// 3. ����ַ�����β������ print�޷��жϽ�β
	sub[len] = '\0';
	return sub;
}

// �ַ������滻
char *str_replace(char *str , char *src  ,char *dst){
	// 1. �����ж� str����û��aa 
	char *pos = strstr(str , src);  // ���ص����ַ�����һ�γ��ֵ�λ��(λ��ָ��)�����û���ҵ����ص��ǿ�

	// �ݹ�Ľ������
	if (!pos){  // !pos �ȼ��� if(pos != NULL)
		return str;  // ���pos��Ϊ�գ���ʾ str���� aa
	}

	// 2. �����aa������ccc��aa�滻֮����Ҫ�����µ������С��
	// ԭ������Ĵ�С - ���滻�Ĵ�С + �滻�Ĵ�С
	int newArraySize = strlen(str) - strlen(src) + strlen(dst);
	// ����һ���µ�����
	char *result = (char*)malloc(sizeof(char) * newArraySize);

	// 3. ����ƴ��
	// �ӵ�һ��a����һ������һ��a��λ��
	int start_end_position = pos - str;
	// a. ���Ȱ� aa �ó���
	char *start = substr(str , 0 , start_end_position);

	// �м���ַ�����������Ҫ�滻���ַ��������Ǵ��ݹ�����dst

	// src������Ҫ�滻���ַ���
	// �����ַ�����ͬ����Ҫ��ȡ
	int end_start_position = start_end_position + strlen(src);
	char *end = substr(str , end_start_position , strlen(str));  // ��ȡstr�ַ�������end_start_positionλ�ý�ȡ���ַ�������

	// ƴ��
	// ���Ȱ� ��ʼ��start�ַ������Ƶ��µ������У�Ȼ����м�ĺ������ַ���ƴ������
	strcpy(result , start);
	strcat(result , dst);
	strcat(result , end);

	// 4. ���src���ж��aa������Ҫ���ж���滻������ʹ�� whileѭ����ݹ�
	return str_replace(result,src,dst);
}


// �ַ������滻
void main(){

	// ��aabbaabbaabb �е�aa ���滻Ϊ cc
	char *str = str_replace("aabbaabbaabb" , "aa" , "ccc");
	printf("str = %s" , str);  // str = cccbbcccbbcccbb
	getchar();
}*/

// ����һ���ṹ�壬�൱��java�е�class����������û�м̳л�������

// ��һ�ֶ��巽ʽ��
/*struct Worker{
	char name[10];
	int age;
	double salary;
};

void main(){

	struct Worker worker = {"Novate" , 26 , 1000};  // ��ʼ���ṹ��

	// ���ֶθ�ֵ
	// worker.name = "Novate";
	strcpy(worker.name , "Jack Chen");
	worker.age = 27;
	printf("name = %s , age = %d , salary = %lf" , worker.name , worker.age , worker.salary);  // name = Novate , age = 27 , salary = 1000.000000
	getchar();
}*/


/*// �ڶ��ֶ��巽ʽ������ֱ��ȡ����
struct Worker{
	char name[10];
	int age;
	double salary;
}novate, jackchen;  // ���ַ�ʽ����һ��Ĭ�ϳ�ʼֵ������� main()�����в�ָ��strcpy_s(jackchen.name , "JackChen")����ӡ����jackchen.nameҲ����ֵ�ģ�ֻ��������� "" 

void main(){

	strcpy_s(jackchen.name , "JackChen");
	jackchen.age = 27;

	// name = JackChen , age = 27 , salary = 0.000000
	printf("name = %s , age = %d , salary = %lf", jackchen.name, jackchen.age, jackchen.salary);
	getchar();
	}*/

/*// �����ֶ��巽ʽ��
struct Worker{
char name[10];
int age;
double salary;
}novate = {"Novate" , 26 , 1000 } , jackchen;

void main(){
jackchen.age = 27;
// name = Novate, age = 26, salary = 1000.000000
printf("name = %s , age = %d , salary = %lf", novate.name, novate.age, novate.salary);
getchar();
}*/

/*// �����ַ�ʽ���ṹ���Ƕ�ף�������
struct Work{  // ����
char name[10];   // ����������
char grade[10];  // �����ĵȼ�
};
struct Worker{
char name[10];
int age;
double salary;

// ������ܻ����������ԣ�����Ҫ����ṹ��
Work work;
};

void main(){

struct Worker worker = { "Novate", 23, 1000, {"Android" , "�м�"}};  // Ƕ�׵ĸ���ʼֵ
// name = Android , grade = �м�
printf("name = %s , grade = %s" , worker.work.name , worker.work.grade);

getchar();
}*/

/*// ��5�ַ�ʽ���ṹ��Ƕ�ף���Work�Ľṹ��д�� Worker�����
struct Worker{
char name[10];
int age;
double salary;

// ���˵Ĺ���
struct Work{
char name[10];
char grade[10];
};
Work work;
};

void main(){

struct Worker worker = { "Novate", 23, 1000, { "Android", "�м�" } };  // Ƕ�׵ĸ���ʼֵ
// name = Android , grade = �м�
printf("name = %s , grade = %s", worker.work.name, worker.work.grade);
getchar();
}*/

/* ����ṹ��ָ�룺��һ�ַ���
struct Worker{
char name[10];
int age;
double salary;

// �����й�����name��grade
// Work work;
};

// �ṹ��ָ��
void main(){

// �ṹ���ʼ����ֵ
struct Worker worker = { "Novate", 26 };

// �� �ṹ��workerȡ��ַ ����ָ����������գ����ڿ�����Ϊ����һ��
Worker *worker_p = &worker;
// ͨ�� �ṹ��ָ�� ���Բ�������:
// ��ȡֵ�����޸�ֵ���� ->

// �ṹ���޸�ֵ��ʹ�õ��� .��
worker.age = 27;

// �ṹ��ָ���޸�ֵ��ʹ�õ��� ->
// �ṹ�����������һ�ַ�ʽ���ܳ���
worker_p->age = 27;
strcpy_s(worker_p -> name , "JackChen");

// name = JackChen , age = 27
printf("name = %s , age = %d" , worker_p->name , worker_p->age);
getchar();
}*/


/*����ṹ��ָ�룺�ڶ��ַ���
struct Worker{
	char name[10];
	int age;
	double salary;
};
// ����ṹ��ָ��
void main(){

	// Worker *worker; // ������һ���ṹ��ָ��,ָ��û�г�ʼ��
	Worker *worker = (Worker*)malloc(sizeof(Worker));
	strcpy_s(worker->name, "jackchen");
	worker->age = 27;
	// name = jackchen , age = 27
	printf("name = %s , age = %d", worker->name, worker->age);
	// �ͷ�
	if (worker){
		free(worker);
		worker = NULL;
	}
	
	getchar();
	}*/


/*// �ṹ������
struct Worker{
	char name[10];
	int age;
	double salary;
};

void main(){

	// �����ṹ������
	// ��һ�֣���̬����
	// Worker worker[10] = { {"Novate" , 26 , 1000}, {}, {} };  // ����10���ṹ�壬���ַ�ʽ������̬����
	// worker[9] = {"Novate9" , 27 , 1000};
	// name = Novate9 , age = 27
	// printf("name = %s , age = %d\n", worker[9].name, worker[9].age);

	//-----------------------------------------------------------------//

	// �ڶ��֣���̬�ڴ濪�٣�Worker*����ṹ��ָ��
	// �ö�̬���ٷ�ʽ������10���ṹ�壬
	Worker *worker = (Worker*)malloc(sizeof(Worker)* 10);
	// strcpy_s(worker->name , "Novate0");
	// worker->age = 10;
	// name = Novate0 , age = 10
	// printf("name = %s , age = %d", worker->name, worker->age);

	//-----------------------------------------------------------------//

	// �Ե�10�����ݽ��в���
	worker += 9;
	strcpy_s(worker->name , "Novate9");
	worker->age = 9;
	// name = Novate9 , age = 9
	printf("name = %s , age = %d", worker->name, worker->age);
	getchar();
}*/

/*// �ṹ���С���㣺����1
struct Worker{
	int age;  // intռ4�ֽ�
	double salary; // doubleռ8�ֽ�
};

void main(){

	int size = sizeof(Worker);
	// size = 16
	printf("size = %d" , size);
	getchar();
}*/

/*// �ṹ���С���㣺����2
struct Worker{
	char name[10];
	int age;
	double salary;
};
void main(){

	int size = sizeof(Worker);
	// size = 24
	printf("size = %d", size);

	getchar();
}*/

/*// �ṹ���С���㣺����3
struct Worker{
	char name[18];
	int age;
	double salary;
};
void main(){

	int size = sizeof(Worker);
	// size = 32
	printf("size = %d", size);

	getchar();
}*/

/*struct date{
	int year;
	int month;
	int day;
};
struct student{
	int number;  // 4
	char sex;  // 1
	int age;  // 4
	char name[10];  // 10

	struct date birthday;  // 12
};
void main(){

	int size = sizeof(student);
	// size = 36
	printf("size = %d", size);

	getchar();
}*/

/*// �ṹ��ͽṹ��ָ��ȡ����
struct Worker{
	char name[10];
	int age;
	double salary;
};

// ��Workerȡһ������
typedef Worker Worker_;

void main(){

	// Ȼ������ñ��� Worker_������
	Worker_ worker = {"Novate" , 27 , 27};
	// Novate , 27 , 27.000000
	printf("%s , %d , %lf" , worker.name , worker.age , worker.salary);
	getchar();
}*/

/*// �ṹ��
struct Worker_{
	char name[10];
	int age;
	double salary;
};

// ���ṹ��ȡ����
typedef Worker_ Worker_;
// ���ṹ����ȡһ��ָ�룬����Worker*��Ȼ��� Worker*ָ��ȡһ������
typedef Worker_* Worker;

void main(){

	Worker worker = (Worker_*)malloc(sizeof(Worker));
	printf("%s , %d , %lf", worker->name, worker->age, worker->salary);
	getchar();
}*/


/*// ����һ��������
union Person{
	char name[10];
	int age;
	double salary;
};
void main(){

	 Person person = {"Novate"};
	//Person person;

	// strcpy_s(person.name, "Novate");
	// person.age = 27;
	//strcpy_s(person.name , "Novate");
	//person.age = 27;
	//person.age = 27;
	//strcpy_s(person.name, "Novate");
	// name =  , age = 27
	//printf("name = %s , age = %d" , person.name , person.age);
	 printf("%d" , sizeof(person));
	getchar();
}*/

// ö��
enum CommentType{
	TEXT, TEXT_IMAGE, IMAGE
};
void main(){

	CommentType commentType = TEXT;
	CommentType commentType1 = TEXT_IMAGE;
	CommentType commentType2 = IMAGE;

	// 0 , 1 , 2
	printf("%d , %d , %d", commentType, commentType1, commentType2);

	getchar();
}
