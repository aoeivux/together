/********************************************************************************
** Form generated from reading UI file 'connecttoserver.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTTOSERVER_H
#define UI_CONNECTTOSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConnectToServer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ipInput;
    QLabel *label_2;
    QLineEdit *portInput;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *usernameInput;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConnectToServer)
    {
        if (ConnectToServer->objectName().isEmpty())
            ConnectToServer->setObjectName("ConnectToServer");
        ConnectToServer->resize(850, 475);
        verticalLayout = new QVBoxLayout(ConnectToServer);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(ConnectToServer);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        ipInput = new QLineEdit(ConnectToServer);
        ipInput->setObjectName("ipInput");

        horizontalLayout->addWidget(ipInput);

        label_2 = new QLabel(ConnectToServer);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        portInput = new QLineEdit(ConnectToServer);
        portInput->setObjectName("portInput");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(portInput->sizePolicy().hasHeightForWidth());
        portInput->setSizePolicy(sizePolicy);
        portInput->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(portInput);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(ConnectToServer);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        usernameInput = new QLineEdit(ConnectToServer);
        usernameInput->setObjectName("usernameInput");

        horizontalLayout_2->addWidget(usernameInput);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(ConnectToServer);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ConnectToServer);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ConnectToServer, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ConnectToServer, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ConnectToServer);
    } // setupUi

    void retranslateUi(QDialog *ConnectToServer)
    {
        ConnectToServer->setWindowTitle(QCoreApplication::translate("ConnectToServer", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ConnectToServer", "Url/IP:", nullptr));
        ipInput->setText(QCoreApplication::translate("ConnectToServer", "localhost", nullptr));
        label_2->setText(QCoreApplication::translate("ConnectToServer", "Port:", nullptr));
        portInput->setText(QCoreApplication::translate("ConnectToServer", "1234", nullptr));
        label_3->setText(QCoreApplication::translate("ConnectToServer", "Username:", nullptr));
        usernameInput->setText(QCoreApplication::translate("ConnectToServer", "client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectToServer: public Ui_ConnectToServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTTOSERVER_H
