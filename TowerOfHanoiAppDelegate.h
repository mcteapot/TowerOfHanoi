//
//  TowerOfHanoiAppDelegate.h
//  TowerOfHanoi
//
//  Created by arjun prakash on 4/15/11.
//  Copyright 2011 bellmonde. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Ogre/Ogre.h>
#import <Ogre/OSX/OgreOSXCocoaView.h>
#include <math.h>
#include "Disk.h"
#include "Stack.h"

@interface TowerOfHanoiAppDelegate : NSObject <NSApplicationDelegate> {
	//Links view to Ogre
    IBOutlet OgreView *mOgreView;
	//Cocoa Inits
	IBOutlet NSTextField *ringLabel;
	//IBOutlet UILabel *display;
	//Ogre Inits
	Ogre::SceneNode *mObjectNode;
    Ogre::Light *mMainLight;
	Ogre::Timer ogTimer;
	//Ogre nodeScene
	Ogre::SceneNode *nodeRingA01[10];
	int ringSize;
	float xStart, yStart;
	bool compute;
	Disk *theDisks[];
}

- (IBAction) ringCountAction:(id) sender;

- (void) createDisks:(int) rSize;

- (void) setRings;
- (int) getRingPoll:(int) diskNum;
- (void) solveStruct:(int) diskNum;
- (bool) solveQueue:(int) diskNum;
@end

