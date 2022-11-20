# struct

## C中的struct
1. C中的struct只是数据的集合，不能定义成员方法
2. C中的struct没有public、private、protected区域之分
3. C中定义的结构体变量，下面使用了实例必须加struct声明
4. C的结构体没有继承概念
5. 如果结构体和函数名相同也可以正常运行正常调用

```cpp
#include<stdio.h>

struct Base {            // public
    int v1; 
//    public:      //error
        int v2; 
    //private:
        int v3; 
    //void print(){       // c中不能在结构体中嵌入函数
    //    printf("%s\n","hello world");
    //};    //error!
};

void Base(){
    printf("%s\n","I am Base func");
}
//struct Base base1;  //ok
//Base base2; //error
int main() {
    struct Base base;
    base.v1=1;
    //base.print();
    printf("%d\n",base.v1);
    Base();
    return 0;
}
```

## C++中的struct
1. 数据+函数的集合
2. 有public、private、protected区域划分
3. 使用时不用声明struct
4. 可以继承
5. 如存在和结构体名字相同的函数，那么在定义结构体变量时，需要在结构体名字前面添加struct关键字以作区分

## struct与class

总的来说，struct 更适合看成是一个数据结构的实现体，class 更适合看成是一个对象的实现体。

最本质的一个区别就是默认的访问控制

1. 默认的继承访问权限。struct 是 public 的，class 是 private 的。
2. struct 作为数据结构的实现体，它默认的数据访问控制是 public 的，而 class 作为对象的实现体，它默认的成员变量访问控制是 private 的。