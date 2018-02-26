#include "circleCylinder.h"
#include <iostream>
#include <cmath>
using namespace std;
/*----------------------------------------------------
Default Constructor
PARAMETERS: none
POSTCONDITION: radius set to 0;
----------------------------------------------------*/
circle::circle()
{
    radius = 0;
    return;
}
/*----------------------------------------------------
Constructor
PARAMETERS: radius in the form of double num
POSTCONDITION: private: Radius from class circle = num
----------------------------------------------------*/
circle::circle(double num)
{
    radius = num;
    return;
}
/*----------------------------------------------------
Default Constructor
PARAMETERS: sets constant PI from class Circle to pi
POSTCONDITION:PI = 3.14, can make more exact
----------------------------------------------------*/
const double circle::PI = 3.14;
/*----------------------------------------------------
value returning function
PARAMETERS: uses radius from class circle
POSTCONDITION: returns the area of a circle when given
a radius.
----------------------------------------------------*/
double circle::area() const
{
  return (PI * pow(radius, 2));
}
/*----------------------------------------------------
Default Constructor
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
cylinder::cylinder() : circle()
{
  height = 0.0;
  circle c;
  return;
}
/*----------------------------------------------------
Constructor
PARAMETERS: radius and height are passed in by value as
rad and tall.
POSTCONDITION: height from cylinder class is now set to tall
circle now had radius inside.
----------------------------------------------------*/
cylinder::cylinder(double rad, double tall) : circle(rad)
{
  height = tall;
  return;
}
/*----------------------------------------------------
value returning function
PARAMETERS: use the circle area and pi to determine radius
of circle. rad holds radius of the circle, area hold area
area of the circle used to determine the radius of the cylinder.
POSTCONDITION: returns the area of a cylinder
----------------------------------------------------*/
double cylinder::area() const
{
double area = circle::area();
double rad = sqrt((area / PI));
return(2 * PI * rad * height) + (2 * PI * pow(rad, 2));
           // 2πrh+2πr2
}
/*----------------------------------------------------
value returning function
PARAMETERS: uses area from the circle class and height
from the cylinder class to find the volume of a cylinder
with a given height and radius.
POSTCONDITION:rad = radius of the cylinder.
returns the volume of the cylinder
----------------------------------------------------*/
double cylinder::volume() const
{
    circle c;
    double rad;
    rad = sqrt((circle::area() / PI));
    return (PI * pow(rad, 2) * height);
    //πr2h
}
