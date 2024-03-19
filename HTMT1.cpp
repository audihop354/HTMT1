#include <iostream>
#include <cmath>

using namespace std;

string to_Bin(int x) {
    string bin;
    for (int i = 6; i >= 0; --i)
        bin += ((x >> i) & 1) ? '1' : '0';
    return bin;
}

string signMagnitude(int x) {
    if ((x<-127) || (x>127)) // Check for overflow
        return "overflow";
    string binary = to_Bin(x < 0 ? -x : x);
    return (x < 0 ? ('1' + binary) : ('0' + binary));
}

string One_Complement(int x) {
    if ((x<-127) || (x>127)) // Check for overflow
        return "overflow";
    string binary = to_Bin(x < 0 ? -x : x);
    if (x > 0)
        return '0' + binary;
    string new_bin;
    for (auto i : binary) {
        new_bin += ((i == '1') ? '0' : '1');
    }
    return '1' + new_bin;
}

string Two_Complement(int x) {
    if ((x < -128) || (x > 127)) // Check for overflow
        return "overflow";
    string binary = to_Bin(x < 0 ? -x : x);
    if (x == -128)
        return "10000000";
    if (x >= 0)
        return '0' + binary;
    binary = One_Complement(x);
    int check = 1;
    for (int i = binary.length() - 1; i >= 0 && check; i--) {
        int sum = (binary[i] - '0') + check;
        binary[i] = (sum % 2) + '0';
        check = sum / 2;
    }
    return binary;
}

string two_Com_to_hex(string bin)
{
    if (bin == "overflow") 
    {
		return "overflow";
	}
	int check=0;
	if (bin[0]=='1')
	{
	    check =1;
	}
    string text = "0123456789ABCDEF";
	string ans = "";
	for (int i = bin.length() - 1; i >= 0; i -= 4) {
		int temp = 0;
		for (int j = 0; j < 4; j++) {
			temp += ((bin[i - j] - '0') << j);
		}
		ans = string(1, text[temp]) + ans;
	}
	return (check==0) ? ("00"+ans) : ("FF"+ans);
}

int main() {
    int n;
    cout << "Moi nhap gia tri: ";
    cin >> n;
    if (n==0)
    {
        cout << "Sign-Magnitude form of " << n << ": 00000000 or 10000000\n";
        cout << "1’s complement form of " << n << ": 00000000 or 11111111\n";
        cout << "2’s complement form of " << n << ": " << Two_Complement(0); 
        cout << "\nHexadecimal: " << two_Com_to_hex(Two_Complement(0));
    }
    else
    {
        cout << "Sign-Magnitude form of " << n << ": " << signMagnitude(n);
        cout << "\n1’s complement form of " << n << ": " << One_Complement(n);
        cout << "\n2’s complement form of " << n << ": " << Two_Complement(n); 
        cout << "\nHexadecimal: " << two_Com_to_hex(Two_Complement(n));
    }
    return 0;
}

