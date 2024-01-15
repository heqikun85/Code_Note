# LeeCode刷题
1. [Binary Search 二分查找](#table1)
2. [Search a 2D Matrix 搜索二维矩阵](#table2)
3. [Koko Eating Bananas 科科吃香蕉](#table3)
4. [Find Minimum In Rotated Sorted Array 查找旋转排序数组中的最小值](#table4)
   

**Binary Search**
是指拆半查找，将数据分成两半，同时查找。计算公式： a < log n < b  
可以这么理解，在顺序的array内，如果我们发现目标肯定不在数据的左半边，我们立刻舍弃寻找左半边  
这样能节省许多时间。  
binary search的核心点在于如何寻找折中点。

### <a id= "table1"> 1. Binary Search 二分查找 </a>

这题是标准的二分查找法的基础应用。逻辑和我一开始相的一样。  
从数组中段查找，如果中段大于目标，舍弃后半段，如果中段小于目标，舍弃前半段。  

**二分法的中间值**
这个中间值为了防止溢出，使用的是数组位置相加后的中位数加上起始点的方法。  
假设数组有10个数字，index区间[0 - 9], 中间位为 9/2 = 4 (int整型 舍去小数点)，  
然后 0 + 4， 则中间位index为 4.  事实上，双数情况下，因为没有中间数，这个中间位是靠左的。  
如果数组有11个数字，index区间[0 - 10], 中间位为 10/2 = 5, 这个是标准中间位。

当双位数数组往右第二次折中，左位已经变为中间位 +1，则为 5， 尾位不变，（9-5）/ 2 = 2
index为，5 + 2 = 7, 为正式中间位。


```Python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while r >= l:
            m = l + (r - l) // 2
            if nums[m] > target:
                r = m - 1
            elif nums[m] < target:
                l = m + 1
            else:
                return m
        return -1
```

```java
class Solution {
    public int search(int[] nums, int target) {
        int i = 0;
        int j = nums.length - 1;

        while(i <= j){
            int mid = i + (j - i)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return -1;
    }
}
```

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while(i <= j){
            int m = i + (j - i) / 2;
            if(nums[m] == target) return m;
            else if(nums[m] < target) i = m + 1;
            else j = m - 1;
        }
        return -1;
    }
};
```



### <a id= "table2"> 2. Search a 2D Matrix 搜索二维矩阵 </a>

这题就是2D数组的二元法应用，逻辑基本和第一题一摸一样。区别是先要确定row，再确定row中的数字。
这里比较关键的反而是**2D数组的应用方式**
1. 是如何判断2D数组的位置。
2. 是如何在没有inner loop的情况下使用2D数组

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix), len(matrix[0])
        top, bot = 0 , row - 1
        while top <= bot:
            row = top + (bot - top) // 2
            if target > matrix[row][-1]:
               top = row + 1
            elif target < matrix[row][0]:
               bot = row - 1
            else:
                row = top + (bot - top) // 2
                break
        
        if not top <= bot:
            return False
        
        l, r = 0, col - 1
        while l <= r:
            m = l + (r - l) // 2
            if target > matrix[row][m]:
                l = m + 1
            elif target < matrix[row][m]:
                r = m - 1
            else:
                return True

        return False
```

Java的第一种方法比较简单，这种方法python也能实现。
逻辑是，每次检查每一行的最后一个数字。如果最后一个数字大于target，则换行
如果最后一个数字小于target，则往内缩进一个。

`int mid = left+ ((right-left) >> 1);` 这条是java中二分法防止溢出的代码

```Java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int i = 0, j = matrix[0].length - 1;
        while(i < matrix.length && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
}
```

这个第二个解法是一种非常好的方式，使用binary search的时候要多用。

```Java
    public boolean searchMatrix2(int[][] matrix, int target) {
        if(matrix.length == 0) return false;

        int rows = matrix.length;
        int columns = matrix[0].length;

        int low = 0;
        // 这行是关键，行数*列数，等于数组内总共有多少个数字。将2D数组摊开成一维数组。
        int high = rows * columns;

        // low 和 high 分别代表的是一维数组中的left point和right point。
        while(low < high) {
            // mid = 整个数组的最中间数
            int mid = (low+high)/2;

            // mid/columns，中间数在的行数 =  中间数的index除以每行有多少elements
            // mid%columns，中间数的位置 = 中间数的index除以每行elements的余数。
            if(matrix[mid/columns][mid%columns] == target) {
                return true;
            } else if (matrix[mid/columns][mid%columns] < target) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return false;
    }
```

Java 使用python的逻辑解法时有一个错误，不知道为何，没找出来。
可能的问题主要在while loop内没给row重新赋值，可能导致row的值出现错误。这个问题是在C++发现的。

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix[0].size() - 1; 
        int top = 0, bot = matrix.size() - 1;

        while(top < bot){
            int row = top + (bot - top) / 2;
            if(matrix[row][0] == target) return true;
            if(matrix[row][0] < target && matrix[row+1][0] > target){
                top = row;
                break;
            }
            if(matrix[row][0] < target){
                top = row + 1;
            }else{
                bot = row - 1;
            }
        }

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[top][mid] == target) return true;
            if(matrix[top][mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
};
```


### <a id= "table3"> 3. Koko Eating Bananas 科科吃香蕉 </a>
小可喜欢吃香蕉。有 n 堆香蕉，第 i 堆有 [i] 堆香蕉。守卫已经走了，h 小时后会回来。

珂珂可以决定自己每小时吃香蕉的速度为 k。每小时，珂珂选择某一堆香蕉，然后从这堆香蕉中吃掉 k 根香蕉。如果这堆香蕉少于 k 根，它就会吃掉所有香蕉，并且在这一小时内不再吃任何香蕉。

珂珂喜欢慢慢吃，但还是想在守卫回来之前吃完所有香蕉。

求小可能在 h 小时内吃完所有香蕉的最小整数 k。

Example 1:

Input: piles = [3,6,7,11], h = 8  
Output: 4  

Example 2:

Input: piles = [30,11,23,4,20], h = 5  
Output: 30  

通过两个Example解释一下题目。  
piles是香蕉堆的数量。h 是管理员离开的时间。我们要找到的是 k = 4 也就是koko吃香蕉的速度，最小多少才能在8小时把香蕉都吃完。

这里用到两个概念，1. 小数点向上进位。Java/python/c++都有`ceil()`这个函数，这个函数就是只要有小数点，就向上进一位。比如，4.1 = 5

那么我们就能通过array中每堆除以koko吃香蕉速度的结果，计算和h是否相同。  
这里的binary search不是对array的search，而是对 k的值的search。  
k的取值范围是`1 - array中最大值`，用example 1 举例，每小时11根香蕉，是koko的速度最大值。  
我们用k的取值范围的binary search 来寻找最小值。

```python
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)

        while l < r:
            k = l + (r - l) // 2
            hours = 0
            for p in piles:
                hours += math.ceil(p / k) # 小数点向上进位的代码
            # 如果k的取值，让hours小于或等于h，说明我们的速度能够下降或已经获得最小值，所以r point移动
            if hours <= h:
                r = k
            # 如果k的取值，让hours大于h，说明我们的速度需要增加，l point移动。
            else:
                l = k + 1
        return r
```

下面这段是传统的binary search，找中间值。上面这段将r作为最终值，两种方式基本一样，区别在于while loop的终止条件。
```PYTHON
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        res = r

        while l <= r:
            k = l + (r - l) // 2
            hours = 0
            for p in piles:
                hours += math.ceil(p / k) # 小数点向上进位的代码
            
            if hours <= h:
                res = min(res, k)
                r = k - 1
            else:
                l = k + 1
        return res
```

```JAVA
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1, right = 1;
        for(int pile : piles){
            right = Math.max(pile, right);
        }

        while(left < right){
            int mid = left + ((right - left) >> 1);
            int hours = 0;

            for(int pile: piles){
                hours += Math.ceil((double)pile / mid);
            }
            if (hours <= h){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return right;

    }
}
```

```C++
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }
        
        int result = high;
        
        while (low <= high) {
            int k = low + (high - low) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double) piles[i] / k);
            }
            if (hours <= h) {
                result = min(result, k);
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        
        return result;
    }
};
```


### <a id= "table4"> 4. Find Minimum In Rotated Sorted Array 查找旋转排序数组中的最小值 </a>
这题主要是考底层逻辑的认识。但实际意义不大。  
一个递增数组中找出原始最小值，这个数组有可能被旋转多次。  
逻辑是，不管怎样旋转，在顺序的情况下Left point都小于right point。  
所以，如果我们寻找left point小于right point的话，最小值就是left point。  
当数组旋转过，初始的left point为 0， right point 为 len of array。   
right point 一定小于 left point，此时记录m point的值和l point哪个小，  
如果m 小于 l，说明最小值在 l - m 之间。如果m 大于 l，说明最小值在 （m + 1）- r 之间。  

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        res = nums[0]
        l, r = 0, len(nums) - 1

        while l <= r:
            if nums[l] < nums[r]:
                res = min(res, nums[l])
                break
            m = (l + r) // 2
            res = min(res, nums[m])
            if nums[m] >= nums[l]:
                l = m + 1
            else:
                r = m - 1
        return res
```

```JAVA
class Solution {
    public int findMin(int[] nums) {
        int l = 0;
        int r = nums.length - 1;

        while(l <= r){
            if(nums[l] <= nums[r]){
                return nums[l];
            }
            int mid = (l + r) / 2;
            if(nums[mid] >= nums[l]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return 0;
    }
}
```

C++ 两种写法

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);

            if (nums[mid] >= nums[l]) // mid present in left sorted array
            {
                l = mid + 1; // try to move closer to right sorted array
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
};
```

```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            if(nums[l] <= nums[r]){
                return nums[l];
            }
            int mid = (l+r)/2;
            if(nums[mid] >= nums[l]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return 0;
    }
};
```



