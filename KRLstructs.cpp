#include <QtWidgets/QApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QTime>
#include <iostream>
#include "msgDeal.h"
#include "define.h"
#include "initCom.h"
#include "readANDwriteVar.h"


//struct KRLPos {
//
//	int X;
//	int Y;
//	int Z;
//	int A;
//	int B;
//	int C;
//	unsigned int S;
//	unsigned int T;
//
//	void setXToZ(int x, int y, int z)
//	{
//		X = x;
//		Y = y;
//		Z = z;
//	}
//
//	void setAToC(int a, int b, int c)
//	{
//		A = a;
//		B = b;
//		C = c;
//	}
//
//	void setS(int s)
//	{
//		S = s;
//	}
//
//	void setT(int t)
//	{
//		T = t;
//	}
//
//	int getX() {
//
//		return X;
//	}
//
//	int getY() {
//
//		return Y;
//	}
//
//	int getZ() {
//
//		return Z;
//	}
//
//	int getA() {
//
//		return A;
//	}
//
//	int getB() {
//
//		return B;
//	}
//
//	int getC() {
//
//		return C;
//	}
//
//	int getS() {
//
//		return S;
//	}
//
//	int getT() {
//
//		return T;
//	}
//
//};
//
////struct KRLE6Pos {
////	int X;
////	int Y;
////	int Z;
////	int A;
////	int B;
////	int C;
////	int E1;
////	int E2;
////	int E3;
////	int E4;
////	int E5;
////	int E6;
////	unsigned int S;
////	unsigned int T;
////};
//
//struct KRLAxis {
//
//	int A1;
//	int A2;
//	int A3;
//	int A4;
//	int A5;
//	int A6;
//
//	void setA1ToA6(int a1,int a2,int a3,int a4,int a5,int a6)
//	{
//		A1 = a1;
//		A2 = a2;
//		A3 = a3;
//		A4 = a4;
//		A5 = a5;
//		A6 = a6;
//	}
//
//	int getA1() {
//
//		return A1;
//	}
//
//	int getA2() {
//
//		return A2;
//	}
//
//	int getA3() {
//
//		return A3;
//	}
//
//	int getA4() {
//
//		return A4;
//	}
//
//	int getA5() {
//
//		return A5;
//	}
//
//	int getA6() {
//
//		return A6;
//	}
//};

