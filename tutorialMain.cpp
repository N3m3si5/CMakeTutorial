/**
  * CMake tutorial
  * source: https://cmake.org/cmake/help/latest/guide/tutorial/index.html#build-and-test
  * @author Christian Luca L&uumltzenkirchen
  * 
  */

#include <iostream>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif // USE_MYMATH


int main(int argc, char **argv)
{
	if (argc < 2) {
		// report version
		std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
				  << Tutorial_VERSION_MINOR << std::endl;
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		return 1;
	}
	else {
		std::cout << "tutorial program to CMake using math functions."
#ifdef USE_MYMATH
			<< "using heron implementation"
#endif
			<< std::endl;

#ifdef USE_MYMATH
		const double res = mysqrt(std::atoi(argv[1]));
#else
		const double res = sqrt(std::atoi(argv[1]));
#endif // USE_MYMATH

		std::cout << "sqrt(" << argv[1] << ") = " << res << std::endl;
	}
	return 0;  
}
