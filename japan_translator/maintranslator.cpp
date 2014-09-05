#include "maintranslator.h"
#include "frenchdatabase.h"
#include "japandatabase.h"

MainTranslator::MainTranslator()
{
	_gui = new translatorGUI();
	initialise_dataBase();
	QObject::connect(_gui, SIGNAL(emit_combo1String(QString)), this, SLOT(changeLang1(QString)));
	QObject::connect(_gui, SIGNAL(emit_combo2String(QString)), this, SLOT(changeLang2(QString)));
	QObject::connect(_gui, SIGNAL(emit_add(QString, QString, QString, QString)), this, SLOT(addData(QString, QString, QString, QString)));
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

void MainTranslator::changeLang1(QString name)
{
	_gui->set_lineEdit1Lang(name);
	_gui->set_LW1list(name, load_bdd(name));
}

void MainTranslator::changeLang2(QString name)
{
	_gui->set_lineEdit2Lang(name);
	_gui->set_LW2list(name, load_bdd(name));
}

void MainTranslator::addData(QString lang1, QString text1, QString lang2, QString text2)
{
	_gui->add_LW1list((_bddLang.value(lang1))->add_data(QByteArray(text1.toStdString().c_str())));
	_gui->add_LW2list((_bddLang.value(lang2))->add_data(QByteArray(text2.toStdString().c_str())));
}