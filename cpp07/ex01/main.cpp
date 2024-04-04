#include "iter.hpp"
#include "Object.hpp"

std::ostream& operator<<(std::ostream& stream, const Object& obj)
{
	stream << "name: " << obj.getName() << " / num: " << obj.getNum();
	return (stream);
}

int main()
{
	{
		std::cout << "Object test\n";
		Object obj1("obj1", 1);
		Object obj2("obj2", 2);
		Object obj3("obj3", 3);
		Object arr[3] = {obj1, obj2, obj3};
		iter(arr, 3, printValue);
	}

	{
		std::cout << "\nconst Object test\n";
		const Object obj1("obj1", 1);
		const Object obj2("obj2", 2);
		const Object obj3("obj3", 3);
		const Object arr[3] = {obj1, obj2, obj3};
		iter(arr, 3, printValue);
	}

	{
		std::cout << "\nint test\n";
		int arr[3] = {0, 1, 2};
		iter(arr, 3, printValue);
	}

	{
		std::cout << "\nconst int test\n";
		const int arr[3] = {0, 1, 2};
		iter(arr, 3, printValue);
	}
}