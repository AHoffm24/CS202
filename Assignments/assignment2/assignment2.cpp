#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

struct automobile
{
        string make;
        string model;
        unsigned int year;
        string engine;
        string color;
};
void get_file(ifstream&, automobile[]);
void get_id(string&);
void attribute(string,unsigned int, automobile[]);
void printmake(automobile[], string);
void printmodel(automobile[], string);
void printyear(automobile[], unsigned int);
void printengine(automobile[], string);
void printcolor(automobile[], string);


const unsigned int DS_SIZE = 20;

int main(int args, char * argv[])
{
        int n = 0;
        string id; //holds user input for searching
        string info;//holds search info from user
        unsigned int car_year;  //hold year
        automobile cars[DS_SIZE];//Array of cars
        ifstream in; // input for searching inventory

        in.open(argv[1]); //attempt to open the filename given by the commandline
        if (!in.is_open()) //if file is not found
        {
                cout << "File not found!" << endl;
                in.close();
                return 0;
        }

        get_file(in, cars);//gets car data from file
        get_id(id);
        while (id != "q")
        {
                attribute(id, car_year, cars);
                get_id(id);
        }

        return 0;
}
//End of main



void get_file(ifstream& in, automobile cars[])
{
        int n = 0;
        in >> cars[n].make;

        while(in)
        {
                in >> cars[n].model;
                in >> cars[n].year;
                in >> cars[n].engine;
                in >> cars[n].color;
                n++;
                if (n == 20)
                {
                        in.close();
                        return;
                }
                in >> cars[n].make;
        }
}
void get_id(string& id)
{
        cout << "Enter Search type or 'q' to quit: ";
        cin >> id;
        int n = 0;
        n = id.length();
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
                id[i] = tolower(id[i]);
        }

}
void attribute(string id, unsigned int years, automobile cars[])
{
        string info;
        if(id == "make")
        {
                cin >> info;
                printmake(cars, info);
        }
        else if (id == "model")
        {
                cin >> info;
                printmodel(cars,info);
        }
        else if (id == "year")
        {
                cin >> years;
                printyear(cars, years);
        }
        else if (id == "engine")
        {
                cin >> info;
                printengine(cars, info);
        }
        else if (id == "color")
        {
                cin >> info;
                printcolor(cars, info);
        }
        else
        {
                cin.ignore(100, '\n');
                return;
        }

}
void printmake(automobile cars[], string info)
{
        for(int n = 0; n < DS_SIZE; n++)
        {
                if (info == cars[n].make)        {
                        cout << "Make : ";
                        cout << cars[n].make << endl;
                        cout << "Model : ";
                        cout << cars[n].model << endl;
                        cout << "Year : ";
                        cout << cars[n].year << endl;
                        cout << "Engine : ";
                        cout << cars[n].engine << endl;
                        cout << "Color : ";
                        cout << cars[n].color << endl; cout << endl;
                }
        }
        return;
}

void printmodel(automobile cars[], string info)
{
        for(int n = 0; n < DS_SIZE; n++)
        {
                if (info == cars[n].model)        {
                        cout << "Make : ";
                        cout << cars[n].make << endl;
                        cout << "Model : ";
                        cout << cars[n].model << endl;
                        cout << "Year : ";
                        cout << cars[n].year << endl;
                        cout << "Engine : ";
                        cout << cars[n].engine << endl;
                        cout << "Color : ";
                        cout << cars[n].color << endl; cout << endl;
                }
        }
        return;
}
void printyear(automobile cars[], unsigned int years)
{
        for(int n = 0; n < DS_SIZE; n++)
        {
                if (years == cars[n].year)        {
                        cout << "Make : ";
                        cout << cars[n].make << endl;
                        cout << "Model : ";
                        cout << cars[n].model << endl;
                        cout << "Year : ";
                        cout << cars[n].year << endl;
                        cout << "Engine : ";
                        cout << cars[n].engine << endl;
                        cout << "Color : ";
                        cout << cars[n].color << endl; cout << endl;
                }
        }
        return;
}
void printengine(automobile cars[], string info)
{
        for(int n = 0; n < DS_SIZE; n++)
        {
                if (info == cars[n].engine)        {
                        cout << "Make : ";
                        cout << cars[n].make << endl;
                        cout << "Model : ";
                        cout << cars[n].model << endl;
                        cout << "Year : ";
                        cout << cars[n].year << endl;
                        cout << "Engine : ";
                        cout << cars[n].engine << endl;
                        cout << "Color : ";
                        cout << cars[n].color << endl; cout << endl;
                }
        }
        return;
}
void printcolor(automobile cars[], string info)
{
        for(int n = 0; n < DS_SIZE; n++)
        {
                if (info == cars[n].color)        {
                        cout << "Make : ";
                        cout << cars[n].make << endl;
                        cout << "Model : ";
                        cout << cars[n].model << endl;
                        cout << "Year : ";
                        cout << cars[n].year << endl;
                        cout << "Engine : ";
                        cout << cars[n].engine << endl;
                        cout << "Color : ";
                        cout << cars[n].color << endl; cout << endl;
                }
        }
        return;
}
