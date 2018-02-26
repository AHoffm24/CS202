#include <iostream>
#include "circleCylinder.h"
#include <iomanip>
using namespace std;

int main()
{
int    quantity = 0;
double radius = 0.0;
double height = 0.0;

double totalship = 0.0;
double totalpaint = 0.0;
double total = 0.0;
bool info1 = false;
bool info2 = false;
bool info3 = false;

cout << "how many cylinders do you want to ship?" << endl;
cin >> quantity;
double shipPerLiter[quantity];
double costSqFt[quantity];
cylinder ** containers;
containers = new cylinder*[quantity];
for(int i = 0; i < quantity; i++)
{
    cout << "Info for Cylinder " << (i+1) << endl;
    while(info1 == false || info2 == false)
    {
        if(info1 == false)
        {
            cout << "Enter the radius of the base of the"
            << " cylinder and the height(in feet)" << endl;
            cin >> radius >> height;
            if (cin.fail() == true)
            {
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
                info1 = true;
        }
        containers[i] = new cylinder(radius, height);


        if (info1 == true)
        {
            cout << "Enter  shipping  cost  per  liter "
            << "and  paint  cost  per  square  foot"
            <<  endl;
            cin >> shipPerLiter[i] >> costSqFt[i];
            if (cin.fail() == true)
            {
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
                info2 = true;
        }

    }
    info1 = false;
    info2 = false;

 }
 for(int j = 0; j < quantity; j++)
 {
        totalpaint = containers[j]->area() * costSqFt[j];
        totalship = containers[j]->volume() * shipPerLiter[j] * 28.32;
        total = totalpaint + totalship;
        cout << "Costs for cylinder no. " << j << endl;

        cout << setfill('.') << setw(29) << left << "Price To ship Container" << "$" << setfill(' ') << setw(10) << right << fixed << setprecision(2) << totalship << endl;

        cout << setfill('.') << setw(29) << left << "Price to paint container"<< "$" << setfill(' ') << setw(10) << right << setprecision(2) << totalpaint << endl;

        cout << setfill('.') << setw(29) << left << "Toal Cost" << "$"  << setfill(' ') << setw(10) << right << setprecision(2) << total << endl;

}

   return 0;
}
