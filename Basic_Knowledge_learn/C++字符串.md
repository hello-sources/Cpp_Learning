### C++字符串

- **成员函数**

| （构造函数）  | 构造basic_string |
| :-----------: | :--------------: |
|  (析构函数)   |   销毁字符串，   |
|   operator=   |   为字符串赋值   |
|    assign     | 赋值字符给字符串 |
| get_allocator | 返回关联的分配器 |



- **元素访问**

|              函数名               |                  函数功能                   |
| :-------------------------------: | :-----------------------------------------: |
|                at                 |          访问指定字符 ，有边界检查          |
|            operator[]             |                访问指定字符                 |
|           front(C++11)            |                 访问首字符                  |
|            back(C++11)            |               访问最后的字符                |
|               data                |         返回指向字符串首字符的指针          |
|               c_str               |      返回字符串不可修改的C字符数组版本      |
| operator basic_string_view(C++17) | 返回整个字符串的不可修改的basic_string_view |



- **操作**

|       函数名       |              函数功能              |
| :----------------: | :--------------------------------: |
|       clear        |              清空内容              |
|       insert       |              插入字符              |
|       erase        |              一处字符              |
|     push_back      |           后附字符到末尾           |
| pop_back（C++11）  |            移除末尾字符            |
|       append       |           后附字符到结尾           |
|     operator+=     |           后附字符到结尾           |
|      compare       |           比较第二个字符           |
| starts_with(C++20) |     检查string是否始于给定前缀     |
|  ends_with(C++20)  |     检查string是否终于给定后缀     |
|  contains(C++23)   | 检查字符串是否含有给定的字串或字符 |
|      replace       |        替换字符串的指定部分        |
|       substr       |              返回子串              |
|        copy        |              复制字符              |
|       resize       |          更改存储的字符数          |
|        swap        |              交换内容              |



- **查找**

|      函数名       |           函数功能           |
| :---------------: | :--------------------------: |
|       find        |  从左至右与字符串中寻找字符  |
|       rfind       | 从右至左寻找子串最后一次出现 |
|   find_first_of   |      寻找字符的首次出现      |
| find_first_not_of |      寻找字符的首次缺失      |
|   find_last_of    |    寻找字符的最后一次出现    |
| find_last_not_of  |    寻找字符的最后一次缺失    |



- **数值转换**

|   函数名   |         函数功能          |
| :--------: | :-----------------------: |
|    stoi    |  转换字符串为有符号整数   |
|    stol    |  转换字符串为有符号整数   |
|   stoll    |  转换字符串为有符号整数   |
|   stoul    |  转换字符串为无符号整数   |
|   stoull   |  转换字符串为无符号整数   |
|    stof    |    转换字符串为浮点数     |
|    stod    |    转换字符串为浮点数     |
|   stold    |    转换字符串为浮点数     |
| to_string  | 转换整数或浮点数为string  |
| to_wstring | 转换整数或浮点数为wstring |



> 以下列举部分函数使用及其意义

**比较compare**

```
compare(s2) 其他同类型字符串 
compare(p) C 风格字符串 
compare(off, cnt, s2) [off, off + cnt) 同 s2 执行比较 
compare(off, cnt, s2, off2, cnt2) [off, off + cnt) 同 s2 [off2, cnt2) 执行比较 
compare(off, cnt, p) [off, off + cnt) 同 [p , <null>) 执行比较 
compare(off, cnt, p, cnt2) [off, off + cnt) 同 [p, p + cnt2) 执行比较  
```

**附加**

```
使用 operator += 接受其他字符串，C 风格字符串和字符 
使用 push_back() 在尾部附加字符，并使得通过字符串构造的 back_iterator 可以访问 
append() 附加 
        1、append(s) 追加字符串 
        2、append(s, off, cnt) 追加字符串 s [off, off + cnt) 
        3、append(p) 追加字符串 [p, <null>) 
        4、append(p, cnt) 追加字符串 [p, p + cnt) 
        5、append(n, c) 填充 n * c 
        6、append(InF, InL) 追加输入流 [InF, InL) 

insert() 插入 
        1、insert(off, s2) 插入字符串 
        2、insert(off, s2, off2, cnt2) 插入字符串 s [off2, off2 + cnt2) 
        3、insert(off, p) 插入字符串 [p, <null>) 
        4、insert(off, p, cnt) 插入字符串 [p, p + cnt)

        5、insert(off, n, c) 插入 n * c 
        6、insert(iter) 元素默认值填充 
        7、insert(iter, c) 插入特定元素 
        8、insert(iter, n, c) 插入 n*c 
        9、insert(iter, InF, InL) 插入 [InF, InL) 

operator +(a, b) 
字符串关联运算符重载中支持 operator + 的形式 
        1、s + s 
        2、s + p 
        3、s + c 
        4、p + s 
        5、c + s 
```

**查找、替换和清除**

```
find() 查找 
        1、find(c, off) 在 s [off, npos) 中查找 c 
        2、find(p, off, n) 在 s [off, npos) 中查找 [p, p + n) 
        3、find(p, off) 在 s [off, npos) 中查找 [p, <null>) 
        4、find(s2, off) 在 s [off, npos) 中查找 s2 

find() 的变种 
        1、rfind() 具有 find() 的输入形式，反序查找 
        2、find_first_of() 具有 find() 的输入形式，返回第一个匹配的索引 
        3、find_last_of() 具有 find() 的输入形式，返回倒数第一个匹配的索引 
        4、find_first_not_of() 具有 find() 的输入形式，返回第一个不匹配的索引 
        5、find_last_not_of() 具有 find() 的输入形式，返回倒数第一个不匹配的索引 

replace() 替换 
        1、replace(off, cnt, s2) 将 s [off, off + cnt) 替换成 s2 
        2、replace(off, cnt, s2, off2, cnt2) 将 s [off, off + cnt) 替换成 s2 [off2, off2 + cnt2)
        3、replace(off, cnt, p) 将 s [off, off + cnt) 替换成 [p, <null>) 
        4、replace(off, cnt, p, cnt2) 将 s [off, off + cnt) 替换成 [p, p + cnt2)

        5、replace(off, cnt, n, c) 将 s [off, off + cnt) 替换成 c * n 

使用迭代器的情况： 
        6、replace(InF, InL, s2) 将 [InF, InL) 替换成 s2 
        7、replace(InF, InL, p) 将 [InF, InL) 替换成 [p, <null>) 
        8、replace(InF, InL, p, cnt) 将 [InF, InL) 替换成 [p, p + cnt) 
        9、replace(InF, InL, n, c) 将 [InF, InL) 替换成 n * c 
        10、replace(InF, InL, InF2, InL2) 将 [InF, InL) 替换成 [InF2, InL2) 

erase() 删除 
        1、erase(off, cnt) 从字符串 s 中删除 s [off, off + cnt) 
        2、erase(iter) 从字符串 s 中删除 *iter 
        3、erase(ItF, ItL) 从字符串 s 中删除 [ItF, ItL) 
```