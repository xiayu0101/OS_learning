//
// Created by yu on 2023/11/26.
//

#ifndef MY_TEST_C_OBJECT_H
#define MY_TEST_C_OBJECT_H
#include <stdint.h>

typedef struct {
    int16_t x;
    int16_t y;
}Shape;
// constructor
void Shape_ctor(Shape * const me,int16_t x,int16_t y);
void Shape_moveBy(Shape * const me,int16_t x,int16_t y);
//int const * - pointer to const int
//int * const - const pointer to int
int16_t Shape_get_X(Shape const * const me);
int16_t Shape_get_Y(Shape const * const me);

#endif //MY_TEST_C_OBJECT_H
