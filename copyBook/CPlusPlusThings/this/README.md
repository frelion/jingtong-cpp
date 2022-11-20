# this
## this的用处
和python中的self类似
1. 一个对象的this指针不是对象本身的一部分，不会影响sizeof(ohj)的结果
2. this作用域是在类内部，当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身的地址作为一个隐含参数传递给函数。

## this的类型

1. 如果是返回*this的函数，则`obj* const this`
2. 其他的一般都是 `const obj* const this`
