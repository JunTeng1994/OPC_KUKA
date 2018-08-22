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

/**********************************************************
* to send a read request to the KRC
* latest version :2017/12/01
* function:readRequest
***********************************************************/
extern QByteArray readRequest(unsigned short id, QByteArray var)
{
	const int Timeout = 5 * 1000;
	QTime readtime;

	QTcpSocket socketClient;
	socketClient.connectToHost("172.31.1.147", 7000);

	readtime.start();

	if (!socketClient.waitForConnected(Timeout)) {
		qDebug() << "Timeout connection!";
		exit(0);
//		return -1;
	}

	//read variable
	socketClient.write(formatMsg(var, id)); //to send the request 

													 //write variable
													 //socketClient.write(formatMsg("$OV_PRO","55",43981));

	if (!socketClient.waitForBytesWritten(Timeout))
	{
		qDebug() << "Timeout message sent!";
		exit(0);
//		return -1;
	}

	if (!socketClient.waitForReadyRead(Timeout)) {
		qDebug() << "Timeout message return!";
		exit(0);
//		return -1;;
	}
	QByteArray returnMsg = socketClient.read(socketClient.bytesAvailable()); // to get the value returned

	qDebug() << "-----------return message-----------";
	unsigned char ok = returnMsg.right(1).at(0);

	QByteArray valueRead;
	unsigned short idMsg = clearMsg(returnMsg, valueRead);
	qDebug() << "valueRead:" << valueRead;
	qDebug() << "Read Time:" << readtime.elapsed() << "ms";
	socketClient.disconnectFromHost();  //disconnect the client

	return valueRead;
}

/**********************************************************
* to send a write request to the KRC
* latest version :2017/12/01
* function:writeRequest
***********************************************************/
extern void writeRequest(unsigned short id, QByteArray var, QByteArray value)
{
	const int Timeout = 5 * 1000;
	QTime readtime;

	QTcpSocket socketClient;
	socketClient.connectToHost("172.31.1.147", 7000);

	readtime.start();

	if (!socketClient.waitForConnected(Timeout)) {
		qDebug() << "Timeout connection!";
		exit(0);
		//		return -1;
	}

	//read variable
//	socketClient.write(formatMsg(var, id)); //to send the request 

	//write variable
	socketClient.write(formatMsg(var,value,id));

	if (!socketClient.waitForBytesWritten(Timeout))
	{
		qDebug() << "Timeout message sent!";
		exit(0);
		//		return -1;
	}

	if (!socketClient.waitForReadyRead(Timeout)) {
		qDebug() << "Timeout message return!";
		exit(0);
		//		return -1;;
	}
	QByteArray returnMsg = socketClient.read(socketClient.bytesAvailable()); // to get the value returned

	qDebug() << "-----------return message-----------";
	unsigned char ok = returnMsg.right(1).at(0);

	QByteArray valueWrite;
	unsigned short idMsg = clearMsg(returnMsg, valueWrite);
	qDebug() << "valueWrite:" << valueWrite;
	qDebug() << "Read Time:" << readtime.elapsed() << "ms";
	socketClient.disconnectFromHost();  //disconnect the client

	//return valueWrite;
}


/**********************************************************
* to send a read request to the KRC(latest method)
* latest version :2017/12/01
* function:readVariable
***********************************************************/
extern QString readVariable(QByteArray var)
{

	if (var == "$AXIS_ACT" || var == "$POS_ACT")
	{
		return QString(readRequest(43981, var)); //transfer QByteArray into QString 
	}
	else
	{
		qDebug() << "readVariable var is invalid!" << endl;
		exit(0);
	}
}

/**********************************************************
* to send a writePOS request to the KRC(latest method)
* latest version :2017/12/01
* function:writeVariableKRLPos
***********************************************************/
extern void writeVariableKRLPos(KRLPos pos)
{
	QString var;
	//Callback sendRequest = client.sendRequest(new Request(0, "MYPOS", "{X 10,Y 10,Z 10,A 10,B 10,C 10,S 1,T 2}"));
	QString varArray[] = { "{X ",",Y ",",Z ",",A ",",B ",",C ",",S ",",T ","}" };

	QString varStr;
	QByteArray varQBA;

	varStr = varArray[0]
		+ QString::number(pos.X, 10, 2)
		+ varArray[1]
		+ QString::number(pos.Y, 10, 2)
		+ varArray[2]
		+ QString::number(pos.Z, 10, 2)
		+ varArray[3]
		+ QString::number(pos.A, 10, 2)
		+ varArray[4]
		+ QString::number(pos.B, 10, 2)
		+ varArray[5]
		+ QString::number(pos.C, 10, 2)
		+ varArray[6]
		+ QString::number(pos.S, 10, 2)
		+ varArray[7]
		+ QString::number(pos.T, 10, 2)
		+ varArray[8];

	varQBA = varStr.toLatin1();

	writeRequest(43981, "MYPOS", varQBA);



	//return varStr;
}

/**********************************************************
* to send a writeAXIS request to the KRC(latest method)
* latest version :2017/12/01
* function:writeVariableKRLAxis
***********************************************************/
extern void writeVariableKRLAxis(KRLAxis axis)
{
	QString var;
	//Callback sendRequest = client.sendRequest(new Request(0, "MYPOS", "{X 10,Y 10,Z 10,A 10,B 10,C 10,S 1,T 2}"));
	QString varArray[] = { "{A1 ",",A2 ",",A3 ",",A4 ",",A5 ",",A6 ","}"};

	QString varStr;
	QByteArray varQBA;

	varStr = varArray[0]
		+ QString::number(axis.A1, 10, 2)
		+ varArray[1]
		+ QString::number(axis.A2, 10, 2)
		+ varArray[2]
		+ QString::number(axis.A3, 10, 2)
		+ varArray[3]
		+ QString::number(axis.A4, 10, 2)
		+ varArray[4]
		+ QString::number(axis.A5, 10, 2)
		+ varArray[5]
		+ QString::number(axis.A6, 10, 2)
		+ varArray[6];

	varQBA = varStr.toLatin1();

	writeRequest(43981, "MYAXIS", varQBA);



	//return varStr;
}