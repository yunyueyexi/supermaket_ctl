#ifndef __LIST_PEO_H__
#define __LIST_PEO_H__
#include"peoples.h"

typedef peoples elem_type;    //将商品结构体重新命名为elem_type  并作为链表的数据域


typedef struct node_p
{
    elem_type data;
    struct node_p* next;
}node_p;

typedef struct _list_p
{
    node_p* head;
    node_p* tail;
    int size;
} *list_p;

//创建一个链表
list_p creat_list();
//销毁某个链表
void destroy(list_p l);
//清空某个链表
void clear_list(list_p l);


//尾插
void push_back(list_p l,elem_type data);
//头插
void push_front(list_p l,elem_type data);
//删除一个节点
int remove_dj(list_p l, void* data,int (*cmp)(void*,void*));
//修改一个节点的数据
void updata(list_p l,elem_type data,int num);
//寻找某个节点返回节点位置
int find_num(list_p l, void* data,int (*cmp)(void*,void*)); 
//寻找目标节点返回节点数据 
elem_type* find_data(list_p l,int num);
 //查长度
 int size(list_p l);
 //判空
int empty(list_p l);

//展示数据
void traverse(list_p l,void* data,int (*cmp)(void*,void*));
//展示所有函数
void show_Peoples_All(list_p l);

//字符比较函数
int cmp_c(void* l_data,void* data);
//浮点数比较函数
//int cmp_f(void* l_data,void* data);
//整数比较函数
//int cmp_d(void* l_data,void* data);

#endif
