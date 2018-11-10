//This test file extensively checks the expressions both boolean and algebraic
//and also the funciton calling and returning process in detail

int printStr(char *c);
int printInt(int i);
int readInt(int *eP);

int diff(int a, int b) 
{
  int ans;
  printStr("got into function \n");
  ans = a-b;
  printStr("ans in diff fn: \n");
  printInt(ans);
  printStr("returning from function \n");
  return ans;
}

int main () 
{
  int x, y, z;
  int eP1, eP2;
  printStr("Enter two numbers : \n");
  x = readInt(&eP1);
  y = readInt(&eP2);
  printStr("x :");
  printInt(x);
  printStr("\n y:");
  printInt(y);
  printStr("\n");

  z = diff(x,y);
  printStr("difference of the two number is equal to\n ");
  printInt(z);
  printStr("\n");
  return c;
}