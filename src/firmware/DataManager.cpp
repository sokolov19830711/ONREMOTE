#include "DataManager.h"

void DataManager::init()
{
    getData();
}

McuInData& DataManager::config()
{
    return getData()._config;
}

McuOutData& DataManager::outData()
{
    return getData()._outData;
}

DataManager& DataManager::getData()
{
    static DataManager data;
    return data;
}
