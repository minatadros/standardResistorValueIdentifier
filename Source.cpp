#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void dispayHeader();
void colorCode();
void valueChecker(char, float&, bool&);
void deCoding(float, float, float, float&, string&);
void cont(char, bool&);



int main() {

	char name[20], character = 'y';
	float firstLetter, secondLetter, thirdLetter, resistor;
	bool  yes_no = true; // is an on/off switch to while loop
	string unit;
	

	

	

	while (yes_no == true)
	{
		dispayHeader();	// function to display header
		cout << endl;
		colorCode();	// function to display the color code
		cout << endl;
		
		bool x = false, y = false, z = false;
	

		while (x == false || y == false || z == false)
		{
			cout << "Enter three valid color codes from the above menu: ";
			cin >> name;

			if (strlen(name) == 3)
			{
				valueChecker(name[0], firstLetter, x);
				valueChecker(name[1], secondLetter, y);
				valueChecker(name[2], thirdLetter, z);

				if (x == true && y == true && z == true)
				{
					deCoding(firstLetter, secondLetter, thirdLetter, resistor, unit); // doing the calculation for the decoded numbers 

					cout << endl;
					cout << "		=================================" << endl;
					cout << "		Resistance value: " << resistor << " " << unit << endl;
					cout << "		=================================" << endl;
					cout << endl;
					cont(character, yes_no);
				}
				else if (x == false || y == false || z == false)
				{
					cout << "Invalid entry!!!" << endl;
				}
			}
			else
			{
				cout << "Invalid entry!!!" << endl;
				x = false;
			}

		}
		
		
	}

}

void dispayHeader()
{
	cout << "	*************************************************\n";
	cout << "	Coen 243 Team Project: Evaluate the Value of a\n";
	cout << "			 Resistor from its Color Code		  \n";
	cout << "			Programmer: Tadros, Mina				  \n";
	cout << "			   Date of Submission:			      \n";
	cout << "	*************************************************\n";
}

void colorCode()
{
	cout << "Resistor Color Code (RCC) Menu Desk\n";
	cout << "===================================\n";
	cout << "		Color and Value Code		\n";
	cout << "		--------------------		\n";
	cout << "		Black (0) ----> B			\n";
	cout << "		Brown (1) ----> N			\n";
	cout << "		Red   (2) ----> R			\n";
	cout << "		Orange(3) ----> O			\n";
	cout << "		Yellow(4) ----> Y			\n";
	cout << "		Green (5) ----> G			\n";
	cout << "		Blue  (6) ----> E			\n";
	cout << "		Violet(7) ----> V			\n";
	cout << "		Gray  (8) ----> A			\n";
	cout << "		White (9) ----> W			\n";
	cout << "===================================\n";
	cout << "[Note: The letters are case insensitive]\n";
}

void valueChecker(char a, float& d, bool& on )
{
	switch (a)
	{
		case ('b'):
		case ('B'):
		on = true, d = 0; break;
		case ('n'): 
		case ('N'):
		on = true, d = 1; break;
		case ('r'):
		case ('R'):
		on = true, d = 2; break;
		case ('o'): 
		case ('O'):
		on = true, d = 3; break;
		case ('y'):
		case ('Y'):
		on = true, d = 4; break;
		case ('g'): 
		case ('G'):
		on = true, d = 5; break;
		case ('e') :
		case ('E') :
		on = true, d = 6; break;
		case ('v') :
		case ('V') :
		on = true, d = 7; break;
		case ('a') :
		case ('A') :
		on = true, d = 8; break;
		case ('w') :
		case ('W') :
		on = true, d = 9; break;
		default:
			on = false;


	}
}

void deCoding(float a, float b, float c, float& r, string& u)
{
	r = (((a * 10) + b) * pow(10, c));

	if (r >= 1000000000)
	{
		r = r / 1000000000;
		u = "Giga ohm";
	}
	else if (r >= 1000000)
	{
		r = r / 1000000;
		u = "Mega ohm";
	}
	else if (r >= 1000)
	{
		r = r / 1000;
		u = "Kilo ohm";
	}
	else
	{
		r = r;
		u = "ohm";
	}

}


void cont( char ch,  bool& on_off)
{
	cout << "Do you want to continue?" << endl;
	cout << "(Press 'y' and hit Enter for ""yes"", and any other key and hit enter to Quit)? ";
	cin >> ch;
	cout << endl;
	if (ch == 'y' || ch == 'Y')
	{
		on_off = true;
	}
	else
	{
		on_off = false;
		cout << "		******************************************* \n		Good bye from the desk of resistance menu!! \n		*******************************************" << endl;
	}

}