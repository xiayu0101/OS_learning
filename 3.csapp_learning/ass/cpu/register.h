#ifndef REGISTER_H__
#define REGISTER_H__
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct REG_STRUCT{
    union {
        struct {
            uint8_t al;
            uint8_t ah;
        };

        uint16_t ax;
        uint32_t eax;
        uint64_t rax;   // return value
    };
    
    union {
        struct {
            uint8_t bl;
            uint8_t bh;
        };

        uint16_t bx;
        uint32_t ebx;
        uint64_t rbx;   // caller saved
    };
    union {
        struct {
            uint8_t cl;
            uint8_t ch;
        };

        uint16_t cx;
        uint32_t ecx;
        uint64_t rcx;   // 4th arugmrnt
    };

    union {
        struct {
            uint8_t dl;
            uint8_t dh;
        };

        uint16_t dx;
        uint32_t edx;
        uint64_t rdx;   // 3th arugmrnt
    };    
    
    union {
        struct {
            uint8_t si1;
            uint8_t si2;
        };

        uint16_t si;
        uint32_t esi;
        uint64_t rsi;   // 2th arugmrnt
    };

    union {
        struct {
            uint8_t di1;
            uint8_t di2;
        };

        uint16_t di;
        uint32_t edi;
        uint64_t rdi;   // 1th arugmrnt
    };

    union {
        struct {
            uint8_t bp1;
            uint8_t bp2;
        };

        uint16_t bp;
        uint32_t ebp;
        uint64_t rbp;   // callee saved
    };

    union {
        struct {
            uint8_t sp1;
            uint8_t sp2;
        };

        uint16_t sp;
        uint32_t esp;
        uint64_t rsp;   // stack pointer
    };
    uint64_t rip; // 指令寄存器

}reg_t;

reg_t reg;
#endif