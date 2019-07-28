@[]

# c++如何编译

## gcc & g++

### 介绍

gcc and g++分别是gnu的c & c++编译器

gcc/g++在执行编译工作的时候，总共需要4步

1. 预处理,生成.i的文件  
> 预处理器cpp
2. 将预处理后的文件不转换成汇编语言,生成文件.s  
> 编译器egcs
3. 有汇编变为目标代码(机器代码)生成.o的文件
>汇编器as
4. 连接目标代码,生成可执行程序
>连接器ld

### 总体选项

1. -E
>只激活预处理，这个不生成文件，需要把它重定向到一个输出文件里。
例子用法：
```shell
gcc -E hello.c > test.txt
gcc -E hello.c | more
```

2. -S
>只激活预处理和编译，就是指把文件编译成为汇编代码。
例子用法
```
gcc -S hello.c
```
他将生成.s的汇编代码，你可以用文本编辑器察看

3. -c
>只激活预处理,编译,和汇编,也就是他只把程序做成obj文件
例子用法:
```
gcc -c hello.c
```
他将生成.o的obj文件

### 目录选项

1. -ldir
2. -include file
3. -l-
4. -ldirafter dir
5. -iprefix prefix
6. -iwithprefix dir
7. -Ldir
8. -llibrary
例如：

```
gcc -lcurses hello.c
```

使用curses库编译程序

### 调试选项

1. -g
>只是编译器，在编译的时候，产生调试信息.

2. -gstabs
>此选项以stabs格式声称调试信息,但是不包括gdb调试信息.
3. -gstabs+
>此选项以stabs格式声称调试信息,并且包含仅供gdb使用的额外调试信息.
4. -ggdb
>此选项将尽可能的生成gdb的可以使用的调试信息.
5. -glevel
>请求生成调试信息，同时用level指出需要多少信息，默认的level值是2

### 链接方式选项

1. -static
>此选项将禁止使用动态库
优点：程序运行不依赖于其他库
缺点：文件比较大
2. -shared(-G)
>此选项将尽量使用动态库，为默认选项
优点：文件比较小
缺点：程序运行依赖动态库
3. -symbolic
>建立共享目标文件的时候，把引用绑定到全局符号上
对所有无法解析的引用作出警告(除非用连接编辑选项'-Xlinker -z -Xlinker defs'取代)。

### 错误与告警选项

1. -Wall
>一般使用该选项，允许发出GCC能够提供的所有的有用警告，也可以用-W{warning}来标记指定的警告

2. -pedantic
>允许发出ANSI/ISO C标准所列出的所有警告

3. -pedantic-errors
>允许发出ANSI/ISO C标准所列出的错误
4. -werror
>把所有警告转换为错误，以在警告发生时中止编译过程
5. -w
>关闭所有警告,建议不要使用此项

### 预处理选项

1. -Dmacro
>相当于C语言中的#define macro

2. -Dmacro=defn
>相当于C语言中的#define macro=defn

3. -Umacro
>相当于C语言中的#undef macro

4. -undef
>取消对任何非标准宏的定义 

### 其他选项

1. -o
>制定目标名称,缺省的时候,gcc 编译出来的文件是a.out,

2. -O0 -O1 -O2 -O3
>编译器的优化选项的4个级别，-O0表示没有优化,-O1为缺省值，-O3优化级别最高

3. -fpic
>编译器就生成位置无关目标码.适用于共享库(shared library)

4. -fPIC
>编译器就输出位置无关目标码.适用于动态连接(dynamic linking),即使分支需要大范围转移.

5. -v
>显示详细的编译、汇编、连接命令

6. -pipe
>使用管道代替编译中临时文件,在使用非gnu汇编工具的时候,可能有些问题

7. -ansi
>关闭gnu c中与ansi c不兼容的特性,激活ansi c的专有特性(包括禁止一些asm inline typeof关键字,以及UNIX,vax等预处理宏,  

8.  -fno-asm
>此选项实现ansi选项的功能的一部分，它禁止将asm,inline和typeof用作关键字。 

9. -fno-strict-prototype 
> 只对g++起作用,使用这个选项,g++将对不带参数的函数,都认为是没有显式的对参数的个数和类型说明,而不是没有参数.而gcc无论是否使用这个参数,都将对没有带参数的函数,认为城没有显式说明的类型

10. -fthis-is-varialble
>就是向传统c++看齐,可以使用this当一般变量使用. 

11. -fcond-mismatch
>允许条件表达式的第二和第三参数类型不匹配,表达式的值将为void类型

12. -funsigned-char   -fno-signed-char   -fsigned-char   -fno-unsigned-char
> 这四个参数是对char类型进行设置,决定将char类型设置成unsigned char(前两个参数)或者 signed char(后两个参数) 

13. -imacros file   
>将file文件的宏,扩展到gcc/g++的输入文件,宏定义本身并不出现在输入文件中       
 
14.   -nostdinc   
>使编译器不再系统缺省的头文件目录里面找头文件,一般和-I联合使用,明确限定头文件的位置   
 
15.   -nostdin C++   
>规定不在g++指定的标准路经中搜索,但仍在其他路径中搜索,.此选项在创建libg++库使用   

16.   -C   
>在预处理的时候,不删除注释信息,一般和-E使用,有时候分析程序，用这个很方便的   
 
17.   -M   
>生成文件关联的信息。包含目标文件所依赖的所有源代码你可以用gcc -M hello.c来测试一下，很简单。   

18.   -MM   
>和上面的那个一样，但是它将忽略由#include造成的依赖关系。   
 
19.   -MD   
>和-M相同，但是输出将导入到.d的文件里面   
 
20.   -MMD   
>和-MM相同，但是输出将导入到.d的文件里面   
 
21.   -Wa,option   
>此选项传递option给汇编程序;如果option中间有逗号,就将option分成多个选项,然后传递给会汇编程序   
 
22.   -Wl.option   
>此选项传递option给连接程序;如果option中间有逗号,就将option分成多个选项,然后传递给会连接程序.

23.   -x language filename   

>设定文件所使用的语言,使后缀名无效,对以后的多个有效.也就是根   
据约定C语言的后缀名称是.c的，而C++的后缀名是.C或者.cpp,如果   
你很个性，决定你的C代码文件的后缀名是.pig 哈哈，那你就要用这   
个参数,这个参数对他后面的文件名都起作用，除非到了下一个参数   
的使用。   

可以使用的参数有下面的这些   

c, objective-c, c-header, c++, cpp-output,assembler,assembler-with-cpp,

看到英文，应该可以理解的。 

例子用法: 

```
gcc -x c hello.pig   
    -x none filename   
```

关掉上一个选项，也就是让gcc根据文件名后缀，自动识别文件类型   
例子用法: 

```
gcc -x c hello.pig -x none hello2.c 
```



## make文件怎么写

g++ -I include -L lib -


## cmake

