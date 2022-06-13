
#include <sstream>
#include <iomanip>
#include <ctime>
#include <iostream>

#include <stdio.h>
 
int main()
{
	std::time_t result = std::time(nullptr);

	char Output[18];

	strftime(Output, 18, "[%Y%m%d_%H%M%S]", std::localtime(&result));

    std::cout << Output << std::endl;

    // std::cout << std::asctime(std::localtime(&result))
    //           << result << " seconds since the Epoch\n";
}

// int main()
// {
//     setenv("TZ", "/usr/share/zoneinfo/Canada/Eastern", 1); // POSIX-specific
 
//     std::tm tm;  // get_time does not set all fields hence {}
//     tm.tm_year = 2020-1900; // 2020
//     tm.tm_mon = 7-1; // July
//     tm.tm_mday = 15; // 15th
//     tm.tm_hour = 10;
//     tm.tm_min = 15;
//     tm.tm_isdst = 1; // Daylight saving in London
//     std::time_t t = std::mktime(&tm); 
 
//     std::cout << "UTC:   " << std::put_time(std::gmtime(&t), "%c %Z") << '\n';
//     std::cout << "local: " << std::put_time(std::localtime(&t), "%c %Z") << '\n';
// }