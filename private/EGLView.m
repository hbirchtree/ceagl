#import <Foundation/Foundation.h>
#import <EGLView.h>

extern void* uikit_appdelegate;

EGLView* current_view = NULL;

@implementation EGLView

+ (EGLView*) createView
{
    if(!current_view)
        current_view = [[EGLView alloc] init];
    return current_view;
}

- (BOOL) createContext:(uint32_t)contextVer
{
    if(self.appDelegate)
        return YES;
    
    self.appDelegate = (id<EGLAppDelegate>)uikit_appdelegate;

    NSUInteger renderApi = kEAGLRenderingAPIOpenGLES2;
    
    if(contextVer == EGL_OPENGL_ES3_BIT)
        renderApi = kEAGLRenderingAPIOpenGLES3;

    self.eaglContext = [[EAGLContext alloc] initWithAPI:renderApi];
    
    return YES;
}

- (BOOL) createView
{
    if(self.view)
        return YES;
    
    GLKView* view = [[GLKView alloc] initWithFrame:
                            [[UIScreen mainScreen] bounds]];
    
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    view.drawableStencilFormat = GLKViewDrawableStencilFormat8;
    
    view.context = self.eaglContext;
    view.delegate = self.appDelegate;
    
    self.view = view;
    
    GLKViewController* vc = nil;
    
    vc = [[GLKViewController alloc]
          initWithNibName: nil
          bundle:nil];
    
    vc.view = view;
    vc.preferredFramesPerSecond = 60;
    
    vc.delegate = self.appDelegate;
    
    self.appDelegate.window.rootViewController = vc;

    return YES;
}

@end
