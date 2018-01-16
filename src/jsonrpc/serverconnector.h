#ifndef SERVERCONNECTOR_H_
#define SERVERCONNECTOR_H_

#include <string>
#include "rpcprotocolserver.h"

namespace jsonrpc
{
    
    class AbstractServerConnector
    {
        public:
            AbstractServerConnector();
            virtual ~AbstractServerConnector();

            virtual bool StartListening() = 0;
            
            virtual bool StopListening() = 0;

            bool virtual SendResponse(const std::string& response,
                    void* addInfo = NULL) = 0;

            bool OnRequest(const std::string& request, void* addInfo = NULL);

            std::string GetSpecification();

            void SetHandler(RpcProtocolServer& handler);

        private:
            RpcProtocolServer* handler;
    };

} /* namespace jsonrpc */
#endif /* SERVERCONNECTOR_H_ */
