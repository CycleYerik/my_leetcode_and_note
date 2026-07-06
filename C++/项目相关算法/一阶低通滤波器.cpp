



float lpf_update(float x, float y_prev, float alpha)
{
    return alpha * x + (1 - alpha) * y_prev;
}

int main()
{
    float x = 10;
    float y_prev = 0;
    float alpha = 0.2;

    //加入测试
    for(int i = 0; i < 10; i++)
    {
        x = x + 1;
        float y = lpf_update(x, y_prev, alpha);
        y_prev = y;
        printf("x = %f, y = %f, y_prev = %f\n", x, y, y_prev);
    }   
    return 0;
}