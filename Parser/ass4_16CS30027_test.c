

void func()
{
    float x = 5.6;
    float y = 45.9;
    float z;
    z= x+y;
}
// A utility function to swap two elements
void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

int getCount(char keypad[][3], int n)
{
    int i;
    i++;
    i--;
    i=i*i;
    i=i-5;
    if (i&&0||!i) i=i+50;

    if(i==0) { i=i*i; }
    i=i%2;
    i= (((i>>5)<<8)+9)-100;
    i=8^5;
    i = 7/4;

    if(i > -10) {i%=20;}
    else if (i < -10) i+=5;
    else i-=7;

    i<<=5;
    i>>=2;
    i&=21;
    i^=12;

    do{
    auto int j=0,k=0;
    j|=i;
    i--;
    if(j>i) break;
    }
    while(i||i+10);

    i=sizeof(char);
    _Bool   a;
    _Complex    b;
    _Imaginary  c;
    enum days;

    int x = -2;
    x = x -1;
    float j1,k123;
    if(keypad == NULL || n <= 0)
        return 0;
    if(n == 1)
        return 10;
 
    int t1 = -10;
    int row[] = {0, 0, -1, 0, 1};
    int col[] = {0, -1, 0, 1, 0};
 
    int count[10][n+1];
    int j=0, k=0, move=0, ro=0, co=0, num = 0;
    int nextNum=0, totalCount = 0;
 
    for (i=0; i<=9; i++)
    {
        count[i][0] = 0;
        count[i][1] = 1;
    }

    for (k=2; k<=n; k++)
    {
        for (i=0; i<4; i++)  
        {
            for (j=0; j<3; j++)   
            {
            
                if (keypad[i][j] != '*' && keypad[i][j] != '#')
                {
                    num = keypad[i][j] - '0';
                    count[num][k] = 0;
 
                    for (move=0; move<5; move++)
                    {
                        ro = i + row[move];
                        co = j + col[move];
                        if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 &&
                           keypad[ro][co] != '*' && keypad[ro][co] != '#')
                        {
                            nextNum = keypad[ro][co] - '0';
                            count[num][k] += count[nextNum][k-1];
                        }
                    }
                }
            }
        }
    }
 
    totalCount = 0;
    for (i=0; i<=9; i++)
        totalCount += count[i][n];
    return totalCount;
}

 