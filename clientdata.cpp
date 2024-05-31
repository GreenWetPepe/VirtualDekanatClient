#include "clientdata.h"

// unsigned int ClientData::userType = UserTypes::TEACHER;
// int ClientData::userId = 2;

unsigned int ClientData::userType = UserTypes::STUDENT;
int ClientData::userId = 7;

ClientData::ClientData()
{

}

int ClientData::getUserType()
{
    return userType;
}

void ClientData::setUserType(int userType)
{
    switch (userType)
    {
    case UserTypes::GUEST:
        ClientData::userType = UserTypes::GUEST;
        break;
    case UserTypes::STUDENT:
        ClientData::userType = UserTypes::STUDENT;
        break;
    case UserTypes::TEACHER:
        ClientData::userType = UserTypes::TEACHER;
        break;
    }
}

int ClientData::getUserId()
{
   return ClientData::userId;
}

void ClientData::setUserId(int userId)
{
   ClientData::userId = userId;
}


