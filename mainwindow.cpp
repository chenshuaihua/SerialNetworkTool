#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("串口调试助手");
    system_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*-----------functions---------*/
void MainWindow::system_init()
{
    //port config
    global_port.setParity(QSerialPort::NoParity);
    global_port.setDataBits(QSerialPort::Data8);
    global_port.setStopBits(QSerialPort::OneStop);

    //connect
    connect(ui->btn_open,&QPushButton::clicked,this,&MainWindow::btn_open_port);
    connect(ui->btn_close,&QPushButton::clicked,this,&MainWindow::btn_close_port);
    connect(ui->btn_send1,&QPushButton::clicked,this,&MainWindow::btn_send1_data);
    connect(&global_port,&QSerialPort::readyRead,this,&MainWindow::sp_receive_data);
}

/*-----------slots-------------*/
void MainWindow::btn_open_port(bool)
{
//    qDebug() << "ok";
//    qDebug() << ui->cmb_port_name->currentIndex();
    //待打开的串口号
//    global_port.setPortName(ui->cmb_port_name->currentText());
    switch (ui->cmb_port_name->currentIndex()) {
    case 0:
        global_port.setPortName("COM1");
        break;
    case 1:
        global_port.setPortName("COM2");
        break;
    case 2:
        global_port.setPortName("COM3");
        break;
    case 3:
        global_port.setPortName("COM4");
        break;
    case 4:
        global_port.setPortName("COM5");
        break;
    case 5:
        global_port.setPortName("COM6");
        break;
    case 6:
        global_port.setPortName("COM7");
        break;
    case 7:
        global_port.setPortName("COM8");
        break;
    default:
        global_port.setPortName("COM1");
        break;
    }
    /*-----------baud rate----------*/
    switch (ui->cmb_baud_rate->currentIndex()) {
    case 0:
        global_port.setBaudRate(QSerialPort::Baud1200);
        break;
    case 1:
        global_port.setBaudRate(QSerialPort::Baud4800);
        break;
    case 2:
        global_port.setBaudRate(QSerialPort::Baud9600);
        break;
    case 3:
        global_port.setBaudRate(QSerialPort::Baud19200);
        break;
    case 4:
        global_port.setBaudRate(QSerialPort::Baud38400);
        break;
    case 5:
        global_port.setBaudRate(QSerialPort::Baud57600);
        break;
    case 6:
        global_port.setBaudRate(QSerialPort::Baud115200);
        break;
    default:
        global_port.setBaudRate(QSerialPort::Baud115200);
        break;
    }
    //open
    ui->btn_open->setText("已打开");
    global_port.open(QIODevice::ReadWrite);

    //test
//    global_port.write("1");

}
void MainWindow::btn_close_port(bool)
{
    ui->btn_open->setText("打开串口");
    global_port.close();
}
/*----------send data----------*/
void MainWindow::btn_send1_data(bool)
{
    QString data = ui->lint_send1->text();
    QByteArray array = data.toLatin1(); //QString转为QByteArray
    global_port.write(array);
}

/*-------receive data by serial port----*/
void MainWindow::sp_receive_data()
{
    QByteArray array = global_port.readAll();

    //选中Hex
    if(ui->chb_hex->checkState() == Qt::Checked)
    {
        ui->plainTextEdit->insertPlainText(QString(array.toHex(' ').toUpper().append(' ')));
    }
    else
    {
        ui->plainTextEdit->insertPlainText(QString(array));
    }
}
























