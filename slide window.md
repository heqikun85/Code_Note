# 刷题笔记
## LeeCode刷题

- [刷题笔记](#刷题笔记)
  - [LeeCode刷题](#leecode刷题)
    - [ 1. Best Time to Buy and Sell Stock 最佳购买日 ](#-1-best-time-to-buy-and-sell-stock-最佳购买日-)
    - [ 2. Longest Substring Without Repeating Characters 最长非重复字符串 ](#-2-longest-substring-without-repeating-characters-最长非重复字符串-)
    - [ 3. Longest Repeating Character Replacement 最长重复字符替换 ](#-3-longest-repeating-character-replacement-最长重复字符替换-)


### <a id= "table1"> 1. Best Time to Buy and Sell Stock 最佳购买日 </a>

这题严格来说算Two point的范畴，以两个point逐步移动的方式，但是他和逐步移动的point可以有一个区别。就是第一个point可以一直固定在最低的数字处，所以我们只需要移动一个指针，在找到适合值后将锚点定在该值，然后继续移动指针寻找最大差，如果没有更小的值，就不移动锚点，最后寻找最大差即可。

```JAVA
        int left = 0;
        int right = 1;
        int maxProfit = 0;

        while(right < prices.length){
            if (prices[left] < prices[right]){
                maxProfit = Math.max(maxProfit, prices[right]-prices[left]);
                right++;
            }else{
                left = right;
                right++;
            }
        }
        return maxProfit;
```


```Python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        lowest = prices[0]

        for price in prices:
            if price < lowest:
                lowest = price
            res = max(res, price - lowest)
            
        return res
```

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int res = 0;
         int lowest = prices[0];

         for(int i = 1; i <= prices.size()-1; i++){
             if(lowest > prices[i]){
                 lowest = prices[i];
             }
             // 这条可以用另外一个代替, 一个是二元判断式，一个是最大值比较
             // res = max(res, prices[i] - lowest);
             res = (res > prices[i]-lowest)? res : prices[i] - lowest;
         }
         return res;
    }
};
```

```C++
int maxProfit(vector<int>& prices) {
        int maxP = 0, l = 0, r = 0;
        while (r < prices.size()){
            if (prices[r] > prices[l])
                maxP = max(maxP, prices[r] - prices[l]);
            else
                l = r;
            ++r;
        }
        return maxP;
}
```
写法不同，逻辑和上面一样。



### <a id= "table2"> 2. Longest Substring Without Repeating Characters 最长非重复字符串 </a>

这题的思路也是由锚点和一个point来解决。
我们将无重复情况下的第一个point作为锚点。
初始状态下，锚点为0，然后设置一个set，set有无重复这个特性。
遍历整个字符串，当出现字符没有重复时，不断储存如set
但当字符在set内出现时，我们开始移除set内字符，锚点在原始字符串中移动，将整个锚点移动到出现重复后的位置，并以此为新的锚点。
最后，确认原先锚点的长度，和新锚点的长度即可。

```python
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        l = 0
        res = 0

        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            charSet.add(s[r])
            res = max(res, r - l + 1)
        return res
```

```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chatSet;
        int l = 0;
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            while(chatSet.find(s[i]) != chatSet.end()){
                chatSet.erase(s[l]);
                l++;
            }
            chatSet.insert(s[i]);
            res = max(res, i - l + 1);
        }
        return res;
    }
};
```

```c++
//这种写法可以避免inner loop，但实际测试下，runtime和memory其实消耗的差不多。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;
        
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (j < s.size()) {
            if (letters.find(s[j]) == letters.end()) {
                letters.insert(s[j]);
                result = max(result, j - i + 1);
                j++;
            } else {
                letters.erase(s[i]);
                i++;
            }
        }
        
        return result;
    }
};

```

Java的写法不是特别理解。但是不打紧，以后如果专注搞Java可以学。

```JAVA
class Solution {
    public int lengthOfLongestSubstring(String s) {
        List<Character> substringL = new ArrayList<>();
        int res = 0;

        for(int i = 0; i < s.length(); i++){
            if(substringL.contains(s.charAt(i))){
                int index = substringL.indexOf(s.charAt(i));
                substringL.remove(index);
                if(index > 0)
                    substringL.subList(0,index).clear();
            }
            substringL.add(s.charAt(i));
            res = Math.max(res, substringL.size());
        }
        return res;
    }
}
```

### <a id= "table3"> 3. Longest Repeating Character Replacement 最长重复字符替换 </a>

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 2:

Input: s = "AABABBA", k = 1  
Output: 4  
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".  
The substring "BBBB" has the longest repeating letters, which is 4.  
There may exists other ways to achieve this answer too.  

这题的难点在于找到最合适的字母去替换。但实际上，我们不需要真的替换字母。    
我们需要找出的是最长substring。所以我们只需要知道更改几次，能获得多长的substring即可。      
也就是说，我们不需要更改原始string。

```Python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        maxf = 0
        l = 0

        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0) # 获取单字符的长度
            maxf = max(maxf, count[s[r]]) # 获取单字符长度中最长的

            if (r - l + 1) - maxf > k: #当right point移动到的位置 减去 最长substring后超过了可更改数量时移动left point
                count[s[l]] -= 1
                l += 1

        return r - l + 1
```

上面的代码，左point基本不移动，只有在更改上线超过时才会移动，移动一格后，相应的在dict内减少一位left point的长度。
逻辑我是对了，但代码需要一定熟悉程度。


```JAVA
class Solution {
    public int characterReplacement(String s, int k) {
        int[] arr = new int[26];

        int ans = 0;
        int max = 0;
        int i = 0;
        for(int j = 0; j < s.length(); j++){
            // 这条是将字符的ACSii代码转换成数字，减去"A"的数字就是0-25的index
            // 这条成立的条件是所有字符都是大写字母，如果大小写都有，需要考虑小写字母的index
            arr[s.charAt(j) - 'A']++;
            max = Math.max(max, arr[s.charAt(j)-'A']);
            if(j - i + 1 - max > k){
                arr[s.charAt(i) - 'A']--;
                i++;
            }
            ans = Math.max(ans, j - i + 1);

        }
        return ans;
    }
}
```
`charAt()` 方法用于返回指定索引处的字符。索引范围为从 0 到 length() - 1


```C++
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxC = 0;

        int i = 0;
        int j = 0;

        int res = 0;

        while(j < s.size()){
            count[s[j] - 'A']++;
            maxC = max(maxC, count[s[j] - 'A']);

            if(j - i + 1 - maxC > k){
                count[s[i] - 'A']--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
```