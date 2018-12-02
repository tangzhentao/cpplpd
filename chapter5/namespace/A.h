/*
 * dd
 */
#ifndef A_H
#define A_H

#include <iostream>

class A
{
	public:
		void print()
		{
			printf("print: i = %d\n", 9);
		}
		void log();

		int i;
};

#endif
