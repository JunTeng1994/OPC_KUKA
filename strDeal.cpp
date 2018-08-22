#include <QtWidgets/QApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QTime>
#include <iostream>
#include "msgDeal.h"
#include "define.h"
#include "initCom.h"
#include "readANDwriteVar.h"
#include "KRLstructs.h"	

using namespace std;

void POS_AXIS_String2Double(QString var, QString str, double *num)
{
	if (var == "$POS_ACT")
	{
		num[0] = str.section(',', 0, 0).section(' ', 2, 2).toDouble();
		num[1] = str.section(',', 1, 1).section(' ', 2, 2).toDouble();
		num[2] = str.section(',', 2, 2).section(' ', 2, 2).toDouble();
		num[3] = str.section(',', 3, 3).section(' ', 2, 2).toDouble();
		num[4] = str.section(',', 4, 4).section(' ', 2, 2).toDouble();
		num[5] = str.section(',', 5, 5).section(' ', 2, 2).toDouble();
		num[6] = str.section(',', 6, 6).section(' ', 2, 2).toDouble();
		num[7] = str.section(',', 7, 7).section(' ', 2, 2).toDouble();
	}
	else if (var == "$AXIS_ACT")
	{
		num[0] = str.section(',', 0, 0).section(' ', 2, 2).toDouble();
		num[1] = str.section(',', 1, 1).section(' ', 2, 2).toDouble();
		num[2] = str.section(',', 2, 2).section(' ', 2, 2).toDouble();
		num[3] = str.section(',', 3, 3).section(' ', 2, 2).toDouble();
		num[4] = str.section(',', 4, 4).section(' ', 2, 2).toDouble();
		num[5] = str.section(',', 5, 5).section(' ', 2, 2).toDouble();
	}
	else
	{
		cout << "invalid var!" << endl;
		exit(0);
	}
}