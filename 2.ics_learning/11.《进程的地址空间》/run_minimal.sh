gcc -c minimal.S && ld minimal.o

## gdb  starti  info inferiors pmap+进程号 strace pmap + 进程号 |& vim -
# 用 |& 来重定向stderr到stdin然后管道给下一个命令。
# !cat /proc/14170/maps
# man 5 proc