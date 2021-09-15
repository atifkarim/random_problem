/**
 * selection sort using while loop.
 * instead of array one can use vector too.
 */

#include <iostream>

int main()
{
	int given_array[] = {-10,5,2,8,7,1,-8,87};
	int given_array_size = (sizeof(given_array)/sizeof(*given_array));
	int start_point = 0;
	int index_min;
	int compare_index;
	int temp;

	/**
	 * first while loop will start from first index of the array and it will
	 * compare from second to last index of the array
	 * that's why first while loop will run till array_size - 1
	 * length
	 */
	while(start_point < given_array_size - 1)
	{
		/**
		 * here index_min an alias for starting point. it will change in every
		 * new comparison. chnage means it starts from 0 and goes till size-2 length
		 * Eg: if size of array is 5 that means it's highest index is 4.
		 * then if index_min reaches to 3 it is unnecessary to go further
		 * (compare someone with itself). so 3 means (size - 2)
		 */
		index_min = start_point;

		/**
		 * here compare_index starts from index 1 and run till last index
		 * A [0] will be compared each time with A [compare_index]
		 * compared_index will be 1,2,..., size-1
		 * the second while loop works for this comparison
		 */

		compare_index = start_point + 1;
		while(compare_index < given_array_size)
		{
			/**
			 * this if condition check A [compare_index] is less than the considered
			 * small value (A [start_point]) or not.
			 * if True then index_min will change it value by compare_index
			 * Don't forget , this index_min only changing it's value in this 2nd
			 * while loop and it will do the rest job for swaping the value in the array
			 * While start again the first while loop it will again take the considered small
			 * value for that iteration
			 * (Eg: first iteration considered small value is in index 0, so index_min is 0
			 *      second iteration considered small value is in index 1, so index_min is 1)
			 */
			if (given_array[compare_index] < given_array[index_min])
			{
				index_min = compare_index;
			}
			/**
			 * end of second while loop. We know who is the smallest value after first iteration
			 * among all of the value. Now compare_index will be 2nd index so increment by one.
			 * try to remember, compare_index was 1 in initial time and it's charecter is to increment
			 * by 1 during each comparison and it's final value will be highest index of the array
			 */
			compare_index ++;
		}

		/**
		 * now it's time to swap value
		 * Already we have tried to change the index_point. If it is unchanged then don't bother
		 * and start the first while loop but if FALSE then the following if condition will be
		 * trigerred and swaping will be taken place
		 */
		if (index_min != start_point)
		{
			// temp is taken the considered small value
			temp = given_array[start_point];

			/**
			 * start_point means lowest index. And index_point is the calculated index of the smallest value.
			 * so, it's time to place the smallest value in the smallest index and that's it
			 */
			given_array[start_point] = given_array[index_min];

			// And now index_point address is going to have the considered small value.
			given_array[index_min] = temp;
		}

		// finish of a successful comparison and increments the position by one to continue the iteraion
		start_point ++;
	}

	// printing the array
	for (int k = 0; k < given_array_size; k++)
	{
		std::cout<<given_array[k] << " : ";
	}
	std::cout<<"\n";

	return 0;
}