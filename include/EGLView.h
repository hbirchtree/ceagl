//
//  EGLView.h
//  Coffee
//
//  Created by Håvard Bjerke on 24/08/2017.
//
//

#pragma once

#import <objective_coffee/protocols/eglappdelegate.h>

#include <CEAGL/eagl_types.h>

@interface EGLView : NSObject

@property (retain) id<EGLAppDelegate> appDelegate;
@property (retain) EAGLContext* eaglContext;
@property (retain) GLKView* view;

+ (EGLView*) createView;

- (BOOL) createContext: (uint32_t)contextVer;
- (BOOL) createView;

@end

extern EGLView* current_view;
