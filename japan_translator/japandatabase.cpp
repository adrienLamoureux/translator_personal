#include "japandatabase.h"

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
	read_file("Japan");
}

