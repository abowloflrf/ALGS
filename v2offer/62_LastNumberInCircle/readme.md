# 约瑟夫环问题

数学归纳技巧

```cpp
return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
```