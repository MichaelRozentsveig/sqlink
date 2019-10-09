#ifndef CONT_H
#define CONT_H
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>
#include <typeinfo>

using namespace std;

template <class T, class Container > 
class tContainer_t
{
    public:
    
        tContainer_t    ()      {}
        ~tContainer_t   ()      {}

        bool isEmpty    ()      const   {return m_container.empty();}
        size_t numOfElements()  const   {return m_container.size();}
        void insertElement(T* elem)     {m_container.push_back(elem);}

        T* firstElem()  const {return *(m_container.begin());}
        T* lastElem()   const {return *(--m_container.end());}
        

        T* findElem(T elem)  
        { 
            iter_t item = 
                find_if(m_container.begin(),m_container.end(), 
                specElem<T>(elem));

            if (item != m_container.end())
            {
                return (T*) (*item);
            } 
            return 0;         
        }

        T* removeElem(const T& elem)
        {
            iter_t item = 
                find_if(m_container.begin(),m_container.end(), 
                specElem<T>(elem));
            if (item != m_container.end())
            {
                T* pos = *item;
                m_container.erase(item);
                return pos;
            }
            return 0;
        }

        void removeAllElems()
        {
            m_container.erase(m_container.begin(),m_container.end());  
        }

        void deleteElem(const T& elem)
        {
            iter_t item = 
                find_if(m_container.begin(),m_container.end(), 
                specElem<T>(elem));
            if (item != m_container.end())
            {
                T* pos = *item;
                m_container.erase(item);
                delete pos;
            }
        }

        void deleteAllElems()
        {
            iter_t pos = m_container.begin();
            iter_t next = pos+1;
            while (pos != m_container.end())
            {
                T* current = *pos;
                m_container.erase(pos);
                delete current;
                pos= next;
                next ++;
            }
        }

        T* operator[]  (size_t index) const
        {

            if (typeid(this).name() == typeid(tContainer_t <T,list<T*> >*).name())
            {
                if (index < m_container.size())
                {
                    citer_t it = m_container.begin();
                    while(index>0)
                    {
                        it++;
                        index--;
                    }                 
                    return *it;
                }   
            }
            else
            {
                citer_t it = m_container.begin();
                while(index>0)
                {
                    it++;
                    index--;
                }                 
                return *it;
            }                     
        }

    private:
        Container m_container; 
        tContainer_t                            (const tContainer_t& cont){}
        tContainer_t <T,Container>& operator=   (const tContainer_t& cont){}
        typedef typename Container::iterator iter_t;
        typedef typename Container::const_iterator citer_t;

        template <class K>
        class specElem
        {
            public:
                specElem(K i) : val(i){}
                bool operator()(K* parm) const {return *parm == val;}

            private:
                K val;
        };       
};
#endif