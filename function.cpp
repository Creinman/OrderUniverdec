#include <stdio.h>
#include <iostream>

Function::Function() {}

// ����� ������ Function setValue -
void Function::SetValue(int u_x, int u_y, int u_z, int temperature, int pressure) //���������� �������� ����������
{
    m_temperature = temperature;
    m_pressure = pressure;
    m_u_x = u_x;
    m_u_y = u_y;
    m_u_z = u_z;
}

void Function::Reset() //�������� ����������
{
    m_temperature = 0;
    m_pressure = 0;
    m_u_x = 0;
    m_u_y = 0;
    m_u_z = 0;
}

int Function::soundSpeed = 343; //���������� �������� �����

//*************������� �������� �� ���� ���������********************************************************

double Function::generalSpeed(int u_x, int u_y, int u_z)
{
    return sqrt(u_x * u_x + u_y * u_y + u_z * u_z);
}

//************������� � ������� ������***********************************************************

void Function::PrintLambdaIn(double speed) //������ �� �����
{
    double Lambda[5];
    Lambda[0] = speed; //Lambda1
    Lambda[1] = speed + soundSpeed;
    Lambda[2] = speed;
    Lambda[3] = speed;
    Lambda[4] = speed - soundSpeed;

    std::cout << "������ �� ����� " << '\n';
    for (int i = 0; i < 4; i++) {
        std::cout << "Lambda" << i + 1 << " = " << Lambda[i] << '\n';
    }
}

void Function::PrintLambdaOut(double speed) //������������� ������ �� ������
{
    double Lambda[5];
    Lambda[0] = -speed; //Lambda1
    Lambda[1] = -speed + soundSpeed;
    Lambda[2] = -speed;
    Lambda[3] = -speed;
    Lambda[4] = -speed - soundSpeed;

    std::cout << "������ �� ������ " << '\n';
    for (int i = 0; i < 4; i++) {
        std::cout << "Lambda" << i + 1 << " = " << Lambda[i] << '\n';
    }
}

//*************������� ���������********************************************************

void Function::PrintResultOverSpeedInput() //��������� ����
{
    double speed = generalSpeed(m_u_x, m_u_y, m_u_z);
    std::cout << "OverSpeed Input: " << '\n';
    std::cout << "Temperature = " << m_temperature << '\n' << "Pressure = " << m_pressure << '\n' << "speed = " << speed << '\n';
    PrintLambdaIn(speed);
}

void Function::PrintResultOverSpeedOut() //��������� �����
{
    double speed = generalSpeed(m_u_x, m_u_y, m_u_z);
    std::cout << "OverSpeed Out: " << '\n';
    std::cout << "Temperature = " << m_temperature << '\n' << "Pressure = " << m_pressure << '\n' << "speed = " << speed << '\n';
    PrintLambdaOut(speed);
}

void Function::PrintResultUnderSpeedInput() //������ ����
{
    double speed = generalSpeed(m_u_x, m_u_y, m_u_z);
    std::cout << "OverSpeed Input: " << '\n';
    std::cout << "Temperature = " << m_temperature << '\n' << "Pressure = " << m_pressure << '\n' << "speed = " << speed << '\n';
    PrintLambdaIn(speed);
}

void Function::PrintResultUnderSpeedOut() //������ �����
{
    double speed = generalSpeed(m_u_x, m_u_y, m_u_z);
    std::cout << "UnderSpeed Out: " << '\n';
    std::cout << "Temperature = " << m_temperature << '\n' << "Pressure = " << m_pressure << '\n' << "speed = " << speed << '\n';
    PrintLambdaOut(speed);
}

void Function::PrintResultWall() //������
{
    std::cout << "Wall: " << '\n';
    std::cout << "Adiabat with sliding: " << '\n' << "Un=0     dut/dn=0   dp/dn=0   Tw = " << m_temperature << '\n';
    std::cout << "not Adiabatic without sliding: " << '\n' << "Un=0     ux=uy=uz=0    dT/dn != 0  dp/dn=0Tw = " << m_temperature << '\n';
}

void Function::PrintResultSymmetry() //���������
{
    std::cout << "Symmetry: " << '\n';
    std::cout << "Un = 0   dUt/dn = 0    dT/dn = 0  dP/dn=0 Tw = " << m_temperature << '\n';
}
