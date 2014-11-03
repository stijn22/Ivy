#include "ReturnValueCompilerToken.h"


ReturnValueCompilerToken::ReturnValueCompilerToken()
{
}

ReturnValueCompilerToken::~ReturnValueCompilerToken()
{
}

void ReturnValueCompilerToken::addValueToVector(boost::any value) { 
	rpnVector.push_back(value);
}

void ReturnValueCompilerToken::pushOperatorToStack(TokenType op) { 
	operatorStack.push(op);
}

TokenType ReturnValueCompilerToken::peekOperatorStack() {
	if (operatorStack.size() > 1) {
		return operatorStack.top();
	}

	return TokenType::Null;
}

void ReturnValueCompilerToken::popOperatorStack() {
	operatorStack.pop();
}

void ReturnValueCompilerToken::completeRPNVector() {
	while (!operatorStack.empty()) {
		addValueToVector(operatorStack.top());
		operatorStack.pop();
	}
}

std::vector<boost::any>* ReturnValueCompilerToken::getrpnVector() {
	return &rpnVector;
}