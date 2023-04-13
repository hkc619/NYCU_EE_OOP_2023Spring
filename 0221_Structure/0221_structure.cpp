// 0221_structure.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#define swap(x,y,t) ((t) = (x),(x) = (y), (y) = (t))
#define max 100
class ABC
{
    //member variable (data):variable pointer array
    int a, b, c;
    //member function 副程式
    int sorting1(int*, int)
    {
        //
    }
    
}abc[4];
struct Data
{
    //變數 指標 陣列
    char name[10];
    int score[4];
    int total;
    int average;
    int id;
    int rank;
};
Data data[max]; //配置資料結構陣列
  
void printout(Data* lp, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %2d %2d %2d %2d 總分%3d 座號%2d 名次%2d\n",
            lp->name,
            lp->score[0],
            lp->score[1],
            lp->score[2],
            lp->score[3],
            lp->total,
            lp->id,
            lp->rank);
        lp++;
    }
}

void sorting(Data* lp, int n)    
{
    Data tmp, * pi, * pj;
    int l = sizeof(Data);//sizeof 'D'ata
    for (int i = 0; i < n-1; i++)
    {
        pi = &data[i];//要在這先打
        for (int j = i+1; j < n; j++)//j = i+1 而不是j = 1
        {
            pj = &data[j];//要分開打
            if ((pi->total) < (pj->total))
            {    
                //swap(pi, pj, &tmp);
                memcpy(&tmp, pi, l);
                memcpy(pi, pj, l);
                memcpy(pj, &tmp, l);
            }
        }
        pi->rank = i+1 ;
    }
    lp[n - 1].rank = n;//補上最後一個
}

void estimate(Data* lp, int n, float a[][4])
{
    //1.max
    for (int i = 0; i < 4; i++)
    {
        a[i][2] = 0;
        a[i][3] = 0;
        for (int j = 0; j < n; j++)
        {
            if ((j == 0) || (a[i][0] < lp[j].score[i]))//1.max
            {//代替設起始值
                a[i][0] = (float)lp[j].score[i];
            }
            if ((j == 0) || (a[i][1] > lp[j].score[i]))//2.min
            {
                a[i][1] = (float)lp[j].score[i];
            }
            a[i][2] += (float)lp[j].score[i];//3.mean
            a[i][3] += pow(lp[j].score[i], 2);//4.std_dev
        }
        a[i][2] /= n;
        a[i][3] /= n;
        a[i][3] -= a[i][2] * a[i][2];
        a[i][3] = sqrt(a[i][3]);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%f\n", a[j][i]);
    }
}

int main()
{
    //1.open & read
    errno_t err;
    FILE* In;
    int no = 0;
    Data* lp;
    if ((err = fopen_s(&In, "Book1.txt","rb")) != 0)
    {
        printf("Book1.txt error/n");
        return -1;
    }
    
    
    while (!feof(In))
    {
        /*
        fscanf_s(In, "%s %d %d %d %d %d",
            data[no].name, 10,
            data[no].score + 0,//same as &data[no].score[0]
            data[no].score + 1,
            data[no].score + 2,
            data[no].score + 3);//指標
        */
        //1. . ->使用方式取決於前面是變數或指標 
        //2. 整串資料結構鍊之前面加& * 時，只會作用於資料鍊最後端之變數或指標
        //3. &A[2] 等同於A+2 都是記憶體運算
        lp = &data[no];
        fscanf_s(In, "%s %d %d %d %d ",
            lp->name,10,
            lp->score + 0,
            lp->score + 1,
            lp->score + 2,
            lp->score + 3);
        lp->total = lp->score[0] + lp->score[1] + lp->score[2] + lp->score[3];
        //lp->total = *lp->score + (* lp->score+1) + (*lp->score + 2) + (*lp->score + 3);
        lp->average = (float)lp->total / 4;
        lp->id = no + 1;
        no++;
    }
    //2.sort
    sorting(data, no);
    //3.print
    printout(data, no);
    //4.hw mean and std_dev of 4 
    float a[4][4];
    estimate(data, no, a);
}

