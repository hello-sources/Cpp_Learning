### sort与nth_element使用

- **sort**

> sort函数是C++中对于跟定区间的所有元素进行排序的函数，默认为升序排序，sort时间复杂度为O(nlog<sub>2</sub>n),因为sort函数底层使用的是快速排序算法。包含在algorithm头文件中

```c
#include <algorithm>
//sort函数用法
sort(start, end, cmp);
//start指的是排序数组的第一个位置、
//end指的是排序数组最后一个位置的下一位
//cmp为可选项，可不填，也可以自己定义排序方法
```

|      函数名       |              功能描述              |        底层实现        |
| :---------------: | :--------------------------------: | :--------------------: |
|       sort        |  对于给定区间元素进行描述(不稳定)  |        快速排序        |
|    stable_sort    |    对于给定区间元素进行稳定排序    |        归并排序        |
|   partial_sort    |    对于给定区间元素进行部分排序    |    交换元素存储位置    |
| partial_sort_copy |    对于给定区间元素复制并且排序    | 拷贝后交换元素存储位置 |
|     is_sorted     |       判断一个区间是否排好序       |         未知😂          |
|     partition     |   使得符合某个条件的元素放在前面   |        快速排序        |
| stable_partition  | 相对稳定的使得某个条件元素放在前面 |        快速排序        |
|    nth_element    |      找到给定区间对应元素的值      |      快速选择排序      |



- **nth_element**

> nth_element()方法主要是求给定区间第k小的元素，与普通的排序不同，它只是选取给定的第k个元素大小所在的固定的位置，底层实现是快速选择排序。值得注意的是nth_element得到的元素序列是乱序的，但是第k个元素位置是正确的

```c
//nth_element使用方法
nth_element(start, start + k, end);
//start表示数组开始的位置
//start + k表示数组升序情况下第k个位置应该对应的数据元素
//end表示数组结束的位置
```

>  [C++reference](http://www.cplusplus.com/reference/algorithm/nth_element/)有对应nth_element的讲解

```c
// nth_element example
#include <iostream>     // std::cout
#include <algorithm>    // std::nth_element, std::random_shuffle
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

int main () {
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

  std::random_shuffle (myvector.begin(), myvector.end());

  // using default comparison (operator <):
  std::nth_element (myvector.begin(), myvector.begin()+5, myvector.end());

  // using function as comp
  std::nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
```

> possible output

```c
myvector contains: 3 1 4 2 5 6 9 7 8
```

