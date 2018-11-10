#include "stdio.h"
#include "myl.h"
#define SIZE 20

int printStr(char* s )
{
  int i=0;
  char c[1]= "\n";
  while(s[i]!= '\0')
  {
    i++;
  }
__asm__ __volatile__ (
  "movl $1, %%eax \n\t"
  "movq $1, %%rdi \n\t"
  "syscall \n\t"::"S"(s), "d"(i)
  ) ;
__asm__ __volatile__ (
  "movl $1, %%eax \n\t"
  "movq $1, %%rdi \n\t"
  "syscall \n\t"::"S"(c), "d"(1)
  ) ;
  return i;
}

int printInt(int n)
{
  // printf("n is %d\n", n);
  char buff[SIZE], zero='0';
  int i=0, j, k, bytes;
  if(n == 0) 
    buff[i++]=zero;
  else
  {
    if(n < 0) 
    {
      buff[i++]='-';
      n = -n;
    }
    while(n)
    {
      int dig = n%10;
      buff[i++] = (char)(zero+dig);
      n /= 10;
    }
    if(buff[0] == '-') 
      j = 1;
    else 
      j = 0;
    k=i-1;
    while(j<k)
    {
      char temp=buff[j];
      buff[j++] = buff[k];
      buff[k--] = temp;
    }
  } 
  buff[i]='\n';
  bytes = i+1;

__asm__ __volatile__ (
  "movl $1, %%eax \n\t"
  "movq $1, %%rdi \n\t"
  "syscall \n\t"
  :
  :"S"(buff), "d"(bytes)
    ) ;  // $1: write, $1: on stdin
  return i;
}


int printFlt(float f)
{
    char buff[100];
    char c[1] ="\n";
  int i=0,j,count=0,k,bytes;
  if (f==0) buff[i++]='0';
  else {
    if(f<0) {
      buff[i++]='-';
      f=-f;
    }
    while (f!=(int)f) {/*checking if the decimal point is reached in our iteration */
      f*=10;
      count++;/*stores the distance of the decimal point from right hand side of the number*/
    }
    int dg=0,n=(int)f;
    if (count==0) count=-2;
    while (n) {
      if (count==0) {
        buff[i++]='.';/*placing the decimal at its correct locaiton*/
        count=-2;
      }
      else {
      dg=n%10;
      buff[i++]=(char)(dg+'0');
      n/=10;
      count--;
      }
    }
    if(buff[0]=='-') j=1;
    else j=0;
    k=i-1;
    char temp;
    /*reversing the array*/
    while (j<k) {
      temp=buff[j];
      buff[j++]=buff[k];
      buff[k--]=temp;
    }
  }
  bytes=i;
  /*inline asm commands for system call to print "buff" till "bytes" length to STDOUT*/
  __asm__ __volatile__ (
  "movl $1, %%eax \n\t"
  "movq $1, %%rdi \n\t"
  "syscall \n\t"
  :
  :"S"(buff),"d"(bytes)
  );
  __asm__ __volatile__ (
  "movl $1, %%eax \n\t"
  "movq $1, %%rdi \n\t"
  "syscall \n\t"
  :
  :"S"(c), "d"(1)
  ) ;
return bytes;
}

int readInt(int *eP)
{ //ERR =1
  char buff[1], num[SIZE];
  int i=0,j, n=0;
  while(1)
  {
      __asm__ __volatile__ ("syscall \n\t"::"a"(0),"D"(0),"S"(buff),"d"(1)
    );
   // if( ('0'<= buff[0] && buff[0]<= '9') || buff[0] == '-')
    if ( buff[0]=='\t' ||  buff[0] == ' ' || buff[0] == '\n')
        break;
    num[i++] = buff[0];
  }
  int len = i;
  if( (num[0] <'0' || num[0] > '9')&& num[0]!= '-')
    *eP=1;
  j = 1;
  while(j < len)
  {
  	if(num[j] == '-' && j>0)
  	  *eP = 1;
  	if(num[j] <'0' || num[j] > '9')
  	  *eP = 1;
  	j++;
  }

  if(i >9 || i <=0)
    *eP = 1;
  
  if(num[0] == '-')
    j=1;
  else
    j=0;

  i= j;
  while(i<len)
  {
    if(num[i] == '-' )
    {
      *eP = 1;
    }
    int x = num[i]-'0'; 
    n = n * 10 + x;
    i++;
  }

  if (j==1) n = -n;
  *eP = 0;
  return n;  
}

int readFlt(float *er)
{
  char buff[1], num[SIZE];
  int i=0,j, ndot=0;
  float n=0;
  float temp = 0.1;
  while(1)
  {
      __asm__ __volatile__ ("syscall \n\t"::"a"(0),"D"(0),"S"(buff),"d"(1)
    );    
    if( buff[0]== '\t' || buff[0] == ' ' || buff[0] == '\n')
      break;
    num[i] = buff[0];
    if(num[i] == '.')
        ndot ++;
    i++;
  }
  if(ndot > 1)
    return ERR;
  if(i >9 || i ==0)
    return ERR;
  j=0;
  while(j < i)
  {
    if(num[j] == '-' && j>0)
      return ERR;
    if(num[j]!='.')
    { 
       if(num[j] <'0' || num[j] > '9' )
        return ERR;
    }
    j++;
  }
  int len = i;
  if(num[0] == '-')
    j=1;
  else
    j=0;

  i= j;
  while(i<len && num[i]!='.' )
  {
    int x = num[i] - '0'; 
    n = n * 10 + x;
    i++;
  }
  if(num[i] == '.')
    i++;
  while(i < len)
  {
    int x = num[i] - '0';
    n = n + (temp) * x;
    temp = temp * 0.1;
    i++;
  }
  
  if (j==1) n = -n;
  *er =n;
  return OK;  
}
