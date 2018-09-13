@echo off

IF NOT EXIST build\windows mkdir build\windows
pushd build\windows
cl -I ..\..\include\ -Zi ..\..\src\main.cpp ..\..\src\shaders.cpp  /EHsc /link /incremental:no /LIBPATH:..\..\lib\ glew32s.lib glew32.lib glut32.lib FreeImage.lib 
popd