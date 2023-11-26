//
// Created by yu on 2023/11/26.
//
#include "c_object.h"
#include "assert.h"
#include "stdio.h"

static uint32_t Shape_area_(Shape const *const me);

static void Shape_draw_(Shape const *const me);

static uint32_t Rectangle_area_(Shape const *const me);

static void Rectangle_draw_(Shape const *const me);

void Shape_ctor(Shape *const me, int16_t x, int16_t y) {
    static struct ShapeVtbl const vtbl = {
            &Shape_area_,
            &Shape_draw_
    };
    me->vptr = &vtbl;
    me->x = x;
    me->y = y;
}

void Shape_moveBy(Shape *const me, int16_t dx, int16_t dy) {
    me->x += dx;
    me->y += dy;
}

int16_t Shape_get_X(Shape const *const me) {
    return me->x;
}

int16_t Shape_get_Y(Shape const *const me) {
    return me->y;
}

static uint32_t Shape_area_(Shape const *const me) {
    assert(0); // 纯虚函数不能被调用
    return 0U;
}

static void Shape_draw_(Shape const *const me) {
    assert(0);
}

Shape const *largestShape(Shape const *shapes[], uint32_t n_shapes) {
    Shape const *s = (Shape *) 0;
    uint32_t max = 0U;
    uint32_t i;
    for (i = 0U; i < n_shapes; i++) {
        uint32_t area = Shape_area(shapes[i]);
        if (area > max) {
            max = area;
            s = shapes[i];
        }
    }
    return s;
}

void drawAllShapes(Shape const *shapes[], uint32_t n_shapes) {
    uint32_t i;
    for (i = 0U; i < n_shapes; i++) {
        Shape_draw(shapes[i]);
    }
}

void Rectangle_ctor(Rectangle *const me, int16_t x, int16_t y, uint16_t width, uint16_t height) {
    static struct ShapeVtbl const vtbl = {
            &Rectangle_area_,
            &Rectangle_draw_
    };
    Shape_ctor(&me->super, x, y);
    // 后期绑定,vptr 必须在ctor之后，不然就调用纯虚函数了
    me->super.vptr = &vtbl;
    me->width = width;
    me->height = height;
}

static uint32_t Rectangle_area_(Shape const *const me) {
    Rectangle const *const me_ = (Rectangle const *) me;
    return (uint32_t) me_->width * (uint32_t) me_->height;
}

static void Rectangle_draw_(Shape const *const me) {
    Rectangle const *const me_ = (Rectangle const *) me;
    printf("Rectangle_draw_(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_get_X(me), Shape_get_Y(me), me_->width, me_->height);
}
