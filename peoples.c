#include"peoples.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>    //这个头文件只允许在linux系统中
#include<time.h>
#include"md5.h"
#include"list_peo.h"


static const char* peoples_where = "people_in";
static const char* peoples_in = "Message";   //这个文件夹的所有权限必须打开
char Address[31];

list_p people;           //全局变量，表示整个人员的信息
struct stat st;


//初始化链表
void peoples_init()   //这个初始化必须保证文件夹已经建立，否则会出错
{
    people = creat_list();
        if(stat(peoples_where,&st) == 0);   //用于判断文件是否存在
        else
        {
            if(mkdir(peoples_where,0777) != 0)  //如果文件不存在，则创建文件。
            perror("\n存入失败，系统出现错误\n");
        }
    snprintf(Address,sizeof(Address),"%s/%s",peoples_where,peoples_in);
    FILE* fp = fopen(Address,"r");   //这里不能用Address  
    if(fp == NULL)
    {
        perror("open foods_in/Message error");
    }

    peoples p;

    while(fread(&p,sizeof(peoples),1,fp) == 1)
    {

        if(p.ID)
            push_back(people,p);
    }

    fclose(fp);
}



void peoples_add()
{
    peoples p;
    char c;
    while(1)
    {
        printf("请输入工号：");     
        scanf("%s",p.ID);
        snprintf(p.ID_card,sizeof(p.ID_card),"x");
        md5_data("123456", 6*sizeof(char), p.key);
        snprintf(p.name,sizeof(p.name),"x");
        snprintf(p.phone,sizeof(p.phone),"x");
        snprintf(p.sex,sizeof(p.sex),"x");
        snprintf(p.where,sizeof(p.where),"x");
        p.is_delete = '1';

        printf("\n正在存入请稍候----\n");        
        push_back(people,p);
        if(stat(peoples_where,&st) == 0);   //用于判断文件是否存在
        else
        {
            if(mkdir(peoples_where,0777) != 0)  //如果文件不存在，则创建文件。
            perror("\n存入失败，系统出现错误\n");
        }

        snprintf(Address,sizeof(Address),"%s/%s",peoples_where,peoples_in);

        FILE* fp = fopen(Address,"a");
        if(NULL != fp)
        {  
            fwrite(&p,sizeof(p),1,fp);
            fclose(fp);
        }
        printf("\n初始化成功！\n");
        printf("是否需要继续初始化？（Y/N）：");
        while ((c = getchar()) != '\n' && c != EOF) ;
        c = getchar();
        if(c == 'N' || c == 'n') break;
    }
}

void peoples_del()
{
    char del_data[41];
    char c;
    peoples* up_d;       //暂存商品信息的文件指针
    while(1)
    {
        system("clear");                                     //清空屏幕
        printf("请输入您要删除的店员（工号/姓名/电话）：");
        scanf("%s",del_data);
        int flage_dl = remove_dj(people,del_data,cmp_c);
        if(-1 != flage_dl && del_data != "admin")
        {
            up_d=find_data(people,flage_dl);
            FILE* fp = fopen(Address,"r+");   
            if(fp == NULL)
            {
                printf("open foods_in/Message error");
            }
            fseek(fp,flage_dl*sizeof(peoples),SEEK_SET);
            fwrite(up_d,sizeof(peoples),1,fp);
            fclose(fp);         
            printf("删除成功");
        }
        else if(del_data == "admin")  
            printf("你咋想删除你自己牙ლ(ಠ_ಠლ)");
        else 
            printf("删除失败，未找到该商品标签");

        printf("\n是否需要继续删除商品？（Y/N）：\n");
        while ((c = getchar()) != '\n' && c != EOF) ;
        c = getchar();
        if(c == 'N' || c == 'n') break;
    }

}

void peoples_update()
{
    char up_data[41];  //储存即将修改的商品索引
    char c;            //判断是否停止
    int d;
    peoples* up_p;       //暂存商品信息的文件指针
    while(1)
    {
        printf("请输入您要修改信息的店员（工号/姓名/身份证）：");
        scanf("%s",up_data);
        if(-1 != find_num(people,up_data,cmp_c))       //找到修改商品的节点位置
        {
            int flage_up = find_num(people,up_data,cmp_c);
            up_p = find_data(people,flage_up);   //利用节点位置找到节点数据
            printf("\n已为您找到该商品：\n");
            printf("\n店员：%s\n性别：%s\n工号：%s\n身份证%s\n电话：%s\n住址%s\n",up_p ->name,up_p ->sex,up_p ->ID,up_p ->ID_card,up_p ->phone,up_p ->where);
            //开始修改商品
            while(1)
            {
                printf("\n是否开始修改（Y/N）\n");
                while ((c = getchar()) != '\n' && c != EOF) ;
                c = getchar();
                if(c == 'N' || c == 'n') break;

                system("clear");                                     //清空屏幕

                printf("\n是否修改名字(1/0)");
                scanf("%d",&d);
                if(d == 1)
                {
                    printf("\n请输入店员新名：");
                    fscanf(stdin,"%s",up_p ->name);
                }
                d = 0;

                system("clear");                                     //清空屏幕

                printf("\n是否修改工号(1/0)");
                scanf("%d",&d);
                if(d == 1)
                {
                    printf("\n请输入店员新工号");
                    fscanf(stdin,"%s",up_p ->ID);
                }
                d = 0;

                system("clear");                                     //清空屏幕

                printf("\n是否重置密码(1/0)");
                scanf("%d",&d);
                if(d == 1)
                {
                   md5_data("123456", 6*sizeof(char), up_p ->key);
                }
                d = 0;

                system("clear");                                     //清空屏幕

                printf("\n是否修改地址(1/0)");
                scanf("%d",&d);
                if(d == 1)
                {
                    printf("\n请输入店员新地址");
                    fscanf(stdin,"%s",up_p ->where);
                }

                system("clear");                                     //清空屏幕

                printf("\n是否修改电话(1/0)");
                scanf("%d",&d);
                if(d == 1)
                {
                    printf("\n请输入店员新电话");
                    fscanf(stdin,"%s",up_p ->phone);
                }

                printf("\n是否需要再次修改（Y/N）\n");
                while ((c = getchar()) != '\n' && c != EOF) ;
                c = getchar();
                if(c == 'y' || c == 'Y')
                { 
                    system("clear");                                     //清空屏幕
                    continue;
                }
                else break;
            }
            updata(people,*up_p,flage_up);
            //打开目标文件
            FILE* fp = fopen(Address,"r+");   
            if(fp == NULL)
            {
                printf("open foods_in/Message error");
            }
            fseek(fp,flage_up*sizeof(peoples),SEEK_SET);
            fwrite(up_p,sizeof(peoples),1,fp);
            fclose(fp);         
            printf("修改成功");

        }
        else 
            printf("修改失败，未找到该商品标签");

        printf("\n是否需要继续修改商品信息？（Y/N）：\n");
        while ((c = getchar()) != '\n' && c != EOF) ;
        c = getchar();
        if(c == 'N' || c == 'n') break;
        system("clear");                                     //清空屏幕
    }
}




void peoples_find(void)   //查
{
    int flag = 0;
    char c;
    while(1)
    {
        printf("\n请选择您的查找模式(输入编号)：\n");
        printf("1.全部查找：   \n");
        printf("2.性别查找：   \n");
        printf("3.地址查找：\n");
        printf("4.查找（用于查找单个店员）：\n");
        printf(">: ");
        scanf("%d",&flag);

        char data_type[61];
        switch(flag)
        {
            case 1: 
                    system("clear");                                     //清空屏幕
                    show_Peoples_All(people);
                break;
            case 2:
                    system("clear");                                     //清空屏幕
                    printf("请输入您要查询的性别：");
                    scanf("%s",data_type);
                    traverse(people,data_type,cmp_c);
                break;
            case 3:
                    system("clear");                                     //清空屏幕 
                    printf("请输入您要查询的地址");
                    scanf("%s",data_type);
                    traverse(people,data_type,cmp_c);
                break;
            case 4:
                    system("clear");                                     //清空屏幕 
                    printf("请输入您要查询的人员的部分信息");
                    scanf("%s",data_type);
                    traverse(people,data_type,cmp_c);
                break;

        }
        printf("\n是否需要继续查找商品？（Y/N）：\n");
        while ((c = getchar()) != '\n' && c != EOF) ;
        c = getchar();
        if(c == 'N' || c == 'n') break;
        system("clear");                                     //清空屏幕
    }
}


int people_find_u(char* name_u,char* key_u)
{
    int j = find_num(people, name_u,cmp_c);
    int k = find_num(people, key_u,cmp_c);
    if(j != -1 && k != -1)
        return 1;
    else
        return 0; 
}