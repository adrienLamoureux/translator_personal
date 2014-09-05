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
	void changeLang1(QString name);
	void changeLang2(QString name);
	void addData(QString lang1, QString text1, QString lang2, QString text2);
};

#endif // MAINTRANSLATOR_H
