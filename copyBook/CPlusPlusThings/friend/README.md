# friend
友元提供了一种普通函数或者类成员函数访问另一个类中的私有或者保护成员的机制。主要两种形式的友元
1. 友元函数：普通函数访问某个类中的私有或保护成员
2. 友元类：类A中的吧成员函数访问类B中的私有或保护成员

优点：提高了程序的运行效率

缺点：破坏了类的封装性和数据的透明性

总结：
1. 能访问私有成员
2. 破坏封装性
3. 友元关系不可传递
4. 友元关系的单向性
5. 友元声明的形式及数量不受限制

