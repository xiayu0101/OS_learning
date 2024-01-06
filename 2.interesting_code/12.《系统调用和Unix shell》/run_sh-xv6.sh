gcc -c -ffreestanding sh-xv6.c -g
ld sh-xv6.o -o sh

## strace -f -o /tmp/strace.log ./sh
## tail -f /tmp/strace.log