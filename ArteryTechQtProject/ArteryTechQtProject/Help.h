#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
namespace Ui { class Help; };

class Help : public QDialog
{
	Q_OBJECT

public:
	Help(QWidget *parent = Q_NULLPTR);
	~Help();

private:
	Ui::Help *ui;
	void InitHelpUi();
};
