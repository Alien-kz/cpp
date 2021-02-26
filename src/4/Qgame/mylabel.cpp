#include "mylabel.h"

MyLabel::MyLabel(QString text, QWidget *parent) : QLabel(text, parent)
{
    counter = 0;
}

void MyLabel::changeText() {
    if (counter % 2 == 0) {
        setText("Eva");
    } else {
        setText("Nikita");
    }
    counter++;
}
