#include "maintranslator.h"
#include "frenchdatabase.h"
#include "japandatabase.h"

MainTranslator::MainTranslator()
{
	_gui = new translatorGUI();
	initialise_dataBase();
	QObject::connect(_gui, SIGNAL(emit_combo1String(QString)), this, SLOT(load_bdd1(QString)));
	QObject::connect(_gui, SIGNAL(emit_combo2String(QString)), this, SLOT(load_bdd2(QString)));
	_gui->show();
}

MainTranslator::~MainTranslator()
{

}

void MainTranslator::initialise_dataBase()
{
	// Pour l'instant, on save en dur
	_bddLang.insert("French", new FrenchDataBase);
	_bddLang.insert("Japan", new JapanDataBase);
	QStringList langs;
	langs << "---------------" << "French" << "Japan";
	_gui->set_comboBox(langs);
}

QStringList MainTranslator::load_bdd(QString name)
{
	if(name.contains("---"))
		return QStringList("");
	AbstractDataBase *bdd = _bddLang.value(name);
	bdd->read_data();
	return bdd->get_data();
}

void MainTranslator::load_bdd1(QString name)
{
	_gui->set_LW1list(load_bdd(name));
}

void MainTranslator::load_bdd2(QString name)
{
	_gui->set_LW2list(load_bdd(name));
}
