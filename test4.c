
int printInt(int n);
int printStr(char* c);
int readInt(int* eP);

int sumofdigits(int x)       // Recursive function that will return the sum of every single digit
{
    int k;
    if((x/10)==0)
    {
        k = x;
    }
    else
    {
        k = sumofdigits(x%10) + sumofdigits(x/10);
        // It will calculate the sum of the digits of the number.
    }
    return k;
}

int main()
{
    int n;
    printStr("This Programs calculate if a number is a magic number or not.\n");
    printStr("ENTER NUMBER\n");    // To input a number
    int err;
    n=readInt(&err);
    while((n/10)!=0)
    {
        n=sumofdigits(n);     // Calculate the sum of the digits until you get a single digit i.e from 0 to 9 and then check if it is 1
    }
    printStr("Sum of digits \n");
    printInt(n);
    printStr("\nKeep calculating sum of digits until single digit, If  1, it is magical, else not!! \n");

    if(n==1)       
    {
        printStr("Number is magic\n");
    }
    else
    {
        printStr("number is not magic\n");
    }
    return 0;
}

