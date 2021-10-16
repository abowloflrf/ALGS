# 986. 区间列表的交集

求交集的算法

-   取 start = max(startA,startB)
-   取 end = min(endA,endB)
-   若 start < end 则说明有交集: `(start,end)

两个列表从头开始量量判断

-   a b 两个区间判断完交集后
-   a b 中先结束的其 `index++`，另一个不变
