#ifdef TECLADO_H //pregunto si esta declarado
#define TECLADO_H //la defino
//incluyo los recursos
#include "stm32f103xb.h"
#include "ctype.h"
#include "stdbool.h"

void teclado_init(char car);
char teclado_dev();