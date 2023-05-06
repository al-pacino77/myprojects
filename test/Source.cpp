#include<iostream>

using namespace std;

int main()
{
	int sum = 0;
	for (int i = 3; i <= 1000; i += 3)
	{
		sum = sum + i;
	}
	cout <<"The sum of all multiples of 3 below 1000 is: " << sum;
}