#ifndef __VESC_USART_H
#define __VESC_USART_H

#include "hk32f030m.h"
#include "crc.h"
#include "usart.h"
#include "datatypes.h"


typedef struct {
	bool floatPackageSupported;
	float avgInputCurrent;
	int dutyCycleNow;
	float inpVoltage;
	long rpm;
	char state;
	char fault;
	bool isForward;
	bool isHandtest;
}dataPackage;

typedef enum : uint8_t {
	BOOT_DEFAULT = 0,
	BOOT_REDWHITEBLUE = 1,
	BOOT_RAINBOW = 2,
	BOOT_LAST = BOOT_RAINBOW,
} BootAnimation;

typedef struct {
	uint8_t headlightBrightness;
	uint8_t headlightIdleBrightness;
	uint8_t statusbarBrightness;
	uint8_t statusbarMode;
	uint8_t dutyBeep;
	float chargeCutoffVoltage;
	bool boardOff;
	BootAnimation bootAnimation;
	bool isSet;
	bool debug;
}lcmConfig_t;

extern uint8_t VESC_RX_Buff[256];
extern uint8_t VESC_RX_Flag;
extern dataPackage data;
extern lcmConfig_t lcmConfig;
extern uint8_t errCode;

void Get_Vesc_Pack_Data(COMM_PACKET_ID id);
uint8_t Protocol_Parse(uint8_t * message);

#endif


