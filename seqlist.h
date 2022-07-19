#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#define MAX 20
typedef int datatype;

typedef struct
{
	datatype data[MAX];//存储顺序表的数组
	int len;           //表示顺序表长度
}seqList;

seqList* listCreate();
int listEmpty(seqList *S);
int listFull(seqList *S);
int listAdd(seqList *S,datatype e);
void listShow(seqList *S);

//任意位置插入
int listInsertPos(seqList *S,int pos,datatype e);

//任意位置删除
int listDeletePos(seqList *S ,int pos);

//按值查找
int listSearchValue(seqList *S,datatype e);

//按位置查找
datatype listSearchPos(seqList *S,int pos);

//按值修改
int listUpdateValue(seqList *S,datatype old_e,datatype new_e);

//按位置修改
int listUpdatePos(seqList *S,int pos,datatype new_e);

//选择排序
void listSort2(seqList *S);

//冒泡排序
void listSort(seqList *S);

//去重
void listDeleteRepeat(seqList *S);

//释放表
void listFree(seqList *S);
#endif
