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
	void set_dimensions_rectangle(double, double);
	double get_area_rectangle() const;
	double get_perimeter_rectangle() const;
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
	void set_dimensions_square(double);
	double get_area_square() const;
	double get_perimeter_square() const;
	/*
	These functions will be private in this
	class since we are doing a private inheritance
	from the rectangle class

	void set_dimensions_rectangle(double, double);
	double get_area_rectangle() const;
	double get_perimeter_rectangle() const;

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
void rectangle::set_dimensions_rectangle(double l, double h)
{
	/*
	If you omitted the parallelogram:: from the statement
	below, the compiler would trace up the derivation tree
	and call parallelogram's set_dimensions function
	*/
	parallelogram::set_dimensions(l, h, h);
}

double rectangle::get_area_rectangle() const
{
	/*
	If you omitted the parallelogram:: from the statement
	below, the compiler would trace up the derivation tree
	and call parallelogram's get_area function
	*/
	return parallelogram::get_area();
}

double rectangle::get_perimeter_rectangle() const
{
	/*
	If you omitted the parallelogram:: from the statement
	below, the compiler would trace up the derivation tree
	and call parallelogram's get_area function
	*/
	return parallelogram::get_perimeter();
}

/*-----------------------------------------------------------------
Square's member functions implementations
-----------------------------------------------------------------*/
void square::set_dimensions_square(double h)
{
	/*
	If you omitted the rectangle:: from the statement
	below, the compiler would trace up the derivation tree
	and call rectangle's set_dimensions_rectangle function
	*/
	rectangle::set_dimensions_rectangle(h, h);
}

double square::get_area_square() const
{
	/*
	If you omitted the rectangle:: from the statement
	below, the compiler would trace up the derivation tree
	and call rectangle's get_area_rectangle function
	*/
	return rectangle::get_area_rectangle();
}

double square::get_perimeter_square() const
{
	/*
	If you omitted the rectangle:: from the statement
	below, the compiler would trace up the derivation tree
	and call rectangle's get_perimeter_rectangle function
	*/
	return rectangle::get_perimeter_rectangle();
}
int main()
{
	parallelogram p;
	rectangle r;
	square s;

	p.set_dimensions(3.0, 5.0, 5.4);
	r.set_dimensions_rectangle(4.0, 5.0);
	s.set_dimensions_square(4.0);

	cout << "Parallelogram's area: " << p.get_area() << endl;
	cout << "Parallelogram's perimeter: " << p.get_perimeter() << endl;


	cout << "Rectangle's area: " << r.get_area_rectangle() << endl;
	cout << "Rectangle's perimeter: " << r.get_perimeter_rectangle() << endl;


	cout << "Square's area: " << s.get_area_square() << endl;
	cout << "Square's perimeter: " << s.get_perimeter_square() << endl;

	return 0;
}
