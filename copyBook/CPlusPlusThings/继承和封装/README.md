# 封装和继承

## 类的封装

```cpp
// 这就是一个类
class Base{
    public:
    int a;
    void func1(){

    }
};
```

### 访问权限
```cpp
class Base{
    /*
    在类的内部，public、private、protected都可以互相访问
    */
    public:
        /*
        公有的
        在外部，通过对象只能访问到pubilc的成员变量和成员函数
        */
        int a;
        void func1();
    private:
        /*
        私有的
        只能在内部访问，在外部无法访问
        */
        int m_b;
        void func2();
    protected:
        /*
        类外不能通过对象访问，但是在他的派生类内部可以访问
        */
        int c;
        void func3();
}
/*
private的作用在于更好地隐藏类的内部实现，该向外暴露的接口都应当声明为public，不希望外部访问，只希望在类内部使用的，或者对外部没有影响的成员，都应当声明为private
*/
```
### 封装性规范
1. 将变量声明为private，利用set、get等public方法进行读写
2. 将部分成员声明为private，将部分成员声明为public，只向用户暴露有用的接口

## 类的继承
```cpp
class [派生类] : [继承方式] [基类]{

}
```

### 继承方式
继承方式限定了基类成员在派生类中的访问权限，包括public、private、protected 默认为private
|继承方式|public|protected|private|
|----|----|----|----|
|public继承|public|protected|private|
|protected继承|protected|protected|private|
|private继承|不可见|不可见|不可见|

> private只是不可见，但是仍然继承了，占用内存空间

### 改变访问权限
使用using关键字可以改变基类成员在派生类中的访问权限

using无法改变基类private成员在子类的访问权限，public和private都可以改变

```cpp
class Entity{
    public:
        int a;
        void Show(){

        }
    protected:
        int b;
};

class Ball : public Entity{
    private:
    using Entity::Show;
    public:
    using Entity::b;
};
```

### 向上转型
基类的指针可以指向子类的实例

子类的实例也可以赋值给基类的变量，但是基类变量会舍弃子类实例中子类的部分

```cpp
#include<iostream>

class Entity{
    public:
        int a;
        void Show(){
            std::cout << "Entity" << std::endl;
        }
};

class Ball : public Entity{
    public:
        int b;
};

int main(){
    Entity e = Ball();
    std::cout << e.a << std::endl;
    std::cout << e.b << std::endl; // error
}
```