#ifndef PROCEDURE_H_
#define PROCEDURE_H_

#include <string>
#include <map>

#include "json/json.h"
#include "specification.h"

namespace jsonrpc
{
    typedef std::map<std::string, jsontype_t> parameterNameList_t;
    typedef std::vector<jsontype_t> parameterPositionList_t;

    typedef enum {PARAMS_BY_NAME, PARAMS_BY_POSITION} parameterDeclaration_t;

    class Procedure
    {
        public:

            Procedure(const std::string name, parameterDeclaration_t paramType, ...);

            Procedure(const std::string name, parameterDeclaration_t paramType, jsontype_t returntype, ...);


            ~Procedure();

            bool ValdiateParameters(const Json::Value &parameters);

            parameterNameList_t& GetParameters();
            procedure_t GetProcedureType() const;
            const std::string& GetProcedureName() const;

            jsontype_t GetReturnType() const;

            void AddParameter(const std::string& name, jsontype_t type);

            parameterDeclaration_t GetParameterDeclarationType();

        private:
         
            std::string procedureName;
            meterNameList_t parametersName;

            parameterPositionList_t parametersPosition;

            procedure_t procedureType;

            jsontype_t returntype;

            parameterDeclaration_t paramDeclaration;

            bool ValidateNamedParameters(const Json::Value &parameters);
            bool ValidatePositionalParameters(const Json::Value &parameters);
            bool ValidateSingleParameter(jsontype_t expectedType, const Json::Value &value);
    };

    typedef std::map<std::string, Procedure*> procedurelist_t;

} /* namespace jsonrpc */
#endif /* PROCEDURE_H_ */
