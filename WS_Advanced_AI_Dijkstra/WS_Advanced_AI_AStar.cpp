#include <iostream>
#include "Field.h"
#include "Nodes.h"
#include "SDLField.h"

using namespace std;

int main(int argc, char* argv[])
{
	Field* field = nullptr;
	SDLField* sdlField = nullptr;

	try
	{
		field = new Field();
		sdlField = new SDLField(field);
	}
	catch(string& error)
	{
		cout << error << endl;
		return -1;
	}

	while (sdlField->IsRunning())
	{
		sdlField->Update();
	}

	/*while (!field->IsCompleted())
	{
		field->Step();
	}*/
	//cout << "Shortest path is " << field->GetShortestPathNodes().size() << " steps" << endl;

	delete sdlField;
	delete field;

	return 0;
}