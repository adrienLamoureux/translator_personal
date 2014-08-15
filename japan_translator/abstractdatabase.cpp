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

void AbstractDataBase::read_file(QString file)
{
	//clear les datas car relecture du fichier
	this->_words.clear();
	
	//verifie le fichier
	QFile fil(file);
	if (!fil.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
	QTextStream in(&fil);
	int cpt = 0;
	QString line;
	 while (!in.atEnd()) {
		 line = in.readLine().simplified().remove(" ");
		 if(cpt == 0){ //to zap header
			cpt++;
			continue;
		 }
		 _words.append(line);
    }
}