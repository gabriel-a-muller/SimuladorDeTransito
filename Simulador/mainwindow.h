#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include "Trafego.h"

#include "imagemcarro.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //metodo que cria e retorna uma nova imagem de carro.
    ImagemCarro *novoCarroImagem();
    //seta o item para a cena da interface
    void         setaCarro(ImagemCarro *ic);
public slots:
    //metodos de timers
    void timerSemaforo();
    void timerGerador1();
    void timerGerador2();
    void timerAtualiza();
private:
    Ui::MainWindow *ui;
    Trafego T;
    QTimer *tSemaforo;
    QTimer *tGerador1;
    QTimer *tGerador2;
    QTimer *tAtualiza;
    QGraphicsScene *scene;
    int tempo;
};

#endif // MAINWINDOW_H
