#ifndef IMAGEMCARRO_H
#define IMAGEMCARRO_H
#include <QDebug>
#include <QGraphicsItem>
#include <QPainter>


//classe onde a imagem do carro eh gerada.
class ImagemCarro : public QGraphicsItem
{
public:
    ImagemCarro(){}
    ~ImagemCarro(){}
    QRectF boundingRect() const override {
        return {x(), y(), 10, 10};
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override {
        painter->setBrush(QBrush(Qt::black));
        painter->drawRect(boundingRect());
    }
};

#endif // IMAGEMCARRO_H
