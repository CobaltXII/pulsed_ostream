#include "pulsed_ostream.hpp"

int main(int argc, char** argv)
{
	pulsed_cout << "Hello, world!" << pulsed_endl;

	pulsed_cout << "Did you know, that I can print integers too?" << pulsed_endl;

	for (int i = 0; i < 50; i++)
	{
		pulsed_cout << i << ", ";
	}

	pulsed_cout << 50 << "." << pulsed_endl;

	pulsed_cout << "Am I going too fast for you? Here, I'll go slower." << pulsed_endl;

	pulsed_ostream slow_pulsed_cout = pulsed_ostream(std::cout, 100);

	slow_pulsed_cout << "How's this? Too slow?" << pulsed_endl;

	pulsed_ostream fast_pulsed_cout = pulsed_ostream(std::cout, 10);

	fast_pulsed_cout << "Alright, I can go faster!" << pulsed_endl;

	pulsed_cout << "Thanks for listening!" << pulsed_endl;

	return 0;
}