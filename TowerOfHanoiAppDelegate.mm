//
//  TowerOfHanoiAppDelegate.m
//  TowerOfHanoi
//
//  Created by arjun prakash on 4/15/11.
//  Copyright 2011 bellmonde. All rights reserved.
//

#import "TowerOfHanoiAppDelegate.h"
using namespace Ogre;

@implementation TowerOfHanoiAppDelegate
- (void)applicationDidFinishLaunching:(NSNotification *)notification {
	std::string mResourcePath = [[[NSBundle mainBundle] resourcePath] cStringUsingEncoding:NSUTF8StringEncoding];
	
	// Create a new root object with the correct paths
	Root *mRoot = new Root(mResourcePath + "/plugins.cfg", mResourcePath + "/ogre.cfg",
						   mResourcePath + "/ogre.log");
	mRoot->setRenderSystem(mRoot->getAvailableRenderers().front());
	
	// Initialise without an automatically created window
    mRoot->initialise(false);
	
    // Ask for a new window passing in the ogreView in our nib file
    NameValuePairList misc;
	misc["macAPI"] = "cocoa";
    misc["externalWindowHandle"] = StringConverter::toString((size_t)mOgreView);
    mRoot->createRenderWindow("ogre window", 0, 0, false, &misc);
    RenderWindow *mWindow = [mOgreView ogreWindow];
	
	
	SceneManager *mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "My scene manager");
    
	// Add resource locations
	ResourceGroupManager::getSingleton().addResourceLocation(mResourcePath, std::string("FileSystem"), ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	
	//Basic inits
	ringSize = 3;
	[self createDisks: ringSize];
	xStart = -200;
	yStart = -100;
	compute = false;
	dataStructure = 1;
	
	
	// Create the camera, node & attach camera
	Camera *mCamera = mSceneMgr->createCamera("My camera");
	SceneNode *camNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	camNode->attachObject(mCamera);
	mWindow->addViewport(mCamera);
	//vp->setBackgroundColour(ColourValue(0.0f,0.0f,1.0f)); mCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
    
    // Create a light
    mSceneMgr->setAmbientLight(ColourValue(0, 0, 0));
    mMainLight01 = mSceneMgr->createLight("MainLight01");
	mMainLight01->setPosition(200,0,0);
    mMainLight02 = mSceneMgr->createLight("MainLight02");
	mMainLight02->setPosition(0,0,-1000);
	
    // Add a object, give it it's own node
    mObjectNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    //Entity *knot = mSceneMgr->createEntity("knot", "knot.mesh");
    Entity *knot = mSceneMgr->createEntity("knot", "knot.mesh");
    mObjectNode->attachObject(knot);
    mObjectNode->setPosition(Vector3(0, 0, -500));
	
	//create a sceneSceneNode Poles
	SceneNode *nodePollA = mSceneMgr->createSceneNode("NodeA");
	mSceneMgr->getRootSceneNode()->addChild(nodePollA);
	SceneNode *nodePollB = mSceneMgr->createSceneNode("NodeB");
	mSceneMgr->getRootSceneNode()->addChild(nodePollB);
	SceneNode *nodePollC = mSceneMgr->createSceneNode("NodeC");
	mSceneMgr->getRootSceneNode()->addChild(nodePollC);
	
	//create createEntity Polls
	Entity *poleA = mSceneMgr->createEntity("poleA", "Pole.mesh");
	nodePollA->attachObject(poleA);
	nodePollA->setScale(6.0f,6.0f,6.0f);
	nodePollA->setPosition(-200,-100,-500);
	Entity *poleB = mSceneMgr->createEntity("poleB", "Pole.mesh");
	nodePollB->attachObject(poleB);
	nodePollB->setScale(6.0f,6.0f,6.0f);
	nodePollB->setPosition(0,-100,-500);
	Entity *poleC = mSceneMgr->createEntity("poleC", "Pole.mesh");
	nodePollC->attachObject(poleC);
	nodePollC->setScale(6.0f,6.0f,6.0f);
	nodePollC->setPosition(200,-100,-500);
	
	//create a sceneNode Rings
	nodeRingA01[0] = mSceneMgr->createSceneNode("RingA00");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[0]);
	nodeRingA01[1] = mSceneMgr->createSceneNode("RingA01");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[1]);
	nodeRingA01[2] = mSceneMgr->createSceneNode("RingA02");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[2]);
	nodeRingA01[3] = mSceneMgr->createSceneNode("RingA03");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[3]);
	nodeRingA01[4] = mSceneMgr->createSceneNode("RingA04");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[4]);
	nodeRingA01[5] = mSceneMgr->createSceneNode("RingA05");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[5]);
	nodeRingA01[6] = mSceneMgr->createSceneNode("RingA06");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[6]);
	nodeRingA01[7] = mSceneMgr->createSceneNode("RingA07");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[7]);
	nodeRingA01[8] = mSceneMgr->createSceneNode("RingA08");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[8]);
	nodeRingA01[9] = mSceneMgr->createSceneNode("RingA09");
	mSceneMgr->getRootSceneNode()->addChild(nodeRingA01[9]);
	
	//create createEntity Polls
	Entity *ring01 = mSceneMgr->createEntity("ring01", "Ring01.mesh");
	nodeRingA01[0]->attachObject(ring01);
	nodeRingA01[0]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[0]->setPosition(xStart,yStart,-500);
	Entity *ring02 = mSceneMgr->createEntity("ring02", "Ring02.mesh");
	nodeRingA01[1]->attachObject(ring02);
	nodeRingA01[1]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[1]->setPosition(xStart,yStart,-500);
	Entity *ring03 = mSceneMgr->createEntity("ring03", "Ring03.mesh");
	nodeRingA01[2]->attachObject(ring03);
	nodeRingA01[2]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[2]->setPosition(xStart,yStart,-500);
	Entity *ring04 = mSceneMgr->createEntity("ring04", "Ring04.mesh");
	nodeRingA01[3]->attachObject(ring04);
	nodeRingA01[3]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[3]->setPosition(xStart,yStart,-500);
	Entity *ring05 = mSceneMgr->createEntity("ring05", "Ring05.mesh");
	nodeRingA01[4]->attachObject(ring05);
	nodeRingA01[4]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[4]->setPosition(xStart,yStart,-500);
	Entity *ring06 = mSceneMgr->createEntity("ring06", "Ring06.mesh");
	nodeRingA01[5]->attachObject(ring06);
	nodeRingA01[5]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[5]->setPosition(xStart,yStart,-500);
	Entity *ring07 = mSceneMgr->createEntity("ring07", "Ring07.mesh");
	nodeRingA01[6]->attachObject(ring07);
	nodeRingA01[6]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[6]->setPosition(xStart,yStart,-500);
	Entity *ring08 = mSceneMgr->createEntity("ring08", "Ring08.mesh");
	nodeRingA01[7]->attachObject(ring08);
	nodeRingA01[7]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[7]->setPosition(xStart,yStart,-500);
	Entity *ring09 = mSceneMgr->createEntity("ring09", "Ring09.mesh");
	nodeRingA01[8]->attachObject(ring09);
	nodeRingA01[8]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[8]->setPosition(xStart,yStart,-500);
	Entity *ring10 = mSceneMgr->createEntity("ring10", "Ring10.mesh");
	nodeRingA01[9]->attachObject(ring10);
	nodeRingA01[9]->setScale(6.0f,6.0f,6.0f);
	nodeRingA01[9]->setPosition(xStart,yStart,-500);
	
	//timer reset
	ogTimer.reset();
    // create a timer that causes OGRE to render at 50fps
    NSTimer *renderTimer = [NSTimer scheduledTimerWithTimeInterval:0.02 target:self
														  selector:@selector(renderFrame) userInfo:NULL repeats:YES];
    [[NSRunLoop currentRunLoop] addTimer:renderTimer forMode:NSEventTrackingRunLoopMode];
}

- (void)renderFrame {
	//compute = false;
	NSLog(@"computer: %d", compute);
    Ogre::Root::getSingleton().renderOneFrame();
    //mObjectNode->rotate(Vector3(0, 1, 0), Radian(0.01));
	//if (!compute) {
		if(ogTimer.getMilliseconds() > 250) {
			[self setRings];
			ogTimer.reset();
		}
	//}  
	[startButton setTitle:@"Start"];

	//NSLog(@"working %d",ringSize );
	
}

// UI link to slider
- (IBAction) ringCountAction:(id) sender {

	[ringLabel setIntValue:[sender intValue]];
	NSLog(@"ringSize %d",ringSize );
	//NSLog(@"string %@",[sender stringValue]);
	if (!compute) {
		ringSize = [sender intValue];
		[self createDisks: ringSize];
	}

	
}
// UI link to start button
- (IBAction) startGame:(id) sender {
	if (!compute) {
		compute = true;
		[startButton setTitle:@"Stop"];
		NSLog(@"Started");
		[self createDisks: ringSize];
		[self solveStruct: ringSize];
		
	}else {
		[startButton setTitle:@"Start"];
		NSLog(@"Stoped");
		ringSize = [ringLabel intValue];
			delete[] theDisks;
		[self createDisks: ringSize];
		compute = false;
	}


}

- (void) createDisks:(int) rSize {
	*theDisks[rSize];
	theDisks[1]->createArray();
	for (int i = rSize; i > 0; i--) {
		NSLog(@"%d",i);
		theDisks[i] = new Disk(i);
	}
	//set disks
	int locationCounter = rSize;
	for (int i = 1; i <= rSize; i++) {
		
		theDisks[i]->moveDisk(locationCounter, 1);
		locationCounter--;
	}
	//theDisks[1]->displayArray();
	
}
- (void) setRings {
	
	for (int i = 1; i <=ringSize; i++) {
		int xSet = [self getRingPoll:(i)];
		int ySet = ((theDisks[i]->getLocation()-1)*15) + (-100); 
		//int ySet = ((ringSize-i)*15) + (-100); 
		//int xSet = 40+j;
		//int ySet = theDisks[i]->getPole();
		NSLog(@"diskLocation: %d", ySet);
		nodeRingA01[(i-1)]->setPosition((float)xSet,(float)ySet,-500);
		
	}
	for (int i = ringSize; i < 10; i++) {
		nodeRingA01[i]->setPosition(-200,-400,-500);
	}
		theDisks[1]->displayArray();
}
- (int) getRingPoll:(int) diskNum {
	switch (theDisks[diskNum]->getPole()) {
		case 1:
			return -200;
			break;
		case 2:
			return 0;
			break;
		case 3:
			return 200;
			break;
		default:
			return 0;
			break;
	}

}

- (void) solveStruct:(int) diskNum {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	//compute = true;
	int even;
	int moveOne = 1;
    int tempMove,tempSize;
    int moveSmall, moveSmallPoll;
    int topA, topB, topC;
	Stack<int> nStackA(diskNum);
	Stack<int> nStackB(diskNum);
	Stack<int> nStackC(diskNum);
	int diskMoves = int(std::pow((float)2, (float)diskNum));
	for (int i = diskNum; i > 0; i--) {
		nStackA.push(i);
	}
	if (ringSize%2 == 0) {
		even = 1;
	} else {
		even = 0;
	}
	int i=1;
	ogTimer.reset();
	while (i < diskMoves) {
		Ogre::Root::getSingleton().renderOneFrame();
		if(ogTimer.getMilliseconds() > 400) {
		//moves		
			if ((i == 1) || (i%2 != 0)) { //disk 1 moves
			cout << "moveDisk: 1" << endl;
			if (!even) {	
				//odd disks
				if (moveOne == 1) {
					tempMove = nStackA.top();
					nStackA.pop();
					nStackC.push(tempMove);
					tempSize = nStackC.size();
					theDisks[tempMove]->moveDisk(tempSize, 3);
					moveOne = theDisks[tempMove]->getPole();
					theDisks[tempMove]->displayArray();
				} else if (moveOne == 3) {
					tempMove = nStackC.top();
					nStackC.pop();
					nStackB.push(tempMove);
					tempSize = nStackB.size();
					theDisks[tempMove]->moveDisk(tempSize, 2);
					moveOne = theDisks[tempMove]->getPole();
					theDisks[tempMove]->displayArray();
				} else if (moveOne == 2) {
					tempMove = nStackB.top();
					nStackB.pop();
					nStackA.push(tempMove);
					tempSize = nStackA.size();
					theDisks[tempMove]->moveDisk(tempSize, 1);
					moveOne = theDisks[tempMove]->getPole();
					theDisks[tempMove]->displayArray();
				}
			} else {
				//even disks
				if (moveOne == 1) {
					tempMove = nStackA.top();
					nStackA.pop();
					nStackB.push(tempMove);
					tempSize = nStackB.size();
					theDisks[tempMove]->moveDisk(tempSize, 2);
					moveOne = theDisks[tempMove]->getPole();
					theDisks[tempMove]->displayArray();
				} else if (moveOne == 2) {
					tempMove = nStackB.top();
					nStackB.pop();
					nStackC.push(tempMove);
					tempSize = nStackC.size();
					theDisks[tempMove]->moveDisk(tempSize, 3);
					moveOne = theDisks[tempMove]->getPole();
					theDisks[tempMove]->displayArray();
				} else if (moveOne == 3) {
					tempMove = nStackC.top();
					nStackC.pop();
					nStackA.push(tempMove);
					tempSize = nStackA.size();
					theDisks[tempMove]->moveDisk(tempSize, 1);
					moveOne = theDisks[tempMove]->getPole();
					theDisks[tempMove]->displayArray();
				}
				
			}
			
		} else { //all other moves
			//setSmall to largest disk
			moveSmall = ringSize;
			
			//load disk sizes into variables
			if (!nStackA.empty()) {
				topA = nStackA.top();
			} else {
				topA = 0;
			}
			if (!nStackB.empty()) {
				topB = nStackB.top();
			} else {
				topB = 0;
			}
			if (!nStackC.empty()) {
				topC = nStackC.top();
			} else {
				topC = 0;
			}
			
			//find largest smallest 
			if ((moveSmall >= topA) && ((topA != 0) && (topA != 1))) {
				moveSmall = nStackA.top();
				moveSmallPoll = theDisks[moveSmall]->getPole();
			}
			if ((moveSmall >= topB) && ((topB != 0) && (topB != 1))) {
				moveSmall = nStackB.top();
				moveSmallPoll = theDisks[moveSmall]->getPole();
			}
			if ((moveSmall >= topC) && ((topC != 0) && (topC != 1))) {
				moveSmall = nStackC.top();
				moveSmallPoll = theDisks[moveSmall]->getPole();
			}
			
			cout << "moveDisk: "<< moveSmall << endl;
			//move small disk
			//on Poll A
			if (moveSmallPoll == 1) { 
				if (moveOne == 2) {
					tempMove = nStackA.top();
					nStackA.pop();
					nStackC.push(tempMove);
					tempSize = nStackC.size();
					theDisks[tempMove]->moveDisk(tempSize, 3);
					theDisks[tempMove]->displayArray();
				} else {
					tempMove = nStackA.top();
					nStackA.pop();
					nStackB.push(tempMove);
					tempSize = nStackB.size();
					theDisks[tempMove]->moveDisk(tempSize, 2);
					theDisks[tempMove]->displayArray();
				}
				
			}
			//on Poll B
			else if (moveSmallPoll == 2) {
				if (moveOne == 1) {
					tempMove = nStackB.top();
					nStackB.pop();
					nStackC.push(tempMove);
					tempSize = nStackC.size();
					theDisks[tempMove]->moveDisk(tempSize, 3);
					theDisks[tempMove]->displayArray();
				} else {
					tempMove = nStackB.top();
					nStackB.pop();
					nStackA.push(tempMove);
					tempSize = nStackA.size();
					theDisks[tempMove]->moveDisk(tempSize, 1);
					theDisks[tempMove]->displayArray();
				}
				
			}
			//on Poll C
			else if (moveSmallPoll == 3) {
				if (moveOne == 1) {
					tempMove = nStackC.top();
					nStackC.pop();
					nStackB.push(tempMove);
					tempSize = nStackB.size();
					theDisks[tempMove]->moveDisk(tempSize, 2);
					theDisks[tempMove]->displayArray();
				} else {
					tempMove = nStackC.top();
					nStackC.pop();
					nStackA.push(tempMove);
					tempSize = nStackA.size();
					theDisks[tempMove]->moveDisk(tempSize, 1);
					theDisks[tempMove]->displayArray();
				}
				
			}
			
		}
			[self setRings];
			i++;
			ogTimer.reset();
		}
	}//Loop end
	compute = false;
	[self createDisks: ringSize];
	//[startButton setTitle:@"Start"];
	NSLog(@"this is the end of the solveStack");
	[pool drain];
	
}
- (void) solveQueue:(int) diskNum {
	//TODO:implemnt
}

- (void) setCompte {
	if (compute) {
		compute = false;
	} else {
		compute = true;
	}

}
@end
