//
//  EGLView.h
//  Coffee
//
//  Created by Håvard Bjerke on 24/08/2017.
//
//

#pragma once

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import <GLKit/GLKViewController.h>
#import <GLKit/GLKView.h>

#include <CEAGL/eagl_types.h>

@protocol EGLAppDelegate <UIApplicationDelegate,
                          GLKViewDelegate,
                          GLKViewControllerDelegate>
@end

@interface EGLView : NSObject {
    
    
    
}
    + (EGLView*) createView;

    - (bool) createContext: (uint32_t)contextVer;

    - (bool) createView;

    - (void) dealloc;

    - (id<EGLAppDelegate>) getApp;
    - (EAGLContext*) getContext;
    - (GLKView*) getView;

@end

extern EGLView* current_view;
