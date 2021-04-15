#pragma once

#define cpplib_API __declspec(dllexport)

extern "C" cpplib_API double cppobliczvx(double* tab);

extern "C" cpplib_API double cppobliczvy(double* tab);

extern "C" cpplib_API double cppobliczsx(double* tab);

extern "C" cpplib_API double cppobliczsy(double* tab);
