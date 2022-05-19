// Calculator
// Kevin Moniz

#include "ButtonFactory.h"
#include "MainWindow.h"


// Constructor
ButtonFactory::ButtonFactory() {
	//
}

// Destructor
ButtonFactory::~ButtonFactory() {
	// Delete each button
	for (auto itr = buttons.begin(); itr != buttons.end(); itr++) {
		delete itr->second;
	}
}

// Returns the button with the given index.
wxButton* ButtonFactory::operator[](char index) {
	return buttons[index];
}

// Returns the button with the given index.
wxButton* ButtonFactory::GetButton(char index) {
	return buttons[index];
}

// Creates and returns a button.
wxButton* ButtonFactory::CreateButton(wxWindow* parent, char index, std::string label) {
	// If label isn't given, use the char index	
	std::string _label = label;
	if (_label.empty()) _label = index;

	// Create the button and insert it into the unordered map
	wxButton* button = new wxButton(parent, 9000 + index, _label);
	buttons.insert(bpair(index, button));

	return button;
}
