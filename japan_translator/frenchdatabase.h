#ifndef FRENCHDATABASE_H
#define FRENCHDATABASE_H

#include "abstractdatabase.h"

class FrenchDataBase : public AbstractDataBase
{
public:
	FrenchDataBase();
	~FrenchDataBase();

	virtual void read_data();

private:
};

#endif // FRENCHDATABASE_H
