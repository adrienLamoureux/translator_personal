#ifndef TRANSLATORGUI_H
#define TRANSLATORGUI_H

#include <qwidget.h>
#include "qlineedit.h"
#include "qlistwidget.h"

namespace Ui{
	class translatorGUI;
}


class translatorGUI : public QWidget
{
	Q_OBJECT

public:
	translatorGUI();
	~translatorGUI();

	void set_comboBox(const QStringList langs);
	void add_LW1list(const QString text);
	void add_LW2list(const QString text);
	void set_LW1list(const QString language, const QStringList langs);
	void set_LW2list(const QString language, const QStringList langs);
	void set_lineEdit1Lang(const QString lang);
	void set_lineEdit2Lang(const QString lang);

protected:
	void build_comboBox();
	void changeLangListW(QListWidget *listW, const QString lang);
	void changeLangLine(QLineEdit *line, const QString lang);

private:
	Ui::translatorGUI *ui;
	QString _language1;
	QString _language2;

protected slots:
	void on_addClicked();
	void on_delClicked();

signals:
	void emit_combo1String(QString);
	void emit_combo2String(QString);
	void emit_add(QString, QString, QString, QString);
	void emit_del(QString, QString, QString, QString);
};

#endif // TRANSLATORGUI_H
