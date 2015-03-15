// init_blue_screen.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include "ExampleApplication.h"

class RotatePitchYawRoll : public ExampleApplication
{
public:
	void createScene()
	{
		mCamera->setPosition(Vector3(0, 0, 100));
		mSceneMgr->setAmbientLight(ColourValue(1, 1, 1));

		// Create Sinbad
		Entity* entBasis = mSceneMgr->createEntity("EntBasis", "Sinbad.mesh");
		Entity* entPitch = mSceneMgr->createEntity("EntPitch", "Sinbad.mesh");
		Entity* entYaw = mSceneMgr->createEntity("EntYaw", "Sinbad.mesh");
		Entity* entRoll = mSceneMgr->createEntity("EntRoll", "Sinbad.mesh");

		// Create Scene Node
		SceneNode* nodeBasis = mSceneMgr->createSceneNode("NodeBasis");
		SceneNode* nodePitch = mSceneMgr->createSceneNode("NodePitch");
		SceneNode* nodeYaw = mSceneMgr->createSceneNode("NodeYaw");
		SceneNode* nodeRoll = mSceneMgr->createSceneNode("NodeRoll");

		// Add all node to root scene node
		mSceneMgr->getRootSceneNode()->addChild(nodeBasis);
		mSceneMgr->getRootSceneNode()->addChild(nodePitch);
		mSceneMgr->getRootSceneNode()->addChild(nodeYaw);
		mSceneMgr->getRootSceneNode()->addChild(nodeRoll);

		// Attach all entity to scene node
		nodeBasis->attachObject(entBasis);
		nodePitch->attachObject(entPitch);
		nodeYaw->attachObject(entYaw);
		nodeRoll->attachObject(entRoll);

		// 신바드 위치에 따른 회전 결과 예
		// [BASIS(기준)] [PITCH 90'] [YAW 90'] [ROLL 90']
		
		// NO ROTATE
		nodeBasis->setPosition(0, 0, 0);

		// ROTATE PITCH 90'
		Quaternion qPitch(Degree(90), Vector3(1, 0, 0));
		nodePitch->setPosition(10, 0, 0);
		nodePitch->rotate(qPitch);

		// ROTATE YAW
		Quaternion qYaw(Degree(90), Vector3(0, 1, 0));
		nodeYaw->setPosition(20, 0, 0);
		nodeYaw->rotate(qYaw);

		// ROTATE ROLL
		Quaternion qRoll(Degree(90), Vector3(0, 0, 1));
		nodeRoll->setPosition(30, 0, 0);
		nodeRoll->rotate(qRoll);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	RotatePitchYawRoll app;

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
