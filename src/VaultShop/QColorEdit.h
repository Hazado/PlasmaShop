#ifndef _QCOLOREDIT_H
#define _QCOLOREDIT_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <Sys/hsColor.h>

class QColorBox : public QWidget {
    Q_OBJECT

protected:
    QColor fColor;
    bool fInClick;

public:
    QColorBox(QWidget* parent = NULL);
    void setColor(QColor col);
    QColor color() const;

protected:
    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual void paintEvent(QPaintEvent*);

signals:
    void activated();
};

class QColorEdit : public QWidget {
    Q_OBJECT

protected:
    QColorBox* fColorBox;
    QDoubleSpinBox* fAlphaBox;
    hsColorRGBA fColor;

public:
    QColorEdit(bool doAlpha, QWidget* parent = NULL);
    void setColor(hsColorRGBA color);
    hsColorRGBA color() const;

protected slots:
    void selectColor();
    void setAlpha(double alpha);
};

#endif
