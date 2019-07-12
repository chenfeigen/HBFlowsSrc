#include "ArteryTechQtProject.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include "LoginInterface.h"
// ��־�����ļ�
#include <iostream>
#include <QFile>
#include <QString>
#include <cstdlib>
#include <QTextStream>
#include <QMutex>
#include <QDateTime>
#include <windows.h>
#include "ComputingMultipleBP.h"//�������߽����
using namespace std;
QMutex mutex;// ��־���뻥��
QString timePoint;

/*
// ��־����
void LogOutTxt(QtMsgType type, const QMessageLogContext &context, const QString &msg) 
{
	//#ifndef _DEBUG
	// ��֤debugģʽ�������
	cout << msg.toStdString() << endl;
	//#endif
	mutex.lock();
	QByteArray localMsg = msg.toLocal8Bit();
	switch (type) {
	case QtDebugMsg:
		fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtInfoMsg:
		fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtWarningMsg:
		fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtCriticalMsg:
		fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtFatalMsg:
		fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		abort();
	}
	mutex.unlock();
}

*/
// ��־����
void LogOutTxt(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
	//#ifndef _DEBUG
	// ��֤debugģʽ�������
	cout << msg.toStdString() << endl;
	//QByteArray localMsg = msg.toLocal8Bit();
	//#endif
	mutex.lock();
	QString typeTxt;
	switch (type) {
	case QtDebugMsg:
		typeTxt = QString("Debug: "); // ������Ϣ
		break;
	case QtInfoMsg:
		typeTxt = QString("Info: ");//��Ϣ��ʾ
		break;
	case QtWarningMsg:
		typeTxt = QString("Warning: "); // ����
		break;
	case QtCriticalMsg:
		typeTxt = QString("Critical: "); // ���ش���
		break;
	case QtFatalMsg:
		typeTxt = QString("Fatal: ");// ��������
		abort();
	default:
		break;
	}
	//QString context_info = QString("File: (%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
	QString current_time = QString("(%1)").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd"));
	//QString log = QString("%1 %2 %3\r\n%4").arg(typeTxt).arg(context_info).arg(current_time).arg(msg);
	QString log = QString("%1 %2\r\n%3").arg(typeTxt).arg(current_time).arg(msg);

	QFile file;
	QString path = QString("log/%1.png").arg(timePoint);
	file.setFileName(path);
	if (!file.open(QIODevice::ReadWrite | QIODevice::Append)) {
		QString erinfo = file.errorString();
		cout << erinfo.toStdString() << endl;
		return;
	}
	QTextStream out(&file);
	out << "\r\n" << log;
	file.flush();
	file.close();
	mutex.unlock();
}

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
//����־
//#ifndef _DEBUG
	timePoint = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	timePoint = QDateTime::currentDateTime().toString("yyyyMMdd");
	//qInstallMessageHandler(LogOutTxt);
//#endif
	QApplication a(argc, argv);

//�Ƚ������������ļ��У�һ����UserInfo��������û���Ϣ�������ļ���һ����LockUserInfo�ļ�����������������û���Ϣ
//�������ļ����µ����ݶ��Ƚ����˼���
#if 1
	// ��ȡ��ǰ��·��
	QString qstrpath = QDir::currentPath();
	QString qstrUserInfo = qstrpath + QString("/UserInfo");
	QString qstrLockUserInfo = qstrpath + QString("/LockUserInfo");
	// ��������������������ļ���
	QDir dirUserInfo(qstrUserInfo);
	if (!dirUserInfo.exists())
	{
		dirUserInfo.mkdir(qstrUserInfo);
	}
	// ����ļ�����Ҫ����
	QDir dirLockUserInfo(qstrLockUserInfo);
	if (!dirLockUserInfo.exists())
	{
		dirLockUserInfo.mkdir(qstrLockUserInfo);
	}
	// windows API��Ҫ�� QString ת��Ϊ LPCWSTR
	// ���ļ�������Ϊ����
	SetFileAttributes((LPCWSTR)qstrUserInfo.unicode(), FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes((LPCWSTR)qstrLockUserInfo.unicode(), FILE_ATTRIBUTE_HIDDEN);
#endif 

	//��������������������vtkOutputWindow�ڳ������е�ʱ����ʾ����
	//vtkObject::GlobalWarningDisplayOff();
	vtkObject::SetGlobalWarningDisplay(0);

	//����ʾArteryTechQtProject����֮ǰ����ʾһ���û���¼���棬ֻ���û���¼�ɹ�������ʾArteryTechQtProject���棬����������в���
	//QTextCodec *codec = QTextCodec::codecForName("GB18030");
	//qFatal("divide:Fatal");

	LoginInterface w;
	//ComputingMultipleBP w;
	//VariableParametersDialog w;
	//w.show();

	
	return a.exec();
}
