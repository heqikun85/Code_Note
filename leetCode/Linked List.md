## LeeCode刷题

- [LeeCode刷题](#leecode刷题)
  - [ 1. Reverse Linked List 反向链接表](#-1-reverse-linked-list-反向链接表)
  - [ 2. Merge Two Sorted Lists  合并两个排序列表](#-2-merge-two-sorted-lists--合并两个排序列表)
  - [ 3. Reorder List  重新排序列表](#-3-reorder-list--重新排序列表)
  - [ 4. Remove Nth Node From End of List  从列表末尾移除第 N 个节点](#-4-remove-nth-node-from-end-of-list--从列表末尾移除第-n-个节点)
  - [ 5. Copy List With Random Pointer  用随机指针复制列表](#-5-copy-list-with-random-pointer--用随机指针复制列表)
  - [ 6. Add Two Numbers  添加两个数字](#-6-add-two-numbers--添加两个数字)


### <a id= "table1"> 1. Reverse Linked List 反向链接表</a>

这个是基础链表的应用。  
linked List 在 C++中是以point的形式, Java和python不是以point的形式。  
`head -> next -> null` 这样的形式。python为`head.next`的形式串联。  

解题思路为，将curr 和 pre 初始设置为 head 和 null
运转整个linked list，提取curr.next 临时储存，然后将curr.next覆盖为pre。
也就是 从head开始，curr = head，然后temp = head，pre = null，curr.next = pre
这样 head.next 则变为null了，然后curr = temp.next，也就是原先的head.next，以此类推

```Python
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head

        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev
```

```JAVA
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode curr = head;
        ListNode pre = null;
        ListNode next = null;

        while(curr != null){
            next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;    
        }

        return pre;
    }
}
```
**Java用递归的方式也可以实现**  

将head 和 next的值传入，递归将当前node设置为原先的下一个，并且将node和pre链接，直到node为null

```JAVA
class Solution {
    public ListNode reverseList(ListNode head) {
        return rev(head, null);
    }

    public ListNode rev(ListNode node, ListNode pre){
        if(node == null)return pre;
        ListNode temp = node.next;
        node.next = pre;
        return rev(temp, node);
    }
}
```

```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *pre = NULL;
        ListNode *curr = head;

        while(curr != NULL){
            ListNode *temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
};
```


### <a id= "table2"> 2. Merge Two Sorted Lists  合并两个排序列表</a>

顺序合并两个链表。还是简单的应用
思路就是分别对比两个链表的大小，将小的数字链接，然后移动到下一个node。

```python
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = node = ListNode()

        while list1 and list2: # 当list1 和 list2 都指向null时结束循环
            if list1.val < list2.val: # 如果list2的值大于list1，则node.next链接到list1
                node.next = list1 
                list1 = list1.next # list1 往后移动一个node
            else:
                node.next = list2 # 如果list2相等或小于list1，则链接list2
                list2 = list2.next # list2 向后移动一个node
            node = node.next # 每次循环都将node往后移动一个节点。
        node.next = list1 or list2 #最后将node连接到null

        return dummy.next # 由于node的第一个节点也是null，而且node已经移动到最后一个节点
                          # 所以我们在一开始赋值的时候添加了一个dummy，这个dummy是从head开始
                          # 但由于node的第一个节点也是null，所以我们返回head->next
```
**递归 Recursive**

递归的思路是将point移动到较小的node

Example 1： 

Input: list1 = [1,2,4], list2 = [1,3,4]  
Output: [1,1,2,3,4,4]

第一个节点时，lil = list1，这时，lil.next 进入递归，原本的lil.next = list1.next = 2
当 2 和 list2 的 1 比较时，list2比较小，所以 lil.next和list2相连，这时lil.next = list2.next = 3
用这样的赋值递归方式，将lil的node分别链接到各个节点。

```python
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1
        lil, big = (list1, list2) if list1.val < list2.val else (list2, list1)
        lil.next = self.mergeTwoLists(lil.next, big)
        return lil
```

```Java
class Solution {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        final ListNode root = new ListNode();
        ListNode prev = root;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                prev.next = list1;
                list1 = list1.next;
            } else {
                prev.next = list2;
                list2 = list2.next;
            }
            prev = prev.next;
        }
        prev.next = list1 != null ? list1 : list2;
        return root.next;
    }
}

// Solution using Recursion
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;

        if (list1.val < list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list2.next, list1);
            return list2;
        }
    }
}
```


```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* dummy = new ListNode(); // create a new linked list
        ListNode *curr = dummy; // create a point copy the new linked list

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        if(list1 == NULL){
            curr->next = list2;
        }else{
            curr->next = list1;
        }
        return dummy->next;
    }
};
```



### <a id= "table3"> 3. Reorder List  重新排序列表</a>



### <a id= "table4"> 4. Remove Nth Node From End of List  从列表末尾移除第 N 个节点</a>



### <a id= "table5"> 5. Copy List With Random Pointer  用随机指针复制列表</a>



### <a id= "table6"> 6. Add Two Numbers  添加两个数字</a>