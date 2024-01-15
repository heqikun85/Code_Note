# 刷题笔记
## LeeCode刷题

1. [Valid Palindrome 有效回文](#table1)
2. [Two Sum II 两数之和 II](#table2)
3. [3Sum 三数之和](#table3)


### <a id= "table1"> 1. Valid Palindrome 有效回文 </a>

**Palindrome(派林卓母)** 是指以中间位为准，前后一致的形式。可以是数字`121`， 也可以是文字`aba`。    
这题的难点在于移除非char字符。

**Python**有三个内奸函数，`isdigit()、isalpha()、isalnum()`   
isdigit()：**纯数字**，即使是带圈的数字，比如 **①，②** 之类的也可解析。  
isalpha()：可解析**字符+汉字**，但不可解析 数字+汉字。  
isalnum()：可解析**字母+汉字+数字**  

这题在Python中可以用 `isalnum()` 这个函数来区分非字符和字符。**面试时可能对这类取巧函数不认可**  

第二个问题点：对比重新储存后的string。我们需要重新储存全字符的input string。有两种方法可以对比  
1. 可接受中间位为独立字符：直接调转整个str，来对比新的str和原str是否一致  
   不可接受中间位：检查str的单双，如为单数则返回false。如为双数，直接调转整个str，来对比新的str和原str是否一致。  
   Python的str 调转为 `newStr == newStr[::-1] #前两个参数为空，第三个参数为从队尾往队前移动

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


### <a id= "table2"> 2. Two Sum II 两数之和 II </a>

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

给到一个一个数组，将该数组内的数字没三个分成一个子组，每个子组的合为0.
不能包含重复的三元组，也就是每个数字只能用一次。**duplicate 重复**

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

这题的code解法非常复杂  
首先我们考虑input数组没有规律，但题目并没有要求给出数组的index，所以我们完全可以sort数组，  
那么数组就会以递增的方式存在。  
以上面example 1 的数组为例
sort之后的 nums = [-4,-1,-1,0,1,2]  
在数组被sort后，我们即可以使用TWO SUM II的方式。  
将第一个数字作为主数字，主位之后一位为left point，最后一位为right point。


```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = [] # set result array
        nums.sort() # sort input array

        # use index and value to set the target value and point value
        for i, a in enumerate(nums): 
            if a > 0: # 已sort的array，如果首位大于0，就不用继续下去了
                break 
            # 因为数组已sort，而且不允许重复的数组出现。所以设置这个条件，如果当前数字和前一个数字相同，就说明我们已找过类似答案，直接跳过这个循环。
            if i > 0 and a == nums[i-1]: 
                continue
            l, r = i + 1, len(nums) - 1 # set the left and right point
            #when left point smaller than right point, continue the loop
            while l < r:
                tSum = a + nums[l] + nums[r] #get the sum
                if tSum > 0: #if too big, move the right point to left
                    r -= 1
                elif tSum < 0: # if too small, move the left point to right
                    l += 1
                else:
                    res.append([a, nums[l], nums[r]]) # if sum equel to 0 then add the three num into result array
                    # 到这里，已经有一个结果了，但是我们不能确定是否有另一个结果。
                    # 比如example中【-1，0，1】和【-1，-1，2】两个-1的结果
                    # so we keep move left point，until left point equal to right point
                    # 并且如果left point于前一个数字相同，就跳过。
                    l += 1 
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res
```

**Java**

第一种解法和python逻辑一样。需要注意的是，for loop的终止时间，为length -2。  
为何要检查到倒数第二个，如果array长度大于3，其实用-3也可以实现。  
但是如果array大小只有3的话，-3会导致整个循环不运作。所以必须检查到-2的位置。
**在同样逻辑的情况下，java的memory使用要高于python。但runtime明显的加快**  

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
        

        for(int i = 0; i < nums.length-2; i++){
            if(nums[i] > 0){
                break;
            }

            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            
            int l = i + 1;
            int r = nums.length - 1;

            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0){
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    ArrayList<Integer> mol = new ArrayList<Integer>();
                    mol.add(nums[i]);
                    mol.add(nums[l]);
                    mol.add(nums[r]);
                    res.add(mol);
                    l++;
                    while(nums[l] == nums[l-1] && l < r){
                        l++;
                    } 
                }
            }
        }
        return res;
    }
}
```

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        //这里用LinkedList的原因在于，1.LinkedList添加和删除元素比java快 2.LinkedList占用小
        LinkedList<List<Integer>> sol = new LinkedList<List<Integer>>();

        for (int i = 0; i < nums.length - 2; i++) {
            //Only consider non-duplicate elements for i
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int target = 0 - nums[i];
                int left = i + 1;
                int right = nums.length - 1;

                while (left < right) {
                    if (nums[left] + nums[right] == target) {
                        ArrayList<Integer> miniSol = new ArrayList<>();
                        miniSol.add(nums[i]);
                        miniSol.add(nums[left]);
                        miniSol.add(nums[right]);
                        sol.add(miniSol);
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (nums[left] + nums[right] > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        return sol;
    }
}
```

整体逻辑和上一个是一样的，只是有部分写法细分不同


**C++**

C++的runtime和memory是相对平衡的，runtime比java的高一点，但不多，memory和python几乎接近。

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        if(n<3) return res;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < n-2; i++){
            if(nums[i] > 0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;

            int l = i + 1;
            int r = n - 1;

            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0) {
                    l++;
                }else if(sum > 0){
                    r--;
                }else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
```
