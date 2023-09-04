#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 //创建一个链表
list creat_list_f()
{
    list l= (list)malloc(sizeof(struct _list));
    node* n = (node*)malloc(sizeof(node));

    //n ->data = NULL;
    n ->next = NULL;

    l ->head = n;
    l ->tail = n;
    l ->size = 0;

    return l;
}

//销毁某个链表
void destroy_f(list l)
{
    node* p = NULL;
    while(l ->head != NULL) 
    {
        p = l ->head ->next;
        free(l ->head);
        l ->head = p;
    }
}

//清空某个链表
void clear_list_f(list l)
{
    node* p =l ->head ->next;   //将第一个节点存储到P中用于后续的删除
    node* k = NULL;            //创建一个中间节点

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
void push_back_f(list l,elem_type data)
{
    node* n = (node*)malloc(sizeof(node));
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
void push_front_f(list l,elem_type data)
{
    node* n = (node*)malloc(sizeof(node));

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
int remove_dj_f(list l, void* data,int (*cmp)(void*,void*))
{
   node* p = l ->head->next;
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
void updata_f(list l,elem_type data,int num)
{
    node* p = l ->head->next;
    for(int i = 0;i < num;i++)  p = p->next;

    p ->data = data;
}

//查找某个节点
int find_num_f(list l, void* data,int (*cmp)(void*,void*))
{
   node* p = l ->head->next;
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
 elem_type* find_data_f(list l,int num)
 {
    node* p = l ->head->next;

    for(int i = 0 ;i < num;i++)  p = p->next;
    if(p  != NULL)
        return &(p->data);
    else return NULL;
 }


//遍历函数
void traverse_f(list l,void* data,int (*cmp)(void*,void*))  //为查找设计的遍历函数
{
    node* p = l ->head->next;
    int traverse_Flag = 0;
    while(NULL != p)
    {
        if(p ->data.is_delete == '1')
        {
            if(cmp(&(p->data),data) == 1)
            printf("\n商品类型：%s\n商品ID：%s\n商品名：%s\n商品价格：%.2f\n商品现存数量：%d\n商品进货数量：%d\n生产商：%s\n入库时间:%d \n",p ->data.goodstype,p->data.id,p ->data.name,p ->data.price,p ->data.new_num,p ->data.start_num,p ->data.factory,p ->data.time),traverse_Flag++;
            else if(cmp(&(p->data),data) == 2)
            printf("\n商品类型：%s\n商品ID：%s\n商品名：%s\n商品价格：%.2f\n商品现存数量：%d\n商品进货数量：%d\n生产商：%s\n入库时间:%d \n",p ->data.goodstype,p->data.id,p ->data.name,p ->data.price,p ->data.new_num,p ->data.start_num,p ->data.factory,p ->data.time),traverse_Flag++;
            else if(cmp(&(p->data),data) == 3)
            printf("\n商品类型：%s\n商品ID：%s\n商品名：%s\n商品价格：%.2f\n商品现存数量：%d\n商品进货数量：%d\n生产商：%s\n入库时间:%d \n",p ->data.goodstype,p->data.id,p ->data.name,p ->data.price,p ->data.new_num,p ->data.start_num,p ->data.factory,p ->data.time),traverse_Flag++;
            else if(cmp(&(p->data),data) == 4)
            printf("\n商品类型：%s\n商品ID：%s\n商品名：%s\n商品价格：%.2f\n商品现存数量：%d\n商品进货数量：%d\n生产商：%s\n入库时间:%d \n",p ->data.goodstype,p->data.id,p ->data.name,p ->data.price,p ->data.new_num,p ->data.start_num,p ->data.factory,p ->data.time),traverse_Flag++; 
        }     
        p = p ->next;
    } 
    if(0 == traverse_Flag) 
    {
        printf("\n很遗憾，未查询到商品(っ◞‸◟c)\n");
    }
    else printf("\n已为您查询到%d件商品(●'◡'●)\n",traverse_Flag);
}

void show_Foods_All(list l)
{
    node* p = l ->head->next;
    while(NULL != p)
    {
        if(p ->data.is_delete == '1')
        {
            printf("\n商品类型：%s\n商品ID：%s\n商品名：%s\n商品价格：%f\n商品现存数量：%d\n商品进货数量：%d\n生产商：%s\n入库时间:%d \n",p ->data.goodstype,p->data.id,p ->data.name,p ->data.price,p ->data.new_num,p ->data.start_num,p ->data.factory,p ->data.time);
        }
        p = p ->next;

    }     
}
//整数比较函数    (不同的返回值，代表着不同的显示量)
int cmp_d(void* l_data,void* data)
{
    foods* p =(foods*)l_data;   //这里使用指针是因为，我们使用的是一个空类型的指针，所以他强转也只能转化为一个指针类型
    float* d = (float*)data;
    if(d[0] <= p->new_num && d[1] >= p->new_num) return 1;
    return 0; 
}

//浮点数比较函数  (不同的返回值，代表着不同的显示量)
int cmp_f(void* l_data,void* data)
{
    foods* p =(foods*)l_data;   //这里使用指针是因为，我们使用的是一个空类型的指针，所以他强转也只能转化为一个指针类型
    float* c = (float*)data;

    if(p->price >= c[0] && p->price <= c[1])      return 1;  //商品比较

    return 0; 
}


//字符串比较函数  (不同的返回值，代表着不同的显示量)
int cmp_c_f(void* l_data,void* data)
{
    foods* p =(foods*)l_data;   //这里使用指针是因为，我们使用的是一个空类型的指针，所以他强转也只能转化为一个指针类型
    const char * c = (char*)data;

    if(0 == strcmp(p ->goodstype,c))    return 1;     //商品类型
    else if(strstr(p ->name,c))         return 2;     //商品名
    else if(0 == strcmp(p ->factory,c)) return 3;     //商品厂商
    else if(0 == strcmp(p ->id,c))      return 4;     //商品ID

    else return 0;    
}



//查长度
 int size_f(list l)
{
    // 时间复杂度为 O(1)
    return l->size;
}

//判空
int empty_f(list l)
{
    return !(l->size);
}