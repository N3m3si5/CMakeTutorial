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
	list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()


add_executable(tutorial tutorialMain.cpp)

target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})

# at the end of cmakelists search for configuration file (include) directories
target_include_directories(tutorial PUBLIC "${PROJECT_BINARY_DIR}" ${EXTRA_INCLUDES})
