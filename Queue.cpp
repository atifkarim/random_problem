#include <cstdlib>
#include <iostream>
#include <ctime>

template < int ARRAY_LEN > // you can even set to a default value here of C++'11
class queue_zone
{
public:
	int const_var;
	int tail;
	int head;
	int array[ARRAY_LEN]; // Don't need to alloc or dealloc in structure!  Works like you imagine!
	void ENQUEUE(queue_zone *s, int value);
	void print_Array(queue_zone *s);
	int DEQUEUE(queue_zone *s);

	queue_zone(int x);
};

template < int ARRAY_LEN >
queue_zone<ARRAY_LEN> :: queue_zone(int x)
: const_var{x}
{
	std::cout<<"constructor is called and const_var: "<<const_var<<"\n";
}

template < int ARRAY_LEN >
void queue_zone<ARRAY_LEN>:: ENQUEUE (queue_zone *s, int value_)
{
	if (s->tail < ARRAY_LEN)
	{
		std::cout<<"inserted value: "<<value_<<" will be placed in position: "<<s->tail<<std::endl;
		s->array[s->tail] = value_;
		s->tail = s->tail + 1;
	}
	else
		std::cout<<"Array is Full\n";
}

template < int ARRAY_LEN >
int queue_zone<ARRAY_LEN>:: DEQUEUE (queue_zone *s)
{
	s->head = s->head + 1;
	if (s->head < s->tail)
	{
		std::cout<<"Popping value "<<s->array[s->head]<<"\n";
		return s->array[s->head];
	}
	else
		std::cout<<"Array is Empty\n";

}

template < int ARRAY_LEN >
void queue_zone<ARRAY_LEN> :: print_Array(queue_zone *s)
{
	std::cout<<"Printing Array\n";
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"array["<<i<<"] = "<<s->array[i]<<"; ";
	}
	std::cout<<"\n";
}


int main()
{
	std::srand((unsigned) time(nullptr));
	queue_zone<5> first_stack(8);
	first_stack.tail = 0;
	first_stack.head = -1;

	for(int i = 0; i < 10; i++)
	{
		// first_stack.ENQUEUE(&first_stack, 10*(i+1));
		first_stack.ENQUEUE(&first_stack, (std::rand() & 0x14));
	}

	first_stack.print_Array(&first_stack);

	for(int i = 0; i < 10; i++)
	{
		first_stack.DEQUEUE(&first_stack);
	}

	std::cout<<"New data\n";
	for(int i = 0; i < 10; i++)
	{
		// first_stack.ENQUEUE(&first_stack, 10*(i+1));
		first_stack.ENQUEUE(&first_stack, (std::rand() & 0x14));
	}

	return 0;
}