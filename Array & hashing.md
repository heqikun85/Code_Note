# 刷题笔记
## LeeCode刷题

1. [contains duplicate(查找重复数据)](#table1)
2. [Valid Anagram 有效异序](#table2)
3. [Two Sum 两数之和](#table3)
4. [Group Anagrams 组合词根](#table4)
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

给定一个数字array，给定一个目标结果，然后找出array中求和结果等于目标结果的两个数字的index。

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

**解题思路**

逻辑上，这个代码只能通过遍历的方式，也就是将每个element与其他element相加。普通情况下会用到两个loop双循环。但双循环就会出现O(n^2)的高运算消耗。
但我们可以通过创建一个dict，通过将element作为Key，来寻找index。

**Python**
```python
    def twoSum(self, nums: list[int], target : int) -> list[int]:
        maps ={} #初始化一个dict val -> index
        # 通过enumerate()方法把element和迭代器储存为 val -> index 的dict pair
        for i , n in enumerate(nums):
            diff = target - n # 将目标结果和element相间，获得符合target的另一个数
            if diff in maps:
                return [maps[diff], i]
            maps[n] = i
```

**python学习笔记：enumerate()方法**
```python
# enumerate返回一个迭代器，其中包含原始可迭代对象中的index和element pair
enumerate(iterable, start=0) 

# 实例
l1 = ["eat", "sleep", "repeat"]
s1 = "geek"
 
# Creating enumerate objects
obj1 = enumerate(l1)
obj2 = enumerate(s1)
 
print ("Return type:", type(obj1)) # 返回类型：<class 'enumerate'> 
print (list(enumerate(l1))) # [(0, 'eat'), (1, 'sleep'), (2, 'repeat')]
 
# changing start index to 2 from 0
print (list(enumerate(s1, 2))) # [(2, 'g'), (3, 'e'), (4, 'e'), (5, 'k')]
```

**Java**

```java
    public int[] twoSum(int[] nums, int target) {
        // 初始化hashmap
        HashMap <Integer, Integer> maps = new HashMap<>();
        
        // 遍历传入数组
        for(int i = 0; i < nums.length; i++){
            int num = nums[i]; // 这行其实可以不用，主要防止可能对传入数组的错误操作
            int diff = target - num;
            // 确认key值是否相匹配, containsKey()方法
            if(maps.containsKey(diff)){
                return new int [] { maps.get(diff), i };
            }
            maps.put(num, i);
        }
        return new int [] {};
    }
```

**C++**

```c++
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // 初始化hashmap
            unordered_map<int, int> mp; // val -> index
            
            //遍历数组
            for (int i = 0; i < nums.size(); i++) {
                //
                int diff = target - nums[i];
                if (mp.find(diff) != mp.end()) {
                    return {mp[diff], i};
                }
                mp.insert({nums[i], i});
            }
            return {};
        }
```

### <a id= 'table4'> 4. Group Anagrams 组合词根 </a>

给到一个string array，把相同element的string储存在一起。

**解体思路**

创建2D的List，并且创建一个hashmap来储存并对比每个string包含的字符。将val作为key

**C++**

```c++
public: 
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        // 创建一个hashmap，储存string的array，每个array是相同字符串的element，所以是2维数组
        unordered_map<string, vector<string>> m;
        // 遍历str array
        for(int i = 0; i < strs.size(); i++){
            // 获取单个string中各个字符出现的次数
            string key = getKey(strs[i]);
            // 以字符出现次数为key，将string储存进map
            m[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto it = m.begin(); it != m.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }

private:
    // 这个是getKey()函数，类似于第二题对比两个string是否罕有相同字符。
    string getKey(string str){
        // 初始化一个包含26个字母的array，以index为顺序，0 = a 以此类推
        vector<int> count(26);

        // 遍历传入的string，将string中单个char所对应的index的count ++ 
        for(int i = 0; i < str.size(); i++){
            count[str[i] - 'a']++;
        }

        string key ="";
        // 将整个count中的计数器以string的形式copy并传出
        for(int j = 0; j < count.size(); j++){
            // 不加‘#’会错,因为如果只用数字表示会出现一个情况
            // 10个d和10个b也会出现10的数字，不用＃隔开会导致特殊情况（不同字符但数字排列相同的情况）
            key.append(to_string(count[j]) + '#');  
        }
        return key;
    }

```

**Java**

```java
    public List<List<String>> groupAnagrams(String[] strs) {
        //创建一个2D数组的List，使用ArrayList模式，动态数组。
        List<List<String>> res = new ArrayList<>(); 
        if(strs.length == 0) return res; // 如果传入的是一个空数组，则直接返回空Array
        //创建一个包含数组的hashmap，key为包含的字符，value为与key的字符相同的单词。
        HashMap<String, List<String>> map = new HashMap<>();
        for(String s : strs){
            //建立一个26个字母的hash表
            char[] hash = new char[26];
            //遍历单个单词中的字母，
            for(char c : s.toCharArray()){
                hash[c-'a']++; //以26个字母的顺序作为index，利用ASCii的特性在index内进行计算
            }
            // 将储存了26个字母分别使用了几个的hash储存为新的string，
            //举例：eat会储存为10001000000000000000100000，
            //代表第一个字母，第五个字母，第21个字母使用了1次。
            String key = new String(hash); 
            
            //通过key确认是否存在在map中，如果不在map中，则新建这个key的动态数组项
            map.computeIfAbsent(key, k -> new ArrayList<>());
            //在已有该key的情况下，在该key下加入s。
            map.get(key).add(s);
        }
        //将map这个2d数组里的value全部储存到res内，其实可以只返回map的value，不用多建立一个res
        res.addAll(map.values());
        return res;
    }
```

**Python**

```python
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)

        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            ans[tuple(count)].append(s)
        return ans.values()
```

ord() 函数是 chr() 函数（对于8位的ASCII字符串）或 unichr() 函数（对于Unicode对象）的配对函数，它以一个字符（长度为1的字符串）作为参数，返回对应的 ASCII 数值，或者 Unicode 数值，如果所给的 Unicode 字符超出了你的 Python 定义范围，则会引发一个 TypeError 的异常。

**python学习笔记：collections.defaultdict()的用法**

在我们创建一个字典时，必须同时填入“键值对”。如果没有值填入，就会发生keyerror的错误。

```python 
res = dict()
res['key']
print(res)
>>KeyError: 'key'

res = dict()
res['key'] = 3
print(res)
>>{'key': 3}
```
用collections.defaultdict(“值的类型”)，一种特殊类型的字典本身就保存了默认值defaultdict()。
```python
from collections import defaultdict

res = defaultdict(list)
res['key']
print(res)
>>defaultdict(<class 'list'>, {'key': []})
```


### <a id="table5">5. Top K frequent elements 最常见元素 </a>

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
给到一个频率数字，找出出现频率最高的K个数字。

**解题思路：** 
1. 先用dict储存每个element的出现频率。
2. 创建一个和给定数组一样大小的2d数组（其index就和出现频率一样）
3. 将dict内的val -> freq 键值对传入2d数组
4. 从后遍历freq数组，因为index越大，出现频率越大。
5. 逐步加入freq内的内容去数组，一旦数组大小等于给定数字，就返回现有值。 

**Python**

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


