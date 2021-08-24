#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //button
    void btn_open_port(bool);
    void btn_close_port(bool);
    void btn_send1_data(bool);

    //receive data by serial port
    void sp_receive_data();
private:
    Ui::MainWindow *ui;
    /*------function--------*/
    void system_init();

    /*-------variable-------*/
    QSerialPort global_port;

};
#endif // MAINWINDOW_H
