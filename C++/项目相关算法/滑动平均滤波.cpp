
#define N 30

typedef struct{
    
    float buffer[N];
    int index;
    float sum;

}MovingAvg_t;


int moving_avg(MovingAvg_t f,float new_data)
{
    f.sum -= f.buffer[f.index];
    f.sum += new_data;
    f.buffer[f.index] = new_data;
    f.index = (f.index + 1) % N;
    return f.sum / N;
}