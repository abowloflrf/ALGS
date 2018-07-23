# 赋值运算函数

为下面类型添加赋值运算符函数

```cpp
class CMyString {
   public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

   private:
    char* m_pData;
}
```
