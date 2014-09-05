#ifndef JAPANDATABASE_H
#define JAPANDATABASE_H

#include "abstractdatabase.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qvector.h"

class JapanDataBase : public AbstractDataBase
{
public:
	JapanDataBase();
	~JapanDataBase();

	virtual void read_data();
	virtual QString add_data(QByteArray data);
	virtual void write_data(QString lang);

private:
};

#endif // JAPANDATABASE_H
