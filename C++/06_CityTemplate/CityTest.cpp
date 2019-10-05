#include <iostream>
#include "City_t.h"

using namespace std;

int main()
{
    Building_t<int> b1;
    Building_t<int> b3;
   
    b1.setBuildingID(16);
    cout << "First building ID is : " << b1.getBuildingID() << endl;

    Building_t<string> b2;
    b2.setBuildingID("16b");
    cout << "Second building ID is : " << b2.getBuildingID() << endl;

    Street_t<string,int> s1;
    Street_t<string,int> s2;
    

    s1.setStreetID("Karl");
    cout << "First street ID is : " << s1.getStreetID() << endl;
    s1.AddBuilding2Street(b1);
    cout << "Added first building to the street"<< endl;
    
    try // Should work
    {
        b3 = s1.getBuilding(16);
    }
    catch(string)
    {
        cout << "16 NOT EXISTS" << endl;
    }

    try // Should fail
    {
        b3 = s1.getBuilding(17);
    }
    catch(string)
    {
        cout << "17 NOT EXISTS" << endl;
    }
    
    

    City_t<string,string,int> c1;
    c1.setCityID("Rishon Lezion");
    cout << "First city ID is : " << c1.getCityID() << endl;
    c1.AddStreet2City(s1);
    cout << "Added first building to the city" << endl;

    return 0;
}