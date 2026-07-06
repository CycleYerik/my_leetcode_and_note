size_t my_strlen(const char *s) 
{
    if(s == nullptr)
    {
        return 0;
    }    
    const char* temp = s;
    int count = 0;
    while(*temp != '\0')
    {
        temp++;
        count++;
    }
    return count;

}

size_t my_strlen(const char *s)
{
    if (s == nullptr) {
        return 0;
    }

    const char *temp = s;
    while (*temp != '\0') {
        temp++;
    }
    return (size_t)(temp - s);
}

char *my_strcpy(char *dest, const char *src)
{
    //判空
    if(src == nullptr)
    {
        return dest;
    }
    if(dest == nullptr)
    {
        return nullptr;
    }



    const char * src_temp = src;
    char * dest_temp = dest;
    while(*src_temp != '\0')
    {
        *dest_temp = *src_temp;
        dest_temp++;
        src_temp++;
    }
    *dest_temp = *src_temp;
    return dest;

}

int my_strcmp(const char *s1, const char *s2)
{
    const char *t1 = s1;
    const char *t2 = s2;

    while (*t1 == *t2) {
        if (*t1 == '\0') {
            return 0;
        }
        t1++;
        t2++;
    }
    return (unsigned char)*t1 - (unsigned char)*t2;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

void *my_memmove(void *dest, const void *src, size_t n)
{


    
    //判断是否重叠
    char * d = (char*)dest;
    const char * s = (const char*) src;

    //边界条件判断
    if(n == 0 || d == s)
    {
        return dest;
    }

    if(d < s || d >= s + n)
    {
        while (n--) {
            *d = *s;
            d++;
            s++;
        }
    }
    else 
    {
        int count = n;
        
        d += n-1; //从尾部开始复制
        s += n-1;
        while(n--)
        {
            *d = *s;
            d--;        
            s--;
        }
        
    }
    return (void*)dest;



}