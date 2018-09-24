#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>



/*// ×Ö·û´®½ØÈ¡
char* substr(char *str, int start, int end){

	// 1. ¿ª±ÙÒ»¸ö×Ö·û´®£¬ÓÃÓÚ´æ´¢ÎÒÃÇµÄÊı¾İ
	// ËùĞèÒªµÄ×Ö·û´®µÄ³¤¶È
	// char sub[end - start];  // ÕâÖÖ²»ĞĞ
	int len = end - start;
	char *sub = (char*)malloc(len * sizeof(char)+1);  // ÕâÀï¼ÇµÃ+1£¬ÔÚAndroid StudioµÄ NDKÖĞÒ»°ã»á²ÉÓÃ¾²Ì¬µÄÊı×é´æ´¢£¬Èç char sub[len]

	// 2. È»ºó±éÀú¸³Öµ
	str += start; // Ö¸Õë++
	int i = 0;
	for (; i < len; i++){
		sub[i] = *str;  // *str:±íÊ¾È¡Öµ
		str++;  // Ö¸ÕëÍùºóÅ²¶¯Ò»Î»
	}

	// 3. ±ê¼Ç×Ö·û´®½áÎ²£¬·ñÔò printÎŞ·¨ÅĞ¶Ï½áÎ²
	sub[len] = '\0';
	return sub;
}

// ×Ö·û´®µÄÌæ»»
char *str_replace(char *str , char *src  ,char *dst){
	// 1. Ê×ÏÈÅĞ¶Ï strÖĞÓĞÃ»ÓĞaa 
	char *pos = strstr(str , src);  // ·µ»ØµÄÊÇ×Ö·û´®µÚÒ»´Î³öÏÖµÄÎ»ÖÃ(Î»ÖÃÖ¸Õë)£¬Èç¹ûÃ»ÓĞÕÒµ½·µ»ØµÄÊÇ¿Õ

	// µİ¹éµÄ½áÊøÓï¾ä
	if (!pos){  // !pos µÈ¼ÛÓÚ if(pos != NULL)
		return str;  // Èç¹ûpos²»Îª¿Õ£¬±íÊ¾ strÖĞÓĞ aa
	}

	// 2. Èç¹ûÓĞaa£¬ÔÚÓÃccc°ÑaaÌæ»»Ö®ºó£¬ĞèÒª¼ÆËãĞÂµÄÊı×é´óĞ¡£»
	// Ô­À´Êı×éµÄ´óĞ¡ - ±»Ìæ»»µÄ´óĞ¡ + Ìæ»»µÄ´óĞ¡
	int newArraySize = strlen(str) - strlen(src) + strlen(dst);
	// ¿ª±ÙÒ»¸öĞÂµÄÊı×é
	char *result = (char*)malloc(sizeof(char) * newArraySize);

	// 3. ½øĞĞÆ´½Ó
	// ´ÓµÚÒ»¸öaµ½ÔÚÒ»ÆğµÄ×îºóÒ»¸öaµÄÎ»ÖÃ
	int start_end_position = pos - str;
	// a. Ê×ÏÈ°Ñ aa ÄÃ³öÀ´
	char *start = substr(str , 0 , start_end_position);

	// ÖĞ¼äµÄ×Ö·û´®£¬¾ÍÊÇĞèÒªÌæ»»µÄ×Ö·û´®£¬¾ÍÊÇ´«µİ¹ıÀ´µÄdst

	// src£ºÊÇĞèÒªÌæ»»µÄ×Ö·û´®
	// ×îºóµÄ×Ö·û´®£ºÍ¬ÑùĞèÒª½ØÈ¡
	int end_start_position = start_end_position + strlen(src);
	char *end = substr(str , end_start_position , strlen(str));  // ½ØÈ¡str×Ö·û´®£¬´Óend_start_positionÎ»ÖÃ½ØÈ¡µ½×Ö·û´®×îºó±ß

	// Æ´½Ó
	// Ê×ÏÈ°Ñ ¿ªÊ¼µÄstart×Ö·û´®¸´ÖÆµ½ĞÂµÄÊı×éÖĞ£¬È»ºó°ÑÖĞ¼äµÄºÍ×îºóµÄ×Ö·û´®Æ´½ÓÆğÀ´
	strcpy(result , start);
	strcat(result , dst);
	strcat(result , end);

	// 4. Èç¹ûsrcÖĞÓĞ¶à¸öaa£¬¾ÍĞèÒª½øĞĞ¶à´ÎÌæ»»£¬¿ÉÒÔÊ¹ÓÃ whileÑ­»·»òµİ¹é
	return str_replace(result,src,dst);
}


// ×Ö·û´®µÄÌæ»»
void main(){

	// °Ñaabbaabbaabb ÖĞµÄaa ¶¼Ìæ»»Îª cc
	char *str = str_replace("aabbaabbaabb" , "aa" , "ccc");
	printf("str = %s" , str);  // str = cccbbcccbbcccbb
	getchar();
}*/

// ¶¨ÒåÒ»¸ö½á¹¹Ìå£¬Ïàµ±ÓÚjavaÖĞµÄclass£¬µ«ÊÇÕâÀïÃ»ÓĞ¼Ì³Ğ»òÕßÆäËû

// µÚÒ»ÖÖ¶¨Òå·½Ê½£º
/*struct Worker{
	char name[10];
	int age;
	double salary;
};

void main(){

	struct Worker worker = {"Novate" , 26 , 1000};  // ³õÊ¼»¯½á¹¹Ìå

	// ¸ø×Ö¶Î¸³Öµ
	// worker.name = "Novate";
	strcpy(worker.name , "Jack Chen");
	worker.age = 27;
	printf("name = %s , age = %d , salary = %lf" , worker.name , worker.age , worker.salary);  // name = Novate , age = 27 , salary = 1000.000000
	getchar();
}*/


/*// µÚ¶şÖÖ¶¨Òå·½Ê½£º¿ÉÒÔÖ±½ÓÈ¡Ãû×Ö
struct Worker{
	char name[10];
	int age;
	double salary;
}novate, jackchen;  // ÕâÖÖ·½Ê½»áÓĞÒ»¸öÄ¬ÈÏ³õÊ¼Öµ£¬Èç¹ûÔÚ main()·½·¨ÖĞ²»Ö¸¶¨strcpy_s(jackchen.name , "JackChen")£¬´òÓ¡³öµÄjackchen.nameÒ²ÊÇÓĞÖµµÄ£¬Ö»²»¹ıÊÇÕâ¸ö "" 

void main(){

	strcpy_s(jackchen.name , "JackChen");
	jackchen.age = 27;

	// name = JackChen , age = 27 , salary = 0.000000
	printf("name = %s , age = %d , salary = %lf", jackchen.name, jackchen.age, jackchen.salary);
	getchar();
	}*/

/*// µÚÈıÖÖ¶¨Òå·½Ê½£º
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

/*// µÚËÄÖÖ·½Ê½£º½á¹¹ÌåµÄÇ¶Ì×£¬ºÜÉÙÓÃ
struct Work{  // ¹¤×÷
char name[10];   // ¹¤×÷µÄÃû×Ö
char grade[10];  // ¹¤×÷µÄµÈ¼¶
};
struct Worker{
char name[10];
int age;
double salary;

// ÕâÀï¿ÉÄÜ»¹ÓĞÆäËûÊôĞÔ£¬¾ÍÓÖÒª¶¨Òå½á¹¹Ìå
Work work;
};

void main(){

struct Worker worker = { "Novate", 23, 1000, {"Android" , "ÖĞ¼¶"}};  // Ç¶Ì×µÄ¸³³õÊ¼Öµ
// name = Android , grade = ÖĞ¼¶
printf("name = %s , grade = %s" , worker.work.name , worker.work.grade);

getchar();
}*/

/*// µÚ5ÖÖ·½Ê½£º½á¹¹ÌåÇ¶Ì×£¬°ÑWorkµÄ½á¹¹ÌåĞ´µ½ WorkerµÄÀï±ß
struct Worker{
char name[10];
int age;
double salary;

// ¹¤ÈËµÄ¹¤×÷
struct Work{
char name[10];
char grade[10];
};
Work work;
};

void main(){

struct Worker worker = { "Novate", 23, 1000, { "Android", "ÖĞ¼¶" } };  // Ç¶Ì×µÄ¸³³õÊ¼Öµ
// name = Android , grade = ÖĞ¼¶
printf("name = %s , grade = %s", worker.work.name, worker.work.grade);
getchar();
}*/

/* ¶¨Òå½á¹¹ÌåÖ¸Õë£ºµÚÒ»ÖÖ·½·¨
struct Worker{
char name[10];
int age;
double salary;

// ¹¤ÈËÓĞ¹¤×÷£ºname£¬grade
// Work work;
};

// ½á¹¹ÌåÖ¸Õë
void main(){

// ½á¹¹Ìå³õÊ¼»¯¸³Öµ
struct Worker worker = { "Novate", 26 };

// ¸ø ½á¹¹ÌåworkerÈ¡µØÖ· £¬ÓÃÖ¸Õë±äÁ¿À´½ÓÊÕ£¬ÏÖÔÚ¿ÉÒÔÈÏÎª¶şÕßÒ»Ñù
Worker *worker_p = &worker;
// Í¨¹ı ½á¹¹ÌåÖ¸Õë ¿ÉÒÔ²Ù×÷Êı¾İ:
// »ñÈ¡Öµ»òÕßĞŞ¸ÄÖµ¶¼ÓÃ ->

// ½á¹¹ÌåĞŞ¸ÄÖµ£¬Ê¹ÓÃµÄÊÇ .µã
worker.age = 27;

// ½á¹¹ÌåÖ¸ÕëĞŞ¸ÄÖµ£¬Ê¹ÓÃµÄÊÇ ->
// ½á¹¹Ìå²Ù×÷µÄÁíÍâÒ»ÖÖ·½Ê½£¬ºÜ³£ÓÃ
worker_p->age = 27;
strcpy_s(worker_p -> name , "JackChen");

// name = JackChen , age = 27
printf("name = %s , age = %d" , worker_p->name , worker_p->age);
getchar();
}*/


/*¶¨Òå½á¹¹ÌåÖ¸Õë£ºµÚ¶şÖÖ·½·¨
struct Worker{
	char name[10];
	int age;
	double salary;
};
// ¶¨Òå½á¹¹ÌåÖ¸Õë
void main(){

	// Worker *worker; // ´´½¨ÁËÒ»¸ö½á¹¹ÌåÖ¸Õë,Ö¸ÕëÃ»ÓĞ³õÊ¼»¯
	Worker *worker = (Worker*)malloc(sizeof(Worker));
	strcpy_s(worker->name, "jackchen");
	worker->age = 27;
	// name = jackchen , age = 27
	printf("name = %s , age = %d", worker->name, worker->age);
	// ÊÍ·Å
	if (worker){
		free(worker);
		worker = NULL;
	}
	
	getchar();
	}*/


/*// ½á¹¹ÌåÊı×é
struct Worker{
	char name[10];
	int age;
	double salary;
};

void main(){

	// ´´½¨½á¹¹ÌåÊı×é
	// µÚÒ»ÖÖ£º¾²Ì¬¿ª±Ù
	// Worker worker[10] = { {"Novate" , 26 , 1000}, {}, {} };  // ´´½¨10¸ö½á¹¹Ìå£¬ÕâÖÖ·½Ê½½Ğ×ö¾²Ì¬¿ª±Ù
	// worker[9] = {"Novate9" , 27 , 1000};
	// name = Novate9 , age = 27
	// printf("name = %s , age = %d\n", worker[9].name, worker[9].age);

	//-----------------------------------------------------------------//

	// µÚ¶şÖÖ£º¶¯Ì¬ÄÚ´æ¿ª±Ù£ºWorker*´ú±í½á¹¹ÌåÖ¸Õë
	// ÓÃ¶¯Ì¬¿ª±Ù·½Ê½£¬´´½¨10¸ö½á¹¹Ìå£¬
	Worker *worker = (Worker*)malloc(sizeof(Worker)* 10);
	// strcpy_s(worker->name , "Novate0");
	// worker->age = 10;
	// name = Novate0 , age = 10
	// printf("name = %s , age = %d", worker->name, worker->age);

	//-----------------------------------------------------------------//

	// ¶ÔµÚ10¸öÊı¾İ½øĞĞ²Ù×÷
	worker += 9;
	strcpy_s(worker->name , "Novate9");
	worker->age = 9;
	// name = Novate9 , age = 9
	printf("name = %s , age = %d", worker->name, worker->age);
	getchar();
}*/

/*// ½á¹¹Ìå´óĞ¡¼ÆËã£º´úÂë1
struct Worker{
	int age;  // intÕ¼4×Ö½Ú
	double salary; // doubleÕ¼8×Ö½Ú
};

void main(){

	int size = sizeof(Worker);
	// size = 16
	printf("size = %d" , size);
	getchar();
}*/

/*// ½á¹¹Ìå´óĞ¡¼ÆËã£º´úÂë2
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

/*// ½á¹¹Ìå´óĞ¡¼ÆËã£º´úÂë3
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

/*// ½á¹¹ÌåºÍ½á¹¹ÌåÖ¸ÕëÈ¡±ğÃû
struct Worker{
	char name[10];
	int age;
	double salary;
};

// ¸øWorkerÈ¡Ò»¸ö±ğÃû
typedef Worker Worker_;

void main(){

	// È»ºó¿ÉÒÔÓÃ±ğÃû Worker_À´²Ù×÷
	Worker_ worker = {"Novate" , 27 , 27};
	// Novate , 27 , 27.000000
	printf("%s , %d , %lf" , worker.name , worker.age , worker.salary);
	getchar();
}*/

/*// ½á¹¹Ìå
struct Worker_{
	char name[10];
	int age;
	double salary;
};

// ¸ø½á¹¹ÌåÈ¡±ğÃû
typedef Worker_ Worker_;
// ¸ø½á¹¹ÌåÏÈÈ¡Ò»¸öÖ¸Õë£¬½Ğ×öWorker*£¬È»ºó¸ø Worker*Ö¸ÕëÈ¡Ò»¸ö±ğÃû
typedef Worker_* Worker;

void main(){

	Worker worker = (Worker_*)malloc(sizeof(Worker));
	printf("%s , %d , %lf", worker->name, worker->age, worker->salary);
	getchar();
}*/


/*// ¶¨ÒåÒ»¸öÁªºÏÌå
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

// Ã¶¾Ù
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
