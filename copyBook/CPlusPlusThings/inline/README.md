# inline

## 原理：可复用的代码块
程序在调用函数的时候有着调用开销

即，找到调用的函数的地址去执行调用的函数，执行完之后再回来。这是有代价的

因此，inline定义的内联函数，会将函数代码复制到被调用的地方，从而**减少函数的调用开销**

但是，坏处也很明显
1. 以代码膨胀为代价，代码编写完后的机器码会占用更多的内存空间
2. 对于复杂的函数，拥有循环和递归的函数。函数本身执行的时间远远大于函数调用的开销，inline优化效果不明显

## 使用

只需要简单的在函数前面加一个inline就可以了
```cpp
#include<iostream>
inline int x2(int x){
    return x*x;
}

int main(){
    std::cout << x2(100) << std::endl;
}
```

### 类中内联
1. 类定义阶段实现的函数，默认都是内联函数！当然，这只是对编译器的建议，具体是否是内联还是要编译器自己判断

```cpp
#include<iostream>

class Entity{
    public:
        void Show(){
            std::cout << "hello" << std::endl;
        };
};

int main(){
    Entity e = Entity();
    e.Show();
}
```

2. 类中声明的函数，想要将其变成内联，定义的时候必须加上inline

```cpp
#include<iostream>

class Entity{
    public:
        void Show();
};

inline void Entity::Show(){
    std::cout << "hello" << std::endl;
}

int main(){
    Entity e = Entity();
    e.Show();
}
```

### 虚函数内联

1. 虚函数可以是内联函数，内联可以修饰虚函数，但是当虚函数表现多态性质的时候不能内联
2. 因为虚函数的多态性是在运行期决定的，而内联却是在编译期决定的，编译器无法在编译器知道该内联哪个具体的函数
3. `inline virtual` 唯一可以内联的时候就是，编译器知道所调用的对象是哪个类，这只有在编译器具有实际对象而不是对象的指针或引用时才会发生的

```cpp
#include<iostream>

class Entity{
    public:
        inline virtual void Show(){
            std::cout << "hello" << std::endl;
        };
};
class Ball : public Entity{
    public:
        void Show(){
            std::cout << "world" << std::endl;
        }
};
int main(){
    Entity* b = new Ball();
    b->Show(); // 没有内联
    Entity e = Entity();
    e.Show(); // 内联了
}
```