#include "japandatabase.h"
#include "qtextcodec.h"

JapanDataBase::JapanDataBase()
	: AbstractDataBase()
{
	//lecture BDD
}

JapanDataBase::~JapanDataBase()
{

}

void JapanDataBase::read_data()
{
	read_file("Japan", QLocale(QLocale::Japanese, QLocale::Japan));
}

QString JapanDataBase::add_data(QByteArray data)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	return codec->toUnicode(data);
}

void JapanDataBase::write_data(QString lang)
{
	
}
