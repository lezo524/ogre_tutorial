// init_blue_screen.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include "ExampleApplication.h"

class MeshLoadBySceneManager : public ExampleApplication
{
public:
	void createScene()
	{
		mCamera->getViewport()->setBackgroundColour(ColourValue::Blue);
		mCamera->setPosition(Vector3(0, 0, 100));
		mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));

		Entity* ent1 = mSceneMgr->createEntity("MyEntity1", "Sinbad.mesh");
		Entity* ent2 = mSceneMgr->createEntity("MyEntity2", "Sinbad.mesh");

		SceneNode* node1 = mSceneMgr->createSceneNode("Node1");
		SceneNode* node2 = mSceneMgr->createSceneNode("Node2");

		mSceneMgr->getRootSceneNode()->addChild(node1);

		node1->setPosition(10, 0, 0);
		node1->attachObject(ent1);
		node1->addChild(node2); // parent(node1) - child(node2)

		node2->setPosition(0, 10, 20);
		node2->attachObject(ent2);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	MeshLoadBySceneManager app;

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
