// init_blue_screen.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include "ExampleApplication.h"

class RelativeTranslate : public ExampleApplication
{
public:
	void createScene()
	{
		mCamera->setPosition(Vector3(0, 0, 100));
		mSceneMgr->setAmbientLight(ColourValue(1, 1, 1));

		// 월드 중심(ROOT)
		Ogre::Entity* ent0 = mSceneMgr->createEntity("MyEntity0", "Sinbad.mesh");
		Ogre::SceneNode* node0 = mSceneMgr->getRootSceneNode()->createChildSceneNode("node0");
		node0->attachObject(ent0);

		// PARENT NODE
		Ogre::Entity* ent1 = mSceneMgr->createEntity("MyEntity1", "Sinbad.mesh");
		Ogre::SceneNode* node1 = mSceneMgr->createSceneNode("Node1");
		mSceneMgr->getRootSceneNode()->addChild(node1);
		node1->attachObject(ent1);
		node1->yaw(Ogre::Degree(180));
		node1->setPosition(30, 0, 30);

		// CHILD - translate LOCAL
		Ogre::Entity* ent2 = mSceneMgr->createEntity("MyEntity2", "Sinbad.mesh");
		Ogre::SceneNode* node2 = node1->createChildSceneNode("node2");
		node2->attachObject(ent2);
		node2->yaw(Ogre::Degree(-45));
		node2->translate(0, 0, 40, Ogre::Node::TS_LOCAL);

		// CHILD - translate PARENT
		Ogre::Entity* ent3 = mSceneMgr->createEntity("MyEntity3", "Sinbad.mesh");
		Ogre::SceneNode* node3 = node1->createChildSceneNode("node3");
		node3->attachObject(ent3);
		node3->yaw(Ogre::Degree(-45));
		node3->translate(0, 0, 40, Ogre::Node::TS_PARENT);

		// CHILD - translate WORLD coordinate
		Ogre::Entity* ent4 = mSceneMgr->createEntity("MyEntity4", "Sinbad.mesh");
		Ogre::SceneNode* node4 = node1->createChildSceneNode("node4");
		node4->attachObject(ent4);
		node4->yaw(Ogre::Degree(-45));
		node4->translate(0, 0, 40, Ogre::Node::TS_WORLD);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	RelativeTranslate app;

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
