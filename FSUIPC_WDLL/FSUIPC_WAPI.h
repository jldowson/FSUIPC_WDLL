#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include "WASMIF.h"

#ifdef FSUIPC_WAPI_EXPORTS
#define FSUIPC_WAPI_API __declspec(dllexport)
#else
#define FSUIPC_WAPI_API __declspec(dllimport)
#endif

extern "C" FSUIPC_WAPI_API void fsuipcw_init(HWND hWnd, int startEventNo, void (*loggerFunction)(const char* logString));
extern "C" FSUIPC_WAPI_API void fsuipcw_start();
extern "C" FSUIPC_WAPI_API void fsuipcw_end();
extern "C" FSUIPC_WAPI_API void fsuipcw_createAircraftLvarFile();
extern "C" FSUIPC_WAPI_API void fsuipcw_reload();
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarUpdateFrequency(int freq);
extern "C" FSUIPC_WAPI_API void fsuipcw_setSimConfigConnection(int connection);
extern "C" FSUIPC_WAPI_API int fsuipcw_getLvarUpdateFrequency();
extern "C" FSUIPC_WAPI_API void fsuipcw_setLogLevel(LOGLEVEL logLevel);
extern "C" FSUIPC_WAPI_API double fsuipcw_getLvarFromId(int lvarID);
extern "C" FSUIPC_WAPI_API double fsuipcw_getLvarFromName(const char* lvarName);
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarAsDouble(unsigned short id, double value);
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarAsShort(unsigned short id, short value);
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarAsString(unsigned short id, const char* value);
extern "C" FSUIPC_WAPI_API void fsuipcw_setLvarAsUShort(unsigned short id, unsigned short value);
extern "C" FSUIPC_WAPI_API void fsuipcw_setHvar(int id);
extern "C" FSUIPC_WAPI_API void fsuipcw_logLvars();
extern "C" FSUIPC_WAPI_API void fsuipcw_logHvars();
extern "C" FSUIPC_WAPI_API void fsuipcw_getLvarValues(map<string, double >&returnMap);
extern "C" FSUIPC_WAPI_API void fsuipcw_getLvarList(unordered_map<int, string >&returnMap);
extern "C" FSUIPC_WAPI_API void fsuipcw_getHvarList(unordered_map<int, string >&returnMap);
extern "C" FSUIPC_WAPI_API void fsuipcw_executeCalclatorCode(const char* code);
extern "C" FSUIPC_WAPI_API int fsuipcw_getLvarIdFromName(const char* lvarName);
extern "C" FSUIPC_WAPI_API void fsuipcw_getLvarNameFromId(int id, char* name);
extern "C" FSUIPC_WAPI_API bool fsuipcw_createLvar(const char* lvarName, DWORD value);
