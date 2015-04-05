// init_blue_screen.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include "ExampleApplication.h"

class Scale : public ExampleApplication
{
public:
	void createScene()
	{
		mCamera->setPosition(Vector3(0, 0, 100));
		mSceneMgr->setAmbientLight(ColourValue(1, 1, 1));

		// Prepare for default scale sinbad
		Entity* entNormal = mSceneMgr->createEntity("EntNormal", "Sinbad.mesh");
		SceneNode* nodeNormal = mSceneMgr->createSceneNode("NodeNormal");

		nodeNormal->setPosition(10, 10, 10);
		mSceneMgr->getRootSceneNode()->addChild(nodeNormal);
		nodeNormal->attachObject(entNormal);

		// Prepare for twice bigger than normal scale sinbad.
		Entity* entScaleTwice = mSceneMgr->createEntity("EntScaleTwice", "Sinbad.mesh");
		SceneNode* nodeScaleTwice = nodeNormal->createChildSceneNode("NodeScaleTwice");

		nodeScaleTwice->setPosition(10, 0, 0);
		nodeScaleTwice->attachObject(entScaleTwice);
		nodeScaleTwice->scale(2, 2, 2);

		// Prepare for half size than normal scale sinbad.
		Entity* entScaleHalf = mSceneMgr->createEntity("EntScaleHalf", "Sinbad.mesh");
		SceneNode* nodeScaleHalf = nodeNormal->createChildSceneNode("NodeScaleHalf", Vector3(20, 0, 0));

		nodeScaleHalf->attachObject(entScaleHalf);
		nodeScaleHalf->scale(0.5, 0.5, 0.5);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Scale app;

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
