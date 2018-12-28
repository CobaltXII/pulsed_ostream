#pragma once

#include <iostream>
#include <ostream>
#include <sstream>
#include <thread>
#include <chrono>

struct pulsed_ostream_trait
{
	unsigned int traits;

	pulsed_ostream_trait(unsigned int _traits)
	{
		traits = _traits;
	}
};

/*

Use the pulsed_endl to flush a pulsed_ostream while also supplying a newline.

*/

const pulsed_ostream_trait pulsed_endl = pulsed_ostream_trait(32);

/*

Use the pulsed_flush to flush a pulsed_ostream without supplying a newline.

*/

const pulsed_ostream_trait pulsed_flush = pulsed_ostream_trait(778699);

/* 

The pulsed_ostream strict will store object passed to it (other than objects 
of type pulsed_ostream_trait) in a std::stringstream. Once an object of
pulsed_ostream_trait is passed to it, the pulsed_ostream will flush it's 
contents down the std::ostream& it was created with, with or without supplying
a newline.

*/

struct pulsed_ostream
{
	std::stringstream collector;

	/*

	A pulsed_ostream struct is by default linked to std::cout, and will sleep 
	for 50 ms between characters. You can change this by calling the 
	constructor.

	*/

	std::ostream& linked_ostream;

	int delay;

	pulsed_ostream(std::ostream& _linked_ostream = std::cout, int _delay = 50) :

		linked_ostream(_linked_ostream)

	{
		delay = _delay;
	}

	/*

	This template allows any type that can be flushed to a std::stringstream
	to be flushed to a pulsed_ostream. However, flushing objects that have a
	type of pulsed_ostream_trait will invoke behaviour specific to the
	pulsed_ostream_trait that was used.

	*/

	template <typename T>

	pulsed_ostream& operator << (T object)
	{
		collector << object;

		return *this;
	}

	void operator << (pulsed_ostream_trait object)
	{
		std::string collected = collector.str();

		for (int i = 0; i < collected.size(); i++)
		{
			linked_ostream << collected[i] << std::flush;

			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		}

		if (object.traits == 32)
		{
			linked_ostream << std::endl;
		}

		collector.str(std::string());
	}
};

/*

If you don't want to initialize your own pulsed_ostream for std::cout, you can
used the pulsed_cout object.

*/

pulsed_ostream pulsed_cout;

/*

If you don't want to initialize your own pulsed_ostream for std::cerr, you can
used the pulsed_cerr object.

*/

pulsed_ostream pulsed_cerr = pulsed_ostream(std::cerr);