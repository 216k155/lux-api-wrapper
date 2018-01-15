/*
 * LuxWalletBase.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: luxcore
 */

#include <stdexcept>
#include "LuxWallet.h"
#include "LuxException.h"

using jsonrpc::Client;
using jsonrpc::HttpClient;
using jsonrpc::JsonRpcException;

using Json::Value;
using std::string;


LuxAPI::LuxAPI() { }
LuxAPI::LuxAPI(const string& user, const string& password, const string& host, int port){
	conn.user = user;
	conn.password = password;
	conn.host = host;
	conn.port = port;
	conn.url = "http://"+ conn.user + ":"+ conn.password + "@" + conn.host + ":" + NumberToString(conn.port);
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

