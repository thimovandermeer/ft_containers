//
// Created by Thimo Van der meer on 25/05/2021.
//

#include "Catch2.h"
#include <vector>
#include "../srcs/vector/vector.hpp"


namespace ft {

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> &mine,
					const std::vector<T, Alloc> &real)
	{
		if (mine.capacity() != real.capacity())
			return (false);
		if (mine.size() != real.size())
			return (false);
		if (mine.get_allocator() != real.get_allocator())
			return (false);
		auto myit = mine.begin();
		auto realit = real.begin();
		for (size_t i = 0; i < mine.size(); i++, myit++, realit++)
		{
			if (*myit != *realit)
				return (false);
		}
		return (true);
	}

	template<class T, class Alloc>
	bool operator==(const std::vector<T, Alloc> &real,
					const ft::vector<T, Alloc> &mine)
	{ return (mine == real); }

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &mine,
					const std::vector<T, Alloc> &real)
	{ return !(mine == real); }

	template<class T, class Alloc>
	bool operator!=(const std::vector<T, Alloc> &real,
					const ft::vector<T, Alloc> &mine)
	{ return !(mine == real); }
}

TEST_CASE("Vector: Constructors", "[Vector]")
{
	SECTION("Default")
	{
		ft::vector<int> myvector;
		std::vector<int> sysvector;


		REQUIRE(myvector.size() == sysvector.size());
		REQUIRE(myvector == sysvector);
	}

	SECTION("Fill")
	{

	}

	SECTION("Range")
	{

	}

	SECTION("Copy")
	{

	}

}

TEST_CASE("Destructor")
{

}

TEST_CASE("Operator=")
{

}


TEST_CASE("Vector: Iterators", "[Vector]")
{
	SECTION("Begin")
	{

	}

	SECTION("End")
	{

	}

	SECTION("Rbegin")
	{

	}

	SECTION("Rend")
	{

	}
}

TEST_CASE("Vector: Capacity", "[Vector]")
{
	SECTION("Size")
	{

	}

	SECTION("Max size")
	{

	}

	SECTION("Resize")
	{

	}

	SECTION("Capacity")
	{

	}

	SECTION("Empty")
	{

	}

	SECTION("Reserve")
	{

	}

}

TEST_CASE("Vector: Element acces")
{
	SECTION("Operator[]")
	{

	}

	SECTION("at")
	{

	}

	SECTION("Front")
	{

	}

	SECTION("Back")
	{

	}

}

TEST_CASE("Vector: Modifiers")
{
	SECTION("Assign")
	{

	}

	SECTION("Push_back")
	{

	}

	SECTION("Pop_back")
	{

	}

	SECTION("Insert single element")
	{

	}

	SECTION("Insert fill")
	{

	}

	SECTION("Insert range")
	{

	}

	SECTION("Erase")
	{

	}

	SECTION("Swap")
	{

	}

	SECTION("Clear")
	{

	}
}

TEST_CASE("Vector: Allocators")
{

}

TEST_CASE("Vector: Non member overloads")
{

}
