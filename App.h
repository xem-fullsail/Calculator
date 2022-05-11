// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#pragma once
#include "wx/wx.h"
#include "MainWindow.h"

class App : public wxApp
{

private:
	MainWindow* mainWindow = nullptr;

public:
	~App();
	virtual bool OnInit();

};
