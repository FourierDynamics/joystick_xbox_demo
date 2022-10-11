#ifndef __XBOX_H__
#define __XBOX_H__

typedef struct xbox_map  
{  
    int     time;  
    int     a;  
    int     b;  
    int     x;  
    int     y;  
    int     lb;  
    int     rb;  
    int     start;  
    int     back;  
    int     home;  
    int     lo;  
    int     ro;  

    int     lx;  
    int     ly;  
    int     rx;  
    int     ry;  
    int     lt;  
    int     rt;  
    int     xx;  
    int     yy;  

}xbox_map_t;  

int xbox_init(void);
int xbox_read(xbox_map_t *xbox_m);

#endif
