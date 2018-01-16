#ifndef REQUESTHANDLER_H_
#define REQUESTHANDLER_H_

#include <string>
#include <vector>
#include <map>

#include "specificationparser.h"
#include "abstractauthenticator.h"
#include "abstractrequesthandler.h"

#define KEY_REQUEST_METHODNAME "method"
#define KEY_REQUEST_VERSION "jsonrpc"
#define KEY_REQUEST_ID "id"
#define KEY_REQUEST_PARAMETERS "params"
#define KEY_RESPONSE_ERROR "error"
#define KEY_RESPONSE_RESULT "result"
#define KEY_AUTHENTICATION "auth"

#define JSON_RPC_VERSION "2.0"

namespace jsonrpc
{
    class RpcProtocolServer
    {
        public:
            RpcProtocolServer(AbstractRequestHandler* server, procedurelist_t* procedures, AbstractAuthenticator* auth = NULL);
            RpcProtocolServer(AbstractRequestHandler* server, AbstractAuthenticator* auth = NULL);

            virtual ~RpcProtocolServer();

            void HandleRequest(const std::string& request, std::string& retValue);

            void SetAuthenticator(AbstractAuthenticator* auth);

            void AddProcedure(Procedure* procedure);

            procedurelist_t& GetProcedures();

        private:

            void HandleSingleRequest(Json::Value& request, Json::Value& response);
            void HandleBatchRequest(Json::Value& requests, Json::Value& response);

            int ValidateRequest(const Json::Value &val);

            void ProcessRequest(const Json::Value &request,
                    Json::Value &retValue);

            procedurelist_t* procedures;
        
            AbstractAuthenticator* authManager;
            AbstractRequestHandler* server;

    };

} /* namespace jsonrpc */
#endif /* REQUESTHANDLER_H_ */
