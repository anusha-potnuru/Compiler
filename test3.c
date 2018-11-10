//test file to check functions and iterations and also some of the
//functions created in assignment 2

int printStr(char *c);
int printInt(int i);
int readInt(int *eP);


int fibonacci(int a)
{
  printStr("Entered the fibonacci function\n");
  int f=1,f_1=0;
  int i=1,temp;
  while(i<a) 
  {

    temp=f;
    f=f+f_1;
    f_1=temp;
    i=i+1;
  }
  return f;
}

int main () 
{
  printStr("Enter the i for finding its fibonacci number : ");
  int i,ep;
  i =readInt(&ep);
  printStr("\nYou Entered : ");
  printInt(i);

  printStr("\nNow, entering the function to calculate fibonacci numbers for i:\n");
  int j;
  j=fibonacci(i);
  printStr("\nThe fibonacci number calculated is : ");
  printInt(j);
  printStr("\nReturned from the fib function\n");
  return;
}