/********************************************************************************
** Form generated from reading UI file 'kruppcalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KRUPPCALCULATOR_H
#define UI_KRUPPCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KruppCalculator
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *title_label;
    QLabel *errorMsg_label;
    QGridLayout *gridLayout_3;
    QLabel *velocity_label;
    QLabel *armor_label;
    QLineEdit *mass_lineEdit;
    QLabel *cal_measure_label;
    QLineEdit *vel_lineEdit;
    QLineEdit *cal_lineEdit;
    QLineEdit *res_lineEdit;
    QLabel *mass_measure_label;
    QLabel *mass_label;
    QLabel *caliber_label;
    QLabel *res_label;
    QLabel *armor_measure_label;
    QLineEdit *armor_lineEdit;
    QLabel *vel_measure_label;
    QPushButton *cal_convert_btn;
    QPushButton *mass_convert_btn;
    QPushButton *vel_convert_btn;
    QPushButton *armor_convert_btn;
    QHBoxLayout *horizontalLayout;
    QPushButton *calculate_btn;
    QPushButton *clear_btn;
    QLineEdit *result_lineEdit;
    QLabel *video_container;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *log_label;
    QPushButton *clearLog_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *KruppCalculator)
    {
        if (KruppCalculator->objectName().isEmpty())
            KruppCalculator->setObjectName(QString::fromUtf8("KruppCalculator"));
        KruppCalculator->resize(646, 746);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(KruppCalculator->sizePolicy().hasHeightForWidth());
        KruppCalculator->setSizePolicy(sizePolicy);
        KruppCalculator->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(KruppCalculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"margin: 2px;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        title_label = new QLabel(centralwidget);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title_label->sizePolicy().hasHeightForWidth());
        title_label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        title_label->setFont(font);
        title_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title_label);

        errorMsg_label = new QLabel(centralwidget);
        errorMsg_label->setObjectName(QString::fromUtf8("errorMsg_label"));
        sizePolicy1.setHeightForWidth(errorMsg_label->sizePolicy().hasHeightForWidth());
        errorMsg_label->setSizePolicy(sizePolicy1);
        errorMsg_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(226, 32, 6);\n"
"}"));
        errorMsg_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(errorMsg_label);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setContentsMargins(12, 12, 12, 12);
        velocity_label = new QLabel(centralwidget);
        velocity_label->setObjectName(QString::fromUtf8("velocity_label"));
        QFont font1;
        font1.setPointSize(16);
        velocity_label->setFont(font1);

        gridLayout_3->addWidget(velocity_label, 2, 0, 1, 1);

        armor_label = new QLabel(centralwidget);
        armor_label->setObjectName(QString::fromUtf8("armor_label"));
        armor_label->setFont(font1);

        gridLayout_3->addWidget(armor_label, 4, 0, 1, 1);

        mass_lineEdit = new QLineEdit(centralwidget);
        mass_lineEdit->setObjectName(QString::fromUtf8("mass_lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mass_lineEdit->sizePolicy().hasHeightForWidth());
        mass_lineEdit->setSizePolicy(sizePolicy2);
        mass_lineEdit->setFont(font1);
        mass_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 1px solid black;\n"
"}"));
        mass_lineEdit->setInputMethodHints(Qt::ImhNone);
        mass_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(mass_lineEdit, 1, 1, 1, 1);

        cal_measure_label = new QLabel(centralwidget);
        cal_measure_label->setObjectName(QString::fromUtf8("cal_measure_label"));
        cal_measure_label->setFont(font1);

        gridLayout_3->addWidget(cal_measure_label, 0, 2, 1, 1);

        vel_lineEdit = new QLineEdit(centralwidget);
        vel_lineEdit->setObjectName(QString::fromUtf8("vel_lineEdit"));
        sizePolicy2.setHeightForWidth(vel_lineEdit->sizePolicy().hasHeightForWidth());
        vel_lineEdit->setSizePolicy(sizePolicy2);
        vel_lineEdit->setFont(font1);
        vel_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 1px solid black;\n"
"}"));
        vel_lineEdit->setInputMethodHints(Qt::ImhNone);
        vel_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(vel_lineEdit, 2, 1, 1, 1);

        cal_lineEdit = new QLineEdit(centralwidget);
        cal_lineEdit->setObjectName(QString::fromUtf8("cal_lineEdit"));
        sizePolicy2.setHeightForWidth(cal_lineEdit->sizePolicy().hasHeightForWidth());
        cal_lineEdit->setSizePolicy(sizePolicy2);
        cal_lineEdit->setFont(font1);
        cal_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 1px solid black;\n"
"}"));
        cal_lineEdit->setInputMethodHints(Qt::ImhNone);
        cal_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(cal_lineEdit, 0, 1, 1, 1);

        res_lineEdit = new QLineEdit(centralwidget);
        res_lineEdit->setObjectName(QString::fromUtf8("res_lineEdit"));
        sizePolicy2.setHeightForWidth(res_lineEdit->sizePolicy().hasHeightForWidth());
        res_lineEdit->setSizePolicy(sizePolicy2);
        res_lineEdit->setFont(font1);
        res_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 1px solid black;\n"
"}"));
        res_lineEdit->setInputMethodHints(Qt::ImhNone);
        res_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(res_lineEdit, 3, 1, 1, 1);

        mass_measure_label = new QLabel(centralwidget);
        mass_measure_label->setObjectName(QString::fromUtf8("mass_measure_label"));
        mass_measure_label->setFont(font1);

        gridLayout_3->addWidget(mass_measure_label, 1, 2, 1, 1);

        mass_label = new QLabel(centralwidget);
        mass_label->setObjectName(QString::fromUtf8("mass_label"));
        mass_label->setFont(font1);

        gridLayout_3->addWidget(mass_label, 1, 0, 1, 1);

        caliber_label = new QLabel(centralwidget);
        caliber_label->setObjectName(QString::fromUtf8("caliber_label"));
        caliber_label->setFont(font1);

        gridLayout_3->addWidget(caliber_label, 0, 0, 1, 1);

        res_label = new QLabel(centralwidget);
        res_label->setObjectName(QString::fromUtf8("res_label"));
        res_label->setFont(font1);

        gridLayout_3->addWidget(res_label, 3, 0, 1, 1);

        armor_measure_label = new QLabel(centralwidget);
        armor_measure_label->setObjectName(QString::fromUtf8("armor_measure_label"));
        armor_measure_label->setFont(font1);

        gridLayout_3->addWidget(armor_measure_label, 4, 2, 1, 1);

        armor_lineEdit = new QLineEdit(centralwidget);
        armor_lineEdit->setObjectName(QString::fromUtf8("armor_lineEdit"));
        sizePolicy2.setHeightForWidth(armor_lineEdit->sizePolicy().hasHeightForWidth());
        armor_lineEdit->setSizePolicy(sizePolicy2);
        armor_lineEdit->setFont(font1);
        armor_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 1px solid black;\n"
"}"));
        armor_lineEdit->setInputMethodHints(Qt::ImhNone);
        armor_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(armor_lineEdit, 4, 1, 1, 1);

        vel_measure_label = new QLabel(centralwidget);
        vel_measure_label->setObjectName(QString::fromUtf8("vel_measure_label"));
        vel_measure_label->setFont(font1);

        gridLayout_3->addWidget(vel_measure_label, 2, 2, 1, 1);

        cal_convert_btn = new QPushButton(centralwidget);
        cal_convert_btn->setObjectName(QString::fromUtf8("cal_convert_btn"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cal_convert_btn->sizePolicy().hasHeightForWidth());
        cal_convert_btn->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(12);
        cal_convert_btn->setFont(font2);
        cal_convert_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(226, 230, 230);\n"
"border: 1px solid black;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(181, 184, 184);\n"
"padding: 5px;\n"
"}"));

        gridLayout_3->addWidget(cal_convert_btn, 0, 3, 1, 1);

        mass_convert_btn = new QPushButton(centralwidget);
        mass_convert_btn->setObjectName(QString::fromUtf8("mass_convert_btn"));
        sizePolicy3.setHeightForWidth(mass_convert_btn->sizePolicy().hasHeightForWidth());
        mass_convert_btn->setSizePolicy(sizePolicy3);
        mass_convert_btn->setFont(font2);
        mass_convert_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(226, 230, 230);\n"
"border: 1px solid black;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(181, 184, 184);\n"
"padding: 5px;\n"
"}"));

        gridLayout_3->addWidget(mass_convert_btn, 1, 3, 1, 1);

        vel_convert_btn = new QPushButton(centralwidget);
        vel_convert_btn->setObjectName(QString::fromUtf8("vel_convert_btn"));
        sizePolicy3.setHeightForWidth(vel_convert_btn->sizePolicy().hasHeightForWidth());
        vel_convert_btn->setSizePolicy(sizePolicy3);
        vel_convert_btn->setFont(font2);
        vel_convert_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(226, 230, 230);\n"
"border: 1px solid black;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(181, 184, 184);\n"
"padding: 5px;\n"
"}"));

        gridLayout_3->addWidget(vel_convert_btn, 2, 3, 1, 1);

        armor_convert_btn = new QPushButton(centralwidget);
        armor_convert_btn->setObjectName(QString::fromUtf8("armor_convert_btn"));
        sizePolicy3.setHeightForWidth(armor_convert_btn->sizePolicy().hasHeightForWidth());
        armor_convert_btn->setSizePolicy(sizePolicy3);
        armor_convert_btn->setFont(font2);
        armor_convert_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(226, 230, 230);\n"
"border: 1px solid black;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(181, 184, 184);\n"
"padding: 5px;\n"
"}"));

        gridLayout_3->addWidget(armor_convert_btn, 4, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        calculate_btn = new QPushButton(centralwidget);
        calculate_btn->setObjectName(QString::fromUtf8("calculate_btn"));
        sizePolicy3.setHeightForWidth(calculate_btn->sizePolicy().hasHeightForWidth());
        calculate_btn->setSizePolicy(sizePolicy3);
        calculate_btn->setFont(font1);
        calculate_btn->setLayoutDirection(Qt::LeftToRight);
        calculate_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(226, 230, 230);\n"
"border: 1px solid black;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(181, 184, 184);\n"
"padding: 5px;\n"
"}"));

        horizontalLayout->addWidget(calculate_btn);

        clear_btn = new QPushButton(centralwidget);
        clear_btn->setObjectName(QString::fromUtf8("clear_btn"));
        sizePolicy3.setHeightForWidth(clear_btn->sizePolicy().hasHeightForWidth());
        clear_btn->setSizePolicy(sizePolicy3);
        clear_btn->setFont(font1);
        clear_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(226, 230, 230);\n"
"border: 1px solid black;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(181, 184, 184);\n"
"padding: 5px;\n"
"}"));

        horizontalLayout->addWidget(clear_btn);


        verticalLayout->addLayout(horizontalLayout);

        result_lineEdit = new QLineEdit(centralwidget);
        result_lineEdit->setObjectName(QString::fromUtf8("result_lineEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(result_lineEdit->sizePolicy().hasHeightForWidth());
        result_lineEdit->setSizePolicy(sizePolicy4);
        QFont font3;
        font3.setPointSize(14);
        result_lineEdit->setFont(font3);
        result_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 1px solid black;\n"
"padding-top: 2px;\n"
"padding-bottom: 2px;\n"
"margin-bottom: 5px;\n"
"}"));
        result_lineEdit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        result_lineEdit->setReadOnly(true);

        verticalLayout->addWidget(result_lineEdit);

        video_container = new QLabel(centralwidget);
        video_container->setObjectName(QString::fromUtf8("video_container"));
        video_container->setFrameShape(QFrame::Box);
        video_container->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(video_container);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 616, 72));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        log_label = new QLabel(scrollAreaWidgetContents);
        log_label->setObjectName(QString::fromUtf8("log_label"));
        sizePolicy1.setHeightForWidth(log_label->sizePolicy().hasHeightForWidth());
        log_label->setSizePolicy(sizePolicy1);
        log_label->setFont(font1);

        verticalLayout_2->addWidget(log_label);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        clearLog_btn = new QPushButton(centralwidget);
        clearLog_btn->setObjectName(QString::fromUtf8("clearLog_btn"));
        sizePolicy3.setHeightForWidth(clearLog_btn->sizePolicy().hasHeightForWidth());
        clearLog_btn->setSizePolicy(sizePolicy3);
        clearLog_btn->setFont(font1);
        clearLog_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(226, 230, 230);\n"
"border: 1px solid black;\n"
"padding: 5px;\n"
"margin-left: 270%;\n"
"margin-bottom: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(181, 184, 184);\n"
"padding: 5px;\n"
"}"));

        verticalLayout->addWidget(clearLog_btn);

        KruppCalculator->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(KruppCalculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        KruppCalculator->setStatusBar(statusbar);

        retranslateUi(KruppCalculator);

        QMetaObject::connectSlotsByName(KruppCalculator);
    } // setupUi

    void retranslateUi(QMainWindow *KruppCalculator)
    {
        KruppCalculator->setWindowTitle(QCoreApplication::translate("KruppCalculator", "KruppCalculator", nullptr));
        title_label->setText(QCoreApplication::translate("KruppCalculator", "Krupp Calculator", nullptr));
        errorMsg_label->setText(QString());
        velocity_label->setText(QCoreApplication::translate("KruppCalculator", "Velocity", nullptr));
        armor_label->setText(QCoreApplication::translate("KruppCalculator", "Armor", nullptr));
        mass_lineEdit->setText(QString());
        cal_measure_label->setText(QCoreApplication::translate("KruppCalculator", "mm", nullptr));
        vel_lineEdit->setText(QString());
        cal_lineEdit->setText(QString());
        res_lineEdit->setText(QString());
        mass_measure_label->setText(QCoreApplication::translate("KruppCalculator", "kg", nullptr));
        mass_label->setText(QCoreApplication::translate("KruppCalculator", "Mass", nullptr));
        caliber_label->setText(QCoreApplication::translate("KruppCalculator", "Caliber", nullptr));
        res_label->setText(QCoreApplication::translate("KruppCalculator", "Resistance", nullptr));
        armor_measure_label->setText(QCoreApplication::translate("KruppCalculator", "mm", nullptr));
        armor_lineEdit->setText(QString());
        vel_measure_label->setText(QCoreApplication::translate("KruppCalculator", "m/s", nullptr));
        cal_convert_btn->setText(QCoreApplication::translate("KruppCalculator", "convert measurement", nullptr));
        mass_convert_btn->setText(QCoreApplication::translate("KruppCalculator", "convert measurement", nullptr));
        vel_convert_btn->setText(QCoreApplication::translate("KruppCalculator", "convert measurement", nullptr));
        armor_convert_btn->setText(QCoreApplication::translate("KruppCalculator", "convert measurement", nullptr));
        calculate_btn->setText(QCoreApplication::translate("KruppCalculator", "Calculate", nullptr));
        clear_btn->setText(QCoreApplication::translate("KruppCalculator", "Clear All", nullptr));
        result_lineEdit->setPlaceholderText(QCoreApplication::translate("KruppCalculator", "Result", nullptr));
        video_container->setText(QString());
        log_label->setText(QCoreApplication::translate("KruppCalculator", "Log", nullptr));
        clearLog_btn->setText(QCoreApplication::translate("KruppCalculator", "Clear Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KruppCalculator: public Ui_KruppCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KRUPPCALCULATOR_H
