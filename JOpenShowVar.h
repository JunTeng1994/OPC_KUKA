#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_JOpenShowVar.h"

class JOpenShowVar : public QMainWindow
{
	Q_OBJECT

public:
	JOpenShowVar(QWidget *parent = Q_NULLPTR);

private:
	Ui::JOpenShowVarClass ui;
};
