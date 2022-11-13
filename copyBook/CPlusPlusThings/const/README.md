# const
## 对变量使用const将它变成 常量 或者 常量约束吧！
c++中有 栈区、堆区、静态区、常量区
常量区 只读不可写，因此理想的情况下我们希望常量就分配在常量区中就好了

const 对变量进行修饰可以让该变量被分配在常量区中（但是有条件的）
1. 必须在全局中进行const定义，在局部函数中进行定义还是分配在栈中，只是语法上编译器不让修改，通过指针我们还是可以修改成功的(但是有的编译器会把这种操作拦截下来)
2. 必须定义的是整数、字符串、枚举类型。其他类型无法分配在常量区

const 仅在定义整数类型和枚举类型，且以常量表达式初始化时才是常量表达式

其他类型时候都只是一种 `常量约束`

也就是说其他类型的时候我们可以通过一些方法改变其的值

`const int MAXN = 1000000;`
```cpp
const int a = 100;
a = 10; // 错误！常量不允许修改了
const int i,j = 10; // 错误常量i没有初始化
const string s = "12345"; // 一种常量约束
```
> 与#define的区别
1. #define仅仅只是代码字符串的替换，const是有类型的，编译器可以进行安全检查
2. const定义的数值，给出的是一份地址，不会有复制，而#define却有，因此const更加节省空间


### const变量默认为文件局部变量

```cpp
// 以下代码中file2引用file1的ext变量

// file1
int ext = 12;
// file2
extern int ext;
```
```cpp
// 以下代码中file2引用file1的ext const变量

// file1
extern const int ext = 12;
// file2
extern const int ext;

// file1 中const int ext前面必须加extern关键字，因为const变量默认文件局部，不加extern是无法被外部文件引用的！
```

## 对指针使用const吧！
```cpp
const char* a = 'a'; // 指向一个常量'a'的指针
char const* a = 'a'; // 同上
char* const a = 'a'; // 一个常指针
const char* const a = 'a'; // 指向一个常量 'a' 的常指针
```
`const在*左侧 修饰指针指向变量`

`const在*右侧 修饰指针本身`
### 指向常量的指针
const对象必须用指向const的指针

```cpp
const int *ptr = 100;
*ptr = 10; //error 指向const变量的指针不可以写值
```

```cpp
const int *ptr;
int a = 100;
ptr = &a; // 可以将非const对象赋值给const指针 此时我们也不能用这个const指针修改这个值
```

总结
1. 对于指向常量的指针，不能通过指针来修改对象的值。
2. 不能使用void*指针保存const对象的地址，必须使用const void*类型的指针保存const对象的地址。
3. 允许把非const对象的地址赋值给const对象的指针，如果要修改指针所指向的对象值，必须通过其他方式修改，不能直接通过当前指针直接修改

### 常指针
1. 指针是常量，不可以修改指针本身
2. 常指针必须初始化，且该指针不能修改


```cpp
int a = 100;
int main(){
    int* const ptr; // error 常指针必须立刻分配初始化
    ptr = &a;
}
```

```cpp
int a = 100;
int main(){
    int* const ptr = &a;
    *ptr = 10; // success 可以修改指针指向的值
}
```

```cpp
const int a = 100;
int main(){
    int* const ptr = &a; // error 不可以用一个非指向常量的指针 去指向常量
}
```

```cpp
int a = 100;
int b = 10;

int main(){
    int* const ptr = &a;
    ptr = &b; // error 常指针不可以重新被写了
}
```

### 指向常量的常指针

```cpp
const int a = 100;
int main(){
    const int* const ptr = &a; // good!
}
```

## 对函数使用const吧！
其实就是对返回值和传入的参数进行const修饰

```cpp
const int func1();
/*
我们定义了这个函数的返回值是一个const int 不可修改
但是这本身毫无意义，因为我们调用这个函数时
int a = func1();
本身也是赋值操作
*/
const int* func2();
/*
指针指向的内容不可变
*/
int* const func3();
/*
一个不可变的指针
*/
```

```cpp
void func1(const int var); // 传递的值不可变
void func1(int* const var); // 传递的指针不可变
/*
上面两种，基本上是没有意义的。
因为函数传参数的时候就是值传递，会拷贝一份
如果是基于保护原有的变量/指针的想法这样做基本上是没有任何意义
*/
void StringCopy(char *dst, const char *src);
/*
其中src 是输入参数，dst 是输出参数。
给src加上const修饰后，如果函数体内的语句试图改动src的内容，编译器将指出错误。
这就是加了const的作用之一。
可以保护值不被修改
同样的还有对引用使用const
*/
void StringCopy(char &dst, const char &src);
/*
是否应将void func(int x) 改写为void func(const int &x)，以便提高效率？完全没有必要，因为内部数据类型的参数不存在构造、析构的过程，而复制也非常快，“值传递”和“引用传递”的效率几乎相当。
*/
```

总结
1. 对于非内部数据类型的输入参数，应该将“值传递”的方式改为“const 引用传递”，目的是提高效率。例如将void func(A a) 改为void func(const A &a)。
2. 对于内部数据类型的输入参数，不要将“值传递”的方式改为“const 引用传递”。否则既达不到提高效率的目的，又降低了函数的可理解性。例如void func(int x) 不应该改为void func(const int &x)。

## 对类使用const吧！
对成员变量和成员函数使用const修饰

const成员函数只能调用const成员函数，而非const成员函数可以访问任何函数包括const函数

1. const函数中不可以写成员变量
2. const函数不可以使用非const函数
3. const实例不能以任何形式对成员变量写
4. const实例只能调用const函数，不能调用非const函数

```cpp
#include<iostream>

class Entity{
    public:
        Entity(int a);
        const int a;
        int b;
        void func1();
        void func2() const;
};
Entity::Entity(int i):a(i),b(i*i){

}
void Entity::func2()const{
    std::cout<< "func2" <<std::endl;
}
void Entity::func1()const{
    std::cout<< "func1" <<std::endl;
    std::cout << a << "," << b << std::endl;
    b = 100; // error 因为对成员变量写了
    func2(); // error 因为const方法func1调用了非const方法func2
}
int main(){
    Entity e(100);
    e.func1();
}
```

```cpp
#include<iostream>

class Entity{
    public:
        Entity(int a);
        const int a;
        int b;
        void func1() const;
        void func2();
};
Entity::Entity(int i):a(i),b(i*i){

}
void Entity::func2(){
    std::cout<< "func2" <<std::endl;
}
void Entity::func1()const{
    std::cout<< "func1" <<std::endl;
}
int main(){
    const Entity e(100);
    e.b = 100; // error const实例对成员变量写了
    e.func2(); // error const实例调用了非const函数
    std::cout << e.b << std::endl;
}
```

也可以static和const结合

`static const int a;`

static一般是在类中定义然后在全局中初始化，c++11编译器允许定义时初始化

`static const int a = 100;`

