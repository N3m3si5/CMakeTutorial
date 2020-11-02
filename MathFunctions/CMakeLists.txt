add_library(MathFuntions mysqrt.cpp MathFunctions.h)

# INTERFACE things that consumers require but he producer does not
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

## INSTALL target
install(TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)