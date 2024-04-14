#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"cpu/register.h"
#include"memory/instruction.h"
#include"disk/elf.h"
#include"memory/dram.h"
#include"cpu/mmu.h"

int main(){
    // reg.rax = 0x1234111155556666;
    // reg.rbx = 0x2222111155556666;
    // printf("eax: %08x\n",reg.eax);
    init_handler_table();

    //init
    reg.rax = 0x1234;
    reg.rbx = 0x555555555190;
    reg.rcx = 0x555555555190;
    reg.rdx = 0xabcd0000;
    reg.rsi = 0x7fffffffd358;
    reg.rdi = 0x1;
    reg.rbp = 0x7fffffffd260;
    reg.rsp = 0x7fffffffd240;

    reg.rip = (uint64_t)&program[11];

    write64bits_dram(va2pa(0x7fffffffd260),0x00000000);//rbp
    write64bits_dram(va2pa(0x7fffffffd258),0x00000000);
    write64bits_dram(va2pa(0x7fffffffd250),0xabcd0000);
    write64bits_dram(va2pa(0x7fffffffd248),0x00001234);
    write64bits_dram(va2pa(0x7fffffffd240),0x00000000);//rsp

    // printf("%16lx\n",read64bits_dram(va2pa(0x7fffffffd250)));
    print_register();
    print_stack();
    // run inst

    for(int i = 0; i < 3;++i){
        instruction_cycle();
        print_register();
        print_stack();
    }

    //verify
    int match = 1;
    match = match &&(reg.rax == 0xabcd1234);
    match = match &&(reg.rbx == 0x555555555190);
    match = match &&(reg.rcx == 0x555555555190);
    match = match &&(reg.rdx == 0x1234);
    match = match &&(reg.rsi == 0xabcd0000);
    match = match &&(reg.rdi == 0x1234);
    match = match &&(reg.rbp == 0x7fffffffd260);
    match = match &&(reg.rsp == 0x7fffffffd240);

    if(match == 1 ){
        printf("register match\n");
    }else{
        printf("register not match\n");
    }

    match = match &&(read64bits_dram(va2pa(0x7fffffffd260)) == 0x00000000); //rbp
    match = match &&(read64bits_dram(va2pa(0x7fffffffd258)) == 0xabcd1234);
    match = match &&(read64bits_dram(va2pa(0x7fffffffd250)) == 0xabcd0000);
    match = match &&(read64bits_dram(va2pa(0x7fffffffd248)) == 0x00001234);
    match = match &&(read64bits_dram(va2pa(0x7fffffffd240)) == 0x00000000); //rsp
    if(match == 1 ){
        printf("memory match\n");
    }else{
        printf("memory not match\n");
    }

    
    return 0;
}
