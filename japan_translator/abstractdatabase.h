#ifndef ABSTRACTDATABASE_H
#define ABSTRACTDATABASE_H

#include <QObject>
#include "qstringlist.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qbytearray.h"

class AbstractDataBase : public QObject
{
	Q_OBJECT

public:
	AbstractDataBase();
	~AbstractDataBase();

	QStringList get_data() const;

	virtual void read_data()=0;
	virtual QString add_data(QByteArray data)=0;
	virtual void write_data(QString lang)=0;

protected:
	void read_file(QString file, QLocale local);
	void write_file(QString file, QLocale local);
	QStringList _words;

private:
	
};

#endif // ABSTRACTDATABASE_H
