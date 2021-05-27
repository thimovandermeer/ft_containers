//
// Created by Thimo Van der meer on 25/05/2021.
//

#include "Catch2.h"
#include <vector>
#include "../srcs/vector/vector.hpp"
#include <iostream>


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
		ft::vector<int> myvector(10, 10);
		std::vector<int> sysvector(10,10);

		REQUIRE(myvector.size() == sysvector.size());
		REQUIRE(myvector == sysvector);

		ft::vector<std::string> myvector1(10, "hallo");
		std::vector<std::string> sysvector1(10, "hallo");

		REQUIRE(myvector1 == sysvector1);

		ft::vector<float> myvector2(1000, 1.0000005);
		std::vector<float> sysvector2(1000,1.0000005);

		REQUIRE(myvector2 == sysvector2);
	}

	SECTION("Range")
	{
//		std::vector<int> sysvector(10, 10);
//		ft::vector<int> myvector(10,10);
//
//		std::vector<int>::iterator sysitbegin = sysvector.begin();
//		ft::vector<int>::iterator myitbegin = sysvector.begin();
	}

	SECTION("Copy")
	{
		ft::vector<int> mycopy(10,10);
		std::vector<int> syscopy(10,10);

		ft::vector<int> myvector(mycopy);
		std::vector<int> sysvector(syscopy);

		REQUIRE(myvector == sysvector);

		ft::vector<int> myemptycopy;
		std::vector<int> sysemptycopy;

		ft::vector<int> myvector1(myemptycopy);
		std::vector<int> sysvector1(sysemptycopy);
		REQUIRE(myvector1 == sysvector1);
	}

}

TEST_CASE("Vector: Operator=", "[Vector]")
{
	// create the ones who need to be copied
	ft::vector<int> copyme(10,10);
	std::vector<int>syscopyme(10,10);
	// create empty ones
	ft::vector<int> myvector;
	std::vector<int> sysvector;
	// copy them
	myvector = copyme;
	sysvector = syscopyme;

	REQUIRE(myvector == sysvector);

	ft::vector<int> copyme2(10,10);
	std::vector<int>syscopyme2(10,10);
	// create empty ones
	ft::vector<int> myvector1(10, 100);
	std::vector<int> sysvector1(10, 100);
	// copy them
	myvector1 = copyme2;
	sysvector1 = syscopyme2;

	REQUIRE(myvector1 == sysvector1);
	REQUIRE(copyme2 == syscopyme2);
}


TEST_CASE("Vector: Iterators", "[Vector]")
{
	SECTION("Begin")
	{
		// normal
		ft::vector<int> myvector(10,10);
		std::vector<int> sysvector(10, 10);

		ft::vector<int>::iterator myit = myvector.begin();
		std::vector<int>::iterator sysit = sysvector.begin();

		REQUIRE(*myit == *sysit);
		// const
		ft::vector<std::string> myconstvector(3, "hallo");
		std::vector<std::string> sysconstvector(3, "hallo");

		// cant do const yet because of type_Traits which do not function yet so have to build this later
//		ft::vector<std::string>::const_iterator myconstit = myconstvector.begin();
//		std::vector<std::string>::const_iterator sysconstit = sysconstvector.begin();
//
//		REQUIRE(*myconstit == *sysconstit);

	}

	SECTION("End")
	{
		// normal
		ft::vector<int> myvector(10,10);
		std::vector<int> sysvector(10, 10);

		ft::vector<int>::iterator myit = myvector.end();
		std::vector<int>::iterator sysit = sysvector.end();
		*myit--;
		*sysit--;
		REQUIRE(*myit == *sysit);
		// const
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
		ft::vector<int> myitvec(10,10);
		ft::vector<int> sysitvec(10,10);

		REQUIRE(myitvec.size() == sysitvec.size());

		ft::vector<std::string> mystringvec(5,"Doei");
		ft::vector<std::string> systringvec(5,"Doei");

		REQUIRE(mystringvec.size() == systringvec.size());


	}

	SECTION("Max size")
	{
		std::vector<int> sysvec(10,10);
		ft::vector<int> myvec(10, 10);

		REQUIRE(myvec.max_size() == sysvec.max_size());
	}

	SECTION("Resize")
	{
		// zo afmaken als push_back af is
		ft::vector<int> myvector(10, 10);
		std::vector<int> sysvector(10,10);

		myvector.resize(5,5);
		sysvector.resize(5,5);
		REQUIRE(myvector == sysvector);

		ft::vector<int> myintvec(3, 5);
		std::vector<int> sysintvec(3,5);

		myintvec.resize(10, 10);
		sysintvec.resize(10,10);
		REQUIRE(myintvec == sysintvec);

		ft::vector<std::string> mystringvector(3, "hallo");
		std::vector<std::string> sysstringvector(3, "hallo");

		mystringvector.resize(10, "doei");
		sysstringvector.resize(10, "doei");

		REQUIRE(mystringvector == sysstringvector);

		ft::vector<float> myfloatvector(1000000, 10.00000);
		std::vector<float> sysfloatvector(1000000, 10.00000);

		myfloatvector.resize(10);
		sysfloatvector.resize(10);
		REQUIRE(myfloatvector == sysfloatvector);

	}

	SECTION("Capacity")
	{
		ft::vector<int> myintvec(10, 5);
		std::vector<int> sysintvec(10,5);

		myintvec.push_back(10);
		sysintvec.push_back(10);

		REQUIRE(myintvec == sysintvec);

		ft::vector<std::string> mystringvec(3, "hallo");
		std::vector<std::string> sysstringvec(3, "hallo");

		mystringvec.push_back("Bonjour");
		sysstringvec.push_back("Bonjour");

		REQUIRE(mystringvec == sysstringvec);

		mystringvec.pop_back();
		sysstringvec.pop_back();

		REQUIRE(mystringvec == sysstringvec);

		ft::vector<float> myfloatvec(5, 5.0001);
		std::vector<float> sysfloatvec(5, 5.0001);

		REQUIRE(myfloatvec == sysfloatvec);

		myfloatvec.pop_back();
		sysfloatvec.pop_back();

		REQUIRE(myfloatvec == sysfloatvec);

	}

	SECTION("Empty")
	{
		ft::vector<int> myintvec;
		std::vector<int> sysintvec;

		REQUIRE(myintvec.empty() == sysintvec.empty());

		myintvec.push_back(10);
		sysintvec.push_back(10);
		REQUIRE(myintvec.empty() == sysintvec.empty());

		myintvec.pop_back();
		sysintvec.pop_back();
		REQUIRE(myintvec.empty() == sysintvec.empty());

	}

	SECTION("Reserve")
	{
		ft::vector<int> myintvec(10,10);
		std::vector<int> sysintvec(10,10);

		myintvec.reserve(15);
		sysintvec.reserve(15);

		REQUIRE(myintvec == sysintvec);

		ft::vector<std::string> mystringvec(3,"hallo");
		std::vector<std::string> sysstringvec(3, "hallo");

		mystringvec.reserve(15);
		sysstringvec.reserve(15);

		REQUIRE(mystringvec == sysstringvec);
	}

}

TEST_CASE("Vector: Element Access", "[Vector]")
{
	SECTION("Operator[]")
	{
		ft::vector<int> myvec;
		myvec.push_back(10);
		myvec.push_back(9);
		myvec.push_back(8);
		myvec.push_back(7);
		myvec.push_back(6);
		myvec.push_back(5);
		myvec.push_back(4);
		myvec.push_back(3);
		myvec.push_back(2);
		myvec.push_back(1);
		myvec.push_back(0);

		std::vector<int> sysvec;
		sysvec.push_back(10);
		sysvec.push_back(9);
		sysvec.push_back(8);
		sysvec.push_back(7);
		sysvec.push_back(6);
		sysvec.push_back(5);
		sysvec.push_back(4);
		sysvec.push_back(3);
		sysvec.push_back(2);
		sysvec.push_back(1);
		sysvec.push_back(0);

		REQUIRE(myvec[5] == sysvec[5]);
	}

	SECTION("at")
	{
		ft::vector<int> myvec;
		myvec.push_back(10);
		myvec.push_back(9);
		myvec.push_back(8);
		myvec.push_back(7);
		myvec.push_back(6);
		myvec.push_back(5);
		myvec.push_back(4);
		myvec.push_back(3);
		myvec.push_back(2);
		myvec.push_back(1);
		myvec.push_back(0);

		std::vector<int> sysvec;
		sysvec.push_back(10);
		sysvec.push_back(9);
		sysvec.push_back(8);
		sysvec.push_back(7);
		sysvec.push_back(6);
		sysvec.push_back(5);
		sysvec.push_back(4);
		sysvec.push_back(3);
		sysvec.push_back(2);
		sysvec.push_back(1);
		sysvec.push_back(0);

		try
		{
			std::cout << myvec.at(-1) << std::endl;
//			std::cout << sysvec.at(-1) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		REQUIRE(myvec.at(5) == sysvec.at(5));
	}

	SECTION("Front")
	{
		ft::vector<int> myvec;
		std::vector<int> sysvec;
		myvec.push_back(10);
		myvec.push_back(5);

		sysvec.push_back(10);
		sysvec.push_back(5);

		REQUIRE(myvec.front() == sysvec.front());

	}

	SECTION("Back")
	{
		ft::vector<int> myvec;
		std::vector<int> sysvec;
		myvec.push_back(10);
		myvec.push_back(5);

		sysvec.push_back(10);
		sysvec.push_back(5);

		REQUIRE(myvec.back() == sysvec.back());
	}

}

TEST_CASE("Vector: Modifiers", "[Vector]")
{
	SECTION("Assign")
	{

	}

	SECTION("Push_back")
	{
		ft::vector<int> myvec;
		std::vector<int> sysvec;

		myvec.push_back(10);
		myvec.push_back(5);
		myvec.push_back(4);
		myvec.push_back(3);

		sysvec.push_back(10);
		sysvec.push_back(5);
		sysvec.push_back(4);
		sysvec.push_back(3);

		REQUIRE(myvec == sysvec);

	}

	SECTION("Pop_back")
	{
		ft::vector<int> myvec(5, 10);
		std::vector<int> sysvec(5, 10);

		myvec.pop_back();
		sysvec.pop_back();
		REQUIRE(myvec == sysvec);

		myvec.pop_back();
		sysvec.pop_back();
		REQUIRE(myvec == sysvec);

		myvec.pop_back();
		sysvec.pop_back();
		REQUIRE(myvec == sysvec);

		myvec.pop_back();
		sysvec.pop_back();
		REQUIRE(myvec == sysvec);

		myvec.pop_back();
		sysvec.pop_back();
		REQUIRE(myvec == sysvec);
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
