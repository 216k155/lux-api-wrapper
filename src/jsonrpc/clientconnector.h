#ifndef CLIENTCONNECTOR_H_
#define CLIENTCONNECTOR_H_

#include <string>
#include "exception.h"

namespace jsonrpc
{
    class AbstractClientConnector
    {
        public:
            virtual ~AbstractClientConnector();

            virtual std::string SendMessage(const std::string& message) throw(JsonRpcException);

            virtual void SendMessage(const std::string& message, std::string& result) throw(JsonRpcException) = 0;
    };
} /* namespace jsonrpc */
#endif /* CLIENTCONNECTOR_H_ */
