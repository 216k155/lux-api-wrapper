#ifndef ERRORS_H_
#define ERRORS_H_

#include <map>
#include <string>

#include "json/json.h"

namespace jsonrpc
{   
    class JsonRpcException;

    class Errors
    {
        public:
        
            static Json::Value GetErrorBlock(const Json::Value& request, const int& errorCode);
      
            static Json::Value GetErrorBlock(const Json::Value& request, const JsonRpcException& exc);

            static std::string GetErrorMessage(int errorCode);

            static class _init
            {
                public:
                _init();
            } _initializer;

            static const int ERROR_RPC_JSON_PARSE_ERROR;
            static const int ERROR_RPC_METHOD_NOT_FOUND;
            static const int ERROR_RPC_INVALID_REQUEST;
            static const int ERROR_RPC_INVALID_PARAMS;
            static const int ERROR_RPC_INTERNAL_ERROR;

            static const int ERROR_SERVER_PROCEDURE_IS_METHOD;
            static const int ERROR_SERVER_PROCEDURE_IS_NOTIFICATION;
            static const int ERROR_SERVER_PROCEDURE_POINTER_IS_NULL;
            static const int ERROR_SERVER_PROCEDURE_SPECIFICATION_NOT_FOUND;
            static const int ERROR_SERVER_PROCEDURE_SPECIFICATION_SYNTAX;
            static const int ERROR_SERVER_CONNECTOR;

            static const int ERROR_CLIENT_CONNECTOR;
            static const int ERROR_CLIENT_INVALID_RESPONSE;
        private:
            static std::map<int, std::string> possibleErrors;
    };
} /* namespace jsonrpc */
#endif /* ERRORS_H_ */
