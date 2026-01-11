CXX = g++
CXXFLAGS = -Wall -Wextra -O2
SDL = `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_image

all:
	$(CXX) $(CXXFLAGS) mordhau2d.cpp $(SDL) # -o mordhau2d