// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#include "MainWindow.h"
#include "wx/gbsizer.h"


// Constructor
MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "calculator.xem", wxPoint(400, 400)) {
	// Create the grid sizer
	wxGridBagSizer* grid = new wxGridBagSizer();

	// Create the buttons
	CreateButton('0');
	CreateButton('1');
	CreateButton('2');
	CreateButton('3');
	CreateButton('4');
	CreateButton('5');
	CreateButton('6');
	CreateButton('7');
	CreateButton('8');
	CreateButton('9');
	CreateButton('=');
	CreateButton('+');
	CreateButton('-');
	CreateButton('*');
	CreateButton('/');
	CreateButton('%');
	CreateButton('N', "+/-");
	CreateButton('C', "Clr");
	CreateButton('D', "Dec");
	CreateButton('B', "Bin");
	CreateButton('H', "Hex");

	// Add the buttons to the grid, ensuring they expand to fill empty space when the window is resized
	grid->Add(buttons['0'], wxGBPosition(7, 0), wxGBSpan(1, 2), wxALL | wxEXPAND);
	grid->Add(buttons['1'], wxGBPosition(6, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['2'], wxGBPosition(6, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['3'], wxGBPosition(6, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['4'], wxGBPosition(5, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['5'], wxGBPosition(5, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['6'], wxGBPosition(5, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['7'], wxGBPosition(4, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['8'], wxGBPosition(4, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['9'], wxGBPosition(4, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['='], wxGBPosition(6, 3), wxGBSpan(2, 1), wxALL|wxEXPAND);
	grid->Add(buttons['+'], wxGBPosition(5, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['-'], wxGBPosition(4, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['*'], wxGBPosition(3, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['/'], wxGBPosition(3, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['%'], wxGBPosition(3, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['N'], wxGBPosition(7, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['C'], wxGBPosition(3, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['D'], wxGBPosition(0, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['B'], wxGBPosition(1, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttons['H'], wxGBPosition(2, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);

	// Create the text controls, ensuring they can not be edited by the user
	equationCtrl = new wxTextCtrl(this, 9100, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	resultCtrl = new wxTextCtrl(this, 9200, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

	// Add the text controls to the grid, ensuring they expand to fill empty space when the window is resized
	grid->Add(equationCtrl, wxGBPosition(0, 1), wxGBSpan(1, 3), wxALL|wxEXPAND);
	grid->Add(resultCtrl, wxGBPosition(1, 1), wxGBSpan(2, 3), wxALL|wxEXPAND);

	// Ensure the grid is resizable
	grid->AddGrowableCol(0);
	grid->AddGrowableCol(1);
	grid->AddGrowableCol(2);
	grid->AddGrowableCol(3);
	grid->AddGrowableRow(0);
	grid->AddGrowableRow(1);
	grid->AddGrowableRow(2);
	grid->AddGrowableRow(3);
	grid->AddGrowableRow(4);
	grid->AddGrowableRow(5);
	grid->AddGrowableRow(6);
	grid->AddGrowableRow(7);

	// Display the grid
	this->SetSizerAndFit(grid);
	grid->Layout();
}

// Destructor
MainWindow::~MainWindow() {
	//
}

// Creates a button, inserts it into the dictionary, and returns it.
wxButton* MainWindow::CreateButton(char index, std::string label) {	
	std::string _label = label;										// Use the given label, unless it is empty
	if (_label.empty()) _label = index;								// If label isn't given, use the char index	
	wxButton* button = new wxButton(this, 9000 + index, _label);	// Create the button
	buttons.insert(bpair(index, button));							// Insert the button into the unordered map
	button->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);	// Bind the button to the click method
	return button;													// Return the button
}

// Executes logic when a button is clicked.
void MainWindow::OnButtonClicked(wxCommandEvent& eventName) {
	// Fetch the clicked button from the given event
	wxButton* button = (wxButton*)eventName.GetEventObject();

	// Append the face value of the button to the end of the equation
	std::string buttonLabel = (button->GetLabel()).ToStdString();
	Append(buttonLabel);
	equationCtrl->SetLabel(equation);

	// The event has been handled: end it
	eventName.Skip();
}

// Appends the given data to the end of the equation.
std::string MainWindow::Append(std::string data) {
	equation += data;
	return equation;
}
