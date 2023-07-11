/*
1、派生类从基类那里继承了什么？
基类的公有成员称为派生类的公有成员。基类的保护成员称为派生类的保护成员。基类的私有成员被继承，
但不能直接访问。

2、派生类不能从基类那里继承什么？
不能继承构造函数、析构函数、赋值运算符和友元。

3、假设baseDMA::operator=()函数的返回类型为void，而不是baseDMA &，这将有什么后果？如果返回类型为baseDMA，
而不是baseDMA &，又将有什么后果？
baseDMA magazine("Pandering to Glitz", 1);
baseDMA gitf1, gift2, gift2;
gift1 = magazine; // ok
gift2 = gift3 = gift1; // no longer valid
如果方法返回一个对象，而不是引用，则该方法的执行速度将有所减慢，这是因为返回语句需要复制对象。

4、创建和删除派生类对象时，构造函数和析构函数调用的顺序是怎样的？
按派生的顺序调用构造函数，最早的构造函数最先调用。调用析构函数的顺序正好相反。

5、如果派生类没有添加任何数据成员，它是否需要构造函数？
需要，每个类都必须有自己的构造函数。如果派生类没有添加新成员，则构造函数可以为空，但必须存在。

6、如果基类和派生类定义了同名的方法，当派生类对象调用该方法时，被调用的将是哪个方法？
只调用派生类方法。它取代基类定义。仅当派生类没有重新定义方法或使用作用域解析运算符时，才会调用基类方法。然而，
应将所有要重新定义的函数声明为虚函数。

7、在什么情况下，派生类应定义赋值运算符？
如果派生类构造函数使用new或new[]运算符来初始化类的指针成员，则应定义一个赋值运算符。更普遍地说，如果对于派
生类成员来说，默认赋值不正确，则应定义赋值运算符。

8、可以将派生类对象的地址赋给基类指针吗？可以将基类对象赋给派生类对象吗？
可以将派生类对象的地址赋给基类指针，但只有通过显示类型转换，才可以将基类对象的地址赋给派生类指针（向下转换），
而使用这样的指针不一定安全。

9、可以将派生类对象赋给基类对象吗？可以将基类对象赋给派生类对象吗？
可以将派生类对象赋给基类对象，对于派生类中新增的数据成员都不会传递给基类对象。然而，程序将使用基类的赋值运算符。
仅当派生类定义了转换运算符（即包含将基类引用作为唯一参数的构造函数）或使用基类作为参数的赋值运算符时，相反
法相的赋值才是可能的。

10、假设定义了一个函数，它将基类对象的引用作为参数。为什么该函数也可以将派生类对象作为参数？
它可以这样做，因为c++允许基类引用指向从该基类派生而来的任何模型。

11、假设定义了一个函数，它将基类对象作为参数（即函数按值传递基类对象）。为什么该函数也可以将派生类对象
作为参数？
按值传递对象将调用复制构造函数。由于形参是基类对象，因此将调用基类的复制构造函数。复制构造函数以基类引用
为参数，该引用可以指向作为参数传递的派生对象。最终结果是，将生成一个新的基类对象，其成员对应于派生对象的
基类部份。

12、
为什么通常按引用传递对象比按值传递对象的效率更高？
按引用（而不是按值）传递对象，这样可以确保函数从虚函数收益。另外，按引用（而不是按值）传递对象可以节省内存
和时间，尤其对于大型对象。按值传递对象的主要优点在于可以保护原始数据，但可以通过将引用作为const类型传递，
来达到同样的目的。

13、假设Corporation是基类，PublicCorporation是派生类。再假设这两个类都定义了head()函数，ph是指向
Corporation类型的指针，且被赋给了一个PublicCorporation对象的地址。如果基类将head()定义为：
a、常规非虚方法；
b、虚方法；
则ph->head()将被如何解释？
a、
Corporation::head(); // 跟着指针、引用类型走，因为没有用virtual
b、
PublicCorporation::head(); // 用了virtual，所以跟着指针、引用指向的对象类型来选择方法

*/