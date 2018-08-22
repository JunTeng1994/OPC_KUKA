/********************************************************************************
** Form generated from reading UI file 'JOpenShowVar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOPENSHOWVAR_H
#define UI_JOPENSHOWVAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JOpenShowVarClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JOpenShowVarClass)
    {
        if (JOpenShowVarClass->objectName().isEmpty())
            JOpenShowVarClass->setObjectName(QStringLiteral("JOpenShowVarClass"));
        JOpenShowVarClass->resize(600, 400);
        menuBar = new QMenuBar(JOpenShowVarClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        JOpenShowVarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(JOpenShowVarClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        JOpenShowVarClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(JOpenShowVarClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        JOpenShowVarClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(JOpenShowVarClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JOpenShowVarClass->setStatusBar(statusBar);

        retranslateUi(JOpenShowVarClass);

        QMetaObject::connectSlotsByName(JOpenShowVarClass);
    } // setupUi

    void retranslateUi(QMainWindow *JOpenShowVarClass)
    {
        JOpenShowVarClass->setWindowTitle(QApplication::translate("JOpenShowVarClass", "JOpenShowVar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JOpenShowVarClass: public Ui_JOpenShowVarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOPENSHOWVAR_H
