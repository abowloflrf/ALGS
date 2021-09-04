# 50. Pow(x, n)

类似二分的方式，n 次幂递归二分为多个子任务

`double res = fastpow(x, n / 2);`

-   `n%2==1` => `res = res * res * x`
-   `n%2==0` => `res = res * res`

注意两点

-   n 可能是负数
-   n 可能是负数，因此 -n 可能会溢出
