///
/// \brief HMLCDNumber
/// \author JackeyLea
/// \copyright MIT
/// \date 2021-03-13
/// \note 自定义的事件显示模块
///

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTimeUpdate();

private:
    Ui::MainWindow *ui;

    QTimer *m_pTimer;
};
#endif // MAINWINDOW_H
