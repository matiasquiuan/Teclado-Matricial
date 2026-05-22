#ifndef d7s_h//pregunto si esta definida
#define d7s_h//la defino
//incluyo los recursos
#include "stm32f103xb.h"
#include "ctype.h"
#include "stdbool.h"

//definicion de funciones
/*
    VALORES DE IO




*/
void d7s_init(int a, int b, int c, int d, int e, int f, int g);
void d7s(int num, int a, int b, int c, int d, int e, int f, int g, char num);
