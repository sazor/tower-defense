ANGEL_DISABLE_FMOD := $(shell sed -rn 's/^[[:space:]]*\#define[[:space:]]+ANGEL_DISABLE_FMOD[[:space:]]+([[:digit:]])[[:space:]]*$$/\1/p' ../Angel/AngelConfig.h)
ANGEL_DISABLE_DEVIL := $(shell sed -rn 's/^[[:space:]]*\#define[[:space:]]+ANGEL_DISABLE_DEVIL[[:space:]]+([[:digit:]])[[:space:]]*$$/\1/p' ../Angel/AngelConfig.h)
CXX = g++
TARGET = TowerDefense
ANGEL_FLAGS = -D ANGEL_RELEASE
ARCH := $(shell uname -m)
ALLEGRO_LIBS := $(shell allegro-config --libs 2>/dev/null)
CWD := $(shell pwd)
CODE_DIR := $(shell dirname "$(CWD)")
LIBANGEL = ../Angel/libangel.a
LUA = ../Angel/Libraries/angel-lua-build/lua
WRAPPER = ../Angel/Scripting/Interfaces/AngelLuaWrapping.cpp

INCLUDE = 							\
	-I.							\
	-I./Game						\
	-I../Angel						\
	-I../Angel/Libraries/glfw-3.0.3/include			\
	-I../Angel/Libraries/Box2D-2.2.1			\
	-I../Angel/Libraries/FTGL/include			\
	-I../Angel/Libraries/lua-5.2.1/src			\
	-I/usr/include/freetype2
ifneq ($(ANGEL_DISABLE_FMOD),1)
	INCLUDE += -I../Angel/Libraries/FMOD/inc
endif

LIBS = 									\
	$(LIBANGEL)							\
	../Angel/Libraries/glfw-3.0.3/src/libglfw3.a			\
	../Angel/Libraries/Box2D-2.2.1/Build/Box2D/libBox2D.a		\
	../Angel/Libraries/FTGL/unix/src/.libs/libftgl.a		\
	../Angel/Libraries/gwen/lib/linux/gmake/libgwen_static.a	\
	../Angel/Libraries/angel-lua-build/liblua.a

ifneq ($(ANGEL_DISABLE_FMOD),1)
	ifeq ($(ARCH),x86_64)
		LIBS += ../Angel/Libraries/FMOD/lib/libfmodex64.so
	else
		LIBS += ../Angel/Libraries/FMOD/lib/libfmodex.so
	endif
endif

SHLIBS = -lGL -lGLU -ldl -lfreetype -lXrandr -lX11 -lpthread -lrt -lXxf86vm -lXi
SHLIBS += $(ALLEGRO_LIBS)
ifeq ($(ANGEL_DISABLE_FMOD),1)
	SHLIBS += -lopenal -lvorbisfile
endif
ifneq ($(ANGEL_DISABLE_DEVIL),1)
	SHLIBS += -lIL -lILU -lILUT
else
	SHLIBS += -lpng
endif

SYSSRCS = 							\
	$(WRAPPER)

SRCS =								\
	GameApp.cpp					\
	Game/Castle.cpp			\
	Game/Enemy.cpp			\
	Game/Characteristics.cpp			\
	Game/Deceleration.cpp	\
	Game/Effect.cpp			\
	Game/Container.cpp \
	Game/Lair.cpp	\
	Game/Level.cpp		\
	Game/Tower.cpp			\
	Game/MagicTower.cpp		\
	Game/Poisoning.cpp		\
	Game/StandartTower.cpp			\
	Game/Trap.cpp			\
	Game/Weakness.cpp			\
	stdafx.cpp						\
	Main.cpp

SYSOBJS = $(patsubst %.cpp,%.o,$(SYSSRCS))
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

.PHONY: clean all SWIG-Wrapper

%.o: %.cpp
	$(CXX) -c $(INCLUDE) -Wno-write-strings -Wno-deprecated -std=gnu++0x -pthread -o $@ $^ 

all: $(TARGET)

publish: $(TARGET)
	$(LUA) ../Tools/BuildScripts/publish_linux.lua -i $(CWD) -e $(TARGET) -g TowerDefense

SWIG-Wrapper:
	$(LUA) ../Tools/BuildScripts/swig_wrap.lua -p "$(CODE_DIR)" -D TOWERDEFENSE

$(WRAPPER): SWIG-Wrapper

$(TARGET): $(LIBANGEL) $(OBJS) $(SYSOBJS) $(WRAPPER)
	$(CXX) -o $@ $(OBJS) $(SYSOBJS) $(LIBS) $(SHLIBS) $(ANGEL_FLAGS)
	cp -p ../Angel/Scripting/EngineScripts/*.lua Resources/Scripts

clean:
	rm -f $(OBJS) $(SYSOBJS) $(TARGET) $(WRAPPER) 

$(LIBANGEL):
	cd ../Angel && make
