
// 连续PID
typedef struct{
    float Kp,Ki,Kd;
    float error;
    float integral;
    float derivative;
    float last_error;
    float output;

} PIDControl_t;

const float MAX_INTEGRAL = 100;
const float MIN_INTEGRAL = -100;
const float MAX_OUTPUT = 100;
const float MIN_OUTPUT = -100;

float PID_Control(PIDControl_t *pid,float target,float feedback)
{
    pid->error = target - feedback;
    pid->integral += pid->error;
    if(pid->integral > MAX_INTEGRAL)
    {
        pid->integral = MAX_INTEGRAL;
    }
    else if(pid->integral < MIN_INTEGRAL)
    {
        pid->integral = MIN_INTEGRAL;
    }
    pid->derivative = pid->error - pid->last_error;
    pid->last_error = pid->error;
    pid->output = pid->Kp * pid->error + pid->Ki * pid->integral + pid->Kd * pid->derivative;
    if(pid->output > MAX_OUTPUT)
    {
        pid->output = MAX_OUTPUT;
    }
    else if(pid->output < MIN_OUTPUT)
    {
        pid->output = MIN_OUTPUT;
    }
    return pid->output;
}

// 离散PID
typedef struct{
    float Kp,Ki,Kd;
    float error;
    float integral;
    float derivative;
    float last_error;
    float output;
} DiscretePIDControl_t;

const float MAX_INTEGRAL = 100.0f;
const float MIN_INTEGRAL = -100.0f;
const float MAX_OUTPUT = 100.0f;
const float MIN_OUTPUT = -100.0f;
const float T = 0.01f;

float DiscretePID_Control(DiscretePIDControl_t *pid,float target,float feedback)
{
    pid->error = target - feedback;
    pid->integral += pid->error * T;
    if(pid->integral > MAX_INTEGRAL)
    {
        pid->integral = MAX_INTEGRAL;
    }
    else if(pid->integral < MIN_INTEGRAL)
    {
        pid->integral = MIN_INTEGRAL;
    }
}
    pid->derivative = (pid->error - pid->last_error) / T;
    pid->last_error = pid->error;
    pid->output = pid->Kp * pid->error + pid->Ki * pid->integral + pid->Kd * pid->derivative * T;
    if(pid->output > MAX_OUTPUT)
    {
        pid->output = MAX_OUTPUT;
    }
    else if(pid->output < MIN_OUTPUT)
    {
        pid->output = MIN_OUTPUT;
    }
    return pid->output;
}