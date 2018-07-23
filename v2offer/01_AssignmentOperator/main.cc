#include <cstring>
class CMyString {
   public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);
    //赋值运算符重载
    CMyString& CMyString::operator=(const CMyString& str) {
        //若两者是同一个对象，则直接返回即可
        if (this == &str) return *this;

        //删除本身的字符内容
        delete[] m_pData;
        m_pData = nullptr;
        //分配目标的指定空间并copy字符串内容
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);

        return *this;
    }

   private:
    char* m_pData;
}
