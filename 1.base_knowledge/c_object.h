//
// Created by yu on 2023/11/26.
//

#ifndef MY_TEST_C_OBJECT_H
#define MY_TEST_C_OBJECT_H

#include <stdint.h>

struct ShapeVtbl;
typedef struct {
    //virtual table 所有虚函数的函数指针的集合
    //virtual pointer 一个指向虚表的指针
    struct ShapeVtbl const *vptr;
    int16_t x;
    int16_t y;
} Shape;

struct ShapeVtbl {
    uint32_t (*area)(Shape const *const me);

    void (*draw)(Shape const *const me);
};

// constructor
void Shape_ctor(Shape *const me, int16_t x, int16_t y);

void Shape_moveBy(Shape *const me, int16_t x, int16_t y);

//int const * - pointer to const int
//int * const - const pointer to int
int16_t Shape_get_X(Shape const *const me);

int16_t Shape_get_Y(Shape const *const me);

static inline uint32_t Shape_area(Shape const *const me) {
    return (*me->vptr->area)(me);
}

static inline void Shape_draw(Shape const *const me) {
    (*me->vptr->draw)(me);
}

Shape const *largestShape(Shape const *shape[], uint32_t nShapes);

void drawAllShapes(Shape const *shape[], uint32_t nShapes);

typedef struct {
    Shape super;
    uint16_t width;
    uint16_t height;
} Rectangle;

void Rectangle_ctor(Rectangle *const me, int16_t x, int16_t y, uint16_t width, uint16_t height);

#endif //MY_TEST_C_OBJECT_H
