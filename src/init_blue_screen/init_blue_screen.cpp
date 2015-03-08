// init_blue_screen.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include "ExampleApplication.h"

class BlueScreen : public ExampleApplication
{
public:
	void createScene()
	{
		mCamera->getViewport()->setBackgroundColour(ColourValue::Blue);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	BlueScreen app;

	try
	{
		app.go();
	}
	catch (Ogre::Exception& e)
	{
		MessageBoxA(NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
		//cerr << "An exception has occured: " << e.getFullDescription().c_str() << endl;
	}

	return 0;
}
