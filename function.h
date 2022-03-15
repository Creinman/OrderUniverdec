#ifndef FUNCTION_H
#define FUNCTION_H

#include <math.h>

class Function
{
private:                        //в области private рассматривается значения параметров ОДНОГО конкретного граничного условия
        int m_pressure;
        int m_temperature;
        int m_u_x;
        int m_u_y;
        int m_u_z;

public:
    static int soundSpeed;
    Function();
    ~Function() {}
    void SetValue(int pressure, int temperature, int u_x, int u_y, int u_z);
    void Reset();

    int getTemperature() { return m_temperature; }
    int getPressure() { return m_pressure; }

    void setPressure(int pressure);
    void setTemperature(int temperature);

    double generalSpeed(int u_x, int u_y, int u_z);

    void PrintLambdaIn(double speed);
    void PrintLambdaOut(double speed);

    void PrintResultOverSpeedInput();
    void PrintResultOverSpeedOut();
    void PrintResultUnderSpeedInput();
    void PrintResultUnderSpeedOut();
    void PrintResultWall();
    void PrintResultSymmetry();
};

#endif // FUNCTION_H