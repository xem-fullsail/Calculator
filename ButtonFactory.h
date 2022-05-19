// Calculator
// Kevin Moniz

#pragma once
#include <string>
#include <unordered_map>
#include "wx/wx.h"

// Button Pair: std::pair<char, wxButton*>
using bpair = std::pair<char, wxButton*>;


class ButtonFactory
{

public:

	ButtonFactory();
	~ButtonFactory();
	
	// Returns the button with the given index.
	wxButton* operator[](char index);

	// Returns the button with the given index.
	wxButton* GetButton(char index);
	
	// Creates and returns a button.
	wxButton* CreateButton(wxWindow* parent, char index, std::string label = "");

private:

	// The collection of buttons indexed by their label
	std::unordered_map<char, wxButton*> buttons;
		
};
