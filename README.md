# OS_learning
my operation system learning


## todo
1. 学会google，**学会查手册(好难O_o)**和man tldr
2. 阅读model_checker和visualize.py.spinlock-xv6.c
4. 实现协程、使用qemu/liunx-minimal.zip
5. make thread-os.c abstract-machines
6. DAG -> 一个小的DAG框架(https://github.com/ChunelFeng/CGraph)->paddlepaddle

## read everyday
1. 防御性编程（check、-fsanitize=address、-fsanitiize=thread、-fwrapv、print）、perf



## less usage
```
/字符串：向下搜索"字符串"的功能
?字符串：向上搜索"字符串"的功能
n：重复前一个搜索（与 / 或 ? 有关）
N：反向重复前一个搜索（与 / 或 ? 有关）
b 向上翻一页
d 向后翻半页
u 向前滚动半页
y 向前滚动一行
空格键 滚动一页
回车键 滚动一行
G - 移动到最后一行
g - 移动到第一行
j - 下一行
k - 上一行
```
## tmux usage
```asm
1.基本操作
ctrl+d exit 退出
ctcl+b 前缀键
先按下Ctrl+b，再按下?，就会显示帮助信息
2.会话管理
# 新建会话
tmux new -s <session-name>

# 分离会话
tmux detach

# 查看当前会话
tmux ls命令

# 使用会话编号
$ tmux attach -t 0

# 使用会话名称
$ tmux attach -t <session-name>

# 使用会话编号
tmux kill-session -t 0

# 使用会话名称
tmux kill-session -t <session-name>

# 使用会话编号
$ tmux switch -t 0

# 使用会话名称
$ tmux switch -t <session-name>

# 重命名会话
tmux rename-session -t 0 <new-name>

Ctrl+b d：分离当前会话。
Ctrl+b s：列出所有会话。
Ctrl+b $：重命名当前会话。

3.窗口操作
# 划分上下两个窗格
$ tmux split-window

# 划分左右两个窗格
$ tmux split-window -h

# 光标切换到上方窗格
$ tmux select-pane -U

# 光标切换到下方窗格
$ tmux select-pane -D

# 光标切换到左边窗格
$ tmux select-pane -L

# 光标切换到右边窗格
$ tmux select-pane -R

# 当前窗格上移
$ tmux swap-pane -U

# 当前窗格下移
$ tmux swap-pane -D

Ctrl+b %：划分左右两个窗格。
Ctrl+b "：划分上下两个窗格。
Ctrl+b <arrow key>：光标切换到其他窗格。<arrow key>是指向要切换到的窗格的方向键，比如切换到下方窗格，就按方向键↓。
Ctrl+b ;：光标切换到上一个窗格。
Ctrl+b o：光标切换到下一个窗格。
Ctrl+b {：当前窗格与上一个窗格交换位置。
Ctrl+b }：当前窗格与下一个窗格交换位置。
Ctrl+b Ctrl+o：所有窗格向前移动一个位置，第一个窗格变成最后一个窗格。
Ctrl+b Alt+o：所有窗格向后移动一个位置，最后一个窗格变成第一个窗格。
Ctrl+b x：关闭当前窗格。
Ctrl+b !：将当前窗格拆分为一个独立窗口。
Ctrl+b z：当前窗格全屏显示，再使用一次会变回原来大小。
Ctrl+b Ctrl+<arrow key>：按箭头方向调整窗格大小。
Ctrl+b q：显示窗格编号。


4.窗口管理
# 新建一个指定名称的窗口
$ tmux new-window -n <window-name>

# 切换到指定编号的窗口
$ tmux select-window -t <window-number>

# 切换到指定名称的窗口
$ tmux select-window -t <window-name>

tmux rename-window <new-name>

Ctrl+b c：创建一个新窗口，状态栏会显示多个窗口的信息。
Ctrl+b p：切换到上一个窗口（按照状态栏上的顺序）。
Ctrl+b n：切换到下一个窗口。
Ctrl+b <number>：切换到指定编号的窗口，其中的<number>是状态栏上的窗口编号。
Ctrl+b w：从列表中选择窗口。
Ctrl+b ,：窗口重命名。
```
https://img-blog.csdnimg.cn/6646a98df921411aaf104e4cb884c6c2.png

## gcc usage
```asm
-E 只运行 C 预编译器。
-g 生成调试信息。GNU 调试器可利用该信息。
-shared 生成共享目标文件。通常用在建立共享库时。
-static 禁止使用共享连接。
-w 不生成任何警告信息。
-Wall 生成所有警告信息。
-c 只激活预处理,编译,和汇编,也就是他只把程序做成obj文件
　　例子用法:
　　gcc -c hello.c
　　他将生成.o的obj文件
-S 只激活预处理和编译，就是指把文件编译成为汇编代码。
　　例子用法
　　gcc -S hello.c
　　他将生成.s的汇编代码，你可以用文本编辑器察看
-o 制定目标名称,缺省的时候,gcc 编译出来的文件是a.out
```
## ld
ld命令是二进制工具集GNU Binutils的一员，是GNU链接器，用于将目标文件与库链接为可执行程序或库文件。

## strace 
strace是一个可用于诊断、调试和教学的Linux用户空间跟踪器。我们用它来监控用户空间进程和内核的交互，比如系统调用、信号传递、进程状态变更等。

strace ./a.out
strace -T ./a.out 显示系统调用时间

**strace pmap 13457 查看pmap的行为** 

## gdb usage
```asm
调试命令 (缩写)	作用
start 会停在 main 函数入口
starti 会停留在第一个要执行的机器指令上，一般是_start的入口
break (b)	在源代码指定的某一行设置断点，其中xxx用于指定具体打断点位置
run (r）	执行被调试的程序，其会自动在第一个断点处暂停执行。
continue (c）	当程序在某一断点处停止后，用该指令可以继续执行，直至遇到断点或者程序结束。
next (n)	令程序一行代码一行代码的执行。
step（s）	如果有调用函数，进入调用的函数内部；否则，和 next 命令的功能一样。
until (u)
until (u) location	当你厌倦了在一个循环体内单步跟踪时，单纯使用 until 命令，可以运行程序直到退出循环体。
until n 命令中，n 为某一行代码的行号，该命令会使程序运行至第 n 行代码处停止。
print (p）	打印指定变量的值，其中 xxx 指的就是某一变量名。
list (l)	显示源程序代码的内容，包括各行代码所在的行号。
finish（fi）	结束当前正在执行的函数，并在跳出函数后暂停程序的执行。
return（return）	结束当前调用函数并返回指定值，到上一层函数调用处停止程序执行。
jump（j)	使程序从当前要执行的代码处，直接跳转到指定位置处继续执行后续的代码。
quit (q)	终止调试。
info inferiors 显示GDB调试的所有inferior(每一个被调试程序的执行状态记录在一个名为inferior的结构中，一般情况下一个inferior对应一个进程)，GDB会为他们分配进程ID,其中带有*的进程是正在调试的inferior
layout src 显示源代码窗口
layout asm 显示汇编窗口
bt 栈
wa watchpoint
x 查看内存地址中的值
```

## pmap
pmap + 进程号 查看进程的内存映像信息
cat /proc/进程号/maps


## vim

```asm
vim - 从标准输入读取
:set nowrap 取消自动折行––超出屏幕范围的文本将不会被显示，你需要向句末移动光标，以使屏幕水平滚动，查看一行的完整内容。
:%! grep xxx 过滤行
:%! grep -v xxx 反向过滤行
v 进入普通可视模式
CTRL_v 进入列可视模式
V 进入行可视模式
!%xxd 十六进制查看
:{作用范围}s/{目标字符}/{替换的字符}/{替换标志} 例子:%s/, /\s将, 换成换行
```

##file
解析该文件的类型
file a.out 

##readelf
readelf -l main 查看可执行的 elf 文件程序头表信息

##qemu
```asm
启动qemu后，ctrl + a + c可以进入monitor的界面，再次ctrl + a + c可以从monitor里退出，
```