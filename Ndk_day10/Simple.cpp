#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>



/*// 字符串截取
char* substr(char *str, int start, int end){

	// 1. 开辟一个字符串，用于存储我们的数据
	// 所需要的字符串的长度
	// char sub[end - start];  // 这种不行
	int len = end - start;
	char *sub = (char*)malloc(len * sizeof(char)+1);  // 这里记得+1，在Android Studio的 NDK中一般会采用静态的数组存储，如 char sub[len]

	// 2. 然后遍历赋值
	str += start; // 指针++
	int i = 0;
	for (; i < len; i++){
		sub[i] = *str;  // *str:表示取值
		str++;  // 指针往后挪动一位
	}

	// 3. 标记字符串结尾，否则 print无法判断结尾
	sub[len] = '\0';
	return sub;
}

// 字符串的替换
char *str_replace(char *str , char *src  ,char *dst){
	// 1. 首先判断 str中有没有aa 
	char *pos = strstr(str , src);  // 返回的是字符串第一次出现的位置(位置指针)，如果没有找到返回的是空

	// 递归的结束语句
	if (!pos){  // !pos 等价于 if(pos != NULL)
		return str;  // 如果pos不为空，表示 str中有 aa
	}

	// 2. 如果有aa，在用ccc把aa替换之后，需要计算新的数组大小；
	// 原来数组的大小 - 被替换的大小 + 替换的大小
	int newArraySize = strlen(str) - strlen(src) + strlen(dst);
	// 开辟一个新的数组
	char *result = (char*)malloc(sizeof(char) * newArraySize);

	// 3. 进行拼接
	// 从第一个a到在一起的最后一个a的位置
	int start_end_position = pos - str;
	// a. 首先把 aa 拿出来
	char *start = substr(str , 0 , start_end_position);

	// 中间的字符串，就是需要替换的字符串，就是传递过来的dst

	// src：是需要替换的字符串
	// 最后的字符串：同样需要截取
	int end_start_position = start_end_position + strlen(src);
	char *end = substr(str , end_start_position , strlen(str));  // 截取str字符串，从end_start_position位置截取到字符串最后边

	// 拼接
	// 首先把 开始的start字符串复制到新的数组中，然后把中间的和最后的字符串拼接起来
	strcpy(result , start);
	strcat(result , dst);
	strcat(result , end);

	// 4. 如果src中有多个aa，就需要进行多次替换，可以使用 while循环或递归
	return str_replace(result,src,dst);
}


// 字符串的替换
void main(){

	// 把aabbaabbaabb 中的aa 都替换为 cc
	char *str = str_replace("aabbaabbaabb" , "aa" , "ccc");
	printf("str = %s" , str);  // str = cccbbcccbbcccbb
	getchar();
}*/

// 定义一个结构体，相当于java中的class，但是这里没有继承或者其他

// 第一种定义方式：
/*struct Worker{
	char name[10];
	int age;
	double salary;
};

void main(){

	struct Worker worker = {"Novate" , 26 , 1000};  // 初始化结构体

	// 给字段赋值
	// worker.name = "Novate";
	strcpy(worker.name , "Jack Chen");
	worker.age = 27;
	printf("name = %s , age = %d , salary = %lf" , worker.name , worker.age , worker.salary);  // name = Novate , age = 27 , salary = 1000.000000
	getchar();
}*/


/*// 第二种定义方式：可以直接取名字
struct Worker{
	char name[10];
	int age;
	double salary;
}novate, jackchen;  // 这种方式会有一个默认初始值，如果在 main()方法中不指定strcpy_s(jackchen.name , "JackChen")，打印出的jackchen.name也是有值的，只不过是这个 "" 

void main(){

	strcpy_s(jackchen.name , "JackChen");
	jackchen.age = 27;

	// name = JackChen , age = 27 , salary = 0.000000
	printf("name = %s , age = %d , salary = %lf", jackchen.name, jackchen.age, jackchen.salary);
	getchar();
	}*/

/*// 第三种定义方式：
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

/*// 第四种方式：结构体的嵌套，很少用
struct Work{  // 工作
char name[10];   // 工作的名字
char grade[10];  // 工作的等级
};
struct Worker{
char name[10];
int age;
double salary;

// 这里可能还有其他属性，就又要定义结构体
Work work;
};

void main(){

struct Worker worker = { "Novate", 23, 1000, {"Android" , "中级"}};  // 嵌套的赋初始值
// name = Android , grade = 中级
printf("name = %s , grade = %s" , worker.work.name , worker.work.grade);

getchar();
}*/

/*// 第5种方式：结构体嵌套，把Work的结构体写到 Worker的里边
struct Worker{
char name[10];
int age;
double salary;

// 工人的工作
struct Work{
char name[10];
char grade[10];
};
Work work;
};

void main(){

struct Worker worker = { "Novate", 23, 1000, { "Android", "中级" } };  // 嵌套的赋初始值
// name = Android , grade = 中级
printf("name = %s , grade = %s", worker.work.name, worker.work.grade);
getchar();
}*/

/* 定义结构体指针：第一种方法
struct Worker{
char name[10];
int age;
double salary;

// 工人有工作：name，grade
// Work work;
};

// 结构体指针
void main(){

// 结构体初始化赋值
struct Worker worker = { "Novate", 26 };

// 给 结构体worker取地址 ，用指针变量来接收，现在可以认为二者一样
Worker *worker_p = &worker;
// 通过 结构体指针 可以操作数据:
// 获取值或者修改值都用 ->

// 结构体修改值，使用的是 .点
worker.age = 27;

// 结构体指针修改值，使用的是 ->
// 结构体操作的另外一种方式，很常用
worker_p->age = 27;
strcpy_s(worker_p -> name , "JackChen");

// name = JackChen , age = 27
printf("name = %s , age = %d" , worker_p->name , worker_p->age);
getchar();
}*/


/*定义结构体指针：第二种方法
struct Worker{
	char name[10];
	int age;
	double salary;
};
// 定义结构体指针
void main(){

	// Worker *worker; // 创建了一个结构体指针,指针没有初始化
	Worker *worker = (Worker*)malloc(sizeof(Worker));
	strcpy_s(worker->name, "jackchen");
	worker->age = 27;
	// name = jackchen , age = 27
	printf("name = %s , age = %d", worker->name, worker->age);
	// 释放
	if (worker){
		free(worker);
		worker = NULL;
	}
	
	getchar();
	}*/


/*// 结构体数组
struct Worker{
	char name[10];
	int age;
	double salary;
};

void main(){

	// 创建结构体数组
	// 第一种：静态开辟
	// Worker worker[10] = { {"Novate" , 26 , 1000}, {}, {} };  // 创建10个结构体，这种方式叫做静态开辟
	// worker[9] = {"Novate9" , 27 , 1000};
	// name = Novate9 , age = 27
	// printf("name = %s , age = %d\n", worker[9].name, worker[9].age);

	//-----------------------------------------------------------------//

	// 第二种：动态内存开辟：Worker*代表结构体指针
	// 用动态开辟方式，创建10个结构体，
	Worker *worker = (Worker*)malloc(sizeof(Worker)* 10);
	// strcpy_s(worker->name , "Novate0");
	// worker->age = 10;
	// name = Novate0 , age = 10
	// printf("name = %s , age = %d", worker->name, worker->age);

	//-----------------------------------------------------------------//

	// 对第10个数据进行操作
	worker += 9;
	strcpy_s(worker->name , "Novate9");
	worker->age = 9;
	// name = Novate9 , age = 9
	printf("name = %s , age = %d", worker->name, worker->age);
	getchar();
}*/

/*// 结构体大小计算：代码1
struct Worker{
	int age;  // int占4字节
	double salary; // double占8字节
};

void main(){

	int size = sizeof(Worker);
	// size = 16
	printf("size = %d" , size);
	getchar();
}*/

/*// 结构体大小计算：代码2
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

/*// 结构体大小计算：代码3
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

/*// 结构体和结构体指针取别名
struct Worker{
	char name[10];
	int age;
	double salary;
};

// 给Worker取一个别名
typedef Worker Worker_;

void main(){

	// 然后可以用别名 Worker_来操作
	Worker_ worker = {"Novate" , 27 , 27};
	// Novate , 27 , 27.000000
	printf("%s , %d , %lf" , worker.name , worker.age , worker.salary);
	getchar();
}*/

/*// 结构体
struct Worker_{
	char name[10];
	int age;
	double salary;
};

// 给结构体取别名
typedef Worker_ Worker_;
// 给结构体先取一个指针，叫做Worker*，然后给 Worker*指针取一个别名
typedef Worker_* Worker;

void main(){

	Worker worker = (Worker_*)malloc(sizeof(Worker));
	printf("%s , %d , %lf", worker->name, worker->age, worker->salary);
	getchar();
}*/


/*// 定义一个联合体
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

// 枚举
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
