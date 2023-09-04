#ifndef __FOODS_H__
#define __FOODS_H__


typedef struct 
{
    char id[20];         //商品ID
    char name[41];      //商品名
    char goodstype[20]; //商品类型
    int start_num;      //商品进货数量
    int new_num;        //商品现存数量
    char factory[31];   //商品厂商
    float price;        //商品价格
    int time;           //商品进货时间
    char is_delete;     //商品现存状态（1表示存在，0表示被删除）
}foods;

void foods_init(void);    //初始化
void foods_add(void);     //增
void foods_del(void);     //删
void foods_update(void);  //改
void foods_find(void);    //查


#endif