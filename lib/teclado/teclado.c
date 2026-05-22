#include "teclado.h"
//puerto a
char keypad[4][4]={
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};




void teclado_init(int f0,int f1,int f2,int f3,int c0, int c1, int c2, int c3){
    int c[4]={f0,f1,f2,f3};
    int f[4]={c0,c1,c2,c3};
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    for(int i=0;i<4;i++){
        if(c[4]<8){
            GPIOA->CRL&=~(0xf<<(c[i]*4));
            GPIOA->CRL|=(0x8<<|c[i]*4);
        }else{
            GPIOA->CRH&=~(0xf<<(c[i]%8)*4);
            GPIOA->CRH|=(0x8<<(c[i]%8)*4);
        }
        if(f[i]<8){
            GPIOA->CRL&=~(0xf<<(f[i]*4));
            GPIOA->CRL|=(0x1<<|f[i]*4);
        }else{
            GPIOA->CRH&=~(0xf<<(f[i]%8)*4);
            GPIOA->CRH|=(0x1<<(f[i]%8)*4);
        }
        GPIOA->BSRR|=(1<<f[i]);
    }
}

char teclado_dev(int f0,int f1,int f2,int f3,int c0, int c1, int c2, int c3){
    
    for(int i=0; i<4;i++){
        GPIOA->BSRR|=(1<<(f[i]+16));
        for(int j=0;j<4;j++){
            if(GPIOA->IDR&(1<<c[j])) return keypad[i][j];

        }
        GPIOA->BSRR|=(1<<f[i]);
    }
    return 'x'
}

