// PercentOf.cpp
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#define DLLEXPORT __declspec(dllexport)

extern "C" DLLEXPORT void __stdcall SmartieInit() { }
extern "C" DLLEXPORT void __stdcall SmartieFini() { }

extern "C" DLLEXPORT char* __stdcall function1(char* param1, char* param2) {
    static char outbuf[64];

    char* end1 = nullptr;
    char* end2 = nullptr;

    double part  = std::strtod(param1, &end1);
    double whole = std::strtod(param2, &end2);

    if (end1 == param1 || end2 == param2) {
        std::snprintf(outbuf, sizeof(outbuf), "N/A");
        return outbuf;
    }

    if (whole == 0.0) {
        std::snprintf(outbuf, sizeof(outbuf), "0.0%%");
        return outbuf;
    }

    double percent = (part / whole) * 100.0;
    std::snprintf(outbuf, sizeof(outbuf), "%.1f%%", percent);
    return outbuf;
}
