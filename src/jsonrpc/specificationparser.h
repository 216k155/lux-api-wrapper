#ifndef SPECIFICATIONPARSER_H
#define SPECIFICATIONPARSER_H

#include "procedure.h"
#include "exception.h"

namespace jsonrpc {

    typedef std::map<std::string, Procedure*> procedurelist_t;

    class SpecificationParser
    {
        public:
            static procedurelist_t* GetProceduresFromFile(const std::string& filename) throw (JsonRpcException);
            static procedurelist_t* GetProceduresFromString(const std::string& spec) throw (JsonRpcException);


        private:
            static Procedure* GetProcedure(Json::Value& val);
            static void GetFileContent(const std::string& filename, std::string& target);
            static jsontype_t toJsonType(Json::Value& val);
    };
}
#endif // SPECIFICATIONPARSER_H
