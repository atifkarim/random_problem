#include <iostream>

int main()
{
	unsigned long long int n;
	std::cout<<"Give number to perform factorial operation\n";
	std::cin >> n;
	if (n == 1 || n == 0)
		return 1;
	else if (n < 0)
	{
		std::cout<<"Number is "<<n<<"\n";
		throw std::runtime_error("Negative number is not accepted");
	}
	else
	{
		std::cout<<n<<"! is ";
		unsigned long long int fact = n;
		while(n != 1)
		{
			fact = fact * (n-1);
			n = n - 1;
		}
		std::cout<<fact<<"\n";
		return fact;
	}
}