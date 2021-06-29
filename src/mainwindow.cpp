#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcdNumber->setDigitCount(25);//设置显示的位数
    ui->lcdNumber->setMode(QLCDNumber::Dec);//设置显示模式为十进制
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);//设置显示外观

    //ui->lcdNumber->setStyleSheet("border: 1px solid green; color: green; background: silver;");//设置样式

    m_pTimer = new QTimer(this);
    m_pTimer->setInterval(100);//设置时间间隔
    connect(m_pTimer,&QTimer::timeout,this,&MainWindow::onTimeUpdate);
    m_pTimer->start();//启动定时器
}

MainWindow::~MainWindow()
{
    delete m_pTimer;
    delete ui;
}

void MainWindow::onTimeUpdate()
{
    QDateTime dateTime = QDateTime::currentDateTime();//获取系统当前时间
    ui->lcdNumber->display(dateTime.toString("yyyy-MM-dd HH:mm:ss.zzz"));//显示内容，显示格式为年-月-日 时:分:秒.毫秒
}

