// Lab 1.5 - Calculator
// Kevin Moniz

#include "MainWindow.h"


// Constructor
MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "calculator.xem", wxPoint(400, 400)) {
	// Create the grid sizer and button factory
	grid = new wxGridBagSizer();
	bfactory = new ButtonFactory();

	// Create the buttons
	bfactory->CreateButton(this, '0');
	bfactory->CreateButton(this, '1');
	bfactory->CreateButton(this, '2');
	bfactory->CreateButton(this, '3');
	bfactory->CreateButton(this, '4');
	bfactory->CreateButton(this, '5');
	bfactory->CreateButton(this, '6');
	bfactory->CreateButton(this, '7');
	bfactory->CreateButton(this, '8');
	bfactory->CreateButton(this, '9');
	bfactory->CreateButton(this, '=');
	bfactory->CreateButton(this, '+');
	bfactory->CreateButton(this, '-');
	bfactory->CreateButton(this, '*');
	bfactory->CreateButton(this, '/');
	bfactory->CreateButton(this, '%');
	bfactory->CreateButton(this, 'N', "+/-");
	bfactory->CreateButton(this, 'C', "Clr");
	bfactory->CreateButton(this, 'D', "Dec");
	bfactory->CreateButton(this, 'B', "Bin");
	bfactory->CreateButton(this, 'H', "Hex");

	// Bind the buttons to the click method
	bfactory->GetButton('0')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('2')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('3')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('4')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('5')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('6')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('1')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('7')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('8')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('9')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('=')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('+')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('-')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('*')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('/')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('%')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('N')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('C')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('D')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('B')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('H')->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);

	// Add the buttons to the grid, ensuring they expand to fill empty space when the window is resized
	grid->Add(bfactory->GetButton('0'), wxGBPosition(7, 0), wxGBSpan(1, 2), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('1'), wxGBPosition(6, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('2'), wxGBPosition(6, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('3'), wxGBPosition(6, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('4'), wxGBPosition(5, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('5'), wxGBPosition(5, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('6'), wxGBPosition(5, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('7'), wxGBPosition(4, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('8'), wxGBPosition(4, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('9'), wxGBPosition(4, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('='), wxGBPosition(6, 3), wxGBSpan(2, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('+'), wxGBPosition(5, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('-'), wxGBPosition(4, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('*'), wxGBPosition(3, 3), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('/'), wxGBPosition(3, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('%'), wxGBPosition(3, 1), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('N'), wxGBPosition(7, 2), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('C'), wxGBPosition(3, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('D'), wxGBPosition(0, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('B'), wxGBPosition(1, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);
	grid->Add(bfactory->GetButton('H'), wxGBPosition(2, 0), wxGBSpan(1, 1), wxALL|wxEXPAND);

	// Create the text controls, ensuring they can not be edited by the user
	equationCtrl = new wxTextCtrl(this, 9800, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	resultCtrl = new wxTextCtrl(this, 9900, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

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
	// Unbind the buttons from the click method
	bfactory->GetButton('0')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('1')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('2')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('3')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('4')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('5')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('6')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('7')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('8')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('9')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('=')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('+')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('-')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('*')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('/')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('%')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('N')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('C')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('D')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('B')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);
	bfactory->GetButton('H')->Unbind(wxEVT_BUTTON, &MainWindow::OnButtonClicked, this);

	// Release memory
	delete equationCtrl;
	delete resultCtrl;
	delete bfactory;
}

// Executes logic when a button is clicked.
void MainWindow::OnButtonClicked(wxCommandEvent& eventName) {
	// Fetch the clicked button from the given event
	wxButton* button = dynamic_cast<wxButton*>(eventName.GetEventObject());

	// Append the face value of the button to the end of the equation
	std::string buttonLabel = (button->GetLabel()).ToStdString();
	Append(buttonLabel);

	// The event has been handled: end it
	eventName.Skip();
}

// Appends the given data to the end of the equation.
std::string MainWindow::Append(std::string data) {
	equation += data;
	equationCtrl->SetLabel(equation);
	return equation;
}
