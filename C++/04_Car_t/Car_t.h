#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car_t
{
    public:
        Car_t(): 
            m_myID(m_publicID++),m_capacity(defCapacity){};
        Car_t(const size_t capacity): 
            m_myID(m_publicID++),m_capacity(capacity){};

        Car_t(const Car_t& car):m_myID(m_publicID++), m_capacity(car.m_capacity){};

        Car_t& operator= (const Car_t& car){m_capacity=car.m_capacity;} 

        string getName() const {return m_name; }
        string getType() const {return m_type;}
        size_t getCapacity() const {return m_capacity;}
        size_t getID() const {return m_myID;}


        bool operator<(const Car_t& car) const {return (m_capacity < car.m_capacity);}

        bool compareCars(const Car_t& car) const { return (m_name.compare(car.m_name));}

    protected:
        ~Car_t(){};
        void setType(string type){m_type = type;}
        void setName(string name){m_name = name;}

    private:

        const size_t m_myID;
        static size_t m_publicID;
        string m_name;
        string m_type;
        size_t m_capacity;
        static size_t defCapacity;

};


class Bus_t: public Car_t
{
    public:
        ~Bus_t(){}; 
        Bus_t():m_nOfSeats(0), m_line(0)
        { 
            setName("BUS"); 
            setType("MANUAL");
        };

        Bus_t(size_t capacity, size_t nOfSeats, size_t line):Car_t(capacity)
        {
            setName("BUS"); 
            setType("MANUAL");
            m_nOfSeats = nOfSeats;
            m_line = line;
        }

        size_t getLine()const {return m_line;}
        void setLine(size_t line){m_line = line;}

        size_t getNOS() const {return m_nOfSeats;}
        void setNOS(size_t nOfSeats) {m_nOfSeats = nOfSeats; }

    private:
        size_t m_line;
        size_t m_nOfSeats;

};


class Private_t: public Car_t
{
    public:
        ~Private_t(){};
        Private_t():m_speed(0){ setName("PRIVATE"); setType("AUTO");}
        Private_t(size_t capacity):Car_t(capacity),m_speed(0){}

        size_t getSpeed() const {return m_speed;}
        void accelerateBy10() { m_speed+=10;}
        void reduceSpeedBy10() {if (m_speed!=0) {m_speed-=10;}}

    private:
        size_t m_speed;
};


#endif