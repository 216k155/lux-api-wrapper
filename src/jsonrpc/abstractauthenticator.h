#ifndef AUTHENTICATIONMANAGER_H_
#define AUTHENTICATIONMANAGER_H_

#include "json/json.h"

namespace jsonrpc
{
    
    class AbstractAuthenticator
    {
        public:
          
            virtual int CheckPermission(const Json::Value &authentication,
                    const std::string &method) = 0;

            virtual void ProcessAuthentication(
                    const Json::Value &authentication,
                    Json::Value &returnValue) = 0;

            virtual ~AbstractAuthenticator() {}
    };

} /* namespace jsonrpc */
#endif /* AUTHENTICATIONMANAGER_H_ */
