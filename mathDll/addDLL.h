#pragma once

#ifdef ADDDLL_EXPORTS
#define ADDDLL_API __declspec(dllexport)
#else
#define ADDDLL_API __declspec(dllimport)
#endif

extern "C" ADDDLL_API int add(int a, int b);