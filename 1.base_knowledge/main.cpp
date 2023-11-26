//
// Created by yu on 2023/11/26.
//
extern "C" {
//solving problem:undefined reference to `Shape_ctor(Shape*, short, short)'
#include "c_object.h"
}

#include "stdio.h"
#include "stdlib.h"

void c_object_test() {
    //封装
    Shape s1, s2;
    Shape_ctor(&s1, -1, 2);
    Shape_ctor(&s2, 2, 4);
    printf("Shape s1(x=%d,y=%d)\n", Shape_get_X(&s1), Shape_get_Y(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_get_X(&s2), Shape_get_Y(&s2));

    Shape_moveBy(&s1, 1, 2);
    Shape_moveBy(&s2, 1, 1);
    printf("Shape s1(x=%d,y=%d)\n", Shape_get_X(&s1), Shape_get_Y(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_get_X(&s2), Shape_get_Y(&s2));

    //继承
    Rectangle r1, r2;
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);
    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_get_X(&r1.super), Shape_get_Y(&r1.super),
           r1.width, r1.height);
    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_get_X(&r2.super), Shape_get_Y(&r2.super),
           r2.width, r2.height);

    Shape_moveBy((Shape *) &r1, -2, 3);
    Shape_moveBy(&r2.super, 2, -1);
    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_get_X(&r1.super), Shape_get_Y(&r1.super),
           r1.width, r1.height);
    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_get_X(&r2.super), Shape_get_Y(&r2.super),
           r2.width, r2.height);

    //多态
    Rectangle r_d1, r_d2;
    Shape const *shapes[] = {
            &r_d1.super,
            &r_d2.super
    };
    Shape const *s;
    Rectangle_ctor(&r_d1, 0, 2, 10, 15);
    Rectangle_ctor(&r_d2, -1, 3, 5, 8);
    s = largestShape(shapes, sizeof(shapes) / sizeof(shapes[0]));
    printf("largetsShape s(x=%d,y=%d)\n", Shape_get_X(s), Shape_get_Y(s));
    drawAllShapes(shapes, sizeof(shapes) / sizeof(shapes[0]));
}

int main() {
    c_object_test();
    return 0;
}