#pragma once

#include "DataManager.h"

class AccountManager : public QObject
{
	Q_OBJECT

public:

	AccountManager(DataManager& dataManager, QObject* parent = nullptr);
	virtual ~AccountManager();

	Q_INVOKABLE bool licenseKeyActivated() const;
	Q_INVOKABLE bool passwordAttempted() const;
	Q_INVOKABLE bool attemptLicenseKey(const QString& key) const;
	Q_INVOKABLE bool attemptPassword(const QString& password);
	Q_INVOKABLE bool checkPassword(const QString& password) const;
	Q_INVOKABLE void savePassword(const QString& password);
	Q_INVOKABLE bool isPasswordSet() const;

private:

	DataManager& _dataManager;
	bool _isPasswordAttempted = false;
	int _attempts = 0;
};
