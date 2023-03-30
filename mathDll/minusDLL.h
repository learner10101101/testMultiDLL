#pragma once

#ifdef MINUSDLL_EXPORTS
#define MINUSDLL_API __declspec(dllexport)
#else
#define MINUSDLL_API __declspec(dllimport)
#endif

extern "C" MINUSDLL_API int minus(int a, int b);//c风格：编译器不对函数签名做处理

float minus(float a, float b);//c++风格：编译器对函数签名做处理，以满足类继承时函数重写（具有相同签名情况）的情况