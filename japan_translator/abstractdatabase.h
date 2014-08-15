#ifndef ABSTRACTDATABASE_H
#define ABSTRACTDATABASE_H

#include <QObject>
#include "qstringlist.h"
#include "qfile.h"
#include "qtextstream.h"

class AbstractDataBase : public QObject
{
	Q_OBJECT

public:
	AbstractDataBase();
	~AbstractDataBase();

	QStringList get_data() const;

	virtual void read_data()=0;

protected:
	void read_file(QString file);
	QStringList _words;

private:
	
};

#endif // ABSTRACTDATABASE_H
