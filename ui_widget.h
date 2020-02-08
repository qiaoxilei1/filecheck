/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *shadowWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *butmin;
    QPushButton *butmax;
    QPushButton *butclose;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(764, 445);
        shadowWidget = new QWidget(Widget);
        shadowWidget->setObjectName(QStringLiteral("shadowWidget"));
        shadowWidget->setGeometry(QRect(50, 20, 661, 391));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shadowWidget->sizePolicy().hasHeightForWidth());
        shadowWidget->setSizePolicy(sizePolicy);
        shadowWidget->setStyleSheet(QLatin1String("#shadowWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        horizontalLayoutWidget = new QWidget(shadowWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 641, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        butmin = new QPushButton(horizontalLayoutWidget);
        butmin->setObjectName(QStringLiteral("butmin"));
        butmin->setMinimumSize(QSize(42, 42));
        butmin->setMaximumSize(QSize(42, 42));
        butmin->setSizeIncrement(QSize(42, 42));

        horizontalLayout->addWidget(butmin);

        butmax = new QPushButton(horizontalLayoutWidget);
        butmax->setObjectName(QStringLiteral("butmax"));
        butmax->setMinimumSize(QSize(42, 42));
        butmax->setMaximumSize(QSize(42, 42));
        butmax->setSizeIncrement(QSize(42, 42));

        horizontalLayout->addWidget(butmax);

        butclose = new QPushButton(horizontalLayoutWidget);
        butclose->setObjectName(QStringLiteral("butclose"));
        butclose->setMinimumSize(QSize(42, 42));
        butclose->setMaximumSize(QSize(42, 42));
        butclose->setSizeIncrement(QSize(42, 42));

        horizontalLayout->addWidget(butclose);

        pushButton = new QPushButton(shadowWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 180, 93, 28));
        pushButton_2 = new QPushButton(shadowWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 180, 93, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        butmin->setText(QApplication::translate("Widget", "butclose", Q_NULLPTR));
        butmax->setText(QApplication::translate("Widget", "butclose", Q_NULLPTR));
        butclose->setText(QApplication::translate("Widget", "butclose", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "getfile", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
