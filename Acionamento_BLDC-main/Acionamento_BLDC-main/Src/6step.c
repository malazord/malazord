#include "Parametros.h"

uint8_t readHallSensors(){
	uint8_t hallA = HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_0);
	uint8_t hallB = HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_1);
	uint8_t hallC = HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_13);
	uint8_t hallState = (hallA << 2) | (hallB << 1) | hallC;

	switch(hallState){
		case 0b101: return 1; // 5
		case 0b100: return 3; // 4
		case 0b110: return 2; // 6
		case 0b010: return 6; // 2
		case 0b011: return 4; // 3
		case 0b001: return 5; // 1
		default: return 0; // erro ou inválido
	}
}


void motorCommutation(currentStep)
{
    switch(currentStep)
    {
      case 6:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        NC        -         +          0        0        1
        CH1|CH1N||CH2|CH2N||CH3|CH3N
        OFF|OFF ||OFF| ON ||PWM1/2
       */
        /* Next step: Step 1 Configuration -------------------------------------- */
        /*  Channel1 configuration - CANAL 1 desativado (nao conectado) */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_INACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH1N);

        /*  Channel2 configuration - CH2 DESATIVADO, CH2N está fechado (dc = 100%) */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_OCMODE_ACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2N);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH2);

        /*  Channel3 configuration - CH3:recebe dc, CH3N recebe o dc "invertido"*/
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH3, LL_TIM_OCMODE_PWM1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3 | LL_TIM_CHANNEL_CH3N);
        break;

      case 3:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        +         NC        -          0        1        0
        CH1|CH1N||CH2|CH2N||CH3|CH3N
        PWM1/2  ||OFF|OFF ||OFF| ON
       */
        /* Next step: Step 1 Configuration -------------------------------------- */
        /*  Channel1 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1 | LL_TIM_CHANNEL_CH1N);

        /*  Channel2 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_OCMODE_INACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH2N);

        /*  Channel3 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH3, LL_TIM_OCMODE_ACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3N);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH3);
        break;

      case 5:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        +         -         NC         0        1        1
        CH1|CH1N||CH2|CH2N||CH3|CH3N
        PWM1/2  ||OFF| ON ||OFF|OFF
       */
        /* Next step: Step 1 Configuration -------------------------------------- */
        /*  Channel1 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1 | LL_TIM_CHANNEL_CH1N);

        /*  Channel2 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_OCMODE_ACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2N);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH2);

        /*  Channel3 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH3, LL_TIM_OCMODE_INACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH3N);
        break;

      case 4:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        -         +         NC         0        0        1
        CH1|CH1N||CH2|CH2N||CH3|CH3N
        OFF| ON ||PWM1/2  ||OFF|OFF
       */
        /* Next step: Step 1 Configuration -------------------------------------- */
        /*  Channel1 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_ACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1N);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH1);

        /*  Channel2 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_OCMODE_PWM1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2 | LL_TIM_CHANNEL_CH2N);

        /*  Channel3 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH3, LL_TIM_OCMODE_INACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH3N);
        break;

      case 2:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        -         NC        +          1        0        1
        CH1|CH1N||CH2|CH2N|CH3|CH3N
        OFF| ON ||OFF|OFF |PWM1/2
       */
        /* Next step: Step 1 Configuration -------------------------------------- */
        /*  Channel1 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_ACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1N);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH1);

        /*  Channel2 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_OCMODE_INACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH2N);

        /*  Channel3 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH3, LL_TIM_OCMODE_PWM1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3 | LL_TIM_CHANNEL_CH3N);
        break;

      case 1:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        NC        +         -          0        1        1
        CH1|CH1N||CH2|CH2N|CH3|CH3N
        OFF|OFF ||PWM1/2  |OFF| ON
       */
        /* Next step: Step 1 Configuration -------------------------------------- */
        /*  Channel1 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_INACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1N);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH1);

        /*  Channel2 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_OCMODE_PWM1);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2 | LL_TIM_CHANNEL_CH2N);

        /*  Channel3 configuration */
        LL_TIM_OC_SetMode(TIM1, LL_TIM_CHANNEL_CH3, LL_TIM_OCMODE_ACTIVE);
        LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3N);
        LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH3);
        break;
    }
  }

void RampaMalhaAberta()  //Para inicializar o motor
{
	float Tensao = 1.0f;
	uint8_t TensaoDiff = 5; //Escolher quanto a tensao aumenta a cada passo (em mV)
	uint8_t stepDuration = 100; //Escolher duração inicial
	uint8_t DurationDiff = 2;   //Escolher quanto a duração diminui a cada passo
	uint8_t step = 1; // posição do motor
	//obviamente, falta definir todos esses valores corretamente.
	LL_TIM_OC_SetCompareCHx(TIM1, DCMAX*Tensao/TensaoBateria);
    MotorCommutation(step); //Para alinhar o rotor inicialmente
    HAL_Delay(10);
	while (VelReal < VelNom/10.0f){
		if (Tensao > TensaoBateria) {
			Tensao = TensaoBateria;
		}
		else if (Tensao - ke*VelReal > CorrenteMax*ResInt){
			Tensao = CorrenteMax*ResInt + ke*VelReal;
			}
		LL_TIM_OC_SetCompareCHx(TIM1, DCMAX*Tensao/TensaoBateria);
		MotorCommutation(step);
		Tensao += TensaoDiff*0.001f;
		HAL_Delay(stepDuration);
		if (DurationDiff < stepDuration) stepDuration -= DurationDiff;
		step++;
		if (step > 6) step = 1;
	}
}
