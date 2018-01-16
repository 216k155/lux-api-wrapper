#include "clientconnector.h"
#include <cstdlib>

using namespace std;

namespace jsonrpc
{
    AbstractClientConnector::~AbstractClientConnector()
    {

    }

    string AbstractClientConnector::SendMessage(const string &message) throw (JsonRpcException)
    {
        string result;
        this->SendMessage(message, result);
        return result;
    }
}
