all:
	g++ -c `root-config --cflags` MakePlots.cpp ComparableObject.cpp FiveSimRun.cpp SixSimRun.cpp
	g++ -o MakePlots `root-config --glibs` MakePlots.o ComparableObject.o FiveSimRun.o SixSimRun.o
