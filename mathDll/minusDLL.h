#pragma once

#ifdef MINUSDLL_EXPORTS
#define MINUSDLL_API __declspec(dllexport)
#else
#define MINUSDLL_API __declspec(dllimport)
#endif

extern "C" MINUSDLL_API int minus(int a, int b);//c��񣺱��������Ժ���ǩ��������

float minus(float a, float b);//c++��񣺱������Ժ���ǩ����������������̳�ʱ������д��������ͬǩ������������