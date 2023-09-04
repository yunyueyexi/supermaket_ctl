#include"list_peo.h"
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
 //创建一个链表
list_p creat_list()
{
    list_p l= (list_p)malloc(sizeof(struct _list_p));
    node_p* n = (node_p*)malloc(sizeof(node_p));

    //n ->data = NULL;
    n ->next = NULL;

    l ->head = n;
    l ->tail = n;
    l ->size = 0;

    return l;
}

//销毁某个链表
void destroy(list_p l)
{
    node_p* p = NULL;
    while(l ->head != NULL) 
    {
        p = l ->head ->next;
        free(l ->head);
        l ->head = p;
    }
}

//清空某个链表
void clear_list(list_p l)
{
    node_p* p =l ->head ->next;   //将第一个节点存储到P中用于后续的删除
    node_p* k = NULL;            //创建一个中间节点

    l ->head ->next = NULL;    //将头节点的指针指向空

    while(p ->next != NULL)    //遍历释放后续节点，即清空链表
    {
        k = p ->next;
        free(p);
        p = k;
    }

    l ->tail = l ->head;       //将链表属性的头尾指针指向同一个节点
    l ->size = 0;

}

//插入新节点

//尾插
void push_back(list_p l,elem_type data)
{
    node_p* n = (node_p*)malloc(sizeof(node_p));
    if(NULL == n)
    {
        fprintf(stderr,"malloc is error!");
        return;
    }
    n ->data = data;
    n ->next = NULL;

    //将新节点插入到链表中
    l ->tail ->next = n;
    l ->tail = n;
    l ->size++;

}


//头插
void push_front(list_p l,elem_type data)
{
    node_p* n = (node_p*)malloc(sizeof(node_p));

    if(NULL == n)
    {
        fprintf(stderr,"malloc is error!");
        return;
    }
    n ->data = data;
    n ->next =l ->head ->next;

    l ->head ->next = n;

    if(NULL == n ->next)  l ->tail = n;

    l ->size++;

}


//删除一个节点
int remove_dj(list_p l, void* data,int (*cmp)(void*,void*))
{
   node_p* p = l ->head->next;
    int flage_dl = 0;
    //找到那个节点的数据
    while(NULL != p )
    {
        if(cmp(&(p->data),data) != 0 && p->data.is_delete != '0')
        {
            p ->data.is_delete = '0';
            break;
        }
        p = p ->next;
        flage_dl++;
    } 
    if(flage_dl != -1 && p != NULL) return flage_dl;
    else return -1;  
}

//修改某个节点
void updata(list_p l,elem_type data,int num)
{
    node_p* p = l ->head->next;
    for(int i = 0;i < num;i++)  p = p->next;

    p ->data = data;
}

//查找某个节点
int find_num(list_p l, void* data,int (*cmp)(void*,void*))
{
   node_p* p = l ->head->next;
    int flage_dl = 0;
    //找到那个节点的数据
    while(NULL != p )
    {
        if(cmp(&(p->data),data) != 0 && p ->data.is_delete != '0')
            break;

        p = p ->next;
        flage_dl++;
    } 
    if(flage_dl  != -1 && p != NULL) return flage_dl;
    else  return -1;
}

//查找某个节点的数据    为写入文件服务
 elem_type* find_data(list_p l,int num)
 {
    node_p* p = l ->head->next;

    for(int i = 0 ;i < num;i++)  p = p->next;
    if(p  != NULL)
        return &(p->data);
    else return NULL;
 }


//遍历函数
void traverse(list_p l,void* data,int (*cmp)(void*,void*))  //为查找设计的遍历函数
{
    node_p* p = l ->head->next;
    int traverse_Flag = 0;
    while(NULL != p)
    {
        if(p ->data.is_delete == '1')
        {
            if(cmp(&(p->data),data) == 1)
            printf("\n店员：%s\n性别：%s\n工号：%s\n身份证%s\n电话：%s\n住址%s\n",p ->data.name,p ->data.sex,p ->data.ID,p ->data.ID_card,p ->data.phone,p ->data.where);
            else if(cmp(&(p->data),data) == 2)
            printf("\n店员：%s\n性别：%s\n工号：%s\n身份证%s\n电话：%s\n住址%s\n",p ->data.name,p ->data.sex,p ->data.ID,p ->data.ID_card,p ->data.phone,p ->data.where);
            else if(cmp(&(p->data),data) == 3)
            printf("\n店员：%s\n性别：%s\n工号：%s\n身份证%s\n电话：%s\n住址%s\n",p ->data.name,p ->data.sex,p ->data.ID,p ->data.ID_card,p ->data.phone,p ->data.where);
            else if(cmp(&(p->data),data) == 4)
            printf("\n店员：%s\n性别：%s\n工号：%s\n身份证%s\n电话：%s\n住址%s\n",p ->data.name,p ->data.sex,p ->data.ID,p ->data.ID_card,p ->data.phone,p ->data.where);
        }     
        p = p ->next;
    } 
    if(0 == traverse_Flag) 
    {
        printf("\n很遗憾，未查询到该店员(っ◞‸◟c)\n");
    }
    else printf("\n已为您查询到%d位店员(●'◡'●)\n",traverse_Flag);
}

void show_Peoples_All(list_p l)
{
    node_p* p = l ->head->next;
    int show_Flag = 0;
    while(NULL != p)
    {
        if(p ->data.is_delete == '1')
        {
            printf("\n店员：%s\n性别：%s\n工号：%s\n身份证%s\n电话：%s\n住址%s\n",p ->data.name,p ->data.sex,p ->data.ID,p ->data.ID_card,p ->data.phone,p ->data.where);
            show_Flag++;
        }
        p = p ->next;
    }    
    printf("\n我们一共%d位店员(●'◡'●)\n",show_Flag);
 
}
//整数比较函数    (不同的返回值，代表着不同的显示量)
/*int cmp_d(void* l_data,void* data)
{
    peoples* p =(peoples*)l_data;   //这里使用指针是因为，我们使用的是一个空类型的指针，所以他强转也只能转化为一个指针类型
    float* d = (float*)data;
    if(d[0] <= p->new_num && d[1] >= p->new_num) return 1;
    return 0; 
}*/

//浮点数比较函数  (不同的返回值，代表着不同的显示量)
/*int cmp_f(void* l_data,void* data)
{
    peoples* p =(peoples*)l_data;   //这里使用指针是因为，我们使用的是一个空类型的指针，所以他强转也只能转化为一个指针类型
    float* c = (float*)data;

    if(p->price >= c[0] && p->price <= c[1])      return 1;  //商品比较

    return 0; 
}*/


//字符串比较函数  (不同的返回值，代表着不同的显示量)
int cmp_c(void* l_data,void* data)
{
    peoples* p =(peoples*)l_data;   //这里使用指针是因为，我们使用的是一个空类型的指针，所以他强转也只能转化为一个指针类型
    const char * c = (char*)data;

    if(0 == strcmp(p ->ID,c))          return 1;     //工号
    else if(strstr(p ->ID_card,c))     return 2;     //身份证
    else if(0 == strcmp(p ->name,c))   return 3;     //名字
    else if(0 == strcmp(p ->phone,c))  return 4;     //电话

    else return 0;    
}



//查长度
 int size(list_p l)
{
    // 时间复杂度为 O(1)
    return l->size;
}

//判空
int empty(list_p l)
{
    return !(l->size);
}