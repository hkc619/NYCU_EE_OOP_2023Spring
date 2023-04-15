// 0307_class.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
//book1:姓名成績資料
// 定義資料結構 last week
#define max 100
struct data
{
	char name[10];
	int score[4];
	
};


// 定義類別(祖父類別 處理排序
class grandpa
{
	void sorting(data* lp, int no);
};

// 定義類別(父類別 處理總分 平均 標準差
class father:public grandpa // 繼承祖父類別
{
public:
	void sum(data* lp, int no);
	void mean(data* lp, int no);
	void std_dev(data* lp, int no);
};

// 定義類別(子類別 處理檔案資料 
class child:public father // 繼承父類別
{
public://讓大家用 
	// member variable(成員變數)
	int no;		   //使用者人數
	data Data[max];//使用者資料
	// member function(成員函式)
	child();//建構式
	~child();//解構式
	int read_file(char* file/*, data* lp*/);//第一個副程式 讀取檔案資料
	int print(/*data* lp, int no*/);//列印資料
private:
	char id[max];
};
//常用
child::child() //建構式
{
	printf("您已配置了child物件\n");
	no = 0;
}

child::~child() //解構式
{
	printf("您已刪掉了child物件\n");
	no = 0;
}

//讀取檔案資料
int child::read_file(char* file/*, data* lp*/)
{
	errno_t err;
	FILE* in;
	
	data* lp = Data;
	if((err = fopen_s(&in, file, "rb"))!=0)
		return -1;
	no = 0;
	while (!feof(in))
	{
		//lp = &data[no++];
		fscanf_s(in, "%s %d %d %d %d\n", lp->name, 10, lp->score, lp->score + 1, lp->score + 2, lp->score + 3);
	  //fscanf_s(in, "%s %d %d %d %d\n", lp->name, 10, lp->score, &lp->score[1], lp->score + 2, lp->score + 3);
		lp++;
		no++;
	}
	fclose(in);
	return no;
}

// 列印檔案資料
int child::print(/*data* lp, int no*/)
{
	data *lp = Data;
	for (int i = 0; i < no; i++)
	{
		printf("%s %d %d %d %d\n", lp->name, lp->score[0], lp->score[1], lp->score[2], lp->score[3]);
		lp++;
	}
	return 0;
}

int main()
{
	//1. 物件宣告與配置
	child* p;		//物件指標p
	p = new child();//從外面配置物件 p之實體 副程式也配給他(data + fuction)
	child* q = new child(); //配置物件 q之實體
	child r; //屬於main 裡面的 不需刪除

	//2. 讀取檔案
	/*int no; */
	/*no = */p->read_file((char*)"Book1.txt"/*, p->Data*/);
	/*no = */q->read_file((char *)"Book1.txt"/*, q->Data */ );
	/*no = */r.read_file((char*)"Book1.txt"/*, r.Data */ );

	//3.列印檔案
	p->print(/*p->Data, p->no*/);

	//4.印出第一人(ID=0)的姓名
	printf("ID = 0 's name is %s \n", p->Data[0].name);
	printf("ID = 10 's name is %s \n", (q->Data+10)->name);
	printf("ID = 20 's name is %s \n", (r.Data+20)->name);

	delete p;
}


