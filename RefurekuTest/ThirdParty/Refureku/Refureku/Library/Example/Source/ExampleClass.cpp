#include "ExampleClass.h"

#include <iostream>
#include <cstdint>

using namespace namespace1;
using namespace namespace2;
using namespace namespace3;

void ExampleClass::method1() const noexcept
{
	std::cout << "ExampleClass::method1() override:" << std::endl;
}

void ExampleClass::method2() const
{
	std::cout << "ExampleClass::method2() const" << std::endl;
}

int ExampleClass::method3()
{
	std::cout << "ExampleClass::method3(): " << 42 << std::endl;

	return 42;
}

float ExampleClass::method3(int i) noexcept
{
	std::cout << "ExampleClass::method3(): " << i << std::endl;

	return 3.14f;
}

float ExampleClass::methodWithDefaultArgs(int i, float f, char const* s) 
{
	std::cout << "i = " << i << ", f = " << f << ", s = " << s << std::endl;

	return f;
}

unsigned long long ExampleClass::method4(void* ptr)
{
	std::cout << "ExampleClass::method4(void* ptr): " << ptr << std::endl;

	return static_cast<unsigned long long>(reinterpret_cast<std::uintptr_t>(ptr));
}

void ExampleClass::staticMethod1()
{
	std::cout << "ExampleClass::staticMethod1()" << std::endl;
}

int ExampleClass::staticMethod2()
{
	std::cout << "ExampleClass::staticMethod2()" << std::endl;

	return 2;
}

int ExampleClass::staticMethod3(char const* param)
{
	std::cout << "ExampleClass::staticMethod3(" << param << ")" << std::endl;

	return 3;
}

int ExampleClass::staticMethod3(int p1, int p2) noexcept
{
	return p1 + p2;
}

std::ostream& namespace3::operator<<(std::ostream& stream, ParentClass const& object) noexcept
{
	stream << object.pInt64;

	return stream;
}