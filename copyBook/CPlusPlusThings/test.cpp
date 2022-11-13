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