/**
*@author Maxwell Griffith
*@file inventory.h
*/

#ifndef inventory_h
#define inventory_h
#include <iostream>
using namespace::std;

class inventory
{
public:
    inventory();
	inventory(int id, int store, int qt);

	void setId(int id);
	void setStoreNr(int store);
	void setQuantity(int qt);

    int getId(void)        const;
	int getStoreNr(void)   const;
	int getQuantity(void)  const;


private:
	int itemId;
	int storeNr;
	int quantity;

};
#endif
