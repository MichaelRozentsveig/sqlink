#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class TB>
class Building_t
{
    public:
        ~Building_t                 ();
        Building_t                  ();
        Building_t                  (const Building_t& b);
        Building_t <TB>& operator=  (const Building_t& b);

        const TB&   getBuildingID()                     const   {return m_buildingID;}
        void        setBuildingID(const TB& buildingID)         {m_buildingID = buildingID;} 

    private:
        TB m_buildingID;
};

template <class TB>
Building_t<TB>::~Building_t(){}

template <class TB> 
Building_t<TB>::Building_t(){}

template <class TB>
Building_t<TB>::Building_t(const Building_t& b)
{
    m_buildingID = b.m_buildingID;
}

template <class TB>
Building_t<TB>& Building_t<TB>:: operator= (const Building_t<TB>& b)
{
    m_buildingID = b.m_buildingID;
    return *this;
}


