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

class rectangle : parallelogram
{
public:
	void set_dimensions(double, double);
	double get_area() const; //Overriding parallelogram's get_area() function
	double get_perimeter() const; //Overriding parallelogram's get_perimeter() function
	/*
	These functions will be private in this
	class since we are doing a private inheritance

	void set_dimensions(double, double);
	double get_area() const;
	double get_perimeter() const;

	-------------------------------------------------------

	Since these fields are private in the base
	class parallelogram, these will exist in this class
	but cannot be accessed directly

	double length;
	double height;
	double side_height;
	*/
};

class square : rectangle
{
public:
	void set_dimensions(double);
	double get_area() const; //Overriding rectangle's get_area() function
	double get_perimeter() const; //Overriding rectangle's get_perimeter() function
	/*
	These functions will be private in this
	class since we are doing a private inheritance
	from the rectangle class

	void set_dimensions(double, double);
	double get_area() const;
	double get_perimeter() const;

	-------------------------------------------------------

	Since these fields are not directly accessible in the rectangle
	class, they are also not directly accessible in this class either

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

/*-----------------------------------------------------------------
Rectangle's member functions implementations
-----------------------------------------------------------------*/
void rectangle::set_dimensions(double l, double h)
{
	/*
	Overriding parallelogram's set_dimensions function, we cannot omit
	parallelogram:: out of the statement below, the compiler will attempt
	to call rectangle's set_dimensions function instead of parallelogram's
	function if we omit parallelogram::
	*/
	parallelogram::set_dimensions(l, h, h);
}

double rectangle::get_area() const
{
	/*
	Overriding parallelogram's get_area function, we cannot omit
	parallelogram:: out of the statement below, the compiler will attempt
	to call rectangle's get_perimeter function instead of parallelogram's
	function if we omit parallelogram::
	*/
	return parallelogram::get_area();
}

double rectangle::get_perimeter() const
{
	/*
	Overriding parallelogram's get_perimeter function, we cannot omit
	parallelogram:: out of the statement below, the compiler will attempt
	to call rectangle's get_perimeter function instead of parallelogram's
	function if we omit parallelogram::
	*/
	return parallelogram::get_perimeter();
}

/*-----------------------------------------------------------------
Square's member functions implementations
-----------------------------------------------------------------*/
void square::set_dimensions(double h)
{
	/*
	Overriding rectangle's set_dimensions function, we cannot omit
	rectangle:: out of the statement below, the compiler will attempt
	to call square's set_dimensions function instead of rectangle's
	function if we omit rectangle::
	*/
	rectangle::set_dimensions(h, h);
}

double square::get_area() const
{
	/*
	Overriding rectangle's get_area function, we cannot omit
	rectangle:: out of the statement below, the compiler will attempt
	to call square's get_area function instead of rectangle's
	function if we omit rectangle::
	*/
	return rectangle::get_area();
}

double square::get_perimeter() const
{
	/*
	Overriding rectangle's get_perimeter function, we cannot omit
	rectangle:: out of the statement below, the compiler will attempt
	to call square's get_perimeter function instead of rectangle's
	function if we omit rectangle::
	*/
	return rectangle::get_perimeter();
}
int main()
{
	parallelogram p;
	rectangle r;
	square s;

	p.set_dimensions(3.0, 5.0, 5.4);
	r.set_dimensions(4.0, 5.0);
	s.set_dimensions(4.0);

	cout << "Parallelogram's area: " << p.get_area() << endl;
	cout << "Parallelogram's perimeter: " << p.get_perimeter() << endl;


	cout << "Rectangle's area: " << r.get_area() << endl;
	cout << "Rectangle's perimeter: " << r.get_perimeter() << endl;


	cout << "Square's area: " << s.get_area() << endl;
	cout << "Square's perimeter: " << s.get_perimeter() << endl;

	return 0;
}
