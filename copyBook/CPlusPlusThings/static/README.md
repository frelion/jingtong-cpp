# static

## 静态变量存储空间
存储在静态变量空间中

## 静态变量初始化
### 静态变量初始化
利用常量对静态变量初始化，**在程序加载时完成初始化**（包括在函数中采用静态初始化的静态变量）
### 动态变量初始化
需要调用函数才能初始化的静态变量。比如：累的构造函数。

对于全局活着类的静态变量是在main()函数执行前由运行时调用的相应的代码进行初始化的。

对于局部静态变量则是在函数执行至此初始化语句才开始进行初始化的

## 使用static修饰函授内部变量吧！
在函数中使用static修饰的变量成为局部静态变量

对函数中的变量前用static修饰，此变量的生命周期将会成为程序的生命周期

1. 初始化时间：第一次执行到此语句
2. 销毁时间：程序结束运行
3. 即使多次调用该函数，静态变量的空间也只分配一次，前一次调用中的变量值通过下一次函数调用传递，也因此**不能保证线程安全**

```cpp
#include<iostream>

void demo(){
    static int count = 0;
    std::cout << count << std::endl;
    count++;
}

int main(){
    for (int i=0;i<=5;i++){
        demo();
    }
}
```

## 使用static修饰类中变量吧！

因为声明为static的变量中只会初始化一次，因此他们在单独的静态存储中分配了空间，类中的静态变量由实例共享。对于不同的实例，不能有相同静态变量的多个副本，也是因为这个原因，静态变量不能使用构造函数初始化

1. 初始化时间：静态变量被第一次定义的时候
2. 销毁时间：程序结束时
3. 单例模式中的饿汉模式

```cpp
#include<iostream>

class Entity{
    public:
        static int a;
        Entity(){

        }
};

int Entity::a = 1; // 在此时被初始化

int main(){
    Entity e1 = Entity();
    Entity e2 = Entity();
    // e1 e2共享同一个static变量a
    e1.a = 100;
    e2.a = 1000;
    std::cout << e1.a << " " << e2.a <<std::endl;
}
```

## 使用static修饰类中函数吧！
1. 类的静态函数不依赖对象
2. 不可以使用类中非静态变量和调用类中非静态函数

```cpp
#include<iostream>

class Entity{
    public:
        int a;
        static void printString(){
            std::cout << "hello" << std::endl;
        }
};

int main(){
    Entity::printString();
}
```

## 使用static修饰实例吧！

```cpp
#include<iostream>

class Entity{
    public:
        int a;
        Entity(){
            a = 100;
            std::cout << "init" << std::endl;
        }
        ~Entity(){
            std::cout << "destroy" << std::endl;
        }
};

int main(){
    int x = 0;
    if (x == 0){
        Entity e;
    }
    std::cout << "end" << std::endl;
}
/*
输出：
init
destroy
end
我们在if模块定义了一个e，然后走出if模块这个e自然就被销毁了，也因此调用了析构函数
*/
#include<iostream>

class Entity{
    public:
        int a;
        Entity(){
            a = 100;
            std::cout << "init" << std::endl;
        }
        ~Entity(){
            std::cout << "destroy" << std::endl;
        }
};

int main(){
    int x = 0;
    if (x == 0){
        static Entity e;
    }
    std::cout << "end" << std::endl;
}
/*
输出：
init
end
destroy
这里可以看到直到程序退出才销毁变量e
*/
```

## 使用static修饰全局变量吧！
使用static修饰文件全局变量

`static int a = 100;`

这会导致本变量是本文件局部作用域的
换句话说，其他文件无法引用这个变量，linker无法连接