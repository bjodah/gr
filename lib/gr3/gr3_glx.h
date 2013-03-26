#ifndef GR3_GLX_H_INCLUDED
#define GR3_GLX_H_INCLUDED


#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glx.h>
#include <unistd.h> /* for getpid() for tempfile names */

#if GL_VERSION_2_1
#define GR3_CAN_USE_VBO
#endif

#if !(GL_ARB_framebuffer_object || GL_EXT_framebuffer_object)
#error "Neither GL_ARB_framebuffer_object nor GL_EXT_framebuffer_object \
are supported!"
#endif

#ifdef GR3_GLX_C
#define GLFUNC
#else
#define GLFUNC extern
#endif

#ifdef GR3_CAN_USE_VBO
GLFUNC PFNGLBUFFERDATAPROC glBufferData;
GLFUNC PFNGLBINDBUFFERPROC glBindBuffer;
GLFUNC PFNGLGENBUFFERSPROC glGenBuffers;
GLFUNC PFNGLGENBUFFERSPROC glDeleteBuffers;
GLFUNC PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
GLFUNC PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
GLFUNC PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
GLFUNC PFNGLUSEPROGRAMPROC glUseProgram;
GLFUNC PFNGLDELETESHADERPROC glDeleteShader;
GLFUNC PFNGLLINKPROGRAMPROC glLinkProgram;
GLFUNC PFNGLATTACHSHADERPROC glAttachShader;
GLFUNC PFNGLCREATESHADERPROC glCreateShader;
GLFUNC PFNGLCOMPILESHADERPROC glCompileShader;
GLFUNC PFNGLCREATEPROGRAMPROC glCreateProgram;
GLFUNC PFNGLDELETEPROGRAMPROC glDeleteProgram;
GLFUNC PFNGLUNIFORM3FPROC glUniform3f;
GLFUNC PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
GLFUNC PFNGLUNIFORM4FPROC glUniform4f;
GLFUNC PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
GLFUNC PFNGLSHADERSOURCEPROC glShaderSource;
#endif
GLFUNC PFNGLDRAWBUFFERSPROC glDrawBuffers;
#ifdef GL_ARB_framebuffer_object
GLFUNC PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
GLFUNC PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
GLFUNC PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
GLFUNC PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
GLFUNC PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
GLFUNC PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
GLFUNC PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
GLFUNC PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
GLFUNC PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
#endif
#ifdef GL_EXT_framebuffer_object
GLFUNC PFNGLBINDRENDERBUFFEREXTPROC glBindRenderbufferEXT;
GLFUNC PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXT;
GLFUNC PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXT;
GLFUNC PFNGLRENDERBUFFERSTORAGEEXTPROC glRenderbufferStorageEXT;
GLFUNC PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT;
GLFUNC PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXT;
GLFUNC PFNGLGENRENDERBUFFERSEXTPROC glGenRenderbuffersEXT;
GLFUNC PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXT;
GLFUNC PFNGLDELETERENDERBUFFERSEXTPROC glDeleteRenderbuffersEXT;
#endif


int  gr3_initGL_GLX_(void);
void gr3_terminateGL_GLX_Pbuffer_(void);
void gr3_terminateGL_GLX_Pixmap_(void);

#endif
