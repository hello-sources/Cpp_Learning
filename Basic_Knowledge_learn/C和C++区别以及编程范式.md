### C/C++区别

> 可以这样理解C++是C语言的超集，C++包含C语言所有内容，除此之外还有C语言所不具备的多余的58个头文件，异常处理，类和对象（面向对象编程），STL，模板（泛型编程），Lambda表达式（函数式编程）

<img src="https://github.com/hello-sources/Relative_Things/blob/master/img/Cpp_Learning_img/1.png?raw=true" alt="1" style="zoom:80%;" />



### 编程范式

> 编程范式分为四种，分别是：函数式编程，泛型编程，面向过程编程，面向对象编程

1. **函数式编程**

> 函数式编程把电脑运算视作函数的计算，属于“结构化编程”一种，主要思想是把运算过程尽量写成一系列嵌套的函数调用。例如lambda表达式，代码如下：

```c
var print = function(i){ console.log(i);};
```

2. **泛型编程**

> 泛型编程目的是为了实现一个通用的标准容器库。代表作STL，泛型编程可以使编写完全一般化并且可以重复使用的算法，其效率是根据某特定的数据类型而设计的算法想相同。泛型是指具有多种数据类型上都可操作的含义，与模板有些类似。STL中算法是泛型的，不与任何特定的数据结构或者对象类型联系在一起。简言之，泛型编程本质是屏蔽数据和操作数据的细节，让算法更为通用，让编程者更为关注算法的结构。

3. **面向过程编程**

> 面向过程是一种以过程为中心的编程思想，与面向对象不同的是封装、继承、类。其中C语言就是面向过程编程，就是先分析出解决问题所需要的步骤，然后用函数把这些步骤一步一步实现，使用的时候一次一次调用即可。

```c
public class 汽车运营 {
	void 汽车启动 {
		发生了什么···
	}
	void 汽车到站 {
		发生了什么···
	}
}
```

4. **面向对象编程**

> 面向对象编程本质上是建立模型体现出来的抽象思维过程和面向对象的方法，模型是用来反映现实世界中事物特征的。任何一个模型都不能反应客观事物的一切具体特征，只能根据事物特征和变化规律的一种抽象，且在它所涉及的范围内更加普遍、集中、深刻的描述客体的特征。通过建立模型而达到的抽象是人们对于客体认识的一种深化。 面向对象程序设计中的概念主要包括：对象、类、数据抽象、继承、动态绑定、数据封装、多态性、消息传递。通过这些概念面向对象的思想得到了具体的体现。 
>
> 1）对象（Object) ：
>
> 可以对其做事情的一些东西。一个对象有状态、行为和标识三种属性。
>
> 2）类（class)：
>
> 一个共享相同结构和行为的对象的集合。类（Class）定义了一件事物的抽象特点。通常来说，类定义了事物的属性和它可以做到的（它的行为）。举例来说，“狗”这个类会包含狗的一切基础特征，例如它的孕育、毛皮颜色和吠叫的能力。类可以为程序提供模版和结构。一个类的方法和属性被称为“成员”。
>
> 3）封装（encapsulation)：
>
> 第一层意思：将数据和操作捆绑在一起，创造出一个新的类型的过程。第二层意思：将接口与实现分离的过程。
>
> 4）继承：
>
> 类之间的关系，在这种关系中，一个类共享了一个或多个其他类定义的结构和行为。继承描述了类之间的“是一种”关系。子类可以对基类的行为进行扩展、覆盖、重定义。
>
> 5）组合：
>
> 既是类之间的关系也是对象之间的关系。在这种关系中一个对象或者类包含了其他的对象和类。
>
> 组合描述了“有”关系。
>
> 6）多态、
>
> 类型理论中的一个概念，一个名称可以表示很多不同类的对象，这些类和一个共同超类有关。因此，这个名称表示的任何对象可以以不同的方式响应一些共同的操作集合。
>
> 7）动态绑定：
>
> 也称动态类型，指的是一个对象或者表达式的类型直到运行时才确定。通常由编译器插入特殊代码来实现。与之对立的是静态类型。
>
> 8）静态绑定：
>
> 也称静态类型，指的是一个对象或者表达式的类型在编译时确定。
>
> 9）消息传递：
>
> 指的是一个对象调用了另一个对象的方法（或者称为成员函数）。
>
> 10）方法：
>
> 也称为成员函数，是指对象上的操作，作为类声明的一部分来定义。方法定义了可以对一个对象执行那些操作。
>
> 常见的面向对象编程语言有C++，Java等, java语言典型示例如下

```java
public class 汽车 {
	void 到站() {
	
    }
	void 启动() {
	
    }
}
```

