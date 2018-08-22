#pragma once
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QTime>
#include <iostream>
#include "msgDeal.h"
#include "define.h"
#include "initCom.h"
//#include "readANDwriteVar.h"

#ifndef KRLSTRUCTS_H
#define KRLSTRUCTS_H

/**********************************************************
* to build the POS structs
*
***********************************************************/
struct KRLPos {

	double X = 0;
	double Y = 0;
	double Z = 0;
	double A = 0;
	double B = 0;
	double C = 0;
	unsigned int S = 0;
	unsigned int T = 0;

	void setXToZ(double x, double y, double z)
	{
		X = x;
		Y = y;
		Z = z;
	}

	void setAToC(double a, double b, double c)
	{
		A = a;
		B = b;
		C = c;
	}

	void setS(unsigned int s)
	{
		S = s;
	}

	void setT(unsigned int t)
	{
		T = t;
	}

	double getX() {

		return X;
	}

	double getY() {

		return Y;
	}

	double getZ() {

		return Z;
	}

	double getA() {

		return A;
	}

	double getB() {

		return B;
	}

	double getC() {

		return C;
	}

	unsigned int  getS() {

		return S;
	}

	unsigned int  getT() {

		return T;
	}

};

/**********************************************************
* to build the AXIS structs
*
***********************************************************/
struct KRLAxis {

	double A1 = 0;
	double A2 = 0;
	double A3 = 0;
	double A4 = 0;
	double A5 = 0;
	double A6 = 0;

	void setA1ToA6(double a1, double a2, double a3, double a4, double a5, double a6)
	{
		A1 = a1;
		A2 = a2;
		A3 = a3;
		A4 = a4;
		A5 = a5;
		A6 = a6;
	}

	double getA1() {

		return A1;
	}

	double getA2() {

		return A2;
	}

	double getA3() {

		return A3;
	}

	double getA4() {

		return A4;
	}

	double getA5() {

		return A5;
	}

	double getA6() {

		return A6;
	}
};



#endif