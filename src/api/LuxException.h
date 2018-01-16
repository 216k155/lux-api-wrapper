#ifndef LUXERROR_H_
#define LUXERROR_H_

#include <string>
#include <sstream>

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



#endif /* LUXERROR_H_ */
