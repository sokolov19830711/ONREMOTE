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
	return _dataManager.getSettingsValue("license/activated");
}

bool AccountManager::passwordAttempted() const
{
	return _isPasswordAttempted;
}

bool AccountManager::attemptLicenseKey(const QString& key) const
{
	QStringList full_keys{
		"J3R3W-VBVDF-2496X-46TQB-HH8BY",
		"BBH2G-D2VK9-QD4M9-F63XB-43C33",
		"HQ6K2-QPC42-3HWDM-BF4KJ-W4XWJ",
		"K4HVD-Q9TJ9-6CRX9-C9G68-RQ2D3"
	};

	QStringList button_only_keys{
		"QMPMF-23D8R-83GV6-MMR3C-BQ7C3",
		"PRDDH-83JD9-G6PK4-684GF-6Y73B",
		"XQY3P-8MMD2-JC6M2-HJDYW-P6H7B",
		"MKMXV-CDQGH-98HCX-3HM2C-G3T7B"
	};

	QStringList dust_only_keys{
		"DBRCB-D43K3-VY4G4-KVG4H-6FK9M",
		"TVYGH-V683W-3CWT9-MQ468-G66WR",
		"P767C-WKHX7-62TFV-H6XTP-JXFQM",
		"T7J8Q-MH7RP-9H9J2-2HVFG-C3X2M"
	};

	if (full_keys.contains(key, Qt::CaseInsensitive))
	{
		_dataManager.setSettingsValue("license/activated", 1);
		_dataManager.setSettingsValue("license/type", DataManager::LicenseType::full);
		return true;
	}

	else if (button_only_keys.contains(key, Qt::CaseInsensitive))
	{
		_dataManager.setSettingsValue("license/activated", 1);
		_dataManager.setSettingsValue("license/type", DataManager::LicenseType::button_only);
		return true;
	}

	else if (dust_only_keys.contains(key, Qt::CaseInsensitive))
	{
		_dataManager.setSettingsValue("license/activated", 1);
		_dataManager.setSettingsValue("license/type", DataManager::LicenseType::dust_only);
		return true;
	}

	else
		return false;
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

bool AccountManager::checkPassword(const QString& password) const
{
	if (
		(password.isEmpty() && !_dataManager.settings()->contains("password")) || // Пароль не установлен
		((_dataManager.settings()->value("password")).toByteArray() == QCryptographicHash::hash(QString(password + "q[fdfj").toUtf8(), QCryptographicHash::Algorithm::Md5))
		)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void AccountManager::savePassword(const QString& password)
{
	if (password != "")
	{
		_dataManager.settings()->setValue("password", QCryptographicHash::hash(QString(password + "q[fdfj").toUtf8(), QCryptographicHash::Algorithm::Md5));
	}

	else
	{
		_dataManager.settings()->remove("password");
	}

	_dataManager.settings()->sync();
}

bool AccountManager::isPasswordSet() const
{
	return _dataManager.settings()->contains("password");
}
