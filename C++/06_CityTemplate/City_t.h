#pragma once
#include "Street_t.h"

using namespace std;

template <class TC, class TS, class TB>
class City_t
{
    public:
        City_t                      ();
        ~City_t                     ();
        City_t                      (const City_t& s);
        City_t<TC,TS,TB>& operator= (const City_t& s);

        const TC&   getCityID()                    const;
        void        setCityID(const TC& cityID)         ;

        void    AddStreet2City          (const Street_t<TS,TB>& s)       ;
        const   Street_t<TS,TB>& getStreet (TS s)                   const;
   private:

        TS m_cityID;
        vector < Street_t<TS,TB> > m_StreetsVector;
};

template <class TC, class TS, class TB>
City_t<TC,TS,TB>::City_t(){}

template <class TC, class TS, class TB>
City_t<TC,TS,TB>::~City_t(){}

template <class TC, class TS, class TB>
City_t<TC,TS,TB>::City_t(const City_t<TC,TS,TB>& c)
{
    m_StreetsVector = c.m_StreetsVector;
    m_cityID = c.m_cityID;
}

template <class TC, class TS, class TB>
City_t<TC,TS,TB>& City_t<TC,TS,TB> :: operator= (const City_t<TC,TS,TB>& c)
{
    m_StreetsVector = c.m_StreetsVector;
    m_cityID = c.m_cityID;
    return *this;
}

template <class TC, class TS, class TB>
const TC& City_t<TC,TS,TB>:: getCityID() const 
{
    return m_cityID;
}

template <class TC, class TS, class TB>
void City_t<TC,TS,TB>:: setCityID(const TC& cityID)
{
    m_cityID = cityID;
}

template <class TC, class TS, class TB>
void City_t<TC,TS,TB>:: AddStreet2City(const Street_t<TS,TB>& s)
{
    m_StreetsVector.push_back(s);
}

template <class TC, class TS, class TB>
const Street_t<TS,TB>& City_t<TC,TS,TB>:: getStreet(TS s) const
{
    for (int i=0;i<m_StreetsVector.size();i++)
    {
        if (m_StreetsVector[i].getStreetID() == s)
        {
            return m_StreetsVector[i];
        }
    }
    throw string("The Street Does NOT EXIST !");
} 