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
CalculatorProcessor* CalculatorProcessor::GetInstance() {
	if (instance == nullptr) instance = new CalculatorProcessor();
	return instance;
}
