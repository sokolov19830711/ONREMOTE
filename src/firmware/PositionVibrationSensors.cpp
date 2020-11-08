#include "PositionVibrationSensors.h"
#include "DataManager.h"
#include "Krakeenone_pinout.h"
#include "Beeper.h"
#include "PcPower.h"

PositionVibrationSensors::PositionVibrationSensors()
{

}

void PositionVibrationSensors::init()
{
	analogReference(EXTERNAL);
}

void PositionVibrationSensors::update()
{
    static int prevX = -999;
    static int prevY = -999;
    static int prevZ = -999;

    const int count = 16;

    int X = 0;
    int Y = 0;
    int Z = 0;

    int vibSensorBuffer1[count];
    int vibSensorBuffer2[count];
    int vibSensorBuffer3[count];

    for (byte i = 0; i < count; i++)
    {
        // переменные акселлерометра
        X += analogRead(X_POS);
        Y += analogRead(Y_POS);
        Z += analogRead(Z_POS);

        // Датчик вибрации
        vibSensorBuffer1[i] = analogRead(VIBRO1);
        vibSensorBuffer2[i] = analogRead(VIBRO2);
        vibSensorBuffer3[i] = analogRead(VIBRO3);
    }

    // Сохраняем средние значения за 16 замеров
    DataManager::outData().positionSensorX = (X / count);
    DataManager::outData().positionSensorY = (Y / count);
    DataManager::outData().positionSensorZ = (Z / count);


    if (prevX != -999)
    {
		int dX = (DataManager::outData().positionSensorX > prevX) ? (DataManager::outData().positionSensorX - prevX) : (prevX - DataManager::outData().positionSensorX);
		int dY = (DataManager::outData().positionSensorY > prevY) ? (DataManager::outData().positionSensorY - prevY) : (prevY - DataManager::outData().positionSensorY);
		int dZ = (DataManager::outData().positionSensorZ > prevZ) ? (DataManager::outData().positionSensorZ - prevZ) : (prevZ - DataManager::outData().positionSensorZ);

        int dMax = dX > dY ? dX : dY;
        dMax = dZ > dMax ? dZ : dMax;

        DataManager::outData().vibrationSensor1 = dMax;

        if (dMax > DataManager::config().vibrationMaxValue1 &&
            DataManager::config().vibrationFlags1 & ActionsFlag::soundSignal)
        {
            Beeper::beep();
        }

		if (dMax > DataManager::config().vibrationMaxValue1 &&
			DataManager::config().vibrationFlags1 & ActionsFlag::PCShutDown)
		{
            PcPower::on();
		}
    }

    prevX = DataManager::outData().positionSensorX;
    prevY = DataManager::outData().positionSensorY;
    prevZ = DataManager::outData().positionSensorZ;

	if((DataManager::config().positionXdeviation || DataManager::config().positionYdeviation || DataManager::config().positionZdeviation) &&
		DataManager::config().positionFlags & ActionsFlag::active)
	{
		float relDeviationX = static_cast<float>(abs(DataManager::outData().positionSensorX - DataManager::config().positionXnormal)) / static_cast<float>(DataManager::outData().positionSensorX) * 100.f;
		float relDeviationY = static_cast<float>(abs(DataManager::outData().positionSensorY - DataManager::config().positionYnormal)) / static_cast<float>(DataManager::outData().positionSensorY) * 100.f;
		float relDeviationZ = static_cast<float>(abs(DataManager::outData().positionSensorZ - DataManager::config().positionZnormal)) / static_cast<float>(DataManager::outData().positionSensorZ) * 100.f;

		if (static_cast<unsigned char>(relDeviationX) > DataManager::config().positionXdeviation ||
			static_cast<unsigned char>(relDeviationY) > DataManager::config().positionYdeviation ||
			static_cast<unsigned char>(relDeviationZ) > DataManager::config().positionZdeviation)
		{
			if (DataManager::config().positionFlags & ActionsFlag::soundSignal)
			{
				Beeper::beep();
			}

			if (DataManager::config().positionFlags & ActionsFlag::PCShutDown)
			{
				PcPower::on();
			}
		}
	}

    // Сохраняем максимальное значение из 16 замеров
    DataManager::outData().vibrationSensor2 = getMax(vibSensorBuffer1, count) / 4;
    DataManager::outData().vibrationSensor3 = getMax(vibSensorBuffer2, count) / 4;
    DataManager::outData().vibrationSensor4 = getMax(vibSensorBuffer3, count) / 4;

    if (DataManager::outData().vibrationSensor2 > DataManager::config().vibrationMaxValue2 &&
        DataManager::config().vibrationFlags2 & ActionsFlag::soundSignal)
    {
        Beeper::beep();
    }

	if (DataManager::outData().vibrationSensor2 > DataManager::config().vibrationMaxValue2 &&
		DataManager::config().vibrationFlags2 & ActionsFlag::PCShutDown)
	{
        PcPower::on();
	}

	if (DataManager::outData().vibrationSensor3 > DataManager::config().vibrationMaxValue3 &&
		DataManager::config().vibrationFlags3 & ActionsFlag::soundSignal)
	{
		Beeper::beep();
	}

	if (DataManager::outData().vibrationSensor3 > DataManager::config().vibrationMaxValue3 &&
		DataManager::config().vibrationFlags3 & ActionsFlag::PCShutDown)
	{
		PcPower::on();
	}

	if (DataManager::outData().vibrationSensor4 > DataManager::config().vibrationMaxValue4 &&
		DataManager::config().vibrationFlags4 & ActionsFlag::soundSignal)
	{
		Beeper::beep();
	}

	if (DataManager::outData().vibrationSensor4 > DataManager::config().vibrationMaxValue4 &&
		DataManager::config().vibrationFlags4 & ActionsFlag::PCShutDown)
	{
		PcPower::on();
	}
}
