cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(TMVA)

include(CheckCXXCompilerFlag)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    check_cxx_compiler_flag(-std=c++11 HAS_GNUSTYLE_CPP11)
    if(HAS_GNUSTYLE_CPP11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
	endif()
			
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors -Wall -Wextra -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-gnu-keywords -fstrict-aliasing") 
   
       if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors -Wall -Wextra -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-gnu-keywords -fstrict-aliasing")

	endif()
endif()



include_directories(/Users/Tim/root-v5-34/include/ /Users/Tim/root-v5-34/tmva/inc/TMVA /Users/Tim/PhD/RootImprover/Include /Users/Tim/PhD/Midterm/Plotting/FakeBDT/Include)
link_directories(/Users/Tim/root-v5-34/lib/)

add_subdirectory(Include)

add_executable(BDT TMVA.cpp)

target_link_libraries(BDT BDTlib MyTMVA MyRootExtras Graf Core Gpad MathCore RIO Tree Hist TMVA )

install(TARGETS BDT DESTINATION bin)

include(CPack)
