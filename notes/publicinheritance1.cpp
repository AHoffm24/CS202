#include <iostream>
using namespace std;

class parallelogram
{
public:
	void set_dimensions(double, double, double);
	double get_area() const;
	double get_perimeter() const;
private:
	double length;
	double height;
	double side_height;
};

class rectangle : public parallelogram
{
	/*
	These functions will be public in this
	class as well because we are doing a
	public inheritance

	void set_dimensions(double, double);
	double get_area() const;
	double get_perimeter() const;

	-------------------------------------------------------

	Since these fields are private in the base
	class rectangle, these will exist in this class
	but cannot be accessed directly

	double length;
	double height;
	double side_height;
	*/
};

class square : public rectangle
{
	/*
	These functions will be public in this
	class as well because we are doing a
	public inheritance and they are public
	in the rectangle class

	void set_dimensions(double, double);
	double get_area() const;
	double get_perimeter() const;

	-------------------------------------------------------

	Since these fields are not directly accessible in the base
	class rectangle, these will exist in this class
	but cannot be accessed directly either

	double length;
	double height;
	double side_height;
	*/
};

/*-----------------------------------------------------------------
Parallelogram's member functions implementations
-----------------------------------------------------------------*/
void parallelogram::set_dimensions(double l, double h, double s)
{
	length = l;
	height = h;
	side_height = s;
}

double parallelogram::get_area() const
{
	return length * height;
}

double parallelogram::get_perimeter() const
{
	return 2 * (side_height + length);
}


int main()
{
	parallelogram p;
	rectangle r;
	square s;

	p.set_dimensions(3.0, 5.0, 5.4);
	r.set_dimensions(4.0, 5.0, 5.0);
	s.set_dimensions(4.0, 4.0, 4.0);

	cout << "Parallelogram's area: " << p.get_area() << endl;
	cout << "Parallelogram's perimeter: " << p.get_perimeter() << endl;

	//Uses parallelogram's get_area() and get_perimeter() in rectangle object
	cout << "Rectangle's area: " << r.get_area() << endl;
	cout << "Rectangle's perimeter: " << r.get_perimeter() << endl;

	/*
	Uses rectangle's get_area() and get_perimeter() (which is inherited from
	parallelogram class) in the square class
	*/
	cout << "Square's area: " << s.get_area() << endl;
	cout << "Square's perimeter: " << s.get_perimeter() << endl;

	return 0;
}
