#include "wife.h"
#include "husband.h"
#include "exhusband.h"

void Wife::printHusband(Husband &h)
{
	//printf("husband money: %d\n", h.money);
}

void Wife::printExhusband(Exhusband &eh)
{
	printf("ex-husband, password: %d, money: %d\n", eh.password, eh.money);
}
