//
//  AppController.h
//  cocos2d-ios
//
//  Created by Ricardo Quesada on 12/17/11.
//  Copyright (c) 2011 Sapus Media. All rights reserved.
//
#import <Foundation/Foundation.h>

#import "cocos2d.h"

#ifdef __CC_PLATFORM_IOS


@class UIWindow, UINavigationController;

@interface BaseAppController : NSObject <UIApplicationDelegate, CCDirectorDelegate>
{
	UIWindow *window_;
	UINavigationController *navController_;

	BOOL			useRetinaDisplay_;
	CCDirectorIOS	*director_;							// weak ref
}

@property (nonatomic, retain) UIWindow *window;
@property (readonly) UINavigationController *navController;
@property (readonly) CCDirectorIOS *director;

@end

#elif defined(__CC_PLATFORM_MAC)

#import <Cocoa/Cocoa.h>
#import "ThoMoServerStub.h"

@class SMLTextView;
@class MGSFragaria;

@interface BaseAppController : NSObject <NSApplicationDelegate, ThoMoServerDelegateProtocol>
{
	NSWindow		*window_;
	CCGLView		*glView_;
	CCDirectorMac	*director_;							// weak ref
    ThoMoServerStub *thoMoServer;
}

@property (nonatomic, assign) IBOutlet NSWindow	*window;
@property (nonatomic, assign) IBOutlet CCGLView	*glView;
@property (nonatomic, readonly) CCDirectorMac	*director;

- (IBAction)toggleFullScreen:(id)sender;

- (void)initThoMoServer;

@end
#endif // __CC_PLATFORM_MAC
