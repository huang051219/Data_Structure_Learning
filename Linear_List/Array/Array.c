#include<stdlib.h>
#include<stdio.h>


#define MAXSIZE 100


// 定义结构体
typedef int ElementType;
struct Lnode{
    ElementType Data[MAXSIZE];  //此处采用静态数组
    int Last;  // 用最后一个元素的下标记录数组长度
};
typedef struct Lnode *List;


//定义变量
struct Lnode L;  //数组变量
List Lnode;

/*====================操作集====================*/
/*===========初始化==========*/
List MakeEmpty(){
    List PtrL;
    PtrL = (List)malloc(sizeof(struct Lnode));
    PtrL->Last = -1;  //新表长度为空
    return PtrL;
}

/*===========查找==========*/
// 按序查找
ElementType Find(List L ,int i){  //顺序存储便于按序查找查找
    //先判断i是否合法
    if(i<0||i>MAXSIZE-1){
        printf("invalid finding");
        return NULL;
    }
    return L->Data[i];  
}
// 按值查找
int FindX(List L,ElementType X){  //这里实际上是找到第一个X
    for(int i = 0;i<=L->Last;i++){
        if(L->Data[i]==X){
            return i;
        }
    }
    //没找到X
    return -1;
}

/*===========插入==========*/
List Insert(List L,ElementType X,int i){  //插入到第i个位置
    //对于有限的存储结构，插入必须先判断合法性
    if(i<0 || i>MAXSIZE-1 || L->Last >=MAXSIZE -1){  //i超出合理范围或者数组已满
        printf("invalid insert");
        return NULL;
    }
    //如果插入位置已经为空
    if(i > L->Last){
        L->Data[i] = X;
        return L;
    }
    //如果插入位置不为空，先腾出第i个位置
    else{
        for(int j = L->Last;j >i;j--){
            L->Data[j+1] = L->Data[j];
        }
        L->Data[i] = X;  //插入
        L->Last++; //更新
        return L;
    }
}

/*===========删除==========*/
List Delete(List L,int i){  //按序号删除
    // 先考虑删除是否合法
    if(i<0 || i>L->Last || L->Last ==-1){
        printf("invalid delete");
        return NULL;
    }
    //合法删除
    else{
        for(int j=i;j<L->Last;j++){
            L->Data[j] = L->Data[j+1];
        }
        L->Last--; //更新
        return L;
    }
}







