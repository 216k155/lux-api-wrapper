#define EXCEPTION_H_

#include <string>
#include <sstream>
#include <exception>

#include "errors.h"

namespace jsonrpc
{
    
    class JsonRpcException: public std::exception
    {
        public:
            JsonRpcException(int code);

            JsonRpcException(int code, const std::string& message);

            JsonRpcException(const std::string& message);

            virtual ~JsonRpcException() throw ();

            int GetCode() const;

            const std::string& GetMessage() const;

            virtual const char* what() const throw ();

        private:
            int code;
            std::string message;
            std::string whatString;

            void setWhatMessage();
    };

} /* namespace jsonrpc */
#endif /* EXCEPTION_H_ */
