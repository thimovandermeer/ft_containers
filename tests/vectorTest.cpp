//
// Created by Thimo Van der meer on 25/05/2021.
//

#include "catch.hpp"
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
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints,myints +sizeof(myints) / sizeof(int));
		int sysints[] = {16,2,77,29};
		std::vector<int> sixth (sysints, sysints + sizeof(sysints) / sizeof(int));

		REQUIRE(fifth == sixth);
	
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
		ft::vector<std::string>::const_iterator myconstit = myconstvector.begin();
		std::vector<std::string>::const_iterator sysconstit = sysconstvector.begin();

		REQUIRE(*myconstit == *sysconstit);

	}

	SECTION("End")
	{
		ft::vector<int> myvector(10,10);
		std::vector<int> sysvector(10, 10);

		ft::vector<int>::iterator myit = myvector.end();
		std::vector<int>::iterator sysit = sysvector.end();
		*myit--;
		*sysit--;
		REQUIRE(*myit == *sysit);
	}

	SECTION("Rbegin")
	{
		ft::vector<int>myvec1(10,15);
		std::vector<int>sysvec1(10,15);

		ft::vector<int>::reverse_iterator myit1 = myvec1.rbegin();
		std::vector<int>::reverse_iterator sysit1 = sysvec1.rbegin();

		REQUIRE(*myit1 == *sysit1);
		*myit1++;
		*sysit1++;
		REQUIRE(*myit1 == *sysit1);
		*myit1++;
		*sysit1++;
		REQUIRE(*myit1 == *sysit1);
		*myit1++;
		*sysit1++;
		REQUIRE(*myit1 == *sysit1);
	}

	SECTION("Const_Rbegin")
	{
		ft::vector<int>myvec1(10,15);
		std::vector<int>sysvec1(10,15);

		ft::vector<int>::const_reverse_iterator myit1 = myvec1.rbegin();
		std::vector<int>::const_reverse_iterator sysit1 = sysvec1.rbegin();

		REQUIRE(*myit1 == *sysit1);
		*myit1++;
		*sysit1++;
		REQUIRE(*myit1 == *sysit1);
		*myit1++;
		*sysit1++;
		REQUIRE(*myit1 == *sysit1);
		*myit1++;
		*sysit1++;
		REQUIRE(*myit1 == *sysit1);

		ft::vector<int>myvec(10,15);
		std::vector<int>sysvec(10,15);

		ft::vector<int>::reverse_iterator myIT = myvec.rbegin();
		std::vector<int>::reverse_iterator sysit = sysvec.rbegin();

		REQUIRE(*myIT == *sysit);
		*myIT++;
		*sysit++;
		REQUIRE(*myIT == *sysit);
		*myIT++;
		*sysit++;
		REQUIRE(*myIT == *sysit);
		*myIT++;
		*sysit++;
		REQUIRE(*myIT == *sysit);
	}

	SECTION("Rend")
	{
		ft::vector<int> myvec(10,10);
		std::vector<int> sysvec(10,10);

		ft::vector<int>::reverse_iterator myit = myvec.rend();
		std::vector<int>::reverse_iterator sysit = sysvec.rend();

		*myit--;
		*sysit--;
		REQUIRE(*myit == *sysit);
		*myit--;
		*sysit--;
		REQUIRE(*myit == *sysit);
		*myit--;
		*sysit--;
		REQUIRE(*myit == *sysit);

	}

	SECTION("const_Rend")
	{
		ft::vector<int> myvec(10,10);
		std::vector<int> sysvec(10,10);

		ft::vector<int>::const_reverse_iterator myit = myvec.rend();
		std::vector<int>::const_reverse_iterator sysit = sysvec.rend();

		*myit--;
		*sysit--;
		REQUIRE(*myit == *sysit);
		*myit--;
		*sysit--;
		REQUIRE(*myit == *sysit);
		*myit--;
		*sysit--;
		REQUIRE(*myit == *sysit);

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
		std::cout << "my int vec\n";
		std::cout << "---------------" << std::endl;
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

		ft::vector<std::string>mystrvec;
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		mystrvec.push_back("hallo");
		std::vector<std::string> sysstrvec;
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");
		sysstrvec.push_back("hallo");

		REQUIRE(mystrvec == sysstrvec);
		std::vector<int>::iterator sysstart = sysvec.begin();
		std::vector<int>::iterator sysend = sysvec.end();
		*sysend--;
		ft::vector<int>::iterator itstart = myvec.begin();
		ft::vector<int>::iterator itend = myvec.end();
		*itend--;
		REQUIRE(*sysstart == *itstart);
		REQUIRE(*sysend == *itend);

		ft::vector<int> newvec;
		std::vector<int> sysnewvec;

		newvec.assign(itstart, itend);
		sysnewvec.assign(sysstart, sysend);
		REQUIRE(myvec == sysvec);


		ft::vector<std::string> myfillvec;
		std::vector<std::string> sysfillvec;

		myfillvec.assign(10, "hallo");
		sysfillvec.assign(10, "hallo");
		REQUIRE(myfillvec == sysfillvec);

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

		ft::vector<int> myvec;
		std::vector<int> sysvec;

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

		ft::vector<int>::iterator myit1 = myvec.begin();
		std::vector<int>::iterator sysit1 = sysvec.begin();

		*myit1++;
		*myit1++;
		*sysit1++;
		*sysit1++;
		myvec.insert(myit1, 15);
		sysvec.insert(sysit1, 15);
		REQUIRE(myvec == sysvec);
	}

	SECTION("Insert fill")
	{
		// insert in empty
		ft::vector<int> myvec;
		std::vector<int> sysvec;
		ft::vector<int>::iterator myit = myvec.begin();
		std::vector<int>::iterator sysit = sysvec.begin();

		myvec.insert(myit, 10,10);
		sysvec.insert(sysit, 10, 10);

		REQUIRE(myvec == sysvec);

		// insert in full
		ft::vector<int> myvec1(10,10);
		std::vector<int> sysvec1(10,10);
		ft::vector<int>::iterator myit1 = myvec1.end();
		std::vector<int>::iterator sysit1 = sysvec1.end();

		*myit1--;
		*myit1--;
		*sysit1--;
		*sysit1--;

		myvec1.insert(myit1, 100,10);
		sysvec1.insert(sysit1, 100,10);

		REQUIRE(myvec1 == sysvec1);
	}

	SECTION("Insert range")
	{
		// filling an empty vector
		ft::vector<int>myvec(10,15);
		ft::vector<int>::iterator myitbegin = myvec.begin();
		ft::vector<int>::iterator myitend = myvec.end();
		ft::vector<int>myvectofill(1,10);
		ft::vector<int>::iterator mypositiontofil = myvectofill.begin();

		std::vector<int>sysvec(10,15);
		std::vector<int>::iterator sysitbegin = sysvec.begin();
		std::vector<int>::iterator sysitend = sysvec.end();
		std::vector<int>sysvectofill(1, 10);
		std::vector<int>::iterator syspositiontofill = sysvectofill.begin();

		myvectofill.insert(mypositiontofil, myitbegin, myitend);
		sysvectofill.insert(syspositiontofill, sysitbegin, sysitend);

		REQUIRE(myvectofill == sysvectofill);

	}

	SECTION("Erase one")
	{
		ft::vector<int> myvec(10,10);
		std::vector<int> sysvec(10,10);
		ft::vector<int>::iterator myit = myvec.begin();
		std::vector<int>::iterator sysit = sysvec.begin();

		myvec.erase(myit);
		sysvec.erase(sysit);

		REQUIRE(myvec == sysvec);
	}

	SECTION("Erase range")
	{
		ft::vector<int> myvec(15, 15);
		std::vector<int> sysvec(15,15);
		ft::vector<int>::iterator myitbegin = myvec.begin();
		ft::vector<int>::iterator myitend = myvec.end();

		std::vector<int>::iterator sysitbegin = sysvec.begin();
		std::vector<int>::iterator sysitend = sysvec.end();

		*myitbegin++;
		*myitbegin++;

		*myitend--;
		*myitend--;

		*sysitbegin++;
		*sysitbegin++;

		*sysitend--;
		*sysitend--;

		myvec.erase(myitbegin, myitend);
		sysvec.erase(sysitbegin, sysitend);
		REQUIRE(myvec == sysvec);
	}


	SECTION("Swap")
	{
		ft::vector<int>myvec(10,10);
		ft::vector<int>myvec1(15,15);

		std::vector<int>sysvec(10,10);
		std::vector<int>sysvec1(15,15);

		myvec.swap(myvec1);
		sysvec.swap(sysvec1);

		REQUIRE(myvec == sysvec);
	}

	SECTION("Clear")
	{
		ft::vector<std::string> myvec(3, "hallo");
		std::vector<std::string> sysvec(3, "hallo");
		myvec.clear();
		sysvec.clear();
		REQUIRE(myvec == sysvec);
	}
}

TEST_CASE("Vector: Non member overloads")
{
	ft::vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	ft::vector<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	ft::vector<int> c;
	c.push_back(30);
	c.push_back(20);
	c.push_back(10);

	REQUIRE((a == b) == true);
	REQUIRE((b != c) == true);
	REQUIRE((b < c) == true);
	REQUIRE((c > b) == true);
	REQUIRE((a <= b) == true);
	REQUIRE((a >= b) == true);
	REQUIRE((a <= b) == true);
	REQUIRE((a > b) == false);
	REQUIRE((a < b) == false);
	REQUIRE((a != b) == false);
	REQUIRE((b > c) == false);
	REQUIRE((b == c) == false);
	REQUIRE((b != c) == true);
}
