all:
	g++ -c `root-config --cflags` MakePlots.cpp ComparableObject.cpp FiveSimRun.cpp
	g++ -o MakePlots `root-config --glibs` MakePlots.o ComparableObject.o FiveSimRun.o
