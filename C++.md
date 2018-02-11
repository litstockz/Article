# C++ base on Linux

---

## 目录Contents

| Part 1 | Part 2 | Part 3 | Part 4 | Part 5  | Part 6 | Part 7 | Part 8 |
| :---------: | :---------: | :---------: | :---------: | :---------: |  :---------: |  :---------: |:---------: |
| The Basics | OOP / OOD | STL && Generic Programming | Design Patterns | Linux | Process programming | Thread programming | NetWord programming |

---

## 内容

### <span id = "base"> 一、The Basics【C++编程基础】 </span>

C++

1. 类和成员函数的基本概念

  - 类：一个类定义了一个类型以及与其关联的行为（操作）。每个类都定义了一个新的类型，类型名就是类名。类一般定义在头文件中(.h, .hpp, .hxx)。类的作者定义了类对象可以执行的所有动作。

  - 成员函数：定义为类的一部分函数，也称为方法（method），我们通常以类对象的名义来调用成员函数

  - 对象： 对象是指一块能储存数据并具有某种类型的内存空间

2. 不同数据类型间转换的方法和预期效果

3. 变量的定义和声明
  - 定义在程序产生一个新实体、声明仅仅在程序中引入一个实体。
  - 如果要在多个文件中使用相同变量，就必须将定义和声明分离。相同变量可以在不同文件多处声明（使用extern），但只能在一处定义。

  - 任何包含了显示初始化的声明即成为定义。声明仅仅是把变量的声明的位置及类型提供给编译器，并不分配内存空间；定义要在定义的地方为其分配存储空间。

- const的使用
  - 因为const对象一旦创建后值就不能改变，所以const对象必须初始化
  - 不会改变数据内容的，马上加上const
  - 如果想在多个文件之间共享const对象，必须在变量的定义之前添加extern关键字，使该常量能被其他文件访问
  - 常量引用（对const的引用）：严格来说并不存在常量引用，因为引用不是一个对象，我们无法让引用本身保持不变。
  - 顶层const：指针本身是一个常量。低层const：指针所指对象是一个常量。指针类型即可以是顶层const也可以是底层const
- struct和class的区别
  - 如果没有标明成员函数或者成员变量的访问权限级别，在struct中默认的是public，而在class中默认是private
  - 在C语言中，struct不能定义成员函数，而在C++中，增加了class类型后，扩展了struct的功能，struct也能定义成员函数了。

- 头文件保护符（防卫式声明）：ifndef、define、endif
  - 建议写的每一个头文件都要加防卫式声明，能有效防止重复包含的发生
  - 为什么要写：因为很多程序可能要用到同一个头文件，使用#ifndef和#endif可以检查某个预处理变量是否已经定义。#ifndef当且仅当未定义时为真，如果不曾定义过，就把它定义出来，如果已经定义过，就不会再include进来

- 范围for语句
  - 语法形式

  ```
  for(declaration : expression)
        statement
  ```
  -

- 随机数库
  - 随机数的生成：rand()/srand(),取种子执行：srand((int)time(0))
  - srand只能调用一次，而且必须是在生成第一个随机数之前调用
  - 接口设计原则：用途一致、操作简单、功能充足、性能稳定。设计随机数接口：
  见random.cpp

- 作用域和生存期
  - 不要在头文件中定义全局数据对象！！！想要变量跨文件引用，使用extern关键字声明。
  - 全局解析操作符::,::i访问的就是全局变量i
  - 作用域表达空间范围，生存期表示量在程序中存在的时间范围：静态（全局）生存期、自动（局部）生存期、static修饰局部变量（静态局部变量，必须进行初始化、拉长局部变量的时间特性）、static修饰全局量（静态全局变量、限定作用域）

- strlen()和sizeof()
  - strlen()是函数，在运算时才能计算，参数必须是字符型指针（char*），且必须以'\0'结尾。当数组名作为参数传入时，实际上数组已经退化成指针了。它的功能是返回字符串的长度
  - sizeof()是运算符，不是函数，在编译时就已经计算好了，用于计算数据空间的字节数。因此sizeof不能用来返回动态分配的内存空间的大小。它的返回值和对象、结构、数组所存储的内容没有关系。

- 数组指针和指针数组的区别
  - 数组指针只是一个指针变量，可以认为是C语言中专门用来指向二维数组的,它占用内存中一个指针的存储空间。
  - 指针数组是多个指针变量，以数组形式存在内存当中，占用多个指针的存储空间。

- 程序执行析构函数的时机有以下4 种。
  - 1) 如果在函数中定义了一个对象，当这个函数调用结束时，对象会被释放，且在对象释放前会自动执行析构函数。
  - 2) static 局部对象在函数调用结束时对象不释放，所以也不执行析构函数，只有在main 函数结束或调用exit 函数结束程序时，才调用static 局部对象的析构函数。
  - 3) 全局对象则是在程序流程离开其作用域（如main 函数结束或调用exit 函数） 时，才会执行该全局对象的析构函数。
  - 4) 用new 建立的对象，用delete 释放该对象时，会调用该对象的析构函数。
### <span id = "oop"> 二、OOP / OOD 【面向对象】 </span>

1. 转换函数：
  -
### <span id = "stl"> 三、STL && Generic Programming【STL与泛型编程】 </span>
1. C++标准库和STL标准模版库的区别：
  - 标准库80%是STL，标准库>STL,六大部件就是STL、C++标准库的头文件不带副档名，比如#include<vector>，新式头文件的组件都封装于namespace"std",旧式头文件（带副档名）都不封装。
  - 重要网页：cplusplus.com | cppreference.com | gcc.gnu.org
2. STL六大部件：容器、分配器、算法、迭代器、适配器、仿函式（containers/allocators/algorithms/iterators/adapters/functors）
3. 前闭后开区间：容器里的end()传回的指针是容器的后一个元素
- 容器的结构和分类：
  - 序列式容器（sequence）、关联式容器（associative 有key适合做查找）、不定序容器（unordered C++新增，本质上是一种关联式容器）
  - 序列式容器：按放进去的次序来排列
    - Array：前后都不能扩充
    - Vector：起点不能扩充，尾部可以自动增长（扩充）
    - Deque：两端可进可出（可扩充）
    - List：双向（环状）链表
    - Forward-list：单向链表
  - 关联式容器：适合大量查找、选用红黑树（高度平衡二叉树）实现最好
    - set/Multiset：set的key和value是不分的，所以放的元素不能重复
    - map/multimap: 每个结点有key和value，元素内容可以重复
  - Unordered Containers: Hash Table使用Separate Chaining实现最好
- OOP（面向对象编程）和GP（泛型编程）的差别
  - OOP企图将datas和methods关联在一起，而GP却把datas和methods分开。
  - 采用GP的优点：容器和算法可以分开，通过迭代器沟通就可以。Algorithms通过iterators确定操作范围，并通过iterator取用container元素
### <span id = "dp"> 四、 Design Patterns【设计模式】 </span>
### <span id = "linux"> 五、 Linux【Linux系统编程基础】 </span>
### <span id = "ppg"> 六、Process programming【进程编程】 </span>
### <span id = "tpg"> 七、Thread programming【线程编程】 </span>
### <span id = "npg"> 八、NetWord programming【网络编程】 </span>
