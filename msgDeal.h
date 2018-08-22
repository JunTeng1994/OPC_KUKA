#pragma once
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QTime>
#include <iostream>
#include "msgDeal.h"
#include "define.h"
#include "initCom.h"

#ifndef MSGDEAL_H
#define MSGDEAL_H

extern QByteArray formatMsg(QByteArray msg, unsigned short idMsg);

extern QByteArray formatMsg(QByteArray msg, QByteArray value, unsigned short idMsg);

extern unsigned short clearMsg(QByteArray msg, QByteArray &value);

#endif