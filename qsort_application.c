/*
输入学生信息：姓名，年龄，分数。按照分数递增排序并输出结果
主要是对qsort的应用。
可以转化为cpp程序，利用重载以及sort进行排序
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char name[20];
    int age;
    int score;
}node;
int cmp(const void *a,const void *b){//返回-1时a在前面
     node * pa=(node *)a;
     node * pb=(node *)b;
     int tmp;
     if((*pa).score!=(*pb).score)
         return (*pa).score>(*pb).score;//按照分数递增排序
     tmp=strcmp((*pa).name,(*pb).name);
     if(tmp!=0)
         return tmp>0;//分数相等按名字字典序递增排序
      else return (*pa).age>(*pb).age;//否则按照年龄递增排序
}
int main(){
    int n,i;
    node stu[1000];
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
           scanf("%s %d %d",stu[i].name,&stu[i].age,&stu[i].score);
        qsort(stu,n,sizeof(stu[0]),cmp);
        for(i=0;i<n;i++)
            printf("%s %d %d\n",stu[i].name,stu[i].age,stu[i].score);
    }
    return 0;
}
