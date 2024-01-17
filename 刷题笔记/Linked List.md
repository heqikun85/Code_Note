## LeeCode刷题

1. [Reverse Linked List 反向链接表](#table1)
2. [Merge Two Sorted Lists  合并两个排序列表](#table2)
3. [Reorder List  重新排序列表](#table3)
4. [Remove Nth Node From End of List  从列表末尾移除第 N 个节点](#table4)
5. [Copy List With Random Pointer  用随机指针复制列表](#table5)
6. [Add Two Numbers  添加两个数字](#table6)


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



### <a id= "table3"> 3. Reorder List  重新排序列表</a>



### <a id= "table4"> 4. Remove Nth Node From End of List  从列表末尾移除第 N 个节点</a>



### <a id= "table5"> 5. Copy List With Random Pointer  用随机指针复制列表</a>



### <a id= "table6"> 6. Add Two Numbers  添加两个数字</a>