#include "Controlador_PI.h"
#include "Parametros.h"

void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd, float output_limit) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->prev_error = 0.0f;
    pid->integral = 0.0f;
    pid->output_limit = output_limit;
}


float PID_Compute(PID_Controller *pid, float setpoint, float measurement, float dt) {
    float error = setpoint - measurement;
    pid->integral += error * dt;

    float derivative = (error - pid->prev_error) / dt;
    pid->prev_error = error;

    float output = pid->Kp * error + pid->Ki * pid->integral + pid->Kd * derivative;

    // Saturação (anti-windup simples)
    if (output > pid->output_limit)
        output = pid->output_limit;
    else if (output < -pid->output_limit)
        output = -pid->output_limit;

    return output;
}

float CorrenteReferencia;
float TensaoReferencia;
float dt = 0.001f;   //mudar isso para variar com o tempo que demorou para fazer os calcular, ou adicionar um delay para que o tempo entre calculos fique constante.

float ControleCorrente(float VelRef, float VelReal, float CorrenteReal){
	CorrenteReferencia = PID_Compute(PIDVelocidade, VelRef, VelReal, dt);
	TensaoReferencia = PID_Compute(PIDCorrente, CorrenteReferencia, CorrenteReal, dt);
	Tensao = TensaoReferencia + ke*VelReal;
	if (Tensao > TensaoBateria) {
		Tensao = TensaoBateria;
	}
	else if (Tensao - ke*VelReal > CorrenteMax*ResInt){
		Tensao = CorrenteMax*ResInt + ke*VelReal;
		}
	return	DCMAX*Tensao/TensaoBateria;
}
