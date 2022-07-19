#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建顺序表
seqList* listCreate()
{
	//在堆区申请一个顺序表的空间，将申请的地址给S
	seqList *S=(seqList*)malloc(sizeof(seqList));
	if(NULL==S)
	{
		printf("申请空间失败\n");
		return NULL;
	}
	memset(S->data,0,sizeof(S->data)); //将数组清零
	S->len = 0;                        //顺序表长度初始化

	//printf("创建成功\n");
	return S;
}

//判空
int listEmpty(seqList *S)
{
	if(NULL==S)
	{
		printf("所给顺序表不合法\n");
		exit(0);
	}
	return S->len==0?1:0;    //0表示非空，1表示空
}
//判满
int listFull(seqList *S)
{
	return S->len==MAX?1:0;   //0表示不满，1表示满
}

//添加元素
int listAdd(seqList *S,datatype e)
{
	//判断逻辑
	if(listFull(S))
	{
		printf("表满，添加失败\n");
		return -1;
	}
	//添加逻辑
	S->data[S->len]=e;

	//表的变化
	S->len++;
	//printf("添加成功\n");
	return 0;
}
//遍历函数
void listShow(seqList *S)
{
	//判断逻辑
	if(listEmpty(S))
	{
		printf("空空如也，遍历失败\n");
		return;
	}
	printf("目前顺序表中元素分别是：");
	for(int i=0;i<S->len;i++)
	{
		printf("%d\t",S->data[i]);
	}
	printf("\n");
}

//任意位置插入
int listInsertPos(seqList *S,int pos,datatype e)
{
	//判断逻辑
	if(listFull(S))
	{
		printf("表满，插入失败\n");
		return -1;
	}
	if(pos<0||pos>S->len)
	{
		printf("位置不合法，插入失败\n");
		return -2;
	}

	//腾空
	for(int i=S->len-1;i>=pos;i--)
	{
		S->data[i+1]=S->data[i];
	}

	//插入数据
	S->data[pos]=e;
	//表的变化
	S->len++;
	printf("插入成功\n");
	return 0;
}

//任意位置删除
int listDeletePos(seqList *S ,int pos)
{
	//判断逻辑
	if(listEmpty(S))
	{
		printf("表空，删除失败\n");
		return -1;
	}
	if(pos<0||pos>S->len-1)
	{
		printf("位置不合法，删除失败\n");
		return -2;
	}
	//删除逻辑
	for (int i=pos+1;i<S->len;i++)
	{
		S->data[i-1]=S->data[i];
	}
	//表的变化
	S->len--;
	printf("删除成功\n");
	return 0;
}
//按值查找
int listSearchValue(seqList *S,datatype e)
{
	//判断逻辑
	if(listEmpty(S))
	{
		printf("空表，查找失败\n");
		return -1;   //表空
	}
	//查找逻辑
	for(int i=0;i<S->len;i++)
	{
		if(e==S->data[i])        //跟任意一个元素比较
		{
			return i;
		}
	}
	return -2;     //表中没找到
}

//按位置查找
datatype listSearchPos(seqList *S,int pos)
{
	if(pos<0||pos>=S->len)
	{
		printf("位置不合法，查找失败\n");
		return -1;
	}
	printf("查找成功，索引%d位置上的元素是%d\n",pos,S->data[pos]);
	return S->data[pos];
}
//按值修改
int listUpdateValue(seqList *S,datatype old_e,datatype new_e)
{
	int pos=listSearchValue(S,old_e);
	if(pos>=0)
	{
		S->data[pos]=new_e;
		printf("修改成功\n");
		return 0;
	}
	else
	{
		printf("修改失败\n");
		return -1;
	}
}
//按位置修改
int listUpdatePos(seqList *S,int pos,datatype new_e)
{
	//判断逻辑
	if(pos<0||pos>S->len-1)
	{
		printf("修改失败\n");
		return -1;
	}
	//修改逻辑
	S->data[pos]=new_e;
	printf("修改成功\n");
	return 0;
}
//冒泡排序
void listSort(seqList *S)
{
	int i,j;    //循环变量
	datatype temp;   //交换变量
	for(i=0;i<S->len-1;i++)  //比较趟数
	{
		for(j=0;j<S->len-i-1;j++)  //元素    比较次数
		{
			if(S->data[j]>S->data[j+1])
			{
				temp=S->data[j];
				S->data[j]=S->data[j+1];
				S->data[j+1]=temp;
			}
		}
	}
	printf("排序成功\n");
}
//选择排序
void listSort2(seqList *S)
{
	for(int i=0;i<S->len-1;i++)
	{
		datatype max =S->data[i];
		int index=i;
		for(int j=i+1;j<S->len;j++)
		{
			if(max<S->data[j])
			{
				index=j;
				max=S->data[j];
			}
		}
		if(index!=i)
		{
			datatype temp = S->data[index];
			S->data[index]=S->data[i];
			S->data[i]=temp;
		}
	}
	printf("排序成功\n");
}

//去重
void listDeleteRepeat(seqList *S)
{
	for(int i=0;i<S->len;i++)
	{
		for(int j=i+1;j<S->len;j++)
		{
			if(S->data[i]==S->data[j])
			{
				listDeletePos(S,j);
				j--;
			}
		}
	}
}

//释放表
void listFree(seqList *S)
{
	if(NULL!=S)
	{
		free(S);
	}
	S=NULL;          //防止野指针
	printf("释放成功\n");
}


