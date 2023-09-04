#include<stdio.h>
#include"owner_menu.h"
#include"peoples.h"
#include <termios.h> 
#include<string.h>
#include<stdlib.h>
#include"md5.h"


void enable_echo(); 
void disable_echo(); 
//int ueser_key(char* name_now,char* key_now)


int main()
{
    char name_now[31];
    char key_now[33];
    char temp[33];
    char key_f[33];
    char ch;
    int i = 0;
   while(1)
    {
        system("clear");
        md5_data("888888", 6*sizeof(char), temp);
        printf("-----------------\n");
        printf("   用户登陆界面\n");
        printf("   用户名\n");
        printf("   密码\n");
        printf("   输入0退出\n");
        printf("-----------------\n");
        printf("用户名：");
        scanf("%s",name_now);
        getchar();
        printf("密码：");
        disable_echo(); // 关闭终端回显
        while (1) 
        {
            ch = getchar(); // 获取用户输入的字符

            if (ch == '\r' || ch == '\n') {
                key_now[i] = '\0'; // 结束字符串
                break;
            } else if (ch == 8 && i > 0) {
                printf("\b \b"); // 处理退格键，擦除一个字符
                i--;
            } else if (i < 19) {
                key_now[i] = ch;
                printf("*"); // 显示星号代替字符
                i++;
            }
        }
        i  = 0;
        enable_echo(); // 恢复终端回显

        FILE* fp = fopen("owner","r");
        fgets(key_f,sizeof(key_f),fp);
        fclose(fp);

        md5_data(key_now, 6*sizeof(char), key_now);
        if(strcmp("admin",name_now) == 0 && strcmp(temp,key_now) == 0)
        {

            printf("登陆成功！\n请修改密码:");
            disable_echo(); // 关闭终端回显
            while (1) 
            {
                ch = getchar(); // 获取用户输入的字符

                if (ch == '\r' || ch == '\n') {
                    key_now[i] = '\0'; // 结束字符串
                    break;
                } else if (ch == 8 && i > 0) {
                    printf("\b \b"); // 处理退格键，擦除一个字符
                    i--;
                } else if (i < 19) {
                    key_now[i] = ch;
                    printf("*"); // 显示星号代替字符
                    i++;
                }
            }
            enable_echo(); // 恢复终端回显
        
            FILE* fp1 = fopen("owner","r+");
            if(NULL != fp1)
            {  
                md5_data(key_now, sizeof(key_now), key_now);
                //md5_data("888888", 6*sizeof(char), key_now);
                fwrite(key_now,strlen(key_now),1,fp1);
                fclose(fp1);
            }
            printf("修改成功！\n");
            continue;
        }
        else if(strcmp("admin",name_now) == 0 && strcmp(key_now,key_f) == 0) owner_menu();
        else if(ueser_key(name_now,key_now) == 1) printf("欢迎");
    
    }
}




int ueser_key(char* name_now,char* key_now)
{
    peoples_init();
    if(people_find_u(name_now,key_now) == 1)
        return 1;
}

    






void disable_echo() 
{
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~ECHO; // 清除ECHO标志
    tcsetattr(0, TCSANOW, &term);
}

// 函数：打开终端回显
void enable_echo() 
{
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ECHO; // 设置ECHO标志
    tcsetattr(0, TCSANOW, &term);
}
