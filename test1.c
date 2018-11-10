//This testfile checks the functioning of the library functions printInt, readInt and printStr

int printInt(int n);
int printStr(char* c);
int readInt(int* eP);

int f(int *a)
{
    int b;
    b = *a;
    b = b + 2;
    return b;
}

int main()
{
    int k;
    k = printStr("Testing print string");
    printInt(k);

    k = printInt(12);
    printInt(k);    

    printStr("Testing read int \n");
    printStr("Enter integer: ");
    int a = readInt(&k);
    printStr("printing the read integer: ");
    if(k ==0)
        printInt(a);
    else
        printStr("Error in reading int");

    int b;
    printStr("Testing pointers!");
    b = f(&k);

    return 0;
}

