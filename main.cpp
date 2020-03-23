#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

int mainK;

///----FillInc---------------///
void FillInc (int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=o+1;
    //printf("FillInc\n");
}
///----FillDec---------------///
void FillDec (int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=n-o;
    //printf("FillDec\n");
}
///----FillRand--------------///
void FillRand(int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=rand()%100+1;
}
///----PrintMas--------------///
void PrintMas(int num[], int n)
{   int o;
    printf("|");
    for (o=0;o<n;o++)
        printf("%2d|",num[o]);
    printf("\n");
}

///InsertSort
void InsertSort(int *A, int n, int &Mf, int &Cf)
{
    int i,b,j;
    for(i=1;i<n;i++) {
        Cf++;Mf++;b=A[i]; j= i - 1;
        for(;j>=0&& b < A[j];)
        {
            Cf++;
            A[j + 1]=A[j];Mf++;
            j=j-1;
        }
        A[j + 1]=b,Mf++;
    }
}

///ShellSort
void ShellSort(int *A, int n, int &Mf, int &Cf)
{
    int k,h,t,j,o,p;
    h=n/2;
    for(k=h;k>=1;)
    {
        for(o=k;o<n;o++)
        {
            Cf++;Mf++;t=A[o]; j= o - k;
            for(;j>=0&& t < A[j];)
            {
                Cf++;
                A[j + k]=A[j];Mf++;
                j=j-k;
            }
            A[j + k]=t;Mf++;
        }
        //printf("%d\n",k);
        k=k/2;
        mainK += k;
    }

}

/////ShellSortKnut
//void ShellSortKnut(int *A, int n, int &Mf, int &Cf)
//{
//    int k,h=0,t,j,o,p,u,y;
//    float m;
//    m=(log(n)/log(2))-1;
//    for (y=1;y<=m;y++) h=2*h+1;
//    for(k=h;k>=1;)
//    {
//        for(o=k;o<n;o++)
//        {
//            Cf++;Mf++;t=A[o]; j= o - k;
//            for(;j>=0&& t < A[j];)
//            {
//                Cf++;
//                A[j + k]=A[j];Mf++;
//                j=j-k;
//            }
//            A[j + k]=t;Mf++;
//        }
//        m--;
//        //printf("%d\n",k);
//        k-=pow(2,(int)m);
//
//    }
//
//}

///Knut
int Knut(int n)
{
    int m;
    m=(log(n)/log(2))-1;
    return m;
}

///neKnut
int neKnut(int n)
{
    int u=0;
    while (n>1)
    {n=n/2;u++;}
    return u;
}

/////ShellSortKnutdem
//void ShellSortKnutdem(int *A, int n, int &Mf, int &Cf)
//{
//    int k,h=0,t,j,o,p,u,y;
//    float m;
//    m=(log(n)/log(2))-1; p=m;
//    printf("|-Количество шагов = %d\n",Knut(n));
//    for (y=1;y<=m;y++) h=2*h+1;
//    for(k=h;k>=1;)
//    {
//        for(o=k;o<n;o++)
//        {
//            Cf++;Mf++;t=A[o]; j= o - k;
//            for(;j>=0&& t < A[j];)
//            {
//                Cf++;
//                A[j + k]=A[j];Mf++;
//                j=j-k;
//            }
//            A[j + k]=t;Mf++;
//        }
//        m--;
//        printf("|-h%d=%d\n",p,k);p--;
//        k-=pow(2,(int)m);
//    }
//}
void SortCount(int *mas, int k){
    int Mf,Cf,C,M;
    printf("Before sort: ");
    PrintMas(mas,k);
    printf("\nAfter sort: ");
    Mf=0; Cf=0;
    ShellSort(mas,k,Mf,Cf);
    PrintMas(mas,k);
}

void MainFunction(int *A, int n){
    int  Mf,Cf,Is,Shs;


    FillRand(A,n);
    Mf=0; Cf=0;
    InsertSort(A,n,Mf,Cf);
    Is=Mf+Cf;

    FillRand(A,n);
    Mf=0; Cf=0;
    ShellSort(A,n,Mf,Cf);
    Shs=Mf+Cf;


    printf("|%5d|%12d         |%12d         |%12d         |\n",n,Knut(n),Is,Shs);
    printf("+-----+---------------------+---------------------+---------------------+\n");
}

void tablishka(int *A, int n){
    int  Mf,Cf,ShsKnut,Shs;
    FillRand(A,n);
    Mf=0; Cf=0;
    ShellSort(A,n,Mf,Cf);
    ShsKnut=Mf+Cf;
    FillRand(A,n);
    Mf=0; Cf=0;
    ShellSort(A,n,Mf,Cf);
    Shs=Mf+Cf;
    printf("|%5d|%12d         |%12d         |%12d         |%12d         |\n",n,Knut(n),ShsKnut,neKnut(n),Shs);
    printf("+-----+---------------------+---------------------+---------------------+---------------------+\n");
}

int main() {
    int n;
    printf("+-----+---------------------+---------------------+---------------------+\n");
    printf("|  n  |          K          |    Mf+Cf Insert.    |     Mf+Cf Shell.    |\n");
    printf("+-----+---------------------+---------------------+---------------------+\n");
    int* A;
    n = 100;
    A=(int *)malloc(500*sizeof(int));
    MainFunction(A, n);
    n=200;
    MainFunction(A, n);
    n=300;
    MainFunction(A, n);
    n=400;
    MainFunction(A, n);
    n=500;
    MainFunction(A, n);


    printf("\n");
    printf("+-----+---------------------+---------------------+---------------------+---------------------+\n");
    printf("|  n  |        Knut.        |    Mf+Cf Shell.     |       Ne Knut.      |     Mf+Cf Shell.    |\n");
    printf("+-----+---------------------+---------------------+---------------------+---------------------+\n");
    n=100;
    tablishka(A, n);
    n=200;
    tablishka(A, n);
    n=300;
    tablishka(A, n);
    n=400;
    tablishka(A, n);
    n=500;
    tablishka(A, n);


}
