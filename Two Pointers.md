# 刷题笔记
## LeeCode刷题

1. [Valid Palindrome(有效回文)](#table1)
2. [Valid Anagram 有效异序](#table2)
3. [Two Sum 两数之和](#table3)
4. [Group Anagrams 组合词根](#table4)
5. [Top K frequent elements 最常见元素](#table5)
6. [Product of Array Except Self 阵列乘积](#table6)

### <a id= "table1"> 1. Valid Palindrome(有效回文) </a>

**Palindrome(派林卓母)** 是指以中间位为准，前后一致的形式。可以是数字 121， 也可以是文字，aba
这题的难点在于移除非char字符。

Python有三个内奸函数，`isdigit()、isalpha()、isalnum()` 
isdigit()：**纯数字**，即使是带圈的数字，比如 **①，②** 之类的也可解析。
isalpha()：可解析**字符+汉字**，但不可解析 数字+汉字。
isalnum()：可解析**字母+汉字+数字**

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


