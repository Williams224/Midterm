all:
	g++ -c -std=c++11 `root-config --cflags` MakePlots.cpp Comparison.cpp ComparableObject.cpp FiveSimRun.cpp SixSimRun.cpp
	g++ -o MakePlots `root-config --glibs` MakePlots.o Comparison.o ComparableObject.o FiveSimRun.o SixSimRun.o
