#include <iostream>
#include <Array.hpp>

// #include <cstdlib>
// void leaks_check()
// {
// 	system("leaks _ex02");
// }

#define MAX_VAL 750
int main(int, char**)
{
	{
		std::cout << "subject test\n";
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}

	{
		std::cout << "\nseonjo test\n";
		std::cout << "constructor test\n";
		Array<int> arrNull;
		Array<int> arrZero(0);
		try
		{
			arrNull[0] = 1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			arrZero[0] = 1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\nbasic test\n";

		Array<int> arr(5);

		for (int i = 0; i < arr.size(); i++)
			arr[i] = i;

		std::cout << arr[0] << std::endl;
		std::cout << arr[1] << std::endl;
		std::cout << arr[2] << std::endl;
		std::cout << arr[3] << std::endl;
		std::cout << arr[4] << std::endl;

		std::cout << "\ncopy constructor test\n";

		Array<int> copy(arr);

		std::cout << copy[0] << std::endl;
		std::cout << copy[1] << std::endl;
		std::cout << copy[2] << std::endl;
		std::cout << copy[3] << std::endl;
		std::cout << copy[4] << std::endl;

		std::cout << "\ncopy assignment operator test\n";

		Array<int> copyOp;
		copyOp = copy;

		Array<int>& copyRef = copyOp;
		copyOp = copyRef;

		std::cout << copyRef[0] << std::endl;
		std::cout << copyRef[1] << std::endl;
		std::cout << copyRef[2] << std::endl;
		std::cout << copyRef[3] << std::endl;
		std::cout << copyRef[4] << std::endl;


		std::cout << "\nconst test\n";

		const Array<int> arrConst(5);

		std::cout << arrConst[0] << std::endl;
		std::cout << arrConst[1] << std::endl;
		std::cout << arrConst[2] << std::endl;
		std::cout << arrConst[3] << std::endl;
		std::cout << arrConst[4] << std::endl;
	}

	// atexit(leaks_check);
	return 0;
}
