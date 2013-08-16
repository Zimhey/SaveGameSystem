/*
 * Main.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: Corey Dixon
 */

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Obj.h"
#include "Entity.h"

// http://www.cplusplus.com/forum/beginner/49924/
int main()
{
	// create objects
	srand(time(NULL));	// seed random number generator with time
	int created = rand() % 25 + 25; //25-50 objects
	Obj **objects1 = new Obj *[created];	// create an array of pointers

	for (int i = 0; i < created; i++)
	{
		int type = rand() % 2;	// types range from 0-1
		if (type == 0)
			objects1[i] = new Obj(rand() % 1280, rand() % 720, rand() % 32 + 32,
					rand() % 64 + 64);
		if (type == 1)
			objects1[i] = new Entity(rand() % 1280, rand() % 720,
					rand() % 32 + 32, rand() % 64 + 64);
	}

	// save objects
	std::ofstream ofs("save.sav");	// file extension is irrelevant
	ofs << created << "\n\n";// write to the file the number of objects we're going to write (and end line)
	for (int i = 0; i < created; i++)
	{
		ofs << objects1[i][0].getType() << '\n' << objects1[i][0] << '\n';// write the type then the object using the <<operator
	}
	ofs.close();	// close file of course

	// load objects
	std::ifstream ifs("save.sav");
	int fileTotal, read = 0;
	ifs >> fileTotal;	// read total number of objects
	Obj **objects2 = new Obj *[fileTotal]; //new array of pointers

	for (int i = 0; i < fileTotal; i++)
	{
		int type = -1;	// Error if this is still -1 after reading
		ifs >> type;	// read the object type
		if (type == 0)	// Obj
		{
			objects2[i] = new Obj;
			ifs >> objects2[i][0];	// read Obj
			read++;
		}
		else if (type == 1) // Entity
		{
			objects2[i] = new Entity;
			ifs >> objects2[i][0];	// read Entity
			read++;
		}
		else		// Unknown
		{	// output error and leave loop if invalid object
			std::cout << "ERROR: Invalid Object Type: Object #" << i
					<< std::endl;
			break;
		}
	}
	ifs.close();	// close file

	std::cout << "Created: " << created << std::endl << "Total read: " << read
			<< std::endl;

	// deallocate
	for (int i = 0; i < created; i++)
	{
		delete objects1[i];
	}
	delete objects1;

	for (int i = 0; i < read; i++)	// separate in case of error
	{
		delete objects2[i];
	}
	delete objects2;

	return 0;
}
