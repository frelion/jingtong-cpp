#include<iostream>
#define ToString(x) #x
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

int func1(){
    return 123;
}

int main(){
    std::cout << ToString(func1()) << std::endl;
    Entity* b = new Ball();
    b->Show(); // 没有内联
    Entity e = Entity();
    e.Show(); // 内联了
}