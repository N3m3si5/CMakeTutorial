# official tutorial
# https://cmake.org/cmake/help/latest/guide/tutorial/index.html

cmake_minimum_required(VERSION 3.10)

# project name
project(BS-tutorial VERSION 1.0)
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

configure_file(TutorialConfig.h.in TutorialConfig.h)

# OPTIONS
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# flags to set before add_executable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add subdirectory
if(USE_MYMATH)
	add_subdirectory(MathFunctions)
	list(APPEND EXTRA_LIBS MathFunctions)	## TODO: does not link properly ATM
endif()


add_executable(tutorial tutorialMain.cpp)

target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})

# at the end of cmakelists search for configuration file (include) directories
target_include_directories(tutorial PUBLIC "${PROJECT_BINARY_DIR}")



## INSTALL targets
install(TARGETS tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)


# basic testing
enable_testing()

# does the app run?
add_test(NAME Runs COMMAND tutorial 25)

# does the usage message work?
add_test(NAME Usage COMMAND tutorial)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

# define a function to simply adding tests
function(do_test target arg result)
	add_test(NAME Comp${arg} COMMAND ${target} ${arg})
	set_tests_properties( Comp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result} )
endfunction(do_test)

# do a bunch of result based tests
do_test(tutorial 4 "4 is 2")
do_test(tutorial 9 "9 is 3")
do_test(tutorial 5 "5 is 2.236")
do_test(tutorial 7 "7 is 2.645")
do_test(tutorial 25 "25 is 5")
do_test(tutorial -25 "-25 is [-nan|nan|0]")
do_test(tutorial 0.0001 "0.0001 is 0.01")
