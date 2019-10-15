#include <iostream>
#include "tAppDiary_t.h"
#include "tMeeting_t.h"

using namespace std;

void insertApp  (tAppDiary_t&);
void removeApp  (tAppDiary_t&);
void findApp    (tAppDiary_t&);
void cleanDiary (tAppDiary_t&);
void myMain     (tAppDiary_t&);


int main()
{
    tAppDiary_t diary;
    myMain(diary);
    return 0;
}

void myMain(tAppDiary_t& diary)
{
    int cont    =   1;
    int option  =   0;

    while (cont)
    {
        cout    << "Please choose an option: (1 to 4)"  << endl
                << "1 >>>      Insert meeting"          << endl
                << "2 >>>      Remove meeting"          << endl
                << "3 >>>      Find meeting"            << endl        
                << "4 >>>      Clean diary"             << endl      
                << "other>>>   Exit"                    << endl;

        cin >> option;

        switch(option)
        {
            case 1:     insertApp(diary);
                break;
            case 2:     removeApp(diary);
                break;
            case 3:     findApp(diary);
                break;
            case 4:     cleanDiary(diary);
                break;
                        
            default:    cont=0;
                break;
        }
    }
}

void insertApp(tAppDiary_t& diary)
{
    float begTime;
    float endTime;
    string subject="";

    cout    << "Enter Begin hour:"  << endl;
    cin     >> begTime;

    cout    << "Enter End hour:"    << endl;
    cin     >> endTime;

    cout    << "Enter subject:"     << endl;
    cin     >> subject;

    try
    {
        tMeeting_t* meet = new tMeeting_t(begTime,endTime,subject);
    }
    catch(string)
    {
        cout << "Failed creating the meeting ! " << endl << endl;
        return;
    }
    tMeeting_t* meet = new tMeeting_t(begTime,endTime,subject);

    cout << "Insertion " << ((diary.insertMeeting(meet)) ? "Succeed" : "Failed") << endl ; 
}


void removeApp(tAppDiary_t& diary)
{
    float begTime;

    cout    << "Enter the beggining time of the meeting you would like to remove:" << endl;
    cin     >> begTime;

    cout    << "Remove " << (diary.removeMeeting(diary.findMeet(begTime)) ? "Succeed" : "Failed") << endl;
}


void findApp(tAppDiary_t& diary)
{
    float begTime;

    cout    << "Enter the beggining time of the meeting you would like to find:" << endl;
    cin     >> begTime;

    cout    <<  (diary.findMeet(begTime) ? "Found" : "Not Found") << endl;
}


void cleanDiary(tAppDiary_t& diary)
{
    diary.cleanAD();
}   