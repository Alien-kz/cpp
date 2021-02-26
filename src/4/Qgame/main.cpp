#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include "mylabel.h"

//#include <iostream>

int main(int argc, char **argv) {
//	std::cout << "QT Hello!" << std::endl;
    QApplication app(argc, argv);
    QMainWindow window;
    window.resize(800, 200);
    window.show();

    MyLabel label("Hello Nikita!", &window);
    label.setGeometry(0, 0, 200, 200);
    label.show();

    QPushButton button("Push me", &window);
    button.setGeometry(400, 0, 200, 200);
    button.show();

    QObject::connect(&button, SIGNAL(clicked()), &label, SLOT(changeText()));

	return app.exec();
}
