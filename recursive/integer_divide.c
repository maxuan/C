#include <stdio.h>
#include <stdlib.h>

int count = 0;
int num = 6;
int top = 0;


void printa(int *a){
    int i = 0;
    printf("%d=", num);
    while(i<top){
        printf("%d", a[i++]);
        if(i<top){
            printf("+");
        }
    }
    printf("\n");
}

void divide(int n, int m, int*a){
    if(1==n||1==m){
        count+=1;
        int t = 0;
        while(t<n){
            t++;
            a[top++] = 1;
        }
        printa(a);
        top=top-n;
    }else if(n<m){
        divide(n, n, a);
    }else if(n==m){
        a[top++]=m;
        count+=1;
        printa(a);
        top--;
        divide(n, m-1,a);
    }else if(n>m){
        a[top++] = m;
        divide(n-m, m, a);
        top--;
        divide(n, m-1, a);
    }
}

int main(void){

    int *a;

    while (scanf("%d", &num) != EOF)
    {
        a = (int*)malloc(sizeof(int)*num);
        divide(num,num,a);
        //add();
        printf("%d的划分数为%d\n", num, count);
        free(a);
    }
    return 0;
}