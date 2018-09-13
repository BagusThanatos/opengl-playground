#define GLEW_STATIC

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    GLenum err = glewInit();
    
    if(GLEW_OK != err) {
        printf("ERROR OCCURED!!!!\n");
        return 1;
    }
    
    int version;
    glGetIntegerv(GL_MAJOR_VERSION, &version);
    const char* sversion = (const char*) glGetString(GL_VERSION);
    
    printf("%d\n", version);
    printf("%s", sversion);
    
    printf("coba\n");
    return 0;
}

