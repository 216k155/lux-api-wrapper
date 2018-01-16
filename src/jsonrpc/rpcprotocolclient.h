#ifndef RESPONSEHANDLER_H
#define RESPONSEHANDLER_H

#include "abstractauthenticator.h"
#include "exception.h"
#include "json/value.h"
#include <string>

namespace jsonrpc {

    typedef std::multimap<const std::string, const Json::Value> batchProcedureCall_t;

    class RpcProtocolClient
    {
        public:
            RpcProtocolClient();
            RpcProtocolClient(AbstractAuthenticator& authenticator);

            std::string BuildRequest(const std::string& method, const Json::Value& parameter, bool isNotification);

            std::string BuildBatchRequest(batchProcedureCall_t& requests, bool isNotification);
            BuildRequest(const std::string& method, const Json::Value& parameter, std::string& result, bool isNotification);

            ldBatchRequest(batchProcedureCall_t& requests, std::string& result, bool isNotification);

            Json::Value HandleResponse(const std::string& response) throw(JsonRpcException);

            void HandleResponse(const std::string& response, Json::Value& result) throw (JsonRpcException);

            void resetId();

            static const std::string KEY_PROTOCOL_VERSION;
            static const std::string KEY_PROCEDURE_NAME;
            static const std::string KEY_ID;
            static const std::string KEY_PARAMETER;
            static const std::string KEY_AUTH;
            static const std::string KEY_RESULT;
            static const std::string KEY_ERROR;
            static const std::string KEY_ERROR_CODE;
            static const std::string KEY_ERROR_MESSAGE;

        private:
            AbstractAuthenticator* authenticator;
            int id;

            void BuildRequest(const std::string& method, const Json::Value& parameter, Json::Value& result, bool isNotification);
    };
}
#endif // RESPONSEHANDLER_H
