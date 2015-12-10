#include <iostream>
#include <string> 
#include "text.h"
#include "point.h" 

using namespace std; 

Text::Text(string t, Point p):out{t}, position{p}
{
	cout << out << endl; 
}

