#include <stdexcept>
#include "LuxWallet.h"
#include "LuxException.h"

using jsonrpc::Client;
using jsonrpc::HttpClient;
using jsonrpc::JsonRpcException;

using Json::Value;
using std::string;


LuxAPI::LuxAPI() {
	conn = {};
}

LuxAPI::LuxAPI(const string& user, const string& password, const string& host, int port){
	conn.user = user;
	conn.password = password;
	conn.host = host;
	conn.port = port;
	conn.url = "http://"+ conn.user + ":"+ conn.password + "@" + conn.host + ":" + NumberToString(conn.port);
}

bool LuxAPI::IsInit(){
	return !(conn.user.empty() || conn.password.empty() || conn.host.empty() || conn.port == 0);
}

string LuxAPI::NumberToString (int number){
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

int LuxAPI::StringToNumber (const string &text){
	std::istringstream ss(text);
	int result;
	return ss >> result ? result : 0;
}

Value LuxAPI::sendcommand(const string& command, const Value& params){
	Value result;
	Client c(new HttpClient(conn.url));

	try{
		result = c.CallMethod(command, params);
	}
	catch (JsonRpcException& e){
		LuxException err(e.GetCode(), e.GetMessage());
		throw err;
	}

	return result;
}

