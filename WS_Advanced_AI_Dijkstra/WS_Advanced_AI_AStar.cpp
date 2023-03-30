#include <iostream>
#include "Field.h"
#include "Nodes.h"

using namespace std;

int main(int argc, char* argv[])
{
	Field* field;

	try
	{
		field = new Field();
	}
	catch(string error)
	{
		cout << error << endl;
	}

	return 0;
}