#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_4");
}

void MainWindow::on_button_1_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_1");
}

void MainWindow::on_pushButton_5_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_2");
}

void MainWindow::on_pushButton_4_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_3");
}

void MainWindow::on_pushButton_6_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_5");
}

void MainWindow::on_pushButton_3_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_6");
}

void MainWindow::on_pushButton_7_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_7");
}

void MainWindow::on_pushButton_8_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_8");
}

void MainWindow::on_pushButton_9_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_NUMERIC_9");
}

void MainWindow::on_pushButton_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_POWER");
}

void MainWindow::on_pushButton_10_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_MUTE");
}

void MainWindow::on_pushButton_11_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_VOLUMEUP");
}

void MainWindow::on_pushButton_12_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_VOLUMEDOWN");
}

void MainWindow::on_pushButton_13_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_CHANNELUP");
}

void MainWindow::on_pushButton_14_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_CHANNELDOWN");
}

void MainWindow::on_button_up_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_UP");
}

void MainWindow::on_button_down_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_DOWN");
}


void MainWindow::on_button_left_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_LEFT");
}

void MainWindow::on_button_right_clicked()
{
    system("irsend SEND_ONCE meucontrole KEY_RIGHT");
}

void MainWindow::on_pushButton_15_clicked()
{
    system("python3 ~/Desktop/testsms.py");
}
