//scanf format stuff

#include <stdio.h>

int main (void){

    //IT NO WORK D:

    int v1;
    float v2;
    char v3,v4;

    // • Input: -567 45.8 gf
    // • What are the values stored into v1-v4?

    scanf("%d%lf%c%c", &v1, &v2, &v3, &v4);
    printf("v1:%d\nv2:%f\nv3:%c\nv4:%c\n", v1, v2, v3, v4);
    // • Answer: v1 = -567, v2 = 45.8, v3 = ' ', v4 = 'g'

    //ADDING SPACE TO FORCE SCANF TO EXPECT ' ' INSTEAD OF REGISTERING AS V3
    scanf("%d%lf %c%c", &v1, &v2, &v3, &v4);
    printf("v1:%d\nv2:%f\nv3:%c\nv4:%c\n", v1, v2, v3, v4);
    // • Answer: v1 = -567, v2 = 45.8, v3 = 'g', v4 = 'f'
    
    return 0;
}