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
    NSLog(@"EGLView::createContext");
    if(self.appDelegate)
        return YES;
    
    self.appDelegate = (__bridge id<EGLAppDelegate>)uikit_appdelegate;

    NSUInteger renderApi = kEAGLRenderingAPIOpenGLES2;
    
    if(contextVer == EGL_OPENGL_ES3_BIT)
        renderApi = kEAGLRenderingAPIOpenGLES3;

    self.eaglContext = [EAGLContext alloc];
    self.eaglContext = [self.eaglContext initWithAPI: renderApi];
    [EAGLContext setCurrentContext: self.eaglContext];
    
    return YES;
}

- (BOOL) createView
{
    NSLog(@"EGLView::createView");
    if(self.view)
        return YES;
    
    GLKView* view = [[GLKView alloc] initWithFrame:
                              [[UIScreen mainScreen] bounds]
                              context: self.eaglContext];
    
    view.drawableColorFormat = GLKViewDrawableColorFormatRGB565;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    view.drawableStencilFormat = GLKViewDrawableStencilFormat8;
    
    view.context = self.eaglContext;
    view.delegate = self.appDelegate;
    
    self.view = view;

    GLKViewController* vc = [[GLKViewController alloc] init];
    
    vc.view = view;
    vc.preferredFramesPerSecond = 60;
    
    vc.delegate = self.appDelegate;
    
    self.appDelegate.window.rootViewController = vc;

    return YES;
}

@end
