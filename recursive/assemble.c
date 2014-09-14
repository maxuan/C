#include <stdio.h>
#include <stdlib.h>

int MAX = 100000;
int *b,top=0;
int count = 0;

void printA(int*a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void assem(int n,int m,int *a){
    if(n < m || m==0)
    {
        return ;
    }
    assem(n-1,m,a+1);//不包含当前元素的所有的组合
    b[top++]=a[0];//包含当前元素
    if(m==1){  //截止到当前元素
        printA(b,top);
        printf("\n");
        count++;
        top--;
        return;
    }
    assem(n-1,m-1,a+1);//包含当前元素但尚未截止
    top--;//返回前恢复top值
}

int main(){

    int n=0,m=0,*a;
    printf("%s\n", "请输入一组数字，数字之间用空格隔开，以回车结束");
    a = (int*)malloc(sizeof(int)*MAX);
    while(scanf("%d",&a[n++])){
        if(getchar()=='\n')
            break;
    }

    printf("请输入需要选取的个数:(<%d)\n", n);

    b = (int*)malloc(sizeof(int)*n);
    if(scanf("%d",&m)){
        assem(n,m,a);
    }
    printf("结果:C（%d，%d）共计：%d个",n,m,count);
    free(a);
    free(b);

    return 0;
}