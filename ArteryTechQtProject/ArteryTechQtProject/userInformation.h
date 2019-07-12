#pragma once

#include <QObject>

class userInformation : public QObject
{
	Q_OBJECT

public:
	userInformation(QObject *parent);
	~userInformation();
};


class puttyInformation : public QObject
{
	Q_OBJECT

public:
	puttyInformation(QObject *parent);
	~puttyInformation();
	QString m_username;
	QString m_password;
	QString m_ip;
	QString m_port;
};