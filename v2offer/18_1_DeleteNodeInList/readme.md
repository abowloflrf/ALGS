# 删除单向链表中的节点

这个题目看上去似乎非常简单且普通，但是也是有一些需要考虑到的地方。首先因为目标链表是单向链表，正常情况通过改变链表节点指针的形式删除链表中的节点是需要拿到目标节点的前一个节点然后改变其 next 指针的，但是因为这里是**单向链表**，而不是双向，因此需要遍历以拿到其前一位，这样一来时间复杂度就编程啦 O(n)。若要以时间 O(1)完成，则可以以改变节点内容的方法而不是改变指针的方法删除节点。

> 假设目标节点是存在于链表中的，不需要在算法中判断目标节点是否存在

## O(n)

直接遍历找到目标的前一个节点，然后将 next 指向目标的下一位。

```cpp
ListNode* item = *pList;
while (item->next) {
    // find node before target
    if (item->next == pTarget) break;
    item = item->next;
}
item->next = pTarget->next;
```

需要注意的时，若目标是头节点是拿不到其前一位节点的，这里则需要单独判断。

```cpp
if (pTarget == *pList) {
    *pList = pTarget->next;
    delete pTarget;
    return;
}
```

## O(1)

将目标节点的内容设置为其下一个节点的内容，next 指针指向下下个节点。

```cpp
ListNode* nextNode = pTarget->next;
pTarget->val = nextNode->val;
pTarget->next = nextNode->next;
```

若要删除的是尾节点，下下个节点是无法得到的，因为下一个节点就已经是 NULL 了，因此是尾节点是还是需要遍历找到前一个节点做处理

```cpp
ListNode* item = *pList;
while (item->next != pTarget) {
    item = item->next;
}
item->next = nullptr;
```

若要删除的既是头节点也是尾节点，即链表中只有这一个元素时，直接将其删除即可。
