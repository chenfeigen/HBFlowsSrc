#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QPrinter>
#include <QPixmap>
#include <QPainter>
#include <QDateTime>
#include <QPoint>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <qDebug>
#include <QDateTime>

class HtmlCreatedWord : public QDialog
{
	Q_OBJECT

public:
	HtmlCreatedWord(QWidget *parent);
	~HtmlCreatedWord();
private:
	void CreatePdfByPixmap();
	void CreatePdfByText();
	QString SaveHtmlToWord();
};
