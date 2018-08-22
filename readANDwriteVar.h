#pragma once
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QTime>
#include <iostream>
#include "msgDeal.h"
#include "KRLstructs.h"		

#ifndef READANDWRITEVAR_H
#define READANDWRITEVAR_H

extern QByteArray readRequest(unsigned short id , QByteArray var);

extern void writeRequest( unsigned short id , QByteArray var, QByteArray value);

extern QString readVariable(QByteArray var);

extern void writeVariableKRLPos(KRLPos pos);

extern void writeVariableKRLAxis(KRLAxis axis);

#endif