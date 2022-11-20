# volatile

## 原理
volatile是一种修饰符，修饰的变量表示该变量可能被某些 **编译器**未知的因素更改，如：多线程、操作系统、硬件、IO等，加上volatile使得代码可感知这个修改

```cpp
#include<iostream>
int a=10;
int main(){
    int b;
    int c;
    b = a;
    c = a;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}
/*
编译器发现他要两次取a进行赋值的时候，第二次赋值操作他就不会去内存中找到a得到值，而是会缓存第一次a的值，直接赋值给c

然而，可能此刻有一个其他的线程把值a改变了！我们的代码中对这个改变是无感知的！
*/
```
因此，对变量a进行volatile修饰，这样每次使用都必须从内存地址读取数据！
```cpp
#include<iostream>
volatile int a=10;
int main(){
    int b;
    int c;
    b = a;
    c = a;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}
```
## 用volatile修饰指针吧
和const类似，有wolatile指针和指针volatile

1. 在*前面的是用来修饰volatile指向的变量
2. 在*后面的是用来修饰指针本身

