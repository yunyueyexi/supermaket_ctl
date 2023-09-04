#include"foods.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>    //这个头文件只允许在linux系统中
#include<time.h>
#include"list.h"

static const char* foods_where = "foods_in";
static const char* foods_in = "Message";   //这个文件夹的所有权限必须打开
char Address[31];

list food;           //全局变量，表示整个商品的信息
struct stat st;




void foods_init()   //这个初始化必须保证文件夹已经建立，否则会出错
{
    food = creat_list_f();
        if(stat(foods_where,&st) == 0);   //用于判断文件是否存在
        else
        {
            if(mkdir(foods_where,0777) != 0)  //如果文件不存在，则创建文件。
            perror("\n存入失败，系统出现错误\n");
        }
    snprintf(Address,sizeof(Address),"%s/%s",foods_where,foods_in);
    FILE* fp = fopen(Address,"r");   //这里不能用Address  "./foods_in/Message"

    if(fp == NULL)
    {
        printf("open foods_in/Message error");
    }

    foods f;

    while(fread(&f,sizeof(foods),1,fp) == 1)
    {

        if(f.id)
        {
            push_back_f(food,f);
        }
    }

    fclose(fp);
}

void foods_add()
{
    foods f;
    char c;
    while(1)
    {
        printf("\n请按照以下提示输入商品信息：\n");
        printf("\n请输入商品类型信息：");
        fscanf(stdin,"%s",f.goodstype);
        printf("\n请输入商品ID(只可输入0-9间的数据，长度不限)：");
        fscanf(stdin,"%s",f.id);
        printf("\n请输入商品名（无特殊限制）：");
        fscanf(stdin,"%s",f.name);
        printf("\n请输入商品采购数量(输入数字0-9，数量不限)：");
        fscanf(stdin,"%d",&f.start_num);
        f.new_num = f.start_num;
        printf("请输入商品的价格（保留小数）：");
        fscanf(stdin,"%f",&f.price);
        printf("请输入商品厂家（无特殊限制）：");
        fscanf(stdin,"%s",f.factory);
        f.time = time(NULL);
        f.is_delete = '1';
        printf("\n正在存入请稍候----\n");        
        push_back_f(food,f);
        if(stat(foods_where,&st) == 0);   //用于判断文件是否存在
        else
        {
            if(mkdir(foods_where,0777) != 0)  //如果文件不存在，则创建文件。
            perror("\n存入失败，系统出现错误\n");
        }

        snprintf(Address,sizeof(Address),"%s/%s",foods_where,foods_in);

        FILE* fp = fopen(Address,"a");
        if(NULL != fp)
        {  
            fwrite(&f,sizeof(f),1,fp);
            fclose(fp);
        }
        printf("\n录入信息成功！\n");
        printf("是否需要继续输入商品？（Y/N）：");
        while ((c = getchar()) != '\n' && c != EOF) ;
        c = getchar();
        if(c == 'N' || c == 'n') break;
    }
}



void foods_del()
{
    char del_data[41];
    char c;
    foods* up_d;       //暂存商品信息的文件指针
    while(1)
    {
        system("clear");                                     //清空屏幕
        printf("请输入您要删除的商品（单个删除支持ID/商品名）：");
        scanf("%s",del_data);
        int flage_dl = remove_dj_f(food,del_data,cmp_c_f);
        if(-1 != flage_dl)
        {
            up_d=find_data_f(food,flage_dl);
            FILE* fp = fopen(Address,"r+");   
            if(fp == NULL)
            {
                printf("open foods_in/Message error");
            }
            fseek(fp,flage_dl*sizeof(foods),SEEK_SET);
            fwrite(up_d,sizeof(foods),1,fp);
            fclose(fp);         
            printf("删除成功");
        }
        else 
            printf("删除失败，未找到该商品标签");

        printf("\n是否需要继续删除商品？（Y/N）：\n");
        while ((c = getchar()) != '\n' && c != EOF) ;
        c = getchar();
        if(c == 'N' || c == 'n') break;
    }

}

void foods_update()
{
    char up_data[41];  //储存即将修改的商品索引
    char c;            //判断是否停止
    foods* up_f;       //暂存商品信息的文件指针
    while(1)
    {
        printf("请输入您要修改信息的商品（ID/商品名）：");
        scanf("%s",up_data);
        if(-1 != find_num_f(food,up_data,cmp_c_f))       //找到修改商品的节点位置
        {
            int flage_up = find_num_f(food,up_data,cmp_c_f);
            up_f = find_data_f(food,flage_up);   //利用节点位置找到节点数据
            printf("\n已为您找到该商品：\n");
            printf("\n商品类型：%s\n商品ID：%s\n商品名：%s\n商品价格：%.2f\n商品现存数量：%d\n商品进货数量：%d\n生产商：%s\n入库时间:%d \n",up_f->goodstype,up_f->id,up_f ->name,up_f ->price,up_f ->new_num,up_f ->start_num,up_f ->factory,up_f ->time);
            //开始修改商品
            while(1)
            {
                printf("\n是否开始修改（Y/N）\n");
                while ((c = getchar()) != '\n' && c != EOF) ;
                c = getchar();
                if(c == 'N' || c == 'n') break;

                system("clear");                                     //清空屏幕
                printf("\n请输入商品类型信息：");
                fscanf(stdin,"%s",up_f ->goodstype);
                printf("\n请输入商品ID(只可输入0-9间的数据，长度不限)：");
                fscanf(stdin,"%s",up_f ->id);
                printf("\n请输入商品名（无特殊限制）：");
                fscanf(stdin,"%s",up_f ->name);
                printf("\n请输入商品采购数量(输入数字0-9，数量不限)：");
                fscanf(stdin,"%d",&(up_f ->start_num));
                up_f ->new_num = up_f ->start_num;
                printf("请输入商品的价格（保留小数）：");
                fscanf(stdin,"%f",&(up_f ->price));
                printf("请输入商品厂家（无特殊限制）：");
                fscanf(stdin,"%s",up_f ->factory);

                printf("\n是否需要再次修改（Y/N）\n");
                while ((c = getchar()) != '\n' && c != EOF) ;
                c = getchar();
                if(c == 'Y' || c == 'y')
                { 
                    system("clear");                                     //清空屏幕
                    continue;
                }
                else break;

            }
            updata_f(food,*up_f,flage_up);
            //打开目标文件
            FILE* fp = fopen(Address,"r+");   
            if(fp == NULL)
            {
                printf("open foods_in/Message error");
            }
            fseek(fp,flage_up*sizeof(foods),SEEK_SET);
            fwrite(up_f,sizeof(foods),1,fp);
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


void foods_find()
{
    int flag = 0;
    char c;
    while(1)
    {
        printf("\n请选择您的查找模式(输入编号)：\n");
        printf("1.全部查找：   \n");
        printf("2.类别查找：   \n");
        printf("3.价格查找：   \n");
        printf("4.现存数量查找：\n");
        printf("5.厂家查找：   \n");
        printf("6.查找单个商品（支持模糊查找）：\n");
        printf(">: ");
        scanf("%d",&flag);

        char data_type[20];
        float data_f[2];
        switch(flag)
        {
            case 1: 
                    system("clear");                                     //清空屏幕
                    show_Foods_All(food);
                break;
            case 2:
                    system("clear");                                     //清空屏幕
                    printf("请输入您要查询的类别：");
                    scanf("%s",data_type);
                    traverse_f(food,data_type,cmp_c_f);
                break;
            case 3:
                    system("clear");                                     //清空屏幕 
                    printf("请输入您要查询的价位（规定格式为xx-xx）：");
                    scanf("%f-%f",&data_f[0],&data_f[1]);
                    traverse_f(food,data_f,cmp_f);
                break;
            case 4:
                    system("clear");                                     //清空屏幕 
                    printf("请输入您要查询的数量（规定格式为xx-xx）：");
                    scanf("%f-%f",&data_f[0],&data_f[1]);
                    traverse_f(food,data_f,cmp_d);
                break;
            case 5: 
                    system("clear");                                     //清空屏幕
                    printf("请输入您要查询的厂家：");
                    scanf("%s",data_type);
                    traverse_f(food,data_type,cmp_c_f);
                break;
            case 6: 
                    system("clear");                                     //清空屏幕
                    printf("请输入您要查询的商品名/商品ID：");
                    scanf("%s",data_type);
                    traverse_f(food,data_type,cmp_c_f);
                break;

        }
        printf("\n是否需要继续查找商品？（Y/N）：\n");
        while ((c = getchar()) != '\n' && c != EOF) ;
        c = getchar();
        if(c == 'N' || c == 'n') break;
        system("clear");                                     //清空屏幕
    }
}