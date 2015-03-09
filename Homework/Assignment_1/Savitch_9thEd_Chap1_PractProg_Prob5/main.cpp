#include <iostream>
using namespace std;
int main()
{
	int width,height,tLength;
	cout<< "This program finds the length of fence needed to cover a rectangular area.\n";
	cout<< "Enter the width of the rectangle in feet: \n";
	cin >> width;
	cout << "Enter the height of the rectangle in feet:\n";
	cin >> height;
	tLength= 2*width + 2*height;
	cout << "If the rectangle is ";
	cout << width;
	cout << " feet wide ";
	cout << "and ";
	cout << height;
	cout << " height tall then \n";
	cout << "you need ";
	cout << tLength;
	cout << " feet of fence.\n";
	return 0;
	}