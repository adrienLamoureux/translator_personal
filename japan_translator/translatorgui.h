#ifndef TRANSLATORGUI_H
#define TRANSLATORGUI_H

#include <qwidget.h>

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
	void set_LW1list(const QStringList langs);
	void set_LW2list(const QStringList langs);

protected:
	void build_comboBox();

private:
	Ui::translatorGUI *ui;

signals:
	void emit_combo1String(QString);
	void emit_combo2String(QString);
};

#endif // TRANSLATORGUI_H
