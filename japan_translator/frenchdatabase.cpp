#include "frenchdatabase.h"
#include "qtextcodec.h"

FrenchDataBase::FrenchDataBase()
	: AbstractDataBase()
{
	//lecture BDD
	
}

FrenchDataBase::~FrenchDataBase()
{

}

void FrenchDataBase::read_data()
{
	read_file("French", QLocale(QLocale::French, QLocale::France));
}

QString FrenchDataBase::add_data(QByteArray data)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	return codec->toUnicode(data);
}

void FrenchDataBase::write_data(QString lang)
{

}