int my_itoa(int value, char *buf)
{
    long long number = value;

    if(value == 0)
    {
        buf[0] = '0';
        buf[1] = '\0';
        return 1;
    }

    int direction = value > 0 ? 1 : -1;
    int index = 0;

    if(direction < 0)
    {
        buf[index ++] = '-';
        number = -number;
    }

    int start = index;

    

    while(number > 0)
    {   
        buf[index++] = '0' +(number % 10);
        number /= 10;
    }
    buf[index] = '\0';

    int left = start, right = index - 1;
    while (left < right) {
        char tmp = buf[left];
        buf[left] = buf[right];
        buf[right] = tmp;
        left++;
        right--;
    }
    return index;

}

string dec_to_bin(int n) {
    if (n == 0) return "0";

    string s;
    while (n > 0) {
        s += (n % 2) ? '1' : '0';  // 先得到低位
        n /= 2;
    }
    reverse(s.begin(), s.end());   // 或头插：s = (n%2?'1':'0') + s
    return s;
}

string dec_to_hex(int n) {
    if (n == 0) return "0";

    const char digits[] = "0123456789ABCDEF";
    string s;
    while (n > 0) {
        s += digits[n % 16];
        n /= 16;
    }
    reverse(s.begin(), s.end()); //核心都是从低位开始，然后反转
    return s;
}