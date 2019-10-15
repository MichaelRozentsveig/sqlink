#ifndef AD_H
#define AD_H

#include "tMeeting_t.h"

#include <map>
#include <string>

using namespace std;

class tAppDiary_t
{
    public:
        virtual ~tAppDiary_t(){}

        tAppDiary_t         (){}

        bool insertMeeting  (tMeeting_t* meet);

        bool removeMeeting  (tMeeting_t* meet)
        {
            if (meet == NULL || m_meetings.find(meet->getBeginHour()) == m_meetings.end())
            {
                return false;
            }
            m_meetings.erase(meet->getBeginHour());
            return true;
        }

        tMeeting_t* findMeet(const float& begHour)
        {
            m_iter it  = m_meetings.find(begHour);
            return ((it == m_meetings.end()) ? 0 : it->second);           
        }

        void cleanAD()
        {
            m_meetings.clear();
        }

        
    private:
        map <float,tMeeting_t*> m_meetings;
        typedef typename map<float,tMeeting_t*>::iterator m_iter;

};

#endif