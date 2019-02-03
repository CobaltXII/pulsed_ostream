# pulsed_ostream

Say you are writing a text-based game. Or anything that uses the console as output, and wants to print text with a delay between each character. Sure, you could just do this

```c++
#include <iostream>
#include <thread>
#include <chrono>

void print_slow(std::string output, int ms)
{
	for (int i = 0; i < output.size(); i++)
	{
		std::cout << output[i] << std::flush;

		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	print_slow("Why am I using such terrible code?", 50);
}
```

It sucks, but it works. But wouldn't it be so much nicer to just be able to do this?

```c++
#include "pulsed_ostream.hpp"

int main(int argc, char** argv)
{
	pulsed_cout << "Yes! Now this is what I'm looking for!" << pulsed_endl;
}
```

Well, with this repository you can. And more. You can print anything to a `pulsed_ostream` that you can print to a `std::stringstream`.

# Demonstration

Just read this to see what you can do.

```c++
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
```

# License

pulsed_ostream is licensed under the WTFPL.