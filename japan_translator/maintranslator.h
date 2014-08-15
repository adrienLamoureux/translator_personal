#ifndef MAINTRANSLATOR_H
#define MAINTRANSLATOR_H

#include <QObject>
#include "abstractdatabase.h"
#include "qhash.h"
#include "translatorgui.h"

class MainTranslator : public QObject
{
	Q_OBJECT

public:
	MainTranslator();
	~MainTranslator();

protected:
	void initialise_dataBase();
	QStringList load_bdd(QString name);

private:
	translatorGUI *_gui;
	QHash<QString, AbstractDataBase*> _bddLang;

protected slots:
	void load_bdd1(QString name);
	void load_bdd2(QString name);
};

#endif // MAINTRANSLATOR_H
