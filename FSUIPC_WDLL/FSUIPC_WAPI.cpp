#include "FSUIPC_WAPI.h"
#include "WASMIF.h"

WASMIF* wasmPtr = nullptr;


void fsuipcw_init(void (*loggerFunction)(const char* logString)) {
	if (!wasmPtr) {
		wasmPtr = WASMIF::GetInstance(loggerFunction);
	}
}

void fsuipcw_start() {
	if (wasmPtr) {
		wasmPtr->start();
	}
}

void fsuipcw_end() {
	if (wasmPtr) {
		wasmPtr->end();
	}
}

void fsuipcw_createAircraftLvarFile() {
	if (wasmPtr) {
		wasmPtr->createAircraftLvarFile();
	}
}

void fsuipcw_reload() {
	if (wasmPtr) {
		wasmPtr->reload();
	}
}

void fsuipcw_setLvarUpdateFrequency(int freq) {
	if (wasmPtr) {
		wasmPtr->setLvarUpdateFrequency(freq);
	}
}

void fsuipcw_setSimConfigConnection(int connection) {
	if (wasmPtr) {
		wasmPtr->setSimConfigConnection(connection);
	}
}

int fsuipcw_getLvarUpdateFrequency() {
	if (wasmPtr) {
		return wasmPtr->getLvarUpdateFrequency();
	}
	return -1;
}

void fsuipcw_setLogLevel(int logLevel) {
	if (wasmPtr) {
		wasmPtr->setLogLevel((LOGLEVEL)logLevel);
	}
}

double fsuipcw_getLvarFromId(int lvarID) {
	if (wasmPtr) {
		return wasmPtr->getLvar(lvarID);
	}
	return 0.0;
}

double fsuipcw_getLvarFromName(const char* lvarName) {
	if (wasmPtr) {
		return wasmPtr->getLvar(lvarName);
	}
	return 0.0;
}

void fsuipcw_setLvarAsDouble(unsigned short id, double value) {
	if (wasmPtr) {
		wasmPtr->setLvar(id, value);
	}
}

void fsuipcw_setLvarAsShort(unsigned short id, short value) {
	if (wasmPtr) {
		wasmPtr->setLvar(id, value);
	}
}

void fsuipcw_setLvarAsString(unsigned short id, const char* value) {
	if (wasmPtr) {
		wasmPtr->setLvar(id, value);
	}
}

void fsuipcw_setLvarAsUShort(unsigned short id, unsigned short value) {
	if (wasmPtr) {
		wasmPtr->setLvar(id, value);
	}
}

void fsuipcw_setHvar(int id) {
	if (wasmPtr) {
		wasmPtr->setHvar(id);
	}
}

void fsuipcw_logLvars() {
	if (wasmPtr) {
		wasmPtr->logLvars();
	}
}

void fsuipcw_logHvars() {
	if (wasmPtr) {
		wasmPtr->logHvars();
	}
}

void fsuipcw_getLvarValues(void (*receiveFunction)(const char*, double)) {
	if (wasmPtr) {
		map<string, double > result;
		wasmPtr->getLvarValues(result);
		for (map<string, double>::iterator it = result.begin(); it != result.end(); it++) {
			receiveFunction(it->first.c_str(), it->second);
		}
	}
}

void fsuipcw_getLvarList(void (*receiveFunction)(int, const char*)) {
	if (wasmPtr) {
		unordered_map<int, string> result;
		wasmPtr->getLvarList(result);
		for (unordered_map<int, string>::iterator it = result.begin(); it != result.end(); it++) {
			receiveFunction(it->first, it->second.c_str());
		}
	}
}

void fsuipcw_getHvarList(void (*receiveFunction)(int, const char*)) {
	if (wasmPtr) {
		unordered_map<int, string> result;
		wasmPtr->getHvarList(result);
		for (unordered_map<int, string>::iterator it = result.begin(); it != result.end(); it++) {
			receiveFunction(it->first, it->second.c_str());
		}
	}
}

bool fsuipcw_isRunning() {
	if (wasmPtr) {
		return wasmPtr->isRunning();
	}
	return FALSE;
}

void fsuipcw_executeCalclatorCode(const char* code) {
	if (wasmPtr) {
		wasmPtr->executeCalclatorCode(code);
	}
}

int fsuipcw_getLvarIdFromName(const char* lvarName) {
	if (wasmPtr) {
		return wasmPtr->getLvarIdFromName(lvarName);
	}
}

void fsuipcw_getLvarNameFromId(int id, char* name) {
	if (wasmPtr) {
		wasmPtr->getLvarNameFromId(id, name);
	}
}

bool fsuipcw_createLvar(const char* lvarName, double value) {
	if (wasmPtr) {
		return wasmPtr->createLvar(lvarName, value);
	}
	return FALSE;
}

void CALLBACK fsuipcw_MyDispatchProc(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext) {
	wasmPtr->MyDispatchProc(pData, cbData, pContext);
}

void fsuipcw_registerUpdateCallback(void (*callbackFunction)(void)) {
	if (wasmPtr) {
		wasmPtr->registerUpdateCallback(callbackFunction);
	}
}
void fsuipcw_registerLvarUpdateCallbackById(void (*callbackFunction)(int id[], double newValue[])) {
	if (wasmPtr) {
		wasmPtr->registerLvarUpdateCallback(callbackFunction);
	}
}
void fsuipcw_registerLvarUpdateCallbackByName(void (*callbackFunction)(const char* lvarName[], double newValue[])) {
	if (wasmPtr) {
		wasmPtr->registerLvarUpdateCallback(callbackFunction);
	}
}
void fsuipcw_flagLvarForUpdateCallbackById(int lvarId) {
	if (wasmPtr) {
		wasmPtr->flagLvarForUpdateCallback(lvarId);
	}
}
void fsuipcw_flagLvarForUpdateCallbackByName(const char* lvarName) {
	if (wasmPtr) {
		wasmPtr->flagLvarForUpdateCallback(lvarName);
	}
}
