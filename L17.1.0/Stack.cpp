#include "Stack.h"

Stack::Stack()
{
	top = -1;
}
void Stack::put(int var)
{
	st[++top] = var;
}
int Stack::pop()
{
	return st[top--];
}