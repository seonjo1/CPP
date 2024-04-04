#include "whatever.hpp"
#include "Object.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Object& obj)
{
	stream << "name: " << obj.getName() << " / num: " << obj.getNum();
	return (stream);
}

int main( void ) {

	{
		std::cout << "subject test\n";
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	{
		std::cout << "\nseonjo test\n";
		std::cout << "min, max test\n";
		Object obj1("obj1", 1);
		Object obj2("obj2", 2);
		std::cout << "min : " << min(obj1, obj2) << std::endl;
		std::cout << "max : " << max(obj1, obj2) << std::endl;

		std::cout << "\nswap test\n";
		swap(obj1, obj2);
		std::cout << "obj1 " << obj1 << std::endl;
		std::cout << "obj2 " << obj2 << std::endl;
		swap(obj1, obj2);

		std::cout << "\nconst min, max test\n";
		const Object obj3("obj3", 3);
		const Object obj4("obj4", 4);
		std::cout << "min : " << min(obj3, obj4) << std::endl;
		std::cout << "max : " << max(obj3, obj4) << std::endl;

		std::cout << "\nconst mix min, max test\n";
		std::cout << "min : " << min(obj1, obj4) << std::endl;
		std::cout << "max : " << max(obj1, obj4) << std::endl;
	}	

	return 0;
}
