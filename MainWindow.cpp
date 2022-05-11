// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#include "MainWindow.h"
#include "wx/gbsizer.h"

// The collection of events that this window will interact with
wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
	//EVT_BUTTON(9000, OnButtonClicked)
wxEND_EVENT_TABLE()

// Constructor
MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "calculator.xem", wxPoint(400, 400)) {
	// Create the grid sizer
	wxGridBagSizer* grid = new wxGridBagSizer();

	// Create the buttons
	button0 = new wxButton(this, 9000, "0");
	button1 = new wxButton(this, 9001, "1");
	button2 = new wxButton(this, 9002, "2");
	button3 = new wxButton(this, 9003, "3");
	button4 = new wxButton(this, 9004, "4");
	button5 = new wxButton(this, 9005, "5");
	button6 = new wxButton(this, 9006, "6");
	button7 = new wxButton(this, 9007, "7");
	button8 = new wxButton(this, 9008, "8");
	button9 = new wxButton(this, 9009, "9");
	buttonEql = new wxButton(this, 9010, "=");
	buttonAdd = new wxButton(this, 9011, "+");
	buttonSub = new wxButton(this, 9012, "-");
	buttonMul = new wxButton(this, 9013, "*");
	buttonDiv = new wxButton(this, 9014, "/");
	buttonMod = new wxButton(this, 9015, "%");
	buttonNeg = new wxButton(this, 9016, "+/-");
	buttonClr = new wxButton(this, 9017, "C");
	buttonDec = new wxButton(this, 9018, "DEC");
	buttonBin = new wxButton(this, 9019, "BIN");
	buttonHex = new wxButton(this, 9020, "HEX");

	// Add the buttons to the grid
	grid->Add(button0, wxGBPosition(7, 0), wxGBSpan(1, 2), wxALL|wxEXPAND);
	grid->Add(button1, wxGBPosition(6, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(button2, wxGBPosition(6, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(button3, wxGBPosition(6, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(button4, wxGBPosition(5, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(button5, wxGBPosition(5, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(button6, wxGBPosition(5, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(button7, wxGBPosition(4, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(button8, wxGBPosition(4, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(button9, wxGBPosition(4, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonEql, wxGBPosition(6, 3), wxGBSpan(2, 1), wxALL|wxEXPAND);
	grid->Add(buttonAdd, wxGBPosition(5, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonSub, wxGBPosition(4, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonMul, wxGBPosition(3, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonDiv, wxGBPosition(3, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonMod, wxGBPosition(3, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonNeg, wxGBPosition(7, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonClr, wxGBPosition(3, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonDec, wxGBPosition(0, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonBin, wxGBPosition(1, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(buttonHex, wxGBPosition(2, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);

	// Create the text controls
	equation = new wxTextCtrl(this, 9100, "");
	result = new wxTextCtrl(this, 9200, "");

	// Add the text controls to the grid
	grid->Add(equation, wxGBPosition(0, 1), wxGBSpan(1, 3), wxALL|wxEXPAND);
	grid->Add(result, wxGBPosition(1, 1), wxGBSpan(2, 3), wxALL|wxEXPAND);

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
	
	//wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
}

MainWindow::~MainWindow() {
	//
}

void MainWindow::OnButtonClicked(wxCommandEvent& eventName) {
	eventName.Skip();
}
