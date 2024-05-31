#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include "states.cpp"


class ClientData
{
public:
    ClientData();

    static int getUserType();
    static void setUserType(int userType);

   static int getUserId();
   static void setUserId(int userId);

private:
    static unsigned int userType;
    static int userId;
};

#endif // CLIENTDATA_H
