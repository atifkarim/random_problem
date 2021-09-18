#include <iostream>

// here 0,1,2,3,4,5 index is present. Assusme last index will be empty alltime
// so, data will be in A[0] to A[4]
#define ARRAY_LEN 6

typedef struct {
	int head, tail;
	int q_array[ARRAY_LEN];
} queue_zone;

void ENQUEUE (queue_zone *s, int value_)
{
	if (s->tail <= (ARRAY_LEN - 2) && s->tail != s->head)
	{
		std::cout<<"inserted value: "<<value_<<" will be placed in position: "<<s->tail<<std::endl;
		s->q_array[s->tail] = value_;
		s->tail = s->tail + 1;
	}
	else if(s->tail == s->head)
	{
		std::cout<<"s->head: "<<s->head << " s->tail: "<<s->tail<<" , they are same so hault and wait for head to proceed" <<std::endl;
	}
	//else if(s->tail == (ARRAY_LEN - 1))
	else
	{
		std::cout<<"position "<<s->tail <<" is reached so NO pushing is possible. Go To initial state\n";
		std::cout<<"s->tail = "<<0<<std::endl;
		s->tail = 0;
		if (s->head != 0)
		{
			std::cout<<"inserted value: "<<value_<<" will be placed in position: "<<s->tail<<std::endl;
			s->q_array[s->tail] = value_;
			s->tail = 1;
		}
	}
}

int DEQUEUE (queue_zone *s)
{
	s->head = s->head + 1;
	if (s->head <= (ARRAY_LEN - 2))
	{
		std::cout<<"Popping value "<<s->q_array[s->head]<<" from position "<<s->head<<"\n";
		return s->q_array[s->head];
	}
	else if (s->head == (ARRAY_LEN - 1))
	{
		s->head = -1;
		std::cout<<"All value is Already popped from Queue so now popping from index 0 : "<<s->q_array[0]<<"\n";
		return s->q_array[0];
	}

}

void print_Array(queue_zone *s)
{
	std::cout<<"Printing Array\n";
	for(int i = 0; i < ARRAY_LEN - 1; i++)
	{
		std::cout<<"array["<<i<<"] = "<<s->q_array[i]<<"; ";
	}
	std::cout<<"\n";
}

int main()
{
	queue_zone q_obj;
	q_obj.tail = 0;
	q_obj.head = -1;

	srand((int)time(0));

	std::cout<<"First insertion in the Queue\n";
	for(int i = 0; i < (ARRAY_LEN - 1); i++)
	{
		// first_stack.ENQUEUE(&first_stack, 10*(i+1));
		ENQUEUE(&q_obj, ((rand() % 100) + 1));
	}

	print_Array(&q_obj);
	DEQUEUE(&q_obj);
	DEQUEUE(&q_obj);
	print_Array(&q_obj);
	std::cout<<"again pushing\n";
	for(int i = 0; i < 3; i++)
	{
		// first_stack.ENQUEUE(&first_stack, 10*(i+1));
		ENQUEUE(&q_obj, ((rand() % 100) + 2*3));
	}
	print_Array(&q_obj);
	DEQUEUE(&q_obj);
	print_Array(&q_obj);

	ENQUEUE(&q_obj, -35);
	ENQUEUE(&q_obj, -5);
	print_Array(&q_obj);

	return 0;
}