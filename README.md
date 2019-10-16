# CEAGL
Apple EAGL to EGL wrapper, for lazy people like me

# How can this be integrated?
This collection of snippets was designed to be plugged in between the `AppDelegate` and EGL code. The EGL support only extends to:

 - Giving information on the current EGL context (with some dummy information)
 - Giving you an EGL-like context for OpenGL ES execution
 - Gluing the EGL lifecycle into the `AppDelegate`
 - Creating an `EAGLContext` and `GLKView` in the background, without having to do it yourself

The current integration works as such:

 - The AppDelegate stores a pointer to itself in a global symbol `uikit_appdelegate`, which can later be accessed by the class `EGLView` when the consumer calls `eglGetDisplay()`.
 - The EGLView will be created with `EGL_OPENGL_ES2_BIT` by default, because OpenGL ES 1.0 is not useful, and the EGLView creates a context that supports OpenGL ES 2.0+ context.
 - After the context is created, you are free to call functions from the OpenGL ES framework.

# Current issues

 - Currently, you still have to make AppDelegate call out to your code for looping. This should probably remain that way.
 - Creating multiple shared/non-shared contexts is not yet supported, but migrating the context across threads should work.
 - You cannot control swapping intervals. This is enforced by iOS by default, and is probably for the best.
 - The only type of rendering surface supported is the default `GLKView` framebuffer
