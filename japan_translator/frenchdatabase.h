#ifndef FRENCHDATABASE_H
#define FRENCHDATABASE_H

#include "abstractdatabase.h"

class FrenchDataBase : public AbstractDataBase
{
public:
	FrenchDataBase();
	~FrenchDataBase();

	virtual void read_data();
	virtual QString add_data(QByteArray data);
	virtual void write_data(QString lang);

private:
};

#endif // FRENCHDATABASE_H
