int decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
}

void decToBinary(int n)
{
    int bin[32];
 
    int i = 0;
    while (n > 0) {
 
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    for (int j = i - 1; j >= 0; j--)
        cout << bin[j];
}

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    int base = 1;
 
    int len = num.size();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}