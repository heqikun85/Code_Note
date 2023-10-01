# 刷题笔记
## LeeCode刷题

1. [contains duplicate(查找重复数据)](#table1)
2. [Valid Anagram 有效异序](#table2)
3. 

### <a id= "table1"> 1. contains duplicate(查找重复数据) </a>

利用hashset，建立一个set，然后遍历array来确认是否有重复内容

python
``` python
def containsDuplicate(self, nums:List[int]) -> bool:
    hashset = set() //set() 在python中有去重特性，所以不会储存重复数据，减少内容太多而产生的不必要储存
    // 遍历传入数组
    for n in nums: 
        // 判断数组内element是否有重复
        if n in hashset:
            return True
        hashset.add(n) // 将非重复element加入判断set
    return False
```

**C++排序法**
```C++
bool containsDuplicate(vector<int>& nums){
    sort(nums.begin(),nums.end()); //对数组进行排序
    // 遍历数组，注意，**传入的数组size要-1**，因为index是从0开始计数，
    // 而size()是从1开始计算。**正常情况下我们不需要-1**，
    // 但这个算法，我们每次遍历都会和数组中下一个内容做比较，所以不需要读取数组最后一个数据。
    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] == nums[i+1])
            return true;
        nums.insert(nums[i]);
    }
    return false;
}
```

**C++查重法**
```C++
bool containsDuplicate(vector<int>& nums){
    //unordered_set 是不排序set在C++中的定义名
    unordered_set<int> s; 
    // 遍历数组
    for(int n in nums){
        //find() 函数返回指向该元素的迭代器，否则返回指向范围结尾的迭代器。
        //s.end()返回数组内最后一个元素，
        //如果find找到元素，则不等于s.end()
        if(s.find(n) != s.end())
            return true;
        s.insert(n);
    }
    return false;
}
```

**Java**
```java
    public boolean containsDuplicate(int[] nums) {
        // 创建hashset
        Set<Integer>hashset = new HashSet<>();
        for(int i : nums){
            // 通过 contains()方法来判断是否存在element
            if(hashset.contains(i)){
                return true;
            }
            hashset.add(i);
        }
        return false;
    }
```
java的HashSet 基于 HashMap 来实现的，是一个不允许有重复元素的集合。 

HashSet 允许有 null 值。

HashSet 是无序的，即不会记录插入的顺序。

HashSet 类位于 java.util 包中，使用前需要引入它，语法格式如下：

**实例**
```java
import java.util.HashSet;  // 引入 HashSet 类

public class RunoobTest {
    public static void main(String[] args) {
    HashSet<String> sites = new HashSet<String>();
        sites.add("Google");
        sites.add("Runoob");
        sites.add("Taobao");
        sites.add("Zhihu");
        sites.add("Runoob");  // 重复的元素不会被添加
        System.out.println(sites);
    }
}
```
执行以上代码，输出结果如下：

[Google, Runoob, Zhihu, Taobao]

**删除元素**

我们可以使用 remove() 方法来删除集合中的元素:
```java
sites.remove("Taobao");  // 删除元素，删除成功返回 true，否则为 false
sites.clear() // 删除所有元素
sites.size() // set大小，注意Set没有重复元素
```

### <a id="table2"> 2. Valid Anagram 有效异序 </a>

确认两个无需的数组是否包含相同的element。

**Sort 方法**比较简单。先对比两个数组的长度是否相同，如果不同直接false。
再将两个数组排序，然后对比两个数组是否相同，返回bool值
**注意** Python的str没有sort功能，需要将str转为list

```python
str = list(s)
s.sort()
```

**HashMap** 现在也有sort，所以也可以用这个方法。

