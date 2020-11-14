#include "AccountManager.h"

#include <QDebug>
#include <QCryptographicHash>

AccountManager::AccountManager(DataManager& dataManager, QObject* parent) :
	QObject(parent),
	_dataManager(dataManager)
{
	if (!_dataManager.settings()->contains("password"))
	{
		_isPasswordAttempted = true;
	}

}

AccountManager::~AccountManager()
{

}

bool AccountManager::licenseKeyActivated() const
{
	return _dataManager.settings()->value("licenseKeyActivated").toBool();
}

bool AccountManager::passwordAttempted() const
{
	return _isPasswordAttempted;
}

bool AccountManager::attemptLicenseKey(const QString& key) const
{
	_dataManager.settings()->setValue("licenseKeyActivated", true);
	return true;
}

bool AccountManager::attemptPassword(const QString& password)
{
	if (
		(password.isEmpty() && !_dataManager.settings()->contains("password")) || // Пароль не установлен
		((_dataManager.settings()->value("password")).toByteArray() == QCryptographicHash::hash(QString(password + "q[fdfj").toUtf8(), QCryptographicHash::Algorithm::Md5))
		)
	{
		_isPasswordAttempted = true;
	}

	else
	{
		_isPasswordAttempted = false;
	}
	
	return _isPasswordAttempted;
}
