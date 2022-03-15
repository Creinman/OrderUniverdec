#include <fstream>
#include <iostream>
#include <cstring>
#include "function.h"

using namespace std;

int main()
{   // ������ �� ����� reading.txt
    //������ ������� ����� ������������� �������� ���������� ����������
    ifstream fin("D:\\a.txt");
    int mass[22];
    for(int i=0;i<22;++i)
    {
        fin >> mass[i];
    }

    fin.close();

    // �������� ������� ������ Function

    Function object;
    //������������� ����
    object.SetValue(mass[0],mass[1],mass[2],mass[3],mass[4]);
    object.PrintResultOverSpeedInput();
    //�������� �������� ������� ���������� ������ (� ������� private)
    object.Reset();
    //������������� �����
    object.SetValue(mass[5],mass[6],mass[7], 0, 0);
    object.PrintResultOverSpeedOut();
    object.Reset();
    //������
    object.SetValue(mass[17],mass[18],mass[19],mass[21],mass[20]);
    object.PrintResultWall();
    object.Reset();
    //���������
    object.SetValue(mass[17],mass[18],mass[19],mass[21],mass[20]);
    object.PrintResultSymmetry();
    return 0;
    
}