#ifndef SPECIFICATION_H
#define SPECIFICATION_H

#define KEY_METHOD_NAME "method"
#define KEY_NOTIFICATION_NAME "notification"
#define KEY_PROCEDURE_PARAMETERS "params"
#define KEY_RETURN_TYPE "returns"

namespace jsonrpc
{
    
    typedef enum
    {
        RPC_METHOD, RPC_NOTIFICATION
    } procedure_t;

   
    enum jsontype_t
    {
        JSON_STRING = 1,
        JSON_BOOLEAN = 2,
        JSON_INTEGER = 3,
        JSON_REAL = 4,
        JSON_OBJECT = 5,
        JSON_ARRAY = 6,
        JSON_NULL = 7
    } ;
}

#endif // SPECIFICATION_H
