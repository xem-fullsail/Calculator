// Lab 1.5 - Calculator
// Kevin Moniz

#include "ButtonFactory.h"
#include "MainWindow.h"


// Constructor
ButtonFactory::ButtonFactory() {
	//
}

// Destructor
ButtonFactory::~ButtonFactory() {
	// Unbind each button from the event handler, then delete them
	for (auto itr = buttons.begin(); itr != buttons.end(); itr++) {
		//itr->second->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, 9999);
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

	// Create the buttons and insert it into the unordered map
	wxButton* button = new wxButton(parent, 9000 + index, _label);
	buttons.insert(bpair(index, button));

	// Bind the button to the click method on the MainWindow
	//button->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, parent->GetId());
	button->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked);

	return button;
}
