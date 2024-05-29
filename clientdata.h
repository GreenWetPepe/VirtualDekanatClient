#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include "states.cpp"


class ClientData
{
public:
    ClientData();

    static int getUserType();
    static void setUserType(int userType);

private:
    static unsigned int userType;
};

#endif // CLIENTDATA_H
