//
// Created by yu on 2023/11/26.
//
extern "C"{
    //solving problem:undefined reference to `Shape_ctor(Shape*, short, short)'
#include "c_object.h"
}
#include "stdio.h"
#include "stdlib.h"
void c_object_test(){
    //封装
    Shape s1,s2;
    Shape_ctor(&s1,-1,2);
    Shape_ctor(&s2,2,4);
    printf("Shape s1(x=%d,y=%d)\n", Shape_get_X(&s1), Shape_get_Y(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_get_X(&s2), Shape_get_Y(&s2));

    Shape_moveBy(&s1,1,2);
    Shape_moveBy(&s2,1,1);
    printf("Shape s1(x=%d,y=%d)\n", Shape_get_X(&s1), Shape_get_Y(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_get_X(&s2), Shape_get_Y(&s2));

}

int main(){
    c_object_test();
    return 0;
}