#include "translatorgui.h"
#include "ui_translatorgui.h"

translatorGUI::translatorGUI() : ui(new Ui::translatorGUI)
{
	ui->setupUi(this);
	QObject::connect(ui->comboBox_lang1, SIGNAL(currentIndexChanged(QString)), this, SIGNAL(emit_combo1String(QString)));
	QObject::connect(ui->comboBox_lang2, SIGNAL(currentIndexChanged(QString)), this, SIGNAL(emit_combo2String(QString)));
	QObject::connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(on_addClicked()));
	QObject::connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(on_delClicked()));

}

translatorGUI::~translatorGUI()
{

}

void translatorGUI::set_comboBox(const QStringList langs)
{
	ui->comboBox_lang1->addItems(langs);
	ui->comboBox_lang2->addItems(langs);
}

void translatorGUI::add_LW1list(const QString text)
{
	ui->listWidget_dic1->addItem(new QListWidgetItem(text));
	ui->listWidget_dic1->update();
}

void translatorGUI::add_LW2list(const QString text)
{
	ui->listWidget_dic2->addItem(new QListWidgetItem(text));
	ui->listWidget_dic2->update();
}

void translatorGUI::set_LW1list(const QString language, const QStringList langs)
{
	this->_language1 = language;
	ui->listWidget_dic1->clear();
	changeLangListW(ui->listWidget_dic1, language);
	ui->listWidget_dic1->addItems(langs);
}

void translatorGUI::set_LW2list(const QString language, const QStringList langs)
{
	this->_language2 = language;
	ui->listWidget_dic2->clear();
	changeLangListW(ui->listWidget_dic2, language);
	ui->listWidget_dic2->addItems(langs);
}

void translatorGUI::set_lineEdit1Lang(const QString lang)
{
	changeLangLine(ui->lineEdit_base1Add, lang);
	changeLangLine(ui->lineEdit_base1Del, lang);
}

void translatorGUI::set_lineEdit2Lang(const QString lang)
{
	changeLangLine(ui->lineEdit_base2Add, lang);
	changeLangLine(ui->lineEdit_base2Del, lang);
}

void translatorGUI::changeLangListW(QListWidget *listW, const QString lang)
{
	if(lang == "French")
		listW->setLocale(QLocale(QLocale::French, QLocale::France));
	if(lang == "Japan")
		listW->setLocale(QLocale(QLocale::Japanese, QLocale::Japan));
}

void translatorGUI::changeLangLine(QLineEdit *line, const QString lang)
{
	if(lang == "French")
		line->setLocale(QLocale(QLocale::French, QLocale::France));
	if(lang == "Japan")
		line->setLocale(QLocale(QLocale::Japanese, QLocale::Japan));
}

void translatorGUI::on_addClicked()
{
	emit_add(_language1, ui->lineEdit_base1Add->text(), _language2, ui->lineEdit_base2Add->text());
}

void translatorGUI::on_delClicked()
{
	emit_del(_language1, ui->lineEdit_base1Del->text(), _language2, ui->lineEdit_base2Del->text());
}