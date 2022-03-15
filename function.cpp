#include <stdio.h>
#include <iostream>

Function::Function() {}

// ћетод класса Function setValue -
void Function::SetValue(int u_x, int u_y, int u_z, int temperature, int pressure) //утсановили значени€ переменных
{
    m_temperature = temperature;
    m_pressure = pressure;
    m_u_x = u_x;
    m_u_y = u_y;
    m_u_z = u_z;
}

void Function::Reset() //обнулили переменные
{
    m_temperature = 0;
    m_pressure = 0;
    m_u_x = 0;
    m_u_y = 0;
    m_u_z = 0;
}

int Function::soundSpeed = 343; //установили скорость звука

//*************—читаем скорость по трем проекци€м********************************************************

double Function::generalSpeed(int u_x, int u_y, int u_z)
{
    return sqrt(u_x * u_x + u_y * u_y + u_z * u_z);
}

//************—читаем и выводим ЋяћЅƒј***********************************************************

void Function::PrintLambdaIn(double speed) //Ћ€мбда на входе
{
    double Lambda[5];
    Lambda[0] = speed; //Lambda1
    Lambda[1] = speed + soundSpeed;
    Lambda[2] = speed;
    Lambda[3] = speed;
    Lambda[4] = speed - soundSpeed;

    std::cout << "Ћ€мбда на входе " << '\n';
    for (int i = 0; i < 4; i++) {
        std::cout << "Lambda" << i + 1 << " = " << Lambda[i] << '\n';
    }
}

void Function::PrintLambdaOut(double speed) //ќ“–»÷ј“≈Ћ№Ќџ≈ ЋяћЅƒј на выходе
{
    double Lambda[5];
    Lambda[0] = -speed; //Lambda1
    Lambda[1] = -speed + soundSpeed;
    Lambda[2] = -speed;
    Lambda[3] = -speed;
    Lambda[4] = -speed - soundSpeed;

    std::cout << "Ћ€мбда на выходе " << '\n';
    for (int i = 0; i < 4; i++) {
        std::cout << "Lambda" << i + 1 << " = " << Lambda[i] << '\n';
    }
}

//*************¬ыводим результат********************************************************

void Function::PrintResultOverSpeedInput() //—верхзвук ¬ход
{
    double speed = generalSpeed(m_u_x, m_u_y, m_u_z);
    std::cout << "OverSpeed Input: " << '\n';
    std::cout << "Temperature = " << m_temperature << '\n' << "Pressure = " << m_pressure << '\n' << "speed = " << speed << '\n';
    PrintLambdaIn(speed);
}

void Function::PrintResultOverSpeedOut() //—верхзвук ¬ыход
{
    double speed = generalSpeed(m_u_x, m_u_y, m_u_z);
    std::cout << "OverSpeed Out: " << '\n';
    std::cout << "Temperature = " << m_temperature << '\n' << "Pressure = " << m_pressure << '\n' << "speed = " << speed << '\n';
    PrintLambdaOut(speed);
}

void Function::PrintResultUnderSpeedInput() //ƒо«вук ¬ход
{
    double speed = generalSpeed(m_u_x, m_u_y, m_u_z);
    std::cout << "OverSpeed Input: " << '\n';
    std::cout << "Temperature = " << m_temperature << '\n' << "Pressure = " << m_pressure << '\n' << "speed = " << speed << '\n';
    PrintLambdaIn(speed);
}

void Function::PrintResultUnderSpeedOut() //ƒо«вук ¬ыход
{
    double speed = generalSpeed(m_u_x, m_u_y, m_u_z);
    std::cout << "UnderSpeed Out: " << '\n';
    std::cout << "Temperature = " << m_temperature << '\n' << "Pressure = " << m_pressure << '\n' << "speed = " << speed << '\n';
    PrintLambdaOut(speed);
}

void Function::PrintResultWall() //стенка
{
    std::cout << "Wall: " << '\n';
    std::cout << "Adiabat with sliding: " << '\n' << "Un=0     dut/dn=0   dp/dn=0   Tw = " << m_temperature << '\n';
    std::cout << "not Adiabatic without sliding: " << '\n' << "Un=0     ux=uy=uz=0    dT/dn != 0  dp/dn=0Tw = " << m_temperature << '\n';
}

void Function::PrintResultSymmetry() //симметри€
{
    std::cout << "Symmetry: " << '\n';
    std::cout << "Un = 0   dUt/dn = 0    dT/dn = 0  dP/dn=0 Tw = " << m_temperature << '\n';
}
