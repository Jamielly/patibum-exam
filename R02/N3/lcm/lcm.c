unsigned int pgcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return (a);
}
unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return (0);
    return ((a * b) / pgcd (a, b));
}

================= versão ainda mais simples =========================

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int temp;
    unsigned int a1 = a;
    unsigned int b1 = b;

    if (a == 0 || b == 0)
        return (0);
    while (b1 != 0)
    {
        temp = b1;
        b1 = a1 % b1;
        a1 = temp;
    }
    return ((a * b) / a1);
}