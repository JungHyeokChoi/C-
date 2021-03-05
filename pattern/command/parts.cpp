#include <iostream>

#include "Parts.h"

using namespace std;

void Relay :: On()
{
    cout << "스위치가 열렸다." << endl;
} 

void Relay :: Off() 
{
    cout << "스위치가 닫쳤다."  << endl;
}

void Motor :: On() 
{
    cout << "모터가 동작한다." << endl;
}

void Motor :: Off() 
{
    cout << "모터가 동작을 멈췄다." << endl;
}

void Clutch :: On()
{
    cout << "클러치을 붙잡았다." << endl;
}

void Clutch :: Off()
{
    cout << "클러치을 놓았다." << endl;
}