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

private:
};

#endif // JAPANDATABASE_H
