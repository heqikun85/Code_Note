# 刷题笔记
## LeeCode刷题

1. [Valid Palindrome 有效回文](#table1)
2. [Two Sum II 两数之和 II](#table2)
3. [3Sum 三数之和](#table3)


### <a id= "table1"> 1. Valid Palindrome 有效回文 </a>

**Palindrome(派林卓母)** 是指以中间位为准，前后一致的形式。可以是数字 121， 也可以是文字，aba
这题的难点在于移除非char字符。

**Python**有三个内奸函数，`isdigit()、isalpha()、isalnum()` 
isdigit()：**纯数字**，即使是带圈的数字，比如 **①，②** 之类的也可解析。/n
isalpha()：可解析**字符+汉字**，但不可解析 数字+汉字。/n
isalnum()：可解析**字母+汉字+数字**/n

这题在Python中可以用 `isalnum()` 这个函数来区分非字符和字符。**面试时可能对这类取巧函数不认可**

第二个问题点：对比重新储存后的string。我们需要重新储存全字符的input string。有两种方法可以对比
1. 可接受中间位为独立字符：直接调转整个str，来对比新的str和原str是否一致
   不可接受中间位：检查str的单双，如为单数则返回false。如为双数，直接调转整个str，来对比新的str和原str是否一致。
   Python的str 调转为 `newStr == newStr[::-1] #前两个参数为空，第三个参数为从队尾往队前移动`

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_str = ''

        for ch in s:
            if ch.isalnum():
               new_str += ch.lower()
        return new_str == new_str[::-1]
```


2. 直接通过指针的方式逐帧移动，来对比input str的每个字符是否一致。
   ![image](https://github.com/heqikun85/Code_Note/raw/main/20231231154431.png)

   这种方法需要用到ASCii码来验证每个字符是否是非字母串。**数字串第一个是0，从编号48开始，到57. 字母串upper从A到Z，65-90，lower从a到z，97-122**

   python如果要用同project内的inside function，需要用前缀self

```python

class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1

        while l < r:
            while l < r and not self.alphaNum(s[l]):
                l += 1
            while r > l and not self.alphaNum(s[r]):
                r -= 1
            
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True 
    
    def alphaNum(self, c):
        return (ord("A") <= ord(c) <= ord("Z") 
                or ord('a') <= ord(c) <= ord('z') 
                or ord('0') <= ord(c) <= ord('9'))
```
以上解法比第一种时间上要快一点，但内存使用会多一点。

**Java**

Java 的思路和Python的第二种思路一样，使用两个pointer的方式。
这其中需要用到`Character`这个特殊类。用以确定字符是否是大小写字母或者转换字符类型。
因为不需要用到内嵌loop，而是用两个if statement替代了内嵌的loop，所以run time很短，
但memory比python高很多。

```java
class Solution {
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j){
            Character start = s.charAt(i);
            Character end = s.charAt(j);
            if(!Character.isLetterOrDigit(start)){
                i++;
                continue;
            }
            if(!Character.isLetterOrDigit(end)){
                j--;
                continue;
            }

            if(Character.toLowerCase(start) != Character.toLowerCase(end)){
                return false;
            }
            i++;
            j--;
        } 
        return true;
    }
}
```

**C++**

isalnum()：用来判断一个字符是否为数字或者字母，也就是说判断一个字符是否属于a-z || A-Z || 0-9。

isalpha()：用来判断一个字符是否为字母，如果是字符则返回非零，否则返回零。

islower()：用来判断一个字符是否为小写字母，也就是是否属于a~z。

isupper()：和islower相反，用来判断一个字符是否为大写字母。

tolower()：转换字符为小写字符

toupper()：转换字符为大写字符

C++仍然使用了while loop，内存使用小了很多，是最小的一个。run time也比python的小。

```c++
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            while(!isalnum(s[i]) && i < j){
                i++;
            }
            while(!isalnum(s[j]) && i < j){
                j--;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
```


### <a id= "table3"> 2. Two Sum II 两数之和 II </a>

和之前题目一样，但不可以用hashmap的方式。
之前的方法是用map的方式，把index 和 number储存为 key -> value的形式，然后用map的搜索功能在队列中寻找匹配的数字。
用pointer的方法我们分别将前后两个pointer相加，因为是非递减数组，所以通过结果的大小来判断移动哪个pointer。

**C++**

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        vector<int> result;

        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum < target){
                i++;
            }else if(sum > target){
                j--;
            }else{
                result.push_back(i+1);
                result.push_back(j+1);
                break;
            }

        }
        return result;
    }
};
```

**Java**

Java的方式，使用while loop，但在while loop的情况下，runtime明显缩短，memory大幅增加。

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int i = 0;
        int j = numbers.length -1;
        int num_a, num_b;
        while(i < j){
            num_a = numbers[i];
            num_b = numbers[j];
            int sum = num_a + num_b;
            if(sum < target){
                i++;
                continue;
            }else if(sum == target){
                break;
            }
            j--;
        }
        return new int[] {i+1, j+1};
    }
}
```

**Python**

Python的逻辑一样，没有取巧法，但runtime非常高。

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            if numbers[l] + numbers[r] < target:
                l += 1
            elif numbers[l] + numbers[r] > target:
                r -= 1
            else:
                return [l+1, r+1]
```


### <a id= "table3"> 3. 3Sum 三数之和 </a>

给到一个一个数组，将该数组内的数字没三个分成一个子组，没个子组的合为0.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

