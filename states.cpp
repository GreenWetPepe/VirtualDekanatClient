#include <iostream>
#include <vector>

namespace UserTypes
{
    const unsigned short GUEST = 0;
    const unsigned short STUDENT = 1;
    const unsigned short TEACHER = 2;
    const unsigned short DEAN = 4;
}

const std::vector<std::vector<int>> USER_NAVIGATION
{
    {0, 1}, // GUEST
    {0, 1, 2, 3, 4, 5}, // STUDENT
    {0, 1, 2, 3, 4, 5}, // TEACHER
    {0, 1, 6, 2, 3, 4, 5}, // DEAN
};

namespace NavigationButtons
{
    const unsigned short NEWS = 0;
    const unsigned short ACCOUNT = 1;
    const unsigned short SCHEDULE  = 2;
    const unsigned short COURSES = 3;
    const unsigned short STATISTIC = 4;
    const unsigned short LOG_OUT = 5;
    const unsigned short USER_OPTIONS = 6;
    const unsigned short SERVER_OPTIONS = 7;
}




