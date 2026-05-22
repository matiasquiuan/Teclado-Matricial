#include <string.h>
#include "stm32f103xb.h"
#include "teclado.h"
#include "d7s.h"

#define F0 0
#define F1 1
#define F2 2
#define F3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define A 8
#define B 9
#define C 10
#define D 11
#define E 12
#define F 13
#define G 14

int main(void){
    teclado_init(F0,F1,F2,F3,C0,C1,C2,C3);
    d7s_init(A,B,C,D,E,F,G);

    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    GPIOB->CRL &= ~(0xFF);
    GPIOB->CRL |= 0x22;

    char contra_correcta[9] = "1234";
    char contra_ingresada[9];
    char tecla;
    int i = 0;
    int autenticado = 0;
    memset(contra_ingresada, 0, sizeof(contra_ingresada));

    while(1){
        
        for(tecla='\0'; tecla=='\0'; tecla=teclado_dev(F0,F1,F2,F3,C0,C1,C2,C3));
        while(teclado_dev(F0,F1,F2,F3,C0,C1,C2,C3) != '\0');
        delay(20);

        if(autenticado && tecla == '#'){
            
            GPIOB->BSRR |= (1<<16);
            autenticado = 0;
            memset(contra_ingresada, 0, sizeof(contra_ingresada));
            i = 0;
            while(tecla != '*'){
                for(tecla='\0'; tecla=='\0'; tecla=teclado_dev(F0,F1,F2,F3,C0,C1,C2,C3));
                while(teclado_dev(F0,F1,F2,F3,C0,C1,C2,C3) != '\0');
                delay(20);
                if(tecla != '*' && i < 8){ contra_ingresada[i] = tecla; i++; }
            }
            contra_ingresada[i] = '\0';
            strcpy(contra_correcta, contra_ingresada);
            for(int k=0;k<3;k++){ GPIOB->BSRR|=(1<<0); delay(200); GPIOB->BSRR|=(1<<16); delay(200); }
            memset(contra_ingresada, 0, sizeof(contra_ingresada));
            i = 0;

        }else if(tecla == '*'){
            contra_ingresada[i] = '\0';
            if(strcmp(contra_ingresada, contra_correcta) == 0){
                GPIOB->BSRR |= (1<<0);  
                GPIOB->BSRR |= (1<<17); 
                autenticado = 1;
            }else{
                GPIOB->BSRR |= (1<<1);  
                GPIOB->BSRR |= (1<<16); 
                autenticado = 0;
            }
            memset(contra_ingresada, 0, sizeof(contra_ingresada));
            i = 0;

        }else{
            
            if(i < 8){ contra_ingresada[i] = tecla; i++; }
            d7s(A,B,C,D,E,F,G, tecla);
        }
    }
}
