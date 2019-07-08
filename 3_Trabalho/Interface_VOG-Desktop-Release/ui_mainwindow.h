/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tv_tab;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_10;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *verticalSpacer_11;
    QGridLayout *gridLayout;
    QPushButton *button_1;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QSpacerItem *verticalSpacer_15;
    QSpacerItem *verticalSpacer_16;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *button_up;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *button_left;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *button_right;
    QSpacerItem *horizontalSpacer_22;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *button_down;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *horizontalSpacer_25;
    QWidget *ar_tab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonOnOff;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_4;
    QPushButton *buttonMode;
    QPushButton *buttonSleep;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_7;
    QPushButton *buttonFan;
    QSpacerItem *verticalSpacer_8;
    QVBoxLayout *verticalLayout_2;
    QPushButton *buttonTempPlus;
    QPushButton *buttonTempMinus;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_9;
    QPushButton *buttonSwing;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QWidget *msg_tab;
    QVBoxLayout *verticalLayout_15;
    QLabel *label;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_26;
    QPushButton *pushButton_15;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *verticalSpacer_14;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(960, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMaximumSize(QSize(960, 720));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(235, 50));
        tv_tab = new QWidget();
        tv_tab->setObjectName(QStringLiteral("tv_tab"));
        horizontalLayout_5 = new QHBoxLayout(tv_tab);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        pushButton = new QPushButton(tv_tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/iconfinder_Power_symbol_2638316.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(20, 20));

        horizontalLayout_13->addWidget(pushButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        pushButton_10 = new QPushButton(tv_tab);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/iconfinder_v-24_3162619.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon1);
        pushButton_10->setIconSize(QSize(20, 20));

        horizontalLayout_13->addWidget(pushButton_10);


        verticalLayout_13->addLayout(horizontalLayout_13);

        verticalSpacer_18 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_13->addItem(verticalSpacer_18);


        verticalLayout_7->addLayout(verticalLayout_13);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_7->addItem(verticalSpacer_11);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        button_1 = new QPushButton(tv_tab);
        button_1->setObjectName(QStringLiteral("button_1"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(button_1->sizePolicy().hasHeightForWidth());
        button_1->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(button_1, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(tv_tab);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy2.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_9, 3, 2, 1, 1);

        pushButton_6 = new QPushButton(tv_tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_8 = new QPushButton(tv_tab);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy2.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);

        pushButton_4 = new QPushButton(tv_tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_4, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(tv_tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(tv_tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(tv_tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy2.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(tv_tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout);


        horizontalLayout_5->addLayout(verticalLayout_7);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        pushButton_11 = new QPushButton(tv_tab);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy2.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/iconfinder_v-21_3162621.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon2);
        pushButton_11->setIconSize(QSize(20, 20));

        verticalLayout_10->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(tv_tab);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy2.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/iconfinder_v-23_3162620.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon3);
        pushButton_12->setIconSize(QSize(16, 16));

        verticalLayout_10->addWidget(pushButton_12);


        horizontalLayout_12->addLayout(verticalLayout_10);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_7);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        pushButton_13 = new QPushButton(tv_tab);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy2.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/iconfinder_control-eject-out-disk-remove_3209402.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon4);
        pushButton_13->setIconSize(QSize(20, 20));

        verticalLayout_12->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(tv_tab);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy2.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/3209402-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon5);
        pushButton_14->setIconSize(QSize(20, 20));

        verticalLayout_12->addWidget(pushButton_14);


        horizontalLayout_12->addLayout(verticalLayout_12);


        verticalLayout_6->addLayout(horizontalLayout_12);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_6->addItem(verticalSpacer_15);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_6->addItem(verticalSpacer_16);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_14);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_17);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_15);

        button_up = new QPushButton(tv_tab);
        button_up->setObjectName(QStringLiteral("button_up"));
        sizePolicy2.setHeightForWidth(button_up->sizePolicy().hasHeightForWidth());
        button_up->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/iconfinder_up_375749.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_up->setIcon(icon6);
        button_up->setIconSize(QSize(40, 40));

        horizontalLayout_20->addWidget(button_up);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_13);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_18);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_16);


        verticalLayout_14->addLayout(horizontalLayout_20);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_20);

        button_left = new QPushButton(tv_tab);
        button_left->setObjectName(QStringLiteral("button_left"));
        sizePolicy2.setHeightForWidth(button_left->sizePolicy().hasHeightForWidth());
        button_left->setSizePolicy(sizePolicy2);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/iconfinder_left_375755.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_left->setIcon(icon7);
        button_left->setIconSize(QSize(40, 40));

        horizontalLayout_18->addWidget(button_left);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_12);

        button_right = new QPushButton(tv_tab);
        button_right->setObjectName(QStringLiteral("button_right"));
        sizePolicy2.setHeightForWidth(button_right->sizePolicy().hasHeightForWidth());
        button_right->setSizePolicy(sizePolicy2);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/iconfinder_right_375751.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_right->setIcon(icon8);
        button_right->setIconSize(QSize(40, 40));

        horizontalLayout_18->addWidget(button_right);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_22);


        verticalLayout_14->addLayout(horizontalLayout_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_11);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_21);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_24);

        button_down = new QPushButton(tv_tab);
        button_down->setObjectName(QStringLiteral("button_down"));
        sizePolicy2.setHeightForWidth(button_down->sizePolicy().hasHeightForWidth());
        button_down->setSizePolicy(sizePolicy2);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/iconfinder_down_375747.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_down->setIcon(icon9);
        button_down->setIconSize(QSize(40, 40));

        horizontalLayout_14->addWidget(button_down);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_23);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_25);


        verticalLayout_14->addLayout(horizontalLayout_14);


        verticalLayout_6->addLayout(verticalLayout_14);


        horizontalLayout_5->addLayout(verticalLayout_6);

        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/scanner.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tv_tab, icon10, QString());
        ar_tab = new QWidget();
        ar_tab->setObjectName(QStringLiteral("ar_tab"));
        verticalLayout_3 = new QVBoxLayout(ar_tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer);

        buttonOnOff = new QPushButton(ar_tab);
        buttonOnOff->setObjectName(QStringLiteral("buttonOnOff"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(buttonOnOff->sizePolicy().hasHeightForWidth());
        buttonOnOff->setSizePolicy(sizePolicy3);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/new/prefix1/img/824687-air-conditioning/png/011-air-conditioner.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOnOff->setIcon(icon11);
        buttonOnOff->setIconSize(QSize(25, 25));

        verticalLayout_4->addWidget(buttonOnOff);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(500, 21, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_9->addItem(verticalSpacer_4);

        buttonMode = new QPushButton(ar_tab);
        buttonMode->setObjectName(QStringLiteral("buttonMode"));
        sizePolicy2.setHeightForWidth(buttonMode->sizePolicy().hasHeightForWidth());
        buttonMode->setSizePolicy(sizePolicy2);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/new/prefix1/img/824687-air-conditioning/png/029-mode.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMode->setIcon(icon12);
        buttonMode->setIconSize(QSize(20, 20));

        verticalLayout_9->addWidget(buttonMode);

        buttonSleep = new QPushButton(ar_tab);
        buttonSleep->setObjectName(QStringLiteral("buttonSleep"));
        sizePolicy2.setHeightForWidth(buttonSleep->sizePolicy().hasHeightForWidth());
        buttonSleep->setSizePolicy(sizePolicy2);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/new/prefix1/img/824687-air-conditioning/png/030-sleep.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonSleep->setIcon(icon13);
        buttonSleep->setIconSize(QSize(20, 20));

        verticalLayout_9->addWidget(buttonSleep);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_9->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout_9);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_8->addItem(verticalSpacer_7);

        buttonFan = new QPushButton(ar_tab);
        buttonFan->setObjectName(QStringLiteral("buttonFan"));
        sizePolicy2.setHeightForWidth(buttonFan->sizePolicy().hasHeightForWidth());
        buttonFan->setSizePolicy(sizePolicy2);
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/new/prefix1/008-fan.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonFan->setIcon(icon14);
        buttonFan->setIconSize(QSize(20, 20));

        verticalLayout_8->addWidget(buttonFan);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_8->addItem(verticalSpacer_8);


        horizontalLayout_4->addLayout(verticalLayout_8);


        horizontalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        buttonTempPlus = new QPushButton(ar_tab);
        buttonTempPlus->setObjectName(QStringLiteral("buttonTempPlus"));
        sizePolicy2.setHeightForWidth(buttonTempPlus->sizePolicy().hasHeightForWidth());
        buttonTempPlus->setSizePolicy(sizePolicy2);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/new/prefix1/003-heat.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonTempPlus->setIcon(icon15);
        buttonTempPlus->setIconSize(QSize(20, 20));

        verticalLayout_2->addWidget(buttonTempPlus);

        buttonTempMinus = new QPushButton(ar_tab);
        buttonTempMinus->setObjectName(QStringLiteral("buttonTempMinus"));
        sizePolicy2.setHeightForWidth(buttonTempMinus->sizePolicy().hasHeightForWidth());
        buttonTempMinus->setSizePolicy(sizePolicy2);
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/new/prefix1/002-cold.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonTempMinus->setIcon(icon16);
        buttonTempMinus->setIconSize(QSize(20, 20));

        verticalLayout_2->addWidget(buttonTempMinus);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer_9);

        buttonSwing = new QPushButton(ar_tab);
        buttonSwing->setObjectName(QStringLiteral("buttonSwing"));
        sizePolicy3.setHeightForWidth(buttonSwing->sizePolicy().hasHeightForWidth());
        buttonSwing->setSizePolicy(sizePolicy3);
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/new/prefix1/023-wind.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonSwing->setIcon(icon17);
        buttonSwing->setIconSize(QSize(18, 18));

        verticalLayout_5->addWidget(buttonSwing);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer_10);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(ar_tab, icon16, QString());
        msg_tab = new QWidget();
        msg_tab->setObjectName(QStringLiteral("msg_tab"));
        verticalLayout_15 = new QVBoxLayout(msg_tab);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label = new QLabel(msg_tab);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_15->addWidget(label);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_15->addItem(verticalSpacer_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(msg_tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setTextFormat(Qt::AutoText);

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_26);

        pushButton_15 = new QPushButton(msg_tab);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy4);
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/new/prefix1/img/iconfinder_outlined_comment_4280528.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon18);
        pushButton_15->setIconSize(QSize(50, 50));

        horizontalLayout_6->addWidget(pushButton_15);


        verticalLayout_15->addLayout(horizontalLayout_6);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_15->addItem(verticalSpacer_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));

        verticalLayout_15->addLayout(horizontalLayout_7);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_15->addItem(verticalSpacer_14);

        QIcon icon19;
        icon19.addFile(QStringLiteral(":/new/prefix1/mobile-app.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(msg_tab, icon19, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 27));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", " On / Off", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", " Mute", Q_NULLPTR));
        button_1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", " VOL UP", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", " VOL DOWN", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", " CH UP", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", " CH DOWN", Q_NULLPTR));
        button_up->setText(QString());
        button_left->setText(QString());
        button_right->setText(QString());
        button_down->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tv_tab), QApplication::translate("MainWindow", "TV", Q_NULLPTR));
        buttonOnOff->setText(QApplication::translate("MainWindow", "  On / Off", Q_NULLPTR));
        buttonMode->setText(QApplication::translate("MainWindow", " Mode", Q_NULLPTR));
        buttonSleep->setText(QApplication::translate("MainWindow", " Sleep", Q_NULLPTR));
        buttonFan->setText(QApplication::translate("MainWindow", " Fan", Q_NULLPTR));
        buttonTempPlus->setText(QApplication::translate("MainWindow", " Temp +", Q_NULLPTR));
        buttonTempMinus->setText(QApplication::translate("MainWindow", " Temp -", Q_NULLPTR));
        buttonSwing->setText(QApplication::translate("MainWindow", " Swing", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(ar_tab), QApplication::translate("MainWindow", "Ar Cond", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Contatos de Emerg\303\252ncia", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Jo\303\243o Paulo Sanches Guimar\303\243es", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "Mensagem de Emerg\303\252ncia", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(msg_tab), QApplication::translate("MainWindow", "Mensagem", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
