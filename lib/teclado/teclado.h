#ifndef TECLADO_H //pregunto si esta declarado
#define TECLADO_H //la defino
//incluyo los recursos
#include "stm32f103xb.h"
#include "ctype.h"
#include "stdbool.h"



void teclado_init(int f0,int f1,int f2,int f3,int c0, int c1, int c2, int c3);
char teclado_dev(int f0,int f1,int f2,int f3,int c0, int c1, int c2, int c3);

#endif