// BY Anusha Potnuru
int printInt(int n);
int printStr(char* c);
int readInt(int* eP);

int main() 
{
	int a[5];
	int ep, ep1, ep2, ep3, ep4;

	printStr("Read and printing array elements of size five\n");
	a[0] = readInt(&ep);
	printInt(a[0]);
	printStr("\n");

	a[1] = readInt(&ep1);
	printInt(a[1]);
	printStr("\n");

	a[2] = readInt(&ep2);
	printInt(a[2]);
	printStr("\n");

	a[3] = readInt(&ep3);
	printInt(a[3]);
	printStr("\n");

	a[4] = readInt(&ep4);
	printInt(a[4]);
	printStr("\n");


	return 0;
}



