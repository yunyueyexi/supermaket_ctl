#include"owner_menu.h"
#include"owner_p.h"
#include"owner_f.h"
#include<stdio.h>
#include<stdlib.h>



void owner_menu()
{
    int choice_o = 0;
    while(1)
    {
        system("clear");
        printf("---------------------------------------\n");
        printf("        欢迎进入管理员系统(◍•ᴗ•◍)❤)\n");
        printf("           请选择您要进入的模式\n");
        printf("            1.商品管理模式\n");
        printf("            2.店员管理模式\n");
        printf("            3.销售信息查询模式\n");
        printf("            0.退出系统\n");
        printf("---------------------------------------\n");    
        printf(">:");
        scanf("%d",&choice_o);
        switch(choice_o)
        {
            case 1:
                    system("clear");
                    owner_f();
                break;
            case 2:
                    system("clear");
                    owner_p();
                break; 
            case 3:
                    system("clear");
                break; 
        }
        if(choice_o == 0)  break;
    }
}