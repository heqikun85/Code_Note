# 刷题笔记
## LeeCode刷题

1. [contains duplicate(查找重复数据)](#table1)
2. [Valid Anagram 有效异序](#table2)
3. [Two Sum 两数之和](#table3)
4. d
5. [Top K frequent elements 最常见元素](#table5)
6. [Product of Array Except Self 阵列乘积](#table6)

### <a id= "table1"> 1. contains duplicate(查找重复数据) </a>

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**解题思路：** 利用hashset，建立一个set，然后遍历array来确认是否有重复内容

**Python**

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

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
确认两个无需的数组是否包含相同的element。

**解题思路：** `sort()`方法，比较简单。先对比两个数组的长度是否相同，如果不同直接false。
再将两个数组排序，然后对比两个数组是否相同，返回bool值. **注意** Python的str没有sort功能，需要将str转为list

```python
str = list(s)
s.sort()
```

**HashMap** 
**C++**

1. 确认string长度相同（不同则false）
2. 建立一个vector，index为dict，用来查找对应的element
3. 利用Ascii表作为index，也就是用Ascii的数字来做为和vector第一列的对比。
4. 然后记录下每个element出现的次数
   
```c++
bool isAnagram(string s, string t){
    if(s.size() != t.size())
        return false;
    
    // 初始化26个为0的element的vector数组。
    vector<int> table(26,0);

    for(auto& i : s){
        // i是s传递进来的单项element，作为index，自动以Ascii数字处理
        // - ‘a’ 是用来把出现的数字结果统一，并且和index相匹配
        // 举例 i = a，Ascii a = 40，40-40 = 0. vector内index 0 = a
        // 这样可以找出每个字母出现的次数。
        table[i - 'a']++;
    }

    for(auto& i : t){
        table[i - 'a'];
        if(table[i - 'a'] < 0)
            return false;
    }

    return true;
}
```

**Python**

1. 确认element数量，不同则返回false
2. 建立两个dict计数器
3. 遍历两个数组，用char作为dict的key，记录每个char出现的次数
4. 对比两个计数器，不同则false
   
```python
def isAnagram(self, s : str, t : str) -> bool:
    if(len(s) != len(t)):
        return False
    # 建立dict计数器
    countS, countT = {},{}

    for i in range(len(s)):
        # countS[s[i]]是用s内的element作为key
        # countS.get(s[i],o), 
        countS[s[i]] = 1 + countS.get(s[i],0)
        countT[t[i]] = 1 + countT.get(t[i],0)

    for c in countS:
        if countS[c] != countT.get(c,0)
            return False
    
    return True


# Python 内置以上算法
    Counter(s) != Counter(t) #这个就是对比array内element是否相同的算法。
```


### <a id = 'table3'> 3. Two Sum 两数之和 </a>






### <a id="table5">5. Top K frequent elements 最常见元素 </a>

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
给到一个频率数字，找出出现频率最高的K个数字。

**解题思路：** 
1. 先用dict储存每个element的出现频率。
2. 创建一个和给定数组一样大小的2d数组（其index就和出现频率一样）
3. 将dict内的val -> freq 键值对传入2d数组
4. 从后遍历freq数组，因为index越大，出现频率越大。
5. 逐步加入freq内的内容去数组，一旦数组大小等于给定数字，就返回现有值。 

```python
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        count = {} # 初始化dict
        # 初始化freq List，该list为一个len大于传入List的2D array
        freq = [[]for i in range(len(nums) + 1)]
        
        # 统计每个element的频率，记录在dict内，频率为value，element为Key
        for i in nums:
            # i为nums内的单个element，count.get(获取值，默认值)方法获取count[i]的值
            # 如果为空，则返回默认值 0
            count[i] = 1 + count.get(i,0)
        
        # item()方法返回key，value的键值对，n取key，c取value。
        for n, c in count.items():
            # 因为freq的index和频率对应，所以可以以此来sort整个出现频率
            freq[c].append(n)
       
        res = []
        # 重后往前遍历数组，出现频率越高的index越大，一旦res中长度与K相等，则返回K
        for i in range(len(freq)-1, 0, -1):
            for n in freq[i]:
                res.append(n)
        return freq
        # return the k required num value
```

Python的range(start, stop, step)
start: 计数从 start 开始。默认是从 0 开始。例如range（5）等价于range（0， 5）;
stop: 计数到 stop 结束，但不包括 stop。例如：range（0， 5） 是[0, 1, 2, 3, 4]没有5
step：步长，默认为1。例如：range（0， 5） 等价于 range(0, 5, 1)



### <a id='table6'> 6. Product of Array Except Self 阵列乘积 </a>

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.


