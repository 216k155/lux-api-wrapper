/*
 * LuxError.h
 *
 *  Created on: May 27, 2014
 *      Author: luxcore
 */

#ifndef BITCOINERROR_H_
#define BITCOINERROR_H_

class LuxException: public std::exception
{
private:
	int code;
	std::string msg;

public:
	explicit LuxException(int errcode, const std::string& message) {
		this->code = errcode;
		this->msg = parse(message);

	}
	~LuxException() throw() { };

	int getCode(){
		return code;
	}

	std::string getMessage(){
		return msg;
	}

	std::string parse(const std::string& in){
		std::string out = in;
		std::string pattern = ": Error: ";
		unsigned int pos = out.find(pattern);
		if(pos <= out.size()){
			out.erase(pos, pattern.size());
			out[0] = toupper(out[0]);
		}

		return out;
	}

	virtual const char* what() const throw (){
		std::stringstream out;
		out << "Error " << code << ": " << msg;
		return out.str().c_str();
	}
};



#endif /* BITCOINERROR_H_ */