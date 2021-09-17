/**
 * bubble sort using while loop.
 * instead of array one can use vector too.
 */

#include <iostream>

int main()
{
	double given_array[] = {-10,5,2,7,1,-8, 0.5};
	int given_array_size = (sizeof(given_array)/sizeof(*given_array));
	int start_point = 0;
	int index_min;
	int compare_index;
	int temp;

	for(int i = 0; i < given_array_size; i++)
	{
		std::cout<<"A_i["<<i<<"]: "<<given_array[i]<<"\n";
		for (int j = 0; j < given_array_size - i - 1; j++)
		{
			std::cout<<"A_j["<<j<<"]: "<<given_array[j]<<"\n";
			if (given_array[j] > given_array[j + 1])
			{
				temp = given_array[j];
				given_array[j] = given_array[j + 1];
				given_array[j + 1] = temp;
			}
		}
	}

	// printing the array
	for (int k = 0; k < given_array_size; k++)
	{
		std::cout<<given_array[k] << " : ";
	}
	std::cout<<"\n";

	return 0;
}