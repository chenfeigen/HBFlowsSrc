#include "ArteryTechQtProject.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include "LoginInterface.h"
// 日志配置文件
#include <iostream>
#include <QFile>
#include <QString>
#include <cstdlib>
#include <QTextStream>
#include <QMutex>
#include <QDateTime>
#include <windows.h>
#include "ComputingMultipleBP.h"//计算多个边界参数
using namespace std;
QMutex mutex;// 日志代码互斥
QString timePoint;

/*
// 日志生成
void LogOutTxt(QtMsgType type, const QMessageLogContext &context, const QString &msg) 
{
	//#ifndef _DEBUG
	// 保证debug模式正常输出
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
// 日志生成
void LogOutTxt(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
	//#ifndef _DEBUG
	// 保证debug模式正常输出
	cout << msg.toStdString() << endl;
	//QByteArray localMsg = msg.toLocal8Bit();
	//#endif
	mutex.lock();
	QString typeTxt;
	switch (type) {
	case QtDebugMsg:
		typeTxt = QString("Debug: "); // 调试信息
		break;
	case QtInfoMsg:
		typeTxt = QString("Info: ");//消息提示
		break;
	case QtWarningMsg:
		typeTxt = QString("Warning: "); // 警告
		break;
	case QtCriticalMsg:
		typeTxt = QString("Critical: "); // 严重错误
		break;
	case QtFatalMsg:
		typeTxt = QString("Fatal: ");// 致命错误
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
//开日志
//#ifndef _DEBUG
	timePoint = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	timePoint = QDateTime::currentDateTime().toString("yyyyMMdd");
	//qInstallMessageHandler(LogOutTxt);
//#endif
	QApplication a(argc, argv);

//先建立两个隐藏文件夹，一个叫UserInfo用来存放用户信息的隐藏文件，一个叫LockUserInfo文件夹用来存放上锁的用户信息
//这两个文件夹下的内容都先进行了加密
#if 1
	// 获取当前的路径
	QString qstrpath = QDir::currentPath();
	QString qstrUserInfo = qstrpath + QString("/UserInfo");
	QString qstrLockUserInfo = qstrpath + QString("/LockUserInfo");
	// 上面这个是正常创建的文件夹
	QDir dirUserInfo(qstrUserInfo);
	if (!dirUserInfo.exists())
	{
		dirUserInfo.mkdir(qstrUserInfo);
	}
	// 这个文件夹需要隐藏
	QDir dirLockUserInfo(qstrLockUserInfo);
	if (!dirLockUserInfo.exists())
	{
		dirLockUserInfo.mkdir(qstrLockUserInfo);
	}
	// windows API需要将 QString 转化为 LPCWSTR
	// 将文件夹设置为隐藏
	SetFileAttributes((LPCWSTR)qstrUserInfo.unicode(), FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes((LPCWSTR)qstrLockUserInfo.unicode(), FILE_ATTRIBUTE_HIDDEN);
#endif 

	//下面两个方法都能设置vtkOutputWindow在程序运行的时候不显示出来
	//vtkObject::GlobalWarningDisplayOff();
	vtkObject::SetGlobalWarningDisplay(0);

	//在显示ArteryTechQtProject界面之前先显示一个用户登录界面，只有用户登录成功才能显示ArteryTechQtProject界面，并对软件进行操作
	//QTextCodec *codec = QTextCodec::codecForName("GB18030");
	//qFatal("divide:Fatal");

	LoginInterface w;
	//ComputingMultipleBP w;
	//VariableParametersDialog w;
	//w.show();

	
	return a.exec();
}
