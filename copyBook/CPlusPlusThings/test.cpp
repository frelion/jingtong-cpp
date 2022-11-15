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