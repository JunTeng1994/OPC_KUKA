#include <QtWidgets/QApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QTime>
#include <iostream>
#include "msgDeal.h"
#include "define.h"
#include "initCom.h"

using namespace std;
/*****************************************************************
* to format the msg into code
* latest version :2017/12/01
* function:formatMsg
******************************************************************/
QByteArray formatMsg(QByteArray msg, unsigned short idMsg) {  //to switch the request into the bin code (read code)

	const char READVARIABLE = 0;

	QByteArray header, block;
	int lunghezza, varNameLen;
	unsigned char hByte, lByte;
	unsigned char hByteMsg, lByteMsg;

	varNameLen = msg.size();
	hByte = (varNameLen & 0xff00) >> 8;
	lByte = (varNameLen & 0x00ff);

	block.append(READVARIABLE).append(hByte).append(lByte).append(msg);
	lunghezza = block.size();

	hByte = (lunghezza & 0xff00) >> 8;
	lByte = (lunghezza & 0x00ff);

	// Message ID ( MAX: 0xFFFF )
	hByteMsg = (idMsg & 0xff00) >> 8;
	lByteMsg = (idMsg & 0x00ff);

	header.append(hByteMsg).append(lByteMsg).append(hByte).append(lByte);
	block.prepend(header);

	qDebug() << "Message send:" << block.toHex();

	return block;
}

/*****************************************************************
* to format the msg into code(suport write value)
* latest version :2017/12/01
* function:formatMsg
******************************************************************/
QByteArray formatMsg(QByteArray msg, QByteArray value, unsigned short idMsg) { //to switch the request into the bin code (write code)

	const char WRITEVARIABLE = 1;

	QByteArray header, block;
	short lunghezza, varNameLen, varValueLen;
	unsigned char hByte, lByte;
	unsigned char hByteMsg, lByteMsg;

	varNameLen = msg.size();
	hByte = (varNameLen & 0xff00) >> 8;
	lByte = (varNameLen & 0x00ff);

	block.append(WRITEVARIABLE).append(hByte).append(lByte).append(msg);

	varValueLen = value.size();
	hByte = (varValueLen & 0xff00) >> 8;
	lByte = (varValueLen & 0x00ff);

	block.append(hByte).append(lByte).append(value);

	lunghezza = block.size();

	hByte = (lunghezza & 0xff00) >> 8;
	lByte = (lunghezza & 0x00ff);

	hByteMsg = (idMsg & 0xff00) >> 8;
	lByteMsg = (idMsg & 0x00ff);

	header.append(hByteMsg).append(lByteMsg).append(hByte).append(lByte);
	block.prepend(header);

	qDebug() << "Message send:" << block.toHex();

	return block;
}

/*****************************************************************
* to decode the massage into the value that we can understand
* latest version :2017/12/01
* function:clearMsg
******************************************************************/
unsigned short clearMsg(QByteArray msg, QByteArray &value) { // to decode the massage into the value that we can understand

	short lenMsg, func, lenValue;
	unsigned short idReadMsg;

	if (msg.size() > 0) { //decode : ID + length +  function + value
						  //Message ID
		idReadMsg = ((unsigned char)msg[0]) << 8 | ((unsigned char)msg[1]);
		qDebug() << "Message ID: " << idReadMsg;

		//Message Length
		lenMsg = ((unsigned char)msg[2]) << 8 | ((unsigned char)msg[3]);
		qDebug() << "Message Length:" << lenMsg;

		//Function(read:0/Write:1)
		func = ((int)msg[4]);
		qDebug() << "Function(read:0/Write:1) " << func;

		//Value Length
		lenValue = ((unsigned char)msg[5]) << 8 | ((unsigned char)msg[6]);
		qDebug() << "Value Length:" << lenValue;

		qDebug() << "Message return:" << msg.toHex();

		// the byte7 begin the value
		value = msg.mid(7, lenValue);
		return idReadMsg;

	}
	else {
		value = QByteArray("");
		return 0;
	}
}