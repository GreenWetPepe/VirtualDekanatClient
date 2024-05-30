#include "clientdata.h"

unsigned int ClientData::userType = UserTypes::GUEST;

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
    case UserTypes::DEPART_ADMIN:
        ClientData::userType = UserTypes::DEPART_ADMIN;
        break;
    case UserTypes::DEAN:
        ClientData::userType = UserTypes::DEAN;
        break;
    case UserTypes::ADMIN:
        ClientData::userType = UserTypes::ADMIN;
        break;
    }
}


