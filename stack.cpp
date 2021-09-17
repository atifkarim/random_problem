#include <cstdlib>
#include <iostream>
#include <ctime>

template < int ARRAY_LEN > // you can even set to a default value here of C++'11
class stack_zone
{
public:
	int const_var;
	int top;
	int array[ARRAY_LEN]; // Don't need to alloc or dealloc in structure!  Works like you imagine!
	void push(stack_zone *s, int value);
	void print_Array(stack_zone *s);
	int pop(stack_zone *s);

	stack_zone(int x);
};

template < int ARRAY_LEN >
stack_zone<ARRAY_LEN> :: stack_zone(int x)
: const_var{x}
{
	std::cout<<"constructor is called and const_var: "<<const_var<<"\n";
}

template < int ARRAY_LEN >
void stack_zone<ARRAY_LEN>:: push (stack_zone *s, int value_)
{
	if (s->top < ARRAY_LEN)
	{
		std::cout<<"inserted value: "<<value_<<" will be placed in position: "<<s->top<<std::endl;
		s->array[s->top] = value_;
		s->top = s->top + 1;
	}
	else
		std::cout<<"Array is Full\n";
}

template < int ARRAY_LEN >
int stack_zone<ARRAY_LEN>:: pop (stack_zone *s)
{
	s->top = s->top - 1;
	if (s->top >= 0)
	{
		std::cout<<"Popping value "<<s->array[s->top]<<"\n";
		return s->array[s->top];
	}
	else
		std::cout<<"Array is Empty\n";

}

template < int ARRAY_LEN >
void stack_zone<ARRAY_LEN> :: print_Array(stack_zone *s)
{
	std::cout<<"Printing Array\n";
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"array["<<i<<"] = "<<s->array[i]<<"\n";
	}
}


int main()
{
	std::srand((unsigned) time(nullptr));
	stack_zone<5> first_stack(8);
	first_stack.top = 0;

	for(int i = 0; i < 10; i++)
	{
		// first_stack.push(&first_stack, 10*(i+1));
		first_stack.push(&first_stack, (std::rand() & 0x14));
	}

	first_stack.print_Array(&first_stack);

	for(int i = 0; i < 10; i++)
	{
		first_stack.pop(&first_stack);
	}

	return 0;
}