#ifndef __PARAMETROS_MOTOR_H
#define __PARAMETROS_MOTOR_H

#include "stm32g4xx_hal.h"

// Variáveis globais dos parâmetros do motor
extern uint16_t Rotor_poles_pairs;   // Número de pares de polos do motor
extern uint8_t ke;                   // Constante de fcem do motor
extern uint8_t TensaoBateria;       // Tensão da bateria
extern uint16_t VelNom;             // Velocidade nominal do motor
extern uint16_t PedalMin;           // Leitura mínima do pedal
extern uint32_t DCMAX;              // Valor máximo do duty cycle (ARR do timer)

#endif /* __PARAMETROS_MOTOR_H */
