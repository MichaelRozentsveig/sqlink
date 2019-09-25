#include <iostream>
#include "Car_t.h"
#include <string>
using namespace std;

void defCtor();
void ctorCapacity();
void assign();
void less1();
void compareTypes();
void getid();
void changeSpeed();

int main()
{
    int cont = 1;
    int option =0;

    while (cont)
    {
        cout << "Please choose an option: (1 to 7)"<< endl;
        cout << "1 >>>      Default constructor "<< endl;
        cout << "2 >>>      Constructor Car with capacity "<< endl;
        cout << "3 >>>      Assignment "<< endl;        
        cout << "4 >>>      Operator <  :"<< endl;
        cout << "5 >>>      Compare Types"<< endl;
        cout << "6 >>>      Get ID"<< endl;
        cout << "7 >>>      Change Speed"<< endl;          
        cout << "other>>>   Exit"<< endl;

        cin >> option;

        switch(option)
        {
            case 1:     defCtor();
                break;
            case 2:     ctorCapacity();
                break;
            case 3:     assign();
                break;
            case 4:     less1();
                break;
            case 5:     compareTypes();
                break;
            case 6:     getid();
                break;
            case 7:     changeSpeed();
                break;
     
            default:    cont=0;
                break;
        }
    }
}

void defCtor()
{
    Bus_t bus;
    Private_t car;
    cout << "Bus: " <<bus.getName() << endl << "Car: " << car.getName() << endl;
}

void ctorCapacity()
{
    size_t capacity;
    cout << "Enter capacity for private car:"<< endl;
    cin >> capacity;
    Private_t pc(capacity);
    cout << "Capacity: " << pc.getCapacity() << endl;
}

void assign()
{
    Private_t pc1(1400);
    Private_t pc2(1200);
    cout << "First car capactiy: " << pc1.getCapacity() << endl;
    cout << "Second car capactiy: " << pc2.getCapacity() << endl;
    cout << "Assign Second to First: " << endl;

    pc1=pc2;
    cout << "First car capactiy: " << pc1.getCapacity() << endl;
}

void less1()
{
    Private_t pc1(1400);
    Private_t pc2(1200);
    cout << "First car capactiy: " << pc1.getCapacity() << endl;
    cout << "Second car capactiy: " << pc2.getCapacity() << endl;
    cout << "First < Second : "<< (pc1 < pc2) << endl;

}

void compareTypes()
{
    Bus_t b1, b2;
    Private_t p1, p2;
    cout << "Compare bus to bus: " << b1.compareCars(b2)<<endl;
    cout << "Compare bus to private: " << b1.compareCars(p1)<<endl;
    cout << "Compare private to private: " << p1.compareCars(p2)<<endl;
}

void getid()
{
    cout << "Create First bus: " << endl << "ID: ";
    Bus_t b1;
    cout << b1.getID() << endl;
    cout << "Create Second bus: " << endl << "ID: ";
    Bus_t b2;
    cout << b2.getID() << endl;
    cout << "Create First car: " << endl << "ID: ";
    Private_t p1;
    cout << p1.getID() << endl;
}

void changeSpeed()
{
    Private_t car;
    cout << "Car speed before: " << car.getSpeed()<< endl ;
    car.accelerateBy10();
    cout << "Car speed After accelerate: " << car.getSpeed()<< endl ;
    car.reduceSpeedBy10();
    cout << "Car speed After reduction: " << car.getSpeed()<< endl ;
}