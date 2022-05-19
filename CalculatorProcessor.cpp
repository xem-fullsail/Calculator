// Calculator
// Kevin Moniz

#include "CalculatorProcessor.h"

// The singleton instance of this class.
CalculatorProcessor* CalculatorProcessor::instance = nullptr;

// Hidden Constructor
CalculatorProcessor::CalculatorProcessor() {
	//
}

// Hidden Destructor
CalculatorProcessor::~CalculatorProcessor() {
	delete instance;
}

// Returns the singleton instance of the calculator processor.
CalculatorProcessor* CalculatorProcessor::Instance() {
	if (instance == nullptr) instance = new CalculatorProcessor();
	return instance;
}

// Process the given equation and return the result.
int CalculatorProcessor::Process(std::string equation) {
	//
	return 0;
}
