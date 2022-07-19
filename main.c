#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    seqList *S = listCreate();
	if(NULL==S)
	{
		return -1;
	}
	//调用添加函数
	listAdd(S,7);
	listAdd(S,2);
	listAdd(S,5);	
	listAdd(S,6);
	listAdd(S,4);
	listAdd(S,4);
	listAdd(S,4);
	listAdd(S,7);
	listAdd(S,8);
	listShow(S);
	//调用选择排序
	listSort2(S);
	listShow(S);
	//listShow(S);
	//listInsertPos(S,1,8);
	//listShow(S);
	//listDeletePos(S,2);
	//listShow(S);

	//int res = listSearchValue(S,100);
	//if(res>=0)
	//{
	//	printf("查找成功，在第%d个位置\n",res+1);
	//}
	//else if(res==-1)
	//{
	//	printf("表空，查找失败\n");
	//}
	//else if(res==-2)
	//{
	//	printf("没找到您要查找的元素\n");
	//}
	////按位置修改
	//listUpdatePos(S,2,100);
	//listShow(S);
	////调用排序函数
	//listSort2(S);
	//listShow(S);
	//listUpdateValue(S,7,50);
	//listShow(S);
	////调用去重函数
	//listDeleteRepeat(S);
	//listShow(S);
	////调用释放表函数
	//listFree(S);
	//S=NULL;
	//listShow(S);
}
