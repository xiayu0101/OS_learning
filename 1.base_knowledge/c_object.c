//
// Created by yu on 2023/11/26.
//
#include "c_object.h"
void Shape_ctor(Shape *const me,int16_t x,int16_t y){
    me->x = x;
    me->y = y;
}
void Shape_moveBy(Shape *const me,int16_t dx,int16_t dy){
    me->x += dx;
    me->y += dy;
}
int16_t Shape_get_X(Shape const *const me){
    return me->x;
}
int16_t Shape_get_Y(Shape const *const me){
    return me->y;
}