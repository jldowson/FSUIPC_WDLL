#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <SimConnect.h>

#ifdef FSUIPC_WAPI_EXPORTS
#define FSUIPC_WAPI_API __declspec(dllexport)
#else
#define FSUIPC_WAPI_API __declspec(dllimport)
#endif

extern "C" FSUIPC_WAPI_API void fsuipcw_init(HWND hWnd, int startEventNo, void (*loggerFunction)(const char* logString));
extern "C" FSUIPC_WAPI_API void fsuipcw_start();
extern "C" FSUIPC_WAPI_API bool fsuipcw_isRunning();
extern "C" FSUIPC_WAPI_API void fsuipcw_end();
extern "C" FSUIPC_WAPI_API void fsuipcw_createAircraftLvarFile();
extern "C" FSUIPC_WAPI_API void fsuipcw_reload();
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarUpdateFrequency(int freq);
extern "C" FSUIPC_WAPI_API void fsuipcw_setSimConfigConnection(int connection);
extern "C" FSUIPC_WAPI_API int fsuipcw_getLvarUpdateFrequency();
extern "C" FSUIPC_WAPI_API void fsuipcw_setLogLevel(int logLevel);
extern "C" FSUIPC_WAPI_API double fsuipcw_getLvarFromId(int lvarID);
extern "C" FSUIPC_WAPI_API double fsuipcw_getLvarFromName(const char* lvarName);
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarAsDouble(unsigned short id, double value);
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarAsShort(unsigned short id, short value);
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarAsString(unsigned short id, const char* value);
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarAsUShort(unsigned short id, unsigned short value);
extern "C" FSUIPC_WAPI_API void fsuipcw_setHvar(int id);
extern "C" FSUIPC_WAPI_API void fsuipcw_logLvars();
extern "C" FSUIPC_WAPI_API void fsuipcw_logHvars();
extern "C" FSUIPC_WAPI_API void fsuipcw_getLvarValues(void (*receiveFunction)(const char*, double));
extern "C" FSUIPC_WAPI_API void fsuipcw_getLvarList(void (*receiveFunction)(int, const char*));
extern "C" FSUIPC_WAPI_API void fsuipcw_getHvarList(void (*receiveFunction)(int, const char*));
extern "C" FSUIPC_WAPI_API void fsuipcw_executeCalclatorCode(const char* code);
extern "C" FSUIPC_WAPI_API int fsuipcw_getLvarIdFromName(const char* lvarName);
extern "C" FSUIPC_WAPI_API void fsuipcw_getLvarNameFromId(int id, char* name);
extern "C" FSUIPC_WAPI_API bool fsuipcw_createLvar(const char* lvarName, double value);

extern "C" FSUIPC_WAPI_API void fsuipcw_registerUpdateCallback(void (*callbackFunction)(void));
extern "C" FSUIPC_WAPI_API void fsuipcw_registerLvarUpdateCallbackById(void (*callbackFunction)(int id[], double newValue[]));
extern "C" FSUIPC_WAPI_API void fsuipcw_registerLvarUpdateCallbackByName(void (*callbackFunction)(const char* lvarName[], double newValue[]));
extern "C" FSUIPC_WAPI_API void fsuipcw_flagLvarForUpdateCallbackById(int lvarId);
extern "C" FSUIPC_WAPI_API void fsuipcw_flagLvarForUpdateCallbackByName(const char* lvarName);

extern "C" FSUIPC_WAPI_API  void CALLBACK fsuipcw_MyDispatchProc(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext);
extern "C" FSUIPC_WAPI_API  VOID CALLBACK fsuipcw_StaticConfigTimer(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
extern "C" FSUIPC_WAPI_API  VOID CALLBACK fsuipcw_StaticRequestDataTimer(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
