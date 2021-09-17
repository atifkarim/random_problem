/**
 * insertion sort using while loop.
 * instead of array one can use vector too.
 */

#include <iostream>

int main()
{
	double given_array[] = {-10,5,2,3,7,1,-8, 0.5};
	int given_array_size = (sizeof(given_array)/sizeof(*given_array));
	int temp;

	for(int i = 1; i < given_array_size; i++)
	{
		std::cout<<"i: "<<i<<" ";
		temp = given_array[i];
		int j = i - 1;
		std::cout<<"j: "<<j<<" ";
		while (j >= 0 && given_array[j] > temp)
		{
			given_array[j+1] = given_array[j];
			std::cout<<"inside of While j-1: "<<j-1<<" ";
			j = j - 1;
		}
		std::cout<<"j+1: "<<j+1<<" temp: "<<temp<<" \n";
		given_array[j+1] = temp;

		for (int k = 0; k < given_array_size; k++)
		{
			std::cout<<given_array[k] << " : ";
		}
		std::cout<<"\n";
	}

	// printing the array
	// for (int k = 0; k < given_array_size; k++)
	// {
	// 	std::cout<<given_array[k] << " : ";
	// }
	// std::cout<<"\n";

	return 0;
}