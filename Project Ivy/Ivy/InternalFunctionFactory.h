#pragma once
#include <string>
#include <map>
#include <functional>
#include "IInternalFunction.h"

#include "ReadFile.h"
#include "SaveFile.h"

#include "Cos.h"
#include "Log.h"
#include "Pow.h"
#include "Sin.h"
#include "SquareRoot.h"
#include "Tan.h"
#include "Invert.h"
#include "Random.h"
#include "RandomWithPara.h"
#include "RandomWithRange.h"
#include "ConsoleInput.h"
#include "Print.h"
#include "WriteToFile.h"
#include "SummonSupremeLord.h"
#include "SummonSupremeCommander.h"

class InternalFunctionFactory
{
public:
	InternalFunctionFactory();
	~InternalFunctionFactory();
	static InternalFunctionFactory * Instance();
	void RegisterFactoryFunction(std::string name, IInternalFunction* classFactoryFunction, int argNr);
	IInternalFunction* Create(std::string name);
	const std::map<std::string, IInternalFunction*> GetMap();
	const std::map<std::string, int> GetArgNrMap();
private:
	std::map<std::string, IInternalFunction*> factoryFunctionRegistry;
	std::map<std::string, int> factoryFunctionArgNrRegistry;
};
