#include <iostream>
#include <string>
#include "step.h"

#ifdef USE_MYMATH
    #include "MathFunctions.h"
#else
    #include <cmath>
#endif

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
	std::cout << argv[0] << " Version " << step6_VERSION_MAJOR << "."
		  << step6_VERSION_MINOR << std::endl;
	std::cout << "Usage: " << argv[0] << " number" << std::endl;
	return 1;
    }
    
    const double inputValue = std::stod(argv[1]);
    #ifdef USE_MYMATH
        const double outputValue = mathfunctions::sqrt(inputValue);
    #else
	const double outputValue = sqrt(inputValue);
    #endif
    std::cout << "The sqrt root of " << inputValue << " is " << outputValue
	      << std::endl;
    return 0;
}
