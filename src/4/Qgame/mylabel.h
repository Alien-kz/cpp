#ifndef MYLABEL_H //error: redefinition of class MyLabel
#define MYLABEL_H

#include <QLabel>
#include <QWidget>
#include <QString>

class MyLabel : public QLabel {
    Q_OBJECT    // QT MACROS -> moc_mylabel.cpp
    int counter;

public:
    MyLabel(QString text, QWidget *parent = NULL);

public slots: // QT MACROS Q_OBJECT
    void changeText();
};
#endif
