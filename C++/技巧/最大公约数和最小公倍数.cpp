
//最大公约数

int gcd(int a, int b)
{
    while(b > 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;

}


//最小公倍数
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}