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
#include "strDeal.h"

using namespace std;

/**********************************************************
* connect with KRL by QtSoceket
* latest version :2017/12/01 
* function:main
***********************************************************/
int main()
{
	//readRequest(43981,"OV_PRO");
	//writeRequest(43981, "OV_PRO","10");

	// //QString(const QByteArray &ba) QString的构造函数默认就可以转换
	//QByteArray baData("abcdefg");
	//QString str = QString(baData);
	//// 反过来转换
	//QByteArray by1 = str.toLatin1();
	//QByteArray by2 = str.toLocal8Bit();
	//qDebug() << str << endl;
	//qDebug() << by1 << endl;
	//qDebug() << by2 << endl;

	/*KRLPos pos;
	KRLAxis axis;
	pos.setXToZ(11,22,33);
	pos.setAToC(44,55,66);
	pos.setT(77);
	pos.setS(88);
	axis.setA1ToA6(11,22,33,44,55,66);
	qDebug() << pos.X << endl;
	qDebug() << pos.Y << endl;
	qDebug() << pos.Z << endl;
	qDebug() << pos.A << endl;
	qDebug() << pos.B << endl;
	qDebug() << pos.C << endl;
	qDebug() << pos.S << endl;
	qDebug() << pos.T << endl;
	qDebug() << axis.A1 << endl;
	qDebug() << axis.A2 << endl;
	qDebug() << axis.A3 << endl;
	qDebug() << axis.A4 << endl;
	qDebug() << axis.A5 << endl;
	qDebug() << axis.A6 << endl;

	qDebug() << pos.getX() << endl;
	qDebug() << axis.getA1() << endl;*/

	//long a = 63;  
	//int b = 55;
	//QString s = QString::number(a, 10);      // s == "63"
	//QString sb = QString::number(b, 10);      // s == "63"
	//qDebug() << s << endl;
	//qDebug() << sb << endl;
	//qDebug() << s+sb << endl;

	

	//qDebug() << writeVariableKRLPos(pos) << endl;
	//qDebug() << writeVariableKRLAxis(axis) << endl;


	//qDebug() << readRequest(43981, "$POS_ACT") << endl;
	//qDebug() << readVariable("$AXIS_ACT") << endl;
	//writeRequest(43981, "MYPOS", "{X 2,Y 2,Z 2,A 2,B 2,C 2,S 2,T 2}");


	//KRLPos pos;
	//KRLAxis axis;
	//pos.setXToZ(11, 22, 33);
	//pos.setAToC(44, 55, 66);
	//pos.setT(77);
	//pos.setS(88);

	//writeVariableKRLPos(pos);


	QString strVar = "{E6POS: X 330.456085, Y -449.031982, Z 760.560303, A -54.3852234, B 53.6800575, C -148.246338, S 2, T 42, E1 0.0, E2 0.0, E3 0.0, E4 0.0, E5 0.0, E6 0.0}";
	QString strVar1 = "{E6AXIS: A1 22.22, A2 22.22, A3 22.22, A4 22.22, A5 22.22, A6 22.22, E1 0, E2 0, E3 0, E4 0, E5 0, E6 0}";
	//string s1 = "{E6POS: X 330.456085, Y -449.031982, Z 760.560303, A -54.3852234, B 53.6800575, C -148.246338, S 2, T 42, E1 0.0, E2 0.0, E3 0.0, E4 0.0, E5 0.0, E6 0.0}";

	/*qDebug() << strVar.section(',', 0, 0).section(' ', 2, 2).toDouble() << endl;
	qDebug() << strVar.section(',', 1, 1).section(' ', 2, 2).toDouble() << endl;
	qDebug() << strVar.section(',', 2, 2).section(' ', 2, 2).toDouble() << endl;
	qDebug() << strVar.section(',', 3, 3).section(' ', 2, 2).toDouble() << endl;
	qDebug() << strVar.section(',', 4, 4).section(' ', 2, 2).toDouble() << endl;
	qDebug() << strVar.section(',', 5, 5).section(' ', 2, 2).toDouble() << endl;
	qDebug() << strVar.section(',', 6, 6).section(' ', 2, 2).toDouble() << endl;
	qDebug() << strVar.section(',', 7, 7).section(' ', 2, 2).toDouble() << endl;*/


	double num[8] = {0};
	POS_AXIS_String2Double("$POS_ACT", strVar, num);
	cout << num[0] << endl;
	cout << num[1] << endl;
	cout << num[2] << endl;
	cout << num[3] << endl;
	cout << num[4] << endl;
	cout << num[5] << endl;
	cout << num[6] << endl;
	cout << num[7] << endl;
	cout << "end" << endl;




	return 0;
}
