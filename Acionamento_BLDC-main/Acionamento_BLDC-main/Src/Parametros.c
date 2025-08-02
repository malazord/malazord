/* Variables -----------------------------------------------------------------*/
uint16_t Rotor_poles_pairs = 9;                        //Numero de pares de polos do motor
float ke = 0.026547f;                                       // Constante de fcem do motor em Volts/radianos elétricos
uint8_t TensaoBateria = 36;                           //Tensão da bateria
uint16_t VelNom = 0;                                  //Velocidade Nominal do motor (ver unidade)
uint16_t PedalMin = 0;                                //Leitura mínima do pedal (precisa checar de acordo com as limitações que a Dinamica aplicou)
uint32_t DCMAX = __HAL_TIM_GET_AUTORELOAD(&htim1);    //Valor maximo do duty cycle
uint16_t CorrenteMax = 10;								//Corrente máximo que podemos aplicar com segurança
float ResInt = 0.17f;									//Resistencia interna do motor em Ohm


//Deixei alguns parametros que achei em outros códigos para depois ver se eles se encaixam no nosso codigo. Depois, irei retirá-los

//uint32_t mech_accel_hz = 0;                         /*!<  Hz -- Mechanical acceleration rate */
//uint32_t constant_k = 0;                            /*!<  1/3*mech_accel_hz */
//uint32_t Time_vector_tmp = 0;                      /*!<  Startup variable  */
//uint32_t Time_vector_prev_tmp = 0 ;                 /*!<  Startup variable  */
//uint32_t T_single_step = 0;                         /*!<  Startup variable  */
//uint32_t T_single_step_first_value = 0;             /*!<  Startup variable  */
//int32_t  delta = 0;                                 /*!<  Startup variable  */
//uint16_t index_array = 1;                           /*!<  Speed filter variable */
//int16_t speed_tmp_array[FILTER_DEEP];               /*!<  Speed filter variable */
//uint16_t speed_tmp_buffer[FILTER_DEEP];             /*!<  Potentiometer filter variable */
//uint16_t HFBuffer[HFBUFFERSIZE];                    /*!<  Buffer for Potentiometer Value Filtering at the High-Frequency ADC conversion */
//uint16_t HFBufferIndex = 0;                         /*!<  High-Frequency Buffer Index */
//uint8_t  array_completed = FALSE;                   /*!<  Speed filter variable */
//uint8_t  buffer_completed = FALSE;                  /*!<  Potentiometer filter variable */
//uint8_t  UART_FLAG_RECEIVE = FALSE;                 /*!<  UART commmunication flag */
//uint32_t ARR_LF = 0;                                /*!<  Autoreload LF TIM variable */
//int32_t Mech_Speed_RPM = 0;                         /*!<  Mechanical motor speed */
//int32_t El_Speed_Hz = Mech_Speed_RPM/60;                            /*!<  Electrical motor speed */
//uint16_t index_adc_chn = 0;                         /*!<  Index of ADC channel selector for measuring */
//uint16_t index_motor_run = 0;                       /*!<  Tmp variable for DEMO mode */
//uint16_t test_motor_run = 1;                        /*!<  Tmp variable for DEMO mode */
//uint8_t Enable_start_button = TRUE;                 /*!<  Start/stop button filter to avoid double command */
//uint16_t index_ARR_step = 1;
//uint32_t n_zcr_startup = 0;
//uint16_t index_startup_motor = 1;
//uint16_t target_speed = TARGET_SPEED;               /*!<  Target speed for closed loop control */
//uint16_t shift_n_sqrt = 14;
//uint16_t cnt_bemf_event = 0;
//uint8_t startup_bemf_failure = 0;
//uint8_t speed_fdbk_error = 0;
//extern __IO uint32_t uwTick;                        /*!<  Tick counter - 1msec updated */
//uint8_t dac_status = DAC_ENABLE;
//uint16_t index_align = 1;
//int32_t speed_sum_sp_filt = 0;
//int32_t speed_sum_pot_filt = 0;
//uint16_t index_pot_filt = 1;
//int16_t potent_filtered = 0;
//uint32_t Tick_cnt = 0;
//uint32_t counter_ARR_Bemf = 0;
//uint64_t constant_multiplier_tmp = 0;*/
