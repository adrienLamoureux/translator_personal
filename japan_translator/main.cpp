
#include <QApplication>
#include <iostream>
#include "maintranslator.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::cout << "test" << std::endl;
	MainTranslator *main = new MainTranslator();

	return a.exec();
}
