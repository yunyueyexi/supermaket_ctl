#ifndef __PEOPLES_H__
#define __PEOPLES_H__

typedef struct peoples
{
    char key[33];       //密码
    char name[31];      //用户名
    char ID_card[19];   //身份证
    char ID[10];        //工号
    char sex[5];        //性别
    char phone[12];     //电话
    char where[61];     //住址
    char is_delete;     //店员状态（1表示存在，0表示被删除）

}peoples;

void peoples_init(void);    //初始化
void peoples_add(void);     //增
void peoples_del(void);     //删
void peoples_update(void);  //改
void peoples_find(void);    //查

int people_find_u(char* name_u,char* key_u);

#endif