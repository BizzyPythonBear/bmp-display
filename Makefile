OBJS = main.cpp
OBJ_NAME = bmpdis

all : $(OBJS)
	g++ $(OBJS) -IC:\dev\SDL2_MinGW_32\include -LC:\dev\SDL2_MinGW_32\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o $(OBJ_NAME)