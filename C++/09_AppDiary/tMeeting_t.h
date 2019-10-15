#ifndef MEET_H
#define MEET_H

#include <string>

using namespace std;

class tMeeting_t
{
    public:
        tMeeting_t(const float& beginTime, const float& endTime, const string& subject)
        {
            string s = "Bad input";
            if (beginTime>=endTime || endTime>24 || endTime<0)
            {
                throw s;
            } 
            m_beginTime = beginTime;
            m_endTime   = endTime;
            m_subject   = subject;
        }

        virtual ~tMeeting_t         ()                      {}
        const float getBeginHour    () const                {return m_beginTime;}
        const float getEndHour      () const                {return m_endTime;}
        const string getSubject     () const                {return m_subject;}

    private:
        float m_beginTime;
        float m_endTime;
        string m_subject;
        tMeeting_t& operator=   (const tMeeting_t& meet){}
        tMeeting_t              (const tMeeting_t& meet){}


};

#endif