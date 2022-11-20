# extern
## 表示变量/函数在别的模块中
`extern int a;`

`extern int add(int,int);`

linker遇到这些变量和函数中就会去外部的模块中寻找函数和变量的定义

## 为了兼容C！
c++是基于c的语言嘛
我们回忆一下c++编译运行的步骤
1. 对单个cpp/c文件进行编译
2. linker进行链接
3. 运行main函数

在第二步，如果我们想要使用使用某个函数，那么我们就引入这个函数所在的头文件，这个头文件中有对这个函数的声明。

编译器拿到这个声明之后，会将这个函数声明生成一个函数签名，然后依靠这个函数签名找到函数定义，之后运行函数

总结
1. 根据函数声明生成函数签名
2. 根据函数签名照到函数定义

但是！

**cpp中生成函数签名的规则和c中生成函数签名的规则不一样！**
因为，cpp中存在虚函数多态的概念，所以生成函数签名的规则不能照搬c

因此，一个和c函数定义不同的函数签名是无法被linker链接到c函数的！

**因此，如果我们想要使用c函数，我们就要用c规则生成函数签名，这里就要使用extern关键字**

1. cpp调用c
```c
int add(int x, int y){
    return x+y;
}
```

```cpp
extern "C"{
   int add(int x,int y);
}
int main(){
    add(1,1);
}
```
**同样如何让c调用cpp的函数呢？让cpp的函数定义变成c规则的**
2. c调用cpp
```cpp
extern "C"{
    int add(int x,int y);
}
int add(int x,int y){
    return x+y;
}
```
```c
extern int add(int x,int y); // ertern表明去外面找该函数
int main(){
    add(1,1);
}
```

## 为了能够使用const变量
因为const默认局部变量，我们可以在const前面使用extern进行修饰，使他变成全局变量

`extern const a = 100;` 