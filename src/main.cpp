#include <windows.h>
#include <stdio.h>

#if 1
#include <gl/GL.h>
#include <gl/GLU.h>

// Taken from glext.h, might as well get and import the file in the future if needed.
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
	{
        case WM_CREATE:
		{
            PIXELFORMATDESCRIPTOR pfd =
            {
                sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
                PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
                32,                   // Colordepth of the framebuffer.
                0, 0, 0, 0, 0, 0,
                0,
                0,
                0,
                0, 0, 0, 0,
                24,                   // Number of bits for the depthbuffer
                8,                    // Number of bits for the stencilbuffer
                0,                    // Number of Aux buffers in the framebuffer.
                PFD_MAIN_PLANE,
                0,
                0, 0, 0
            };
            
            HDC ourWindowHandleToDeviceContext = GetDC(hWnd);
            
            int  letWindowsChooseThisPixelFormat;
            letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd); 
            SetPixelFormat(ourWindowHandleToDeviceContext,letWindowsChooseThisPixelFormat, &pfd);
            
            HGLRC ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
            wglMakeCurrent (ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);
            
            GLint majorVersion, minorVersion;
            glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
            glGetIntegerv(GL_MINOR_VERSION, &minorVersion);
            char sversion[50];
            sprintf(sversion, "%d: %d", (int)majorVersion, (int)minorVersion);
            MessageBoxA(0, sversion, "OPENGL VERSION INTEGER ONLY", 0);
            
            MessageBoxA(0,(char*)glGetString(GL_VERSION), "OPENGL VERSION",0);
            /*
This apparently doesn't work, should attach a command line or something.
           printf("%s\n", (char *)glGetString(GL_VERSION));
           printf("------ %c", version);
          */
            wglDeleteContext(ourOpenGLRenderingContext);
            PostQuitMessage(0);
        }
        break;
        default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
    
}

int WinMain(HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            LPSTR lpCmdLine,
            int nShowCmd )
{
    MSG msg          = {0};
    WNDCLASS wc      = {0}; 
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = "oglversionchecksample";
    wc.style = CS_OWNDC;
    if( !RegisterClass(&wc) )
        return 1;
    CreateWindowA(
        wc.lpszClassName,
        "openglversioncheck",
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        0,
        0,
        640,
        480,
        0,
        0,
        hInstance,
        0);
    
    while( GetMessage( &msg, NULL, 0, 0 ) > 0 )
        DispatchMessage( &msg );
    
    return 0;
}
#else
int main(int argc, char *argv[])
{
    printf("Hellow world!");
    int version = 0;
    //glGetIntegerv(0x821B , &version);
    char sversion[50];
    sprintf(sversion, "%d %s", version, "coba");
    //MessageBoxA(0, sversion, "OPENGL VERSION INTEGER", 0);
    printf("%s\n", sversion);
    return 0;
}

#endif