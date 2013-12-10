#include "iostream"
#include "common.h"

using namespace std;

template<typename V_T>
class LNode
{
public:
    V_T m_v;
    LNode* m_next;
    LNode* m_pre;
    LNode(const V_T& p_v)
        {
            m_v=p_v;
            m_next=NULL;
            m_pre=NULL;
        }
    void GetRidOf(LNode* n)
        {
            n->m_pre->m_next=n->m_next;
            n->m_next->m_pre=n->m_pre;
        } 
    void Insert(LNode* prev, V_T& v)
        {
          prev->m_pre
        }    
};

void test1()
{


}

template<typename KeyT, typename ValueT>
class LruCache
{
public:
    LruCache(size_t p_cacheTableSize)
        {
        }

    LruCache()
        {

        }
    
    
    ~LruCache()
        {
        }
    
//if the value is exsit in cache, the value will be in p_v and return true;
//if the value is not exist in cache, the function will return false
    bool Read(const KeyT& p_key, ValueT& p_v)
        {
            return true;
        }
    
    void Write(const KeyT& p_key, const ValueT& p_v)
        {
            return;
        }
    
private:
    size_t m_size;
    size_t current_size;
    
};

int main()
{


}


