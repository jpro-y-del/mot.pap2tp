#include "Arduino.h"
#include "lib.pap2.h"
#include "Ctype.h"
int i, b, num;
char tipo_paso;
char tougger(tipo_paso);


void MotorPaP_init(int IN0, int IN1, int IN2, int IN3){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;//habilito el clk
    int pines [4]={IN0, IN1, IN2, IN3};
        for(i=0;i<4;i++){
            if (pines[i]<8){
                GPIOA-> CRL&=~(1<<pines[i]*4) &~(1<<pines[i]*4+1)
                           &~(1<<pines[i]*4+2)&~(1<<pines[i]*4+3);
                GPIOA-> CRL|=(1<<pines[i]*4);  
            } 
            else {
                GPIOA-> CRH&=~((1<<pines[i]%8)*4) &~((1<<pines[i]%8)*4+1)
                           &~((1<<pines[i]%8)*4+2)&~((1<<pines[i]%8)*4+3);
                GPIOA-> CRH|=((1<<pines[i]%8)*4);
            }

        }
       

    }
    void MotorPaP(int IN0, int IN1, int IN2, int IN3, char tipoPaso, int pasos){
        tipoPaso= toupper(tipoPaso);
        switch (tipoPaso){
            case 'N' :
            int IN0, IN1,  IN2, IN3, pasos;
                    int pasoc [4][4]{
                    {1,1,0,0},
                    {0,1,1,0},
                    {0,0,1,1},
                    {1,0,0,1}
                    };
                    int pines [4]={IN0, IN1, IN2, IN3};  
                    for(i=0;i<pasos;i++){
                        for(int j=0;j<4;j++){
                            b= i%4;
                            if (pasoc[b][j]){
                                GPIOA->BSRR|=(1<<pines[j]);
                            }
                            else {
                                GPIOA->BSRR|=(1<<pines[j]+16);
                            }  
                        }
                    }
                    break;
            case 'C':
            int IN0, IN1,  IN2, IN3, pasos;
            int pasoc [4][4]{
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}
            };
            int pines [4]={IN0, IN1, IN2, IN3};  
            for(i=0;i<pasos;i++){
                for(int j=0;j<4;j++){
                    b= i%4;
                    if (pasoc[b][j]){
                        GPIOA->BSRR|=(1<<pines[j]);
                    }
                    else {
                        GPIOA->BSRR|=(1<<pines[j]+16);
                    }  
                }
            }
            break;
            case 'M':
            int IN0, IN1, IN2,IN3, pasos;
                int pasoc [8][4]{
                {1,0,0,0},
                {1,1,0,0},
                {0,1,0,0},
                {0,1,1,0},
                {0,0,1,0},
                {0,0,1,1},
                {0,0,0,1},
                {1,0,0,1}
                };
                int pines [4]={IN0, IN1, IN2, IN3};  
                for(i=0;i<pasos;i++){
                    for(int j=0;j<4;j++){
                        b= i%8;
                        if (pasoc[b][j]){
                            GPIOA->BSRR|=(1<<pines[j]);
                        }
                        else {
                            GPIOA->BSRR|=(1<<pines[j]+16);
                        }  
                    }
                }
                break;
                default:
                int IN0, IN1,  IN2, IN3, pasos;
                    int pasoc [4][4]{
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}
                    };
                    int pines [4]={IN0, IN1, IN2, IN3};  
                    for(i=0;i<pasos;i++){
                        for(int j=0;j<4;j++){
                            b= i%4;
                            if (pasoc[b][j]){
                                GPIOA->BSRR|=(1<<pines[j]);
                            }
                            else {
                                GPIOA->BSRR|=(1<<pines[j]+16);
                            }  
                        }
                    }
                    break;
            } 
            }