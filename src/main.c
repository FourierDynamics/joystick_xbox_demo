#include <stdio.h>  
#include <unistd.h>  
#include <string.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <errno.h>  
#include <pthread.h>
#include "xbox.h"

xbox_map_t xbox_m;

void *xbox_run(void *arg)
{
    int len,ret;
    
    ret = xbox_init();
    if(ret < 0)
    {
        printf("xbox init fail\n");
    }
    
    while(ret == 0)
    {
        len = xbox_read(&xbox_m);
        if (len < 0)  
        {  
            // usleep(10*1000);  
            continue;  
        }  

        printf("Time:%8d A:%d B:%d X:%d Y:%d LB:%d RB:%d start:%d back:%d home:%d LO:%d RO:%d XX:%-6d YY:%-6d LX:%-6d LY:%-6d RX:%-6d RY:%-6d LT:%-6d RT:%-6d\n",  
                xbox_m.time, xbox_m.a, xbox_m.b, xbox_m.x, xbox_m.y, xbox_m.lb, xbox_m.rb, xbox_m.start, xbox_m.back, xbox_m.home, xbox_m.lo, xbox_m.ro,  
                xbox_m.xx, xbox_m.yy, xbox_m.lx, xbox_m.ly, xbox_m.rx, xbox_m.ry, xbox_m.lt, xbox_m.rt);  
        fflush(stdout);  

        // usleep(10*1000);  
    }
}

int main(void)  
{  

    pthread_t xbox_thread;
    int ret = -1;
    
    ret = pthread_create(&xbox_thread, NULL, xbox_run, NULL);
    if (ret != 0) {
        printf("creat xbox_thread fail.\n");
        return -1;
    }

    
    while(1)  
    {  
        usleep(1000);  
    }  

    return 0;  
}  