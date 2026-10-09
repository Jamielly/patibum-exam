unsigned char	reverse_bits(unsigned char octet)
{
  int i = 8;
  unsigned char res = 0;
  while (i > 0)
  {
    res = (res << 1) | (octet & 1);
    octet >>= 1;
    i--;
  }
  return (res);
}


unsigned char	reverse_bits(unsigned char octet)
{
  int i;
  unsigned char result;

  i = 8;
  result
  while(i-- > 0)
  {
    result = (result * 2) + (octet % 2);
    octet = octet / 2;
  }
  return(result);
}



void print_bits(unsigned char octet)
{
  int i = 8;
  unsigned char result; 

  while(i-- > 0)
  {
    result = (result >> i & 1) + '0';
    write(1, &result, 1);
  }
}
