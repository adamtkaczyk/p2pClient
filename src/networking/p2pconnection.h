#ifndef P2PCONNECTION_H
#define P2PCONNECTION_H

#include "protocol/p2pmessage.h"

#include <memory>

class P2PConnectionException : public std::runtime_error
{
public:
    P2PConnectionException(const std::string message) : std::runtime_error(message) {}
};

class P2PConnection
{
public:
    P2PConnection();
    //receive next P2PMessage
    virtual const std::shared_ptr<P2PMessage> receive() = 0;
    //send P2PMessage
    virtual void send(const std::shared_ptr<P2PMessage> message) = 0;
    //send simple text message
    virtual void send(const std::string message) = 0;
    //get string which is unique for this connection
    virtual const std::string getConnectionIdentifier() const = 0;
};

#endif // P2PCONNECTION_H
