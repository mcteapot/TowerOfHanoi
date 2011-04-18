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
	IBOutlet NSButton *startButton;
	//IBOutlet UILabel *display;
	//Ogre Inits
	Ogre::SceneNode *mObjectNode;
    Ogre::Light *mMainLight01;
    Ogre::Light *mMainLight02;
	Ogre::Timer ogTimer;
	//Ogre nodeScene
	Ogre::SceneNode *nodeRingA01[10];
	int ringSize;
	float xStart, yStart;
	bool compute;
	int dataStructure;
	Disk *theDisks[];
}

- (IBAction) ringCountAction:(id) sender;
- (IBAction) startGame:(id) sender;

- (void) createDisks:(int) rSize;

- (void) setRings;
- (int) getRingPoll:(int) diskNum;
- (void) solveStruct:(int) diskNum;
- (void) solveQueue:(int) diskNum;
- (void) setCompte;
@end

