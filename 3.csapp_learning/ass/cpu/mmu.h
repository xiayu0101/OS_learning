//memory management unit
#ifndef MMU_H__
#define MMU_H__
#include"stdio.h"
#include"stdlib.h"
#include"stdint.h"

uint64_t va2pa(uint64_t vaddr);
#endif