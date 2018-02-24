#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class circle
{
public:
    circle();
    circle(double);
    double area() const;
protected:
    const static double PI;
private:
    double radius;
};

class cylinder : circle
{
public:
  cylinder();
  cylinder(double, double);
  double area() const;
  double volume() const;
private:
  double height;
};
