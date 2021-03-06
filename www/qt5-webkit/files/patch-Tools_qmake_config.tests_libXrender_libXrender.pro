Setting OBJECTS_DIR to "obj" causes problems with make(1), as "obj" is one of
the directories make tries to enter in case it exists (because of .OBJDIR).
Since qmake will create it because of OBJECTS_DIR, make will invoke the
compiler from there and fail because it's trying to pass "-o obj/foo.o" while
already in obj/.

--- Tools/qmake/config.tests/libXrender/libXrender.pro.orig	2016-09-26 14:56:47 UTC
+++ Tools/qmake/config.tests/libXrender/libXrender.pro
@@ -1,3 +1,2 @@
 SOURCES = libXrender.cpp
-OBJECTS_DIR = obj
 LIBS += -lXrender -lX11
