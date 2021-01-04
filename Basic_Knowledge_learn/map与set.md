### map、unordered_map与set

- **map**

> map是有序键值对容器，提供一对一的hash,第一个称为关键字，第二个称为关键字的值，关键字的值是唯一的。map可以存储任意类型的数据，map底层实现是红黑树，这棵树具有排序的功能，按照迭代器输出

```c++
//map示例
#include <map> //头文件
#include <unordered_map>
map<key, value> arr;
for (auto iter = arr.begin(); iter != arr.end(); iter++) {
    cout << *iter << endl; //使用迭代器输出按照顺序的键值，可以理解iter为指针
}
```

**修改器**

|      函数名      |                    功能                     |
| :--------------: | :-----------------------------------------: |
|      clear       |                  清楚内容                   |
|      insert      |               插入元素或节点                |
| insert_or_assign | 插入元素，若键值已经存在，则赋值给当前元素  |
|     emplace      |                原位构造元素                 |
|   emplace_hint   |            使用提示原位构造元素             |
|   try_emplace    | 若键值 不存在则原位插入，存在则不做任何事情 |
|      erase       |                  删除元素                   |
|       swap       |                  交换内容                   |
|     extract      |             从零一容器释放节点              |
|      merge       |             从另一容器结合节点              |

**查找**

|   函数名    |                  功能                  |
| :---------: | :------------------------------------: |
|    count    |        返回匹配特定键的元素数量        |
|    find     |         寻找带有特定键值的元素         |
|  contains   |    检查容器是否含有带特定键值的元素    |
| equal_range |          返回匹配特定键的元素          |
| lower_bound | 返回指向首个不小于给定键值元素的迭代器 |
| upper_bound |  返回指向首个大于给定键值元素的迭代器  |

**map常用代码举例**

```c++
//map构造函数
map<int, string> m; 

//map插入元素
m.insert(pair<int, string>(000, "student_zero"));//插入pair
m.insert(map<int, string>::value_type(001, "student_one"));//插入value_type数据
m[1] = "hello";//直接赋值

//map查找对象
iter = m.find("hello");

//map的清空与删除
iter = m.find("hello");
m.erase(iter);//迭代器删除
m.erase("hello");//按照键值删除
m.erase(m.begin(), m.end());//把整个map清空
```



- **unordered_map**

> unordered_map与map类似，只是map里面的键值是按照顺序排列的，但是unordered_map元素在内部不以任何特定的顺序排列，而是组织进桶中。元素放进哪个桶完全依赖于其键的哈希。这允许对单独元素的快速访问，因为一旦计算哈希，则它准确指代元素所放进的桶。 其余用法与map大同小异。

​	

- **set**

> set 是关联容器，含有key类型对象的已经**排好序的集合**。set中每一个元素的值也是唯一的，关键字不重复，但是set中元素的值不能直接被改变。 set中每个元素只包含一个关键字：set支持高效的关键字查询操作----检查一个给定关键字是否在set中。 set底层实现也是一种非常高效的平衡二叉排序树：红黑树。同时也有关键字可以重复出现的multiset。
>
> 同时与map类似，也有unordered_set与unordered_multiset

**set的修改器与查找与map几乎完全相同，下面只介绍相关set用法**

```c++
//set示例
#include <set> //头文件
#include <unordered_set> 

set<int> s;//set构造函数

s.insert(1);//插入1
s.clear();//清除集合
s.erase(iterator); //删除定位器iterator指向的值
s.erase(first,second); //删除定位器first和second之间的值
s.erase(key_value); //删除键值key_value的值

s.insert(first,second);//将定位器first到second之间的元素插入到set中，返回值是void.
```

