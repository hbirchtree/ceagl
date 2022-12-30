#pragma once

/*
 * If you've come here, then I welcome you to hell!
 * This is a wrapper around Apple's EAGL API.
 *
 */

#include <stdint.h>
#include "eagl_types.h"

typedef void* EGLDisplay;
typedef void* EGLConfig;
typedef void* EGLSurface;
typedef void* EGLContext;

typedef void* EGLNativeDisplayType;
typedef void* EGLNativeWindowType;

typedef int32_t EGLint;
typedef uint32_t EGLuint;
typedef EGLint EGLboolean;

// Setup
EGLDisplay eglGetDisplay(EGLNativeDisplayType nativeDisplay);
EGLboolean eglInitialize(EGLDisplay display, void*, void*);

// Queries
EGLboolean eglQuerySurface(EGLDisplay display, EGLSurface surface,
                           EGLint attr, EGLint* value);
const char* eglQueryString(EGLDisplay display, EGLint attr);

// Setup
EGLboolean eglGetConfigAttrib(EGLDisplay display, EGLConfig cfg,
                              EGLint attr,
                              EGLint* value);
EGLboolean eglChooseConfig(EGLDisplay disp, EGLint const* preferred,
                           EGLConfig* config, EGLint numConfigs,
                           EGLint* pnumConfigs);
void* eglGetProcAddress(const char* name) { return nullptr; }

EGLDisplay eglGetCurrentDisplay();

// Constructors
EGLContext eglCreateContext(EGLDisplay display, EGLConfig cfg,
                            EGLContext share, EGLint const* cfg_pref);
EGLSurface eglCreateWindowSurface(EGLDisplay display, EGLConfig cfg,
                                  EGLNativeWindowType window,
                                  EGLint const* attrs);

// Processing
EGLboolean eglSwapBuffers(EGLDisplay display, EGLSurface surface);
EGLboolean eglSwapInterval(EGLDisplay display, EGLint interval);

EGLboolean eglMakeCurrent(EGLDisplay display, EGLSurface surfaceDraw,
                          EGLSurface surfaceRead, EGLContext context);


// Destructors
EGLboolean eglDestroySurface(EGLDisplay display, EGLSurface surface);
EGLboolean eglDestroyContext(EGLDisplay display, EGLContext context);

EGLboolean eglTerminate(EGLDisplay display);

EGLint eglGetError(void);


#define EGL_NO_CONTEXT nullptr
#define EGL_NO_SURFACE nullptr
#define EGL_NO_DISPLAY nullptr

#define EGL_DEFAULT_DISPLAY nullptr

#define EGL_VERSION_1_0
#define EGL_VERSION_1_1
#define EGL_VERSION_1_2
#define EGL_VERSION_1_3

#define EGL_SUCCESS             0x0000
#define EGL_BAD_ACCESS          0x0101
#define EGL_BAD_ALLOC           0x0102
#define EGL_BAD_ATTRIBUTE       0x0103
#define EGL_BAD_CONFIG          0x0104
#define EGL_BAD_CONTEXT         0x0105
#define EGL_BAD_CURRENT_SURFACE 0x0106
#define EGL_BAD_DISPLAY         0x0107
#define EGL_BAD_MATCH           0x0108
#define EGL_BAD_NATIVE_PIXMAP   0x0109
#define EGL_BAD_NATIVE_WINDOW   0x0110
#define EGL_BAD_PARAMETER       0x0111
#define EGL_BAD_SURFACE         0x0112

#define EGL_NOT_INITIALIZED     0x0101
