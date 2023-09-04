#include"owner_f.h"
#include<stdio.h>
#include<stdlib.h>
#include"foods.h"

void owner_f()
{
    int num = 0;
    foods_init();
    while(1)
    {
        system("clear");                                     //清空屏幕
        printf("\n--------------------------------");       
        printf("\n欢迎来到商品信息管理系统!(⑅˃◡˂⑅)");
        printf("\n-----功能选择（序号）----------");
        printf("\n     1.增加商品标签");
        printf("\n     2.修改商品标签");
        printf("\n     3.删除商品标签");
        printf("\n     4.查询商品标签");
        printf("\n     0.退出系统");
        printf("\n--------------------------------");   
        printf("\n>:");   
        scanf("%d",&num);
        switch(num)
        {
            case 1: 
                    system("clear");                                     //清空屏幕
                    foods_add();
            case 2: 
                    system("clear");                                     //清空屏幕
                    foods_update();
                break;
            case 3:
                    system("clear");                                     //清空屏幕 
                    foods_del();
                break;
            case 4: 
                    system("clear");                                     //清空屏幕
                    foods_find();
                break; 
        }
        if(num == 0) break;
    }

}