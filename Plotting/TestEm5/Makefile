#all:
#	g++ -c -std=c++11 `root-config --cflags` MakePlots.cpp Comparison.cpp ComparableObject.cpp FiveSimRun.cpp SixSimRun.cpp
#	g++ -o MakePlots `root-config --glibs` MakePlots.o Comparison.o ComparableObject.o FiveSimRun.o SixSimRun.o
all:
	g++ -c -std=c++11 -I/Users/Tim/PhD/RootImprover/Include `root-config --cflags`  MakePlots.cpp ComparableObject.cpp Comparison.cpp
	g++ -o MakePlots `root-config --glibs` -L/Users/Tim/PhD/RootImprover/lib/ -lMyOther -lMyRootExtras MakePlots.o ComparableObject.o Comparison.o
