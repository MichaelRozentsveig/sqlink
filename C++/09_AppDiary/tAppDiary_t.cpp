#include "tAppDiary_t.h"

bool tAppDiary_t::insertMeeting  ( tMeeting_t* meet)
{
    m_iter it =   m_meetings.begin();
    tMeeting_t* currentMeet;
    tMeeting_t* nextMeet;        
    
    if(it==m_meetings.end()) // Empty map
    {
        m_meetings[meet->getBeginHour()]=meet;
        return true;
    }
    currentMeet = it->second; 
    if(meet->getEndHour() < currentMeet->getBeginHour()) // Earlier than the first
    {
        m_meetings[meet->getBeginHour()]=meet;
        return true;
    }

    it=m_meetings.end();
    it--;
    currentMeet=it->second;

    if(meet->getBeginHour() > currentMeet->getEndHour()) // Post last meeting
    {
        m_meetings[meet->getBeginHour()]=meet;
        return true;
    }
    if(m_meetings.size()==1)
    {
        return false;
    }
    it=m_meetings.begin();
    currentMeet = it->second;
    it++;
    nextMeet = it->second;
    while(it!=m_meetings.end())
    {
        if(meet->getBeginHour() > currentMeet->getEndHour() && meet->getEndHour() < nextMeet->getBeginHour())
        {
            m_meetings[meet->getBeginHour()]=meet;
            return true;
        }
        currentMeet = it->second;
        it++;
        nextMeet = it->second;        
    }        
    return false;
}