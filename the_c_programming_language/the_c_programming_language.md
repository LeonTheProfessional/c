# The C Programming Language

## 第1章 导言

1. 在C语言中，所有变量都必须先声明后使用。声明通常放在函数的起始处，在任何可执行语句之前。

2. printf函数并不是C语言本身的一部分，C语言本身并没有定义输入/输出功能。printf仅仅是标准库函数中一个有用的函数。

3. **如何区分文件中的有效数据与输入结束符？**

```
#include <stdio.h>

int main(void)
{
    int ch;
    
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }
    printf("EOF is %d\n", ch);
    printf("EOF is %d\n", EOF);
    
    return 0;
}
```

C语言采取的解决方法是：在没有输入时，getchar()函数将返回一个特殊值EOF(end of file)。上面代码中之所以不把c声明为char类型，是因为它必须足够大，除了能存储任何可能的字符之外还要能存储文件结束符EOF。EOF定义在头文件`<stdio.h>`中，是一个整型数，与任何char类型的值都不相同。






