#ifndef __LIST_H__
#define __LIST_H__
#include"foods.h"

typedef foods elem_type;    //将商品结构体重新命名为elem_type  并作为链表的数据域
//typedef double elem_type;


typedef struct node
{
    elem_type data;
    struct node* next;
}node;

typedef struct _list
{
    node* head;
    node* tail;
    int size;
} *list;

//创建一个链表
list creat_list_f();
//销毁某个链表
void destroy_f(list l);
//清空某个链表
void clear_list_f(list l);


//尾插
void push_back_f(list l,elem_type data);
//头插
void push_front_f(list l,elem_type data);
//删除一个节点
int remove_dj_f(list l, void* data,int (*cmp)(void*,void*));
//修改一个节点的数据
void updata_f(list l,elem_type data,int num);
//寻找某个节点返回节点位置
int find_num_f(list l, void* data,int (*cmp)(void*,void*)); 
//寻找目标节点返回节点数据 
elem_type* find_data_f(list l,int num);
 //查长度
 int size_f(list l);
 //判空
int empty_f(list l);

//展示数据
void traverse_f(list l,void* data,int (*cmp)(void*,void*));
//展示所有函数
void show_Foods_All(list l);

//字符比较函数
int cmp_c_f(void* l_data,void* data);
//浮点数比较函数
int cmp_f(void* l_data,void* data);
//整数比较函数
int cmp_d(void* l_data,void* data);

#endif
