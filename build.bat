@echo off

IF NOT EXIST build\windows mkdir build\windows
pushd build\windows
cl -I ..\..\include\ -Zi ..\..\src\main.cpp ..\..\src\shaders.cpp  /EHsc /link /incremental:no /LIBPATH:..\..\lib\ glew32.lib FreeImage.lib glew32s.lib glut32.lib
popd