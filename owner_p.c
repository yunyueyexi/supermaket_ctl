#include"owner_p.h"
#include"peoples.h"
#include<stdio.h>
#include<stdlib.h>


void owner_p()
{
    int num = 0;
    peoples_init();
    while(1)
    {
        system("clear");                                     //清空屏幕
        printf("\n--------------------------------");       
        printf("\n欢迎来到店员信息管理系统!(⑅˃◡˂⑅)");
        printf("\n-----功能选择（序号）----------");
        printf("\n 1.增加店员（初始化一个空店员）");
        printf("\n      2.修改店员信息");
        printf("\n      3.删除店员");
        printf("\n      4.查询店员");
        printf("\n      0.退出系统");
        printf("\n--------------------------------");   
        printf("\n>:");   
        scanf("%d",&num);
        switch(num)
        {
            case 1: 
                    system("clear");                                     //清空屏幕
                    peoples_add();
                break;
            case 2: 
                    system("clear");                                     //清空屏幕
                    peoples_update();
                break;
            case 3:
                    system("clear");                                     //清空屏幕 
                    peoples_del();
                break;
            case 4: 
                    system("clear");                                     //清空屏幕
                    peoples_find();
                break; 
        }
        if(num == 0) break;
    }
}