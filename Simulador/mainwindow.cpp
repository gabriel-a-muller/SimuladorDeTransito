#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    T(this)
{
    ui->setupUi(this);
    tempo = 0;
    scene = new QGraphicsScene(0,0,720,460);
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);

    //timerSemaforo();
    //timerGerador();


    tGerador1 = new QTimer(this);
    tGerador2 = new QTimer(this);
    tSemaforo = new QTimer(this);
    tAtualiza = new QTimer(this);
    connect(tSemaforo, SIGNAL(timeout()),this,SLOT(timerSemaforo()));
    connect(tGerador1, SIGNAL(timeout()),this,SLOT(timerGerador1()));
    connect(tGerador2, SIGNAL(timeout()),this,SLOT(timerGerador2()));
    connect(tAtualiza, SIGNAL(timeout()),this,SLOT(timerAtualiza()));
    tSemaforo->start(10000);
    tGerador1->start(12000);
    tGerador2->start(8000);
    tAtualiza->start(100);


    //QGraphicsView w;
    scene = new QGraphicsScene(0,0,720,460);

    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);

    //grama
    QGraphicsRectItem* gect1 = new QGraphicsRectItem(520,260,200,200);
    QGraphicsRectItem* gect2 = new QGraphicsRectItem(520,0,200,200);
    QGraphicsRectItem* gect3 = new QGraphicsRectItem(260,260,200,200);
    QGraphicsRectItem* gect4 = new QGraphicsRectItem(260,0,200,200);
    QGraphicsRectItem* gect5 = new QGraphicsRectItem(0,260,200,200);
    QGraphicsRectItem* gect6 = new QGraphicsRectItem(0,0,200,200);
    gect1->setBrush(Qt::green);
    gect2->setBrush(Qt::green);
    gect3->setBrush(Qt::green);
    gect4->setBrush(Qt::green);
    gect5->setBrush(Qt::green);
    gect6->setBrush(Qt::green);
    scene->addItem(gect1);
    scene->addItem(gect2);
    scene->addItem(gect3);
    scene->addItem(gect4);
    scene->addItem(gect5);
    scene->addItem(gect6);

    //rua
    QGraphicsRectItem* rect1 = new QGraphicsRectItem(0,200,720,60);
    QGraphicsRectItem* rect2 = new QGraphicsRectItem(200,0,60,460);
    QGraphicsRectItem* rect3 = new QGraphicsRectItem(460,0,60,460);
    rect1->setBrush(Qt::gray);
    rect2->setBrush(Qt::gray);
    rect3->setBrush(Qt::gray);
    scene->addItem(rect1);
    scene->addItem(rect2);
    scene->addItem(rect3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

ImagemCarro *MainWindow::novoCarroImagem()
{
    auto *ic = new ImagemCarro;
    //scene->addItem(ic);
    ic->setZValue(1);
    return ic;
}

void MainWindow::setaCarro(ImagemCarro *ic)
{
    scene->addItem(ic);
}


void MainWindow::timerSemaforo()
{
    T.mudaSemaforos();

}

void MainWindow::timerGerador2()
{
    T.geraCarros2();
}

void MainWindow::timerGerador1()
{
    T.geraCarros1();
}

void MainWindow::timerAtualiza()
{
    T.simulador();
    tempo++;
}
