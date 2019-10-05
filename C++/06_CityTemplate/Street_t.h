#pragma once
#include "Building_t.h"
#include <vector>

using namespace std;

template <class TS, class TB>
class Street_t
{
    //typedef status enum{FAILED, SUCCEED};

    public:
        Street_t                   ();
        ~Street_t                   ();
        Street_t                    (const Street_t& s);
        Street_t<TS,TB>& operator=   (const Street_t& s);

        const TS&   getStreetID()                     const ;
        void        setStreetID(const TS& streetID)         ; 

        void    AddBuilding2Street          (const Building_t<TB>& b)    ;
        const   Building_t<TB>& getBuilding (TB b)                  const;
   private:

        TS m_streetID;
        vector < Building_t<TB> > m_BuildingsVector;
};

template <class TS, class TB>
Street_t<TS,TB>::Street_t(){}

template <class TS, class TB>
Street_t<TS,TB>::~Street_t(){}

template <class TS, class TB>
Street_t<TS,TB>::Street_t(const Street_t<TS,TB>& s)
{
    m_BuildingsVector = s.m_BuildingsVector;
    m_streetID = s.m_streetID;
}

template <class TS, class TB>
Street_t<TS,TB>& Street_t<TS,TB> :: operator= (const Street_t<TS,TB>& s)
{
    m_BuildingsVector = s.m_BuildingsVector;
    m_streetID = s.m_streetID;
    return *this;
}

template <class TS, class TB>
const TS& Street_t<TS,TB>:: getStreetID() const 
{
    return m_streetID;
}

template <class TS,class TB>
void Street_t<TS,TB>:: setStreetID(const TS& streetID)
{
    m_streetID = streetID;
}

template <class TS, class TB>
void Street_t<TS,TB>:: AddBuilding2Street(const Building_t<TB>& b)
{
    m_BuildingsVector.push_back(b);
}

template <class TS,class TB>
const Building_t<TB>& Street_t<TS,TB>:: getBuilding(TB b) const
{
    for (int i=0;i<m_BuildingsVector.size();i++)
    {
        if (m_BuildingsVector[i].getBuildingID() == b)
        {
            return m_BuildingsVector[i];
        }
    }
    throw string("The Building Does NOT EXIST !");
} 

