#include "abstractdatabase.h"

AbstractDataBase::AbstractDataBase()
{

}

AbstractDataBase::~AbstractDataBase()
{

}

QStringList AbstractDataBase::get_data() const
{
	return this->_words;
}

void AbstractDataBase::read_file(QString file, QLocale local)
{
	//clear les datas car relecture du fichier
	this->_words.clear();
	
	//verifie le fichier
	QFile fil(file);
	if (!fil.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

	//standard pour le streamer pour caractere Asia
	QTextStream in(&fil);
	in.setLocale(local);
	in.setCodec("UTF-8");
	
	int cpt = 0;
	QString line;
	 while (!in.atEnd()) {
		 line = QString::fromUtf8(in.readLine().toStdString().c_str(), -1);
		 if(cpt == 0){ //to zap header
			cpt++;
			continue;
		 }
		 _words.append(line);
    }
}