# LeeCode刷题

- [LeeCode刷题](#leecode刷题)
    - [ 1. Valid Parentheses 有效括号 ](#-1-valid-parentheses-有效括号-)
    - [ 2. Min Stack 最小堆栈 ](#-2-min-stack-最小堆栈-)
    - [ 3. Evaluate Reverse Polish Notation 评估反波兰符号 ](#-3-evaluate-reverse-polish-notation-评估反波兰符号-)
    - [ 4. Generate Parentheses 生成括号 ](#-4-generate-parentheses-生成括号-)


### <a id= "table1"> 1. Valid Parentheses 有效括号 </a>

Parentheses 怕润色C斯 （小括号/圆括号）
Square brackets 中括号
braces 布瑞色斯 （大括号/花括号）

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

```Python
class Solution:
    def isValid(self, s: str) -> bool:
        Map = {")": "(", "]": "[", "}": "{"}
        stack = []

        for c in s:
            if c not in Map:
                # c not in Map, 这个判断式是判断的Key。这里所有的Key都是结束括号
                #所以前部符号被按顺序储存进stack
                stack.append(c)
                continue
            #当前部符号按顺序储存进stack后，C则为后部符号，这时后部符号应和前部符号相对应
            #stack的最后一个，应该和c这个key所对应的value相同，
            if not stack or stack[-1] != Map[c]:
                return False
            stack.pop()

        return not stack
        
```

Java的逻辑是一样的，有另一种写法，但写法太复杂了。runtime和memory使用几乎一样。

```JAVA
class Solution {
    public boolean isValid(String s) {
        Stack<Character> brackets = new Stack<>();
        Map<Character, Character> bracketLookup = new HashMap<>(3);

        bracketLookup.put(')', '(');
        bracketLookup.put('}', '{');
        bracketLookup.put(']', '[');

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (bracketLookup.containsKey(c)) {
                if (!brackets.isEmpty() && bracketLookup.get(c).equals(brackets.peek())) {
                    brackets.pop();
                } else {
                    return false;
                }
            } else {
                brackets.push(c);
            }
        }

        return brackets.isEmpty();
    }
}
```

```C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char, char> map = {{')', '('}, {']', '['}, {'}', '{'},};

        for (const auto& c : s){
            if(map.find(c) != map.end()){
                if(open.empty()){
                    return false;
                }
                if(open.top() != map[c]){
                    return false;
                }
                open.pop();
            }else{
                open.push(c);
            }
        }
        return open.empty();
    }
};
```


### <a id= "table2"> 2. Min Stack 最小堆栈 </a>



### <a id= "table3"> 3. Evaluate Reverse Polish Notation 评估反波兰符号 </a>



### <a id= "table4"> 4. Generate Parentheses 生成括号 </a>
