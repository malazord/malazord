#ifndef Controlador_PI_H_
#define Controlador_PI_H_

#endif /*Controlador_PI_H_*/


typedef struct {
    float Kp;
    float Ki;
    float Kd;

    float prev_error;
    float integral;
    float output_limit; // para limitar a saída, se necessário

} PID_Controller;

void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd, float output_limit);
float PID_Compute(PID_Controller *pid, float setpoint, float measurement, float dt);
