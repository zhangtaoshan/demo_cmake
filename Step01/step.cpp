#include <cmath>
#include <iostream>
#include <string>
#include "step.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
	std::cout << argv[0] << " Version " << step1_VERSION_MAJOR << "."
		  << step1_VERSION_MINOR << std::endl;
	std::cout << "Usage: " << argv[0] << " number" << std::endl;
	return 1;
    }
    
    const double inputValue = std::stod(argv[1]);

    const double outputValue = sqrt(inputValue);
    std::cout << "The sqrt root of " << inputValue << " is " << outputValue
	      << std::endl;
    return 0;
}
