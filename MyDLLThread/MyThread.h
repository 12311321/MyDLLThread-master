#pragma once

#define MYTHREAD_API __declspec(dllexport)

extern "C" MYTHREAD_API void SV_Interface_InitGame();

extern "C" MYTHREAD_API void SV_Interface_PlayGame();

extern "C" MYTHREAD_API void SV_Interface_EndGame();


extern "C" MYTHREAD_API LPCTSTR SV_Interface_GetData();

extern "C" MYTHREAD_API LPCTSTR SV_Interface_EnforcePolicy();



//init, play, fast, slow, puase, end, destroy
//get data, input data, EnforcePolicy