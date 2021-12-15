#include "mainwindow.h"
#include "./ui_mainwindow.h"

void calculate(char sign, float *num1, float *num2);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = "";
    str = "";
    num1 = 0.0;
    num2 = 0.0;
    res = 0.0;
    mark = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{
    s+="1";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 1;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 1;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    s+="2";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 2;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 2;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    s+="3";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 3;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 3;
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    s+="4";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 4;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 4;
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    s+="5";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 5;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 5;
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    s+="6";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 6;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 6;
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    s+="7";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 7;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 7;
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    s+="8";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 8;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 8;
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    s+="9";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 9;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 9;
    }
}


void MainWindow::on_pushButton_0_clicked()
{
    s+="0";
    ui->textBrowser->setText(s);
    if(mark)
    {
        num2 = num2 * 10 + 0;
        calculate(sign, &num1, &num2);
        s=QString("%1").arg(num1);
        ui->textBrowser->setText(s);
    }
    else
    {
        num1 = num1 * 10 + 0;
    }
}


void MainWindow::on_pushButton_mul_clicked() //×
{
    s+="x";
    ui->textBrowser->setText(s);
    mark = true;
    sign = 'x';
}

void MainWindow::on_pushButton_add_clicked() //+
{
    s+="+";
    ui->textBrowser->setText(s);
    mark = true;
    sign = '+';
}

void MainWindow::on_pushButton_min_clicked() //-
{
    s+="-";
    ui->textBrowser->setText(s);
    mark = true;
    sign = '-';
}

void MainWindow::on_pushButton_div_clicked() // div
{
    s+="/";
    ui->textBrowser->setText(s);
    mark = true;
    sign = '/';
}

void MainWindow::on_pushButton_equ_clicked() //=
{
    s+="=";

    calculate(sign, &num1, &num2);

    s+=QString("%1").arg(num1);
    ui->textBrowser->setText(s);
}


void MainWindow::on_pushButton_c_clicked() //clear
{
    s="";
    ui->textBrowser->setText(s);
    num1=0.0;
    num2=0.0;
    res=0.0;
    mark=false;
}

void calculate(char sign, float *num1, float *num2)
{
    switch(sign)
    {
    case '+':
        *num1 = *num1 + *num2;
        *num2 = 0.0;
        break;
    case '-':
        *num1 = *num1 - *num2;
        *num2 = 0.0;
        break;
    case 'x':
        *num1 = *num1 * *num2;
        *num2 = 0.0;
        break;
    case '/':
        *num1 = *num1 / *num2;
        *num2 = 0.0;
        break;
    default:
        break;
    }
}




