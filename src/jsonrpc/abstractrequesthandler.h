#ifndef ABSTRACTREQUESTHANDLER_H
#define ABSTRACTREQUESTHANDLER_H

namespace jsonrpc
{
    class AbstractRequestHandler {
        public:
            virtual void handleMethodCall(Procedure* proc, const Json::Value& input, Json::Value& output) = 0;
            virtual void handleNotificationCall(Procedure* proc, const Json::Value& input) = 0;
    };
}

#endif // ABSTRACTREQUESTHANDLER_H
