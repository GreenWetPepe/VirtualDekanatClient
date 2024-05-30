#ifndef SERVER_H
#define SERVER_H

#include <iostream>

class Server
{
public:
    ~Server();

    static void sendRequest(std::string req);

private:
};

#endif // SERVER_H
