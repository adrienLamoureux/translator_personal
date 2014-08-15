#include "frenchdatabase.h"

FrenchDataBase::FrenchDataBase()
	: AbstractDataBase()
{
	//lecture BDD
	
}

FrenchDataBase::~FrenchDataBase()
{

}

void FrenchDataBase::read_data()
{
	read_file("French");
}