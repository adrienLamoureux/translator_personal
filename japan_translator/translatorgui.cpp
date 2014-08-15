#include "translatorgui.h"
#include "ui_translatorgui.h"

translatorGUI::translatorGUI() : ui(new Ui::translatorGUI)
{
	ui->setupUi(this);
	QObject::connect(ui->comboBox_lang1, SIGNAL(currentIndexChanged(QString)), this, SIGNAL(emit_combo1String(QString)));
	QObject::connect(ui->comboBox_lang2, SIGNAL(currentIndexChanged(QString)), this, SIGNAL(emit_combo2String(QString)));
}

translatorGUI::~translatorGUI()
{

}

void translatorGUI::set_comboBox(const QStringList langs)
{
	ui->comboBox_lang1->addItems(langs);
	ui->comboBox_lang2->addItems(langs);
}

void translatorGUI::set_LW1list(const QStringList langs)
{
	ui->listWidget_dic1->clear();
	ui->listWidget_dic1->addItems(langs);
}

void translatorGUI::set_LW2list(const QStringList langs)
{
	ui->listWidget_dic2->clear();
	ui->listWidget_dic2->addItems(langs);
}



