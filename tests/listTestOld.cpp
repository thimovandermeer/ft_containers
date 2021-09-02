//
// Created by Thimo Van der meer on 02/09/2021.
//

//
// Created by Thimo Van der meer on 06/05/2021.
//

#include "catch.hpp"
#include "../srcs/list/list.hpp"
#include <list>
#include <iostream>
namespace ft
{
	template<class T, class Alloc>
	bool operator==(const ft::list<T, Alloc> &mine,
					const std::list<T, Alloc> &real)
	{
		if (mine.size() != real.size())
			return (false);
		if (mine.get_allocator() != real.get_allocator())
			return (false);
		auto myit = mine.begin();
		auto realit = real.begin();
		for (size_t i = 0; i < mine.size(); ++i, ++myit, ++realit)
		{
			if (*myit != *realit)
				return (false);
		}
		return (true);
	}

	template<class T, class Alloc>
	bool operator==(const std::list<T, Alloc> &real,
					const ft::list<T, Alloc> &mine)
	{ return (mine == real); }

	template<class T, class Alloc>
	bool operator!=(const ft::list<T, Alloc> &mine,
					const std::list<T, Alloc> &real)
	{ return !(mine == real); }

	template<class T, class Alloc>
	bool operator!=(const std::list<T, Alloc> &real,
					const ft::list<T, Alloc> &mine)
	{ return !(mine == real); }
}
TEST_CASE("List: Constructors", "[List]")
{
	ft::list<std::string> myList;
	std::list<std::string> sysList;


	SECTION("Size check for constructor")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);
		REQUIRE(myList1.size() == sysList1.size());
	}
//	SECTION("Extra checks")
//	{
//		std::list<int> real1;
//		ft::list<int> mine1;
//		REQUIRE(mine1 == real1);
//		std::list<int> real2(4, 100);
//		ft::list<int> mine2(4, 100);
//		REQUIRE(mine2 == real2);
//
//		std::list<int> real3(real2.begin(), real2.end());
//		ft::list<int> mine3(mine2.begin(), mine2.end());
//
//		std::list<int> real4(real3);
//		ft::list<int> mine4(mine3);
//
//		int intarr[] = {16, 2, 77, 29};
//		std::list<int> real5(intarr, intarr + sizeof(intarr) / sizeof(int));
//		ft::list<int> mine5(intarr, intarr + sizeof(intarr) / sizeof(int));
//		REQUIRE(mine5 == real5);
//	}

//	SECTION("copy constructor")
//	{
//		ft::list<int>		own(6, 100);
//		ft::list<int>		own2(own);
//		std::list<int>		real(6, 100);
//		std::list<int>		real2(real);
//
//
//		REQUIRE(own2.size() == real2.size());
//		REQUIRE(own2.empty() == real2.empty());
//		REQUIRE(own2.front() == real2.front());
//		REQUIRE(own2.back() == real2.back());
//	}
}


TEST_CASE("List: Iterators", "[List]")
{
	SECTION("INCREMENT over int")
	{
		ft::list<int> myList;
		std::list<int> sysList;

		myList.push_back(10);
		myList.push_back(5);
		myList.push_back(15);
		myList.push_back(20);
		myList.push_back(25);
		myList.push_back(30);
		myList.push_back(35);


		sysList.push_back(10);
		sysList.push_back(5);
		sysList.push_back(15);
		sysList.push_back(20);
		sysList.push_back(25);
		sysList.push_back(30);
		sysList.push_back(35);

		ft::list<int>::iterator myIT = myList.begin();
		std::list<int>::iterator sysIT = sysList.begin();
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
		++myIT;
		++sysIT;
		REQUIRE(*myIT == *sysIT);
		++myIT;
		++sysIT;
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("INCREMENT over std::string")
	{
		ft::list<std::string> myList;
		std::list<std::string> sysList;

		myList.push_back("Hallo");
		myList.push_back("Ik");
		myList.push_back("Ben");
		myList.push_back("Een");
		myList.push_back("Baassie");
		myList.push_back("Geweldig");
		myList.push_back("Iterators");


		sysList.push_back("Hallo");
		sysList.push_back("Ik");
		sysList.push_back("Ben");
		sysList.push_back("Een");
		sysList.push_back("Baassie");
		sysList.push_back("Geweldig");
		sysList.push_back("Iterators");

		ft::list<std::string>::iterator myIT = myList.begin();
		std::list<std::string>::iterator sysIT = sysList.begin();
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
		++myIT;
		++sysIT;
		REQUIRE(*myIT == *sysIT);
		++myIT;
		++sysIT;
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("DECREMENT over int")
	{
		ft::list<int> myList;
		std::list<int> sysList;

		myList.push_back(10);
		myList.push_back(5);
		myList.push_back(15);
		myList.push_back(20);
		myList.push_back(25);
		myList.push_back(30);
		myList.push_back(35);


		sysList.push_back(10);
		sysList.push_back(5);
		sysList.push_back(15);
		sysList.push_back(20);
		sysList.push_back(25);
		sysList.push_back(30);
		sysList.push_back(35);

		ft::list<int>::iterator myIT = myList.end();
		std::list<int>::iterator sysIT = sysList.end();
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
		--myIT;
		--sysIT;
		REQUIRE(*myIT == *sysIT);
		--myIT;
		--sysIT;
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("DECREMENT over std::string")
	{
		ft::list<std::string> myList;
		std::list<std::string> sysList;

		myList.push_back("Hallo");
		myList.push_back("Ik");
		myList.push_back("Ben");
		myList.push_back("Een");
		myList.push_back("Baassie");
		myList.push_back("Geweldig");
		myList.push_back("Iterators");


		sysList.push_back("Hallo");
		sysList.push_back("Ik");
		sysList.push_back("Ben");
		sysList.push_back("Een");
		sysList.push_back("Baassie");
		sysList.push_back("Geweldig");
		sysList.push_back("Iterators");

		ft::list<std::string>::iterator myIT = myList.end();
		std::list<std::string>::iterator sysIT = sysList.end();
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
		--myIT;
		--sysIT;
		REQUIRE(*myIT == *sysIT);
		--myIT;
		--sysIT;
		REQUIRE(*myIT == *sysIT);
	}

	ft::list<std::string>mylist;
	std::list<std::string>syslist;

	mylist.push_back("iterators");
	mylist.push_back("Zijn");
	mylist.push_back("EPIC");


	syslist.push_back("iterators");
	syslist.push_back("Zijn");
	syslist.push_back("EPIC");
	ft::list<std::string>::iterator myIT = mylist.begin();
	std::list<std::string>::iterator sysIT = syslist.begin();
	SECTION("-> overload")
	{
		myIT++;
		sysIT++;
		REQUIRE(*myIT->data() == *sysIT->data());
	}

	SECTION("* overload")
	{
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("== overload")
	{
		bool res;
		res = myIT == mylist.begin();
		REQUIRE(res == true);
		myIT++;
		res = myIT == mylist.begin();
		REQUIRE(res == false);
	}

	SECTION("!= overload")
	{
		bool res;
		res = myIT != mylist.begin();
		REQUIRE(res == false);
		myIT++;
		res = myIT != mylist.begin();
		REQUIRE(res == true);
	}

	SECTION("Test (*it)++")
	{
		ft::list<int> myIntList;
		std::list<int> sysIntList;

		myIntList.push_back(1);
		sysIntList.push_back(1);

		ft::list<int>::iterator myIntIt = myIntList.begin();
		std::list<int>::iterator sysIntIt = sysIntList.begin();
		(*myIntIt)++;
		(*sysIntIt)++;
		REQUIRE((*myIntIt) == (*sysIntIt));
		(*myIntIt)--;
		REQUIRE(*myIntIt == 1);
		(*myIntIt)++;
		REQUIRE(*myIntIt == 2);
		*myIntIt++;
		bool res = (myIntIt == myIntList.end());
		REQUIRE(res == true);

	}

	SECTION("Test (*it)--") {
		ft::list<int> myIntList;
		std::list<int> sysIntList;

		myIntList.push_back(2);
		sysIntList.push_back(2);
		std::list<int>::iterator sysIntIt = sysIntList.begin();
		ft::list<int>::iterator myIntIt = myIntList.begin();
		(*myIntIt)--;
		(*sysIntIt)--;
		REQUIRE((*myIntIt) == (*sysIntIt));
		(*myIntIt)++;
		REQUIRE(*myIntIt == 2);
		(*myIntIt)--;
		REQUIRE(*myIntIt == 1);
		*myIntIt--;
		bool res = (myIntIt != myIntList.begin());
		REQUIRE(res == true);
	}

	SECTION("Test assignment with iterator")
	{
		ft::list<int> myIntList;
		std::list<int> sysIntList;

		myIntList.push_back(1);
		myIntList.push_back(8);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		REQUIRE(*myIntIt == 1);
		*myIntIt = 5;
		REQUIRE(*myIntIt == 5);
	}

	SECTION("TEST dereference as lvalue" )
	{
		ft::list<int> myIntList;
		std::list<int> sysIntList;
		myIntList.push_back(1);
		myIntList.push_back(8);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		*myIntIt++ = 5;
		REQUIRE(*myIntIt == 8);
		myIntIt--;
		REQUIRE(*myIntIt == 5);
	}

}

TEST_CASE("List: CONST Iterators", "[List]")
{

	SECTION("INCREMENT over int")
	{
		ft::list<int> myList;
		std::list<int> sysList;

		myList.push_back(10);
		myList.push_back(5);
		myList.push_back(15);
		myList.push_back(20);
		myList.push_back(25);
		myList.push_back(30);
		myList.push_back(35);


		sysList.push_back(10);
		sysList.push_back(5);
		sysList.push_back(15);
		sysList.push_back(20);
		sysList.push_back(25);
		sysList.push_back(30);
		sysList.push_back(35);

		ft::list<int>::const_iterator myIT = myList.begin();
		std::list<int>::const_iterator sysIT = sysList.begin();
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
		++myIT;
		++sysIT;
		REQUIRE(*myIT == *sysIT);
		++myIT;
		++sysIT;
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("INCREMENT over std::string")
	{
		ft::list<std::string> myList;
		std::list<std::string> sysList;

		myList.push_back("Hallo");
		myList.push_back("Ik");
		myList.push_back("Ben");
		myList.push_back("Een");
		myList.push_back("Baassie");
		myList.push_back("Geweldig");
		myList.push_back("Iterators");


		sysList.push_back("Hallo");
		sysList.push_back("Ik");
		sysList.push_back("Ben");
		sysList.push_back("Een");
		sysList.push_back("Baassie");
		sysList.push_back("Geweldig");
		sysList.push_back("Iterators");

		ft::list<std::string>::const_iterator myIT = myList.begin();
		std::list<std::string>::const_iterator sysIT = sysList.begin();
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
		++myIT;
		++sysIT;
		REQUIRE(*myIT == *sysIT);
		++myIT;
		++sysIT;
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("DECREMENT over int")
	{
		ft::list<int> myList;
		std::list<int> sysList;

		myList.push_back(10);
		myList.push_back(5);
		myList.push_back(15);
		myList.push_back(20);
		myList.push_back(25);
		myList.push_back(30);
		myList.push_back(35);


		sysList.push_back(10);
		sysList.push_back(5);
		sysList.push_back(15);
		sysList.push_back(20);
		sysList.push_back(25);
		sysList.push_back(30);
		sysList.push_back(35);

		ft::list<int>::const_iterator myIT = myList.end();
		std::list<int>::const_iterator sysIT = sysList.end();
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
		--myIT;
		--sysIT;
		REQUIRE(*myIT == *sysIT);
		--myIT;
		--sysIT;
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("DECREMENT over std::string")
	{
		ft::list<std::string> myList;
		std::list<std::string> sysList;

		myList.push_back("Hallo");
		myList.push_back("Ik");
		myList.push_back("Ben");
		myList.push_back("Een");
		myList.push_back("Baassie");
		myList.push_back("Geweldig");
		myList.push_back("Iterators");


		sysList.push_back("Hallo");
		sysList.push_back("Ik");
		sysList.push_back("Ben");
		sysList.push_back("Een");
		sysList.push_back("Baassie");
		sysList.push_back("Geweldig");
		sysList.push_back("Iterators");

		ft::list<std::string>::const_iterator myIT = myList.end();
		std::list<std::string>::const_iterator sysIT = sysList.end();
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
		--myIT;
		--sysIT;
		REQUIRE(*myIT == *sysIT);
		--myIT;
		--sysIT;
		REQUIRE(*myIT == *sysIT);
	}

	ft::list<std::string> mylist;
	std::list<std::string> syslist;

	mylist.push_back("iterators");
	mylist.push_back("Zijn");
	mylist.push_back("EPIC");


	syslist.push_back("iterators");
	syslist.push_back("Zijn");
	syslist.push_back("EPIC");
	ft::list<std::string>::const_iterator myIT = mylist.begin();
	std::list<std::string>::const_iterator sysIT = syslist.begin();

	SECTION("Begin")
	{
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("END")
	{
		ft::list<std::string> mylist;
		std::list<std::string> syslist;

		mylist.push_back("iterators");
		mylist.push_back("Zijn");
		mylist.push_back("EPIC");


		syslist.push_back("iterators");
		syslist.push_back("Zijn");
		syslist.push_back("EPIC");
		ft::list<std::string>::const_iterator myIT = mylist.end();
		std::list<std::string>::const_iterator sysIT = syslist.end();
		myIT--;
		sysIT--;
		REQUIRE(*myIT == *sysIT);
	}
	SECTION("-> overload")
	{
		myIT++;
		sysIT++;
		REQUIRE(*myIT->data() == *sysIT->data());
	}

	SECTION("* overload")
	{
		myIT++;
		sysIT++;
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("== overload")
	{
		bool res;
		res = myIT == mylist.begin();
		REQUIRE(res == true);
		myIT++;
		res = myIT == mylist.begin();
		REQUIRE(res == false);
	}

	SECTION("!= overload")
	{
		bool res;
		res = myIT != mylist.begin();
		REQUIRE(res == false);
		myIT++;
		res = myIT != mylist.begin();
		REQUIRE(res == true);
	}


}

TEST_CASE("List: Member Functions Assign", "[List]")
{
	SECTION("FIll version of assign")
	{
		ft::list<std::string> myList1;
		std::list<std::string> sysList1;

		myList1.assign(10, "hello");
		sysList1.assign(10, "hello");
		REQUIRE(myList1.size() == sysList1.size());
		REQUIRE(myList1.front() == sysList1.front());
		REQUIRE(myList1.back() == sysList1.back());

	}

	SECTION("FIll version of assign with pre sized list")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);

		myList1.assign(10, "hello");
		sysList1.assign(10, "hello");
		REQUIRE(myList1.size() == sysList1.size());
		REQUIRE(myList1.front() == sysList1.front());
		REQUIRE(myList1.back() == sysList1.back());
	}

	SECTION("Template version of ASSIGN")
	{
		ft::list<int>list;
		ft::list<int>receivelist;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(150);
		receivelist.assign(list.begin(), list.end());
		REQUIRE(receivelist.size() == 4);
		ft::list<int>::iterator myit = receivelist.begin();
		myit++;
		REQUIRE(*myit == 2);
		ft::list<int>::iterator myitback = receivelist.end();
		myitback--;
		REQUIRE(*myitback == 150);
	}
}

TEST_CASE("List: Member Functions Clear", "[List]")
{
	ft::list<std::string> myList1;
	std::list<std::string> sysList1;
	myList1.push_back("Epic next elem1");
	sysList1.push_back("Epic next elem1");
	myList1.push_back("Epic next elem2");
	sysList1.push_back("Epic next elem2");
	myList1.push_back("Epic next elem3");
	sysList1.push_back("Epic next elem3");
	myList1.push_back("Epic next elem4");
	sysList1.push_back("Epic next elem4");
	myList1.push_back("Epic next elem5");
	sysList1.push_back("Epic next elem5");
	myList1.push_back("Epic next elem6");
	sysList1.push_back("Epic next elem6");
	REQUIRE(sysList1.size() == myList1.size());
	REQUIRE(sysList1.front() == myList1.front());
}

TEST_CASE("List: Member Functions Empty", "[List]")
{
	SECTION("check if empty list is empty")
	{
		ft::list<std::string> myList1;
		std::list<std::string> sysList1;
		REQUIRE(myList1.empty() == sysList1.empty());
	}

	SECTION("check if non empty list is not empty")
	{
		ft::list<std::string> myList1;
		std::list<std::string> sysList1;
		myList1.push_back("Uw zus");
		sysList1.push_back("Uw zus");
		REQUIRE(myList1.empty() == sysList1.empty());
	}

}

TEST_CASE("List: Member Functions Erase", "[List]")
{
	SECTION("Position erase")
	{
		ft::list<std::string> mylist;
		std::list<std::string> syslist;

		mylist.push_back("iterators");
		mylist.push_back("Zijn");
		mylist.push_back("EPIC");


		syslist.push_back("iterators");
		syslist.push_back("Zijn");
		syslist.push_back("EPIC");
		ft::list<std::string>::const_iterator myIT = mylist.begin();
		std::list<std::string>::const_iterator sysIT = syslist.begin();

		mylist.erase(myIT);
		syslist.erase(sysIT);
		myIT = mylist.begin();
		sysIT = syslist.begin();
		REQUIRE(mylist.size() == syslist.size());
		REQUIRE(*myIT == *sysIT);
	}

	SECTION("range erase")
	{
		ft::list<std::string> mylist;
		std::list<std::string> syslist;

		mylist.push_back("iterators");
		mylist.push_back("Zijn");
		mylist.push_back("EPIC");


		syslist.push_back("iterators");
		syslist.push_back("Zijn");
		syslist.push_back("EPIC");
		ft::list<std::string>::const_iterator myIT = mylist.begin();
		std::list<std::string>::const_iterator sysIT = syslist.begin();

		ft::list<std::string>::const_iterator myITEND = mylist.end();
		std::list<std::string>::const_iterator sysITEND = syslist.end();

		mylist.erase(myIT, myITEND);
		syslist.erase(sysIT, sysITEND);
		myIT = mylist.begin();
		sysIT = syslist.begin();
		REQUIRE(mylist.size() == syslist.size());
		REQUIRE(*myIT == *sysIT);
	}
}

TEST_CASE("List: Member Functions Insert", "[List]")
{
	SECTION("INSERT SPECIFIC POSITION")
	{
		ft::list<std::string> mylist;
		std::list<std::string> syslist;

		mylist.push_back("iterators");
		mylist.push_back("Zijn");
		mylist.push_back("EPIC");


		syslist.push_back("iterators");
		syslist.push_back("Zijn");
		syslist.push_back("EPIC");
		ft::list<std::string>::const_iterator myIT = mylist.begin();
		std::list<std::string>::const_iterator sysIT = syslist.begin();

		mylist.insert(myIT, "Niet meer EPIC");
		syslist.insert(sysIT, "Niet meer EPIC");
		myIT = mylist.begin();
		sysIT = syslist.begin();
		REQUIRE(mylist.size() == syslist.size());
		REQUIRE(*myIT == *sysIT);

		ft::list<std::string>::const_iterator myITEND = mylist.end();
		std::list<std::string>::const_iterator sysITEND = syslist.end();

		mylist.insert(myITEND, "Zet dit aan de achterkant");
		syslist.insert(sysITEND, "Zet dit aan de achterkant");
		myITEND = mylist.end();
		sysITEND = syslist.end();
		*myITEND--;
		*sysITEND--;
		REQUIRE(mylist.size() == syslist.size());
		REQUIRE(*myITEND == *sysITEND);
	}

	SECTION("INSERT RANGE")
	{
		ft::list<int> mylist;
		ft::list<int>::iterator myit;
		std::list<int> syslist;
		std::list<int>::iterator sysit;
		// set some initial values:
		for (int i = 1; i <= 5; ++i) mylist.push_back(i); // 1 2 3 4 5
		for (int i = 1; i <= 5; ++i) syslist.push_back(i);
		myit = mylist.begin();
		sysit = syslist.begin();
		++myit;       // it points now to number 2           ^
		++sysit;

		REQUIRE(*myit == *sysit);
		mylist.insert(myit, 10);                        // 1 10 2 3 4 5
		syslist.insert(sysit, 10);
		REQUIRE(mylist.size() == syslist.size());
		// "it" still points to number 2                           ^
		mylist.insert(myit, 2, 20);                      // 1 10 20 20 2 3 4 5
		syslist.insert(sysit, 2, 20);                      // 1 10 20 20 2 3 4 5
		REQUIRE(mylist.size() == syslist.size());
		--myit;       // it points now to the second 20            ^
		--sysit;
		REQUIRE(*myit == *sysit);
	}

	SECTION("INSERT TEMPLATE")
	{
		ft::list<int> mylist;
		std::list<int> syslist;
		ft::list<int> mylist1;
		std::list<int> syslist1;
		ft::list<int>::iterator myit = mylist.begin();
		std::list<int>::iterator sysit = syslist.begin();

		mylist1.push_front(10);
		mylist1.push_front(15);
		mylist1.push_front(20);
		mylist1.push_front(25);

		syslist1.push_front(10);
		syslist1.push_front(15);
		syslist1.push_front(20);
		syslist1.push_front(25);

		mylist.insert(myit, mylist1.begin(), mylist1.end());
		syslist.insert(sysit, syslist1.begin(), syslist1.end());
		// 1 10 20 30 30 20 2 3 4 5
		//               ^
		REQUIRE(mylist.size() == syslist.size());
		for (int i = 0; i < 4; i++) {
			myit--;
			sysit--;
			REQUIRE(*myit == *sysit);
		}
	}
}

TEST_CASE("List: Member Functions Merge", "[List]")
{
	SECTION("List X merging")
	{
		int numbers[5] = {10, 9, 50, 30, 4};
		int mergenumbers[6] = {12, 8, 7, 3, 12, 1};
		std::list<int> syslist(numbers, numbers+5);
		std::list<int> mergelist(mergenumbers, mergenumbers+6);
		syslist.sort();
		mergelist.sort();

		ft::list<int> mylist(numbers, numbers+5);
		ft::list<int> mymergelist(mergenumbers, mergenumbers+6);
		mylist.sort();
		mergelist.sort();
		syslist.sort();
		mymergelist.sort();
		mylist.merge(mymergelist);
		syslist.merge(mergelist);
		REQUIRE(mylist.size() == syslist.size());
		ft::list<int>::iterator myit = mylist.begin();
		std::list<int>::iterator sysit = syslist.begin();

		for (int i = 0; i < (int)mylist.size(); i++, myit++, sysit++)
		{
//			std::cout << "my it " << *myit << std::endl;
//			std::cout << "sys it " << *sysit << std::endl;
			REQUIRE(*myit == *sysit);
		}
	}
}

TEST_CASE("List: Member Functions PopBack", "[List]")
{
	ft::list<std::string> myList;
	std::list<std::string> sysList;

	SECTION("check first elem after popback")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);

		myList1.push_back("Epic next elem");
		sysList1.push_back("Epic next elem");
		myList1.push_back("Epic elem which is going to be deleted");
		sysList1.push_back("Epic elem which is going to be deleted");
		myList1.pop_back();
		sysList1.pop_back();

		REQUIRE(myList1.back() == sysList1.back());
	}

	SECTION("check size after popback")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);

		myList1.push_back("Epic next elem");
		sysList1.push_back("Epic next elem");
		myList1.push_back("Epic elem which is going to be deleted");
		sysList1.push_back("Epic elem which is going to be deleted");
		myList1.pop_back();
		sysList1.pop_back();
		REQUIRE(myList1.size() == sysList1.size());
	}
}

TEST_CASE("List: Member Functions PopFront", "[List]")
{
	ft::list<std::string> myList;
	std::list<std::string> sysList;

	SECTION("check first elem after popfront")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);

		myList1.push_front("Epic next elem");
		sysList1.push_front("Epic next elem");
		myList1.push_front("Epic elem which is going to be deleted");
		sysList1.push_front("Epic elem which is going to be deleted");
		myList1.pop_front();
		sysList1.pop_front();

		REQUIRE(myList1.front() == sysList1.front());
	}

	SECTION("check size after popfront")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);

		myList1.push_front("Epic next elem");
		sysList1.push_front("Epic next elem");
		myList1.push_front("Epic elem which is going to be deleted");
		sysList1.push_front("Epic elem which is going to be deleted");
		myList1.pop_front();
		sysList1.pop_front();
		REQUIRE(myList1.size() == sysList1.size());
	}
}

TEST_CASE("List: Member Functions PushBack", "[List]")
{
	ft::list<std::string> myList;
	std::list<std::string> sysList;

	SECTION("check last elem after pushBack")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);

		myList1.push_back("Epic next elem");
		sysList1.push_back("Epic next elem");
		REQUIRE(myList1.back() == sysList1.back());
	}

	SECTION("check size after pushBack")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);

		myList1.push_back("Epic next elem");
		sysList1.push_back("Epic next elem");
		REQUIRE(myList1.size() == 11);
		REQUIRE(myList1.size() == sysList1.size());
	}

}

TEST_CASE("List: Member Functions PushFront", "[List]")
{
	ft::list<std::string> myList;
	std::list<std::string> sysList;

	SECTION("check first elem after pushfront")
	{
		ft::list<std::string> myList(10);
		std::list<std::string> sysList(10);

		myList.push_front("Epic next elem");
		sysList.push_front("Epic next elem");
		REQUIRE(myList.front() == sysList.front());
	}

	SECTION("check size after pushfront")
	{
		ft::list<std::string> myList1(10);
		std::list<std::string> sysList1(10);

		myList1.push_front("Epic next elem");
		sysList1.push_front("Epic next elem");
		REQUIRE(myList1.size() == 11);
		REQUIRE(myList1.size() == sysList1.size());
	}

}

TEST_CASE("List: Member Functions Remove", "[List]")
{
	int myints[]= {17,89,7,14};
	ft::list<int> myintlist(myints, myints+4);
	std::list<int> sysintslist(myints, myints+4);

	myintlist.remove(89);
	sysintslist.remove(89);
	REQUIRE(myintlist.size() == sysintslist.size());
	ft::list<int>::iterator myit = myintlist.begin();
	std::list<int>::iterator sysit = sysintslist.begin();
	*myit++;
	*sysit++;
	REQUIRE(*myit == *sysit);
	*myit++;
	*sysit++;
	REQUIRE(*myit == *sysit);

}

TEST_CASE("List: Member Functions RemoveIF", "[List]")
{

// a predicate implemented as a class:
	struct is_odd {
		bool operator() (const int& value) { return (value%2)==1; }
	};

	int myints[]= {15,36,7,17,20,39,4,1};
	int sysints[]= {15,36,7,17,20,39,4,1};
	ft::list<int> mylist (myints, myints+8);
	std::list<int> syslist (sysints,sysints+8);   // 15 36 7 17 20 39 4 1


	mylist.remove_if (is_odd());
	syslist.remove_if (is_odd());// 36 20 36 17 20 39

	REQUIRE(mylist.size() == syslist.size());
	ft::list<int>::iterator myit = mylist.begin();
	std::list<int>::iterator sysit = syslist.begin();

	for (int i = 0; i < (int)mylist.size(); i++, myit++, sysit++)
	{
		REQUIRE(*myit == *sysit);
	}
}

TEST_CASE("List: Member Functions Resize", "[List]")
{
	SECTION("List needs to be made smaller")
	{
		int myints[]= {15,36,7,17,20,39,4,1};
		int sysints[]= {15,36,7,17,20,39,4,1};

		ft::list<int> myintlist(myints, myints+8);
		std::list<int> sysintlist(sysints, sysints+8);

		myintlist.resize(5);
		sysintlist.resize(5);

		REQUIRE(myintlist.size() == sysintlist.size());
		ft::list<int>::iterator myit = myintlist.begin();
		std::list<int>::iterator sysit = sysintlist.begin();

		for (int i = 0; i < (int)myintlist.size(); i++, myit++, sysit++)
		{
//			std::cout << *myit << std::endl;
//			std::cout << *sysit << std::endl;
			REQUIRE(*myit == *sysit);
		}
	}

	SECTION ("List needs to be made bigger with given values")
	{
		int myints[]= {15,36,7,17,20,39,4,1};
		int sysints[]= {15,36,7,17,20,39,4,1};

		ft::list<int> myintlist(myints, myints+8);
		std::list<int> sysintlist(sysints, sysints+8);

		myintlist.resize(20, 15);
		sysintlist.resize(20,15);

		REQUIRE(myintlist.size() == sysintlist.size());
		ft::list<int>::iterator myit = myintlist.begin();
		std::list<int>::iterator sysit = sysintlist.begin();

		for (int i = 0; i < (int)myintlist.size(); i++, myit++, sysit++)
		{
//			std::cout << "my it " << *myit << std::endl;
//			std::cout << "sys it " << *sysit << std::endl;
			REQUIRE(*myit == *sysit);
		}
	}

	SECTION("List need to be made bigger with zero values")
	{
		int myints[]= {15,36,7,17,20,39,4,1};
		int sysints[]= {15,36,7,17,20,39,4,1};

		ft::list<int> myintlist(myints, myints+8);
		std::list<int> sysintlist(sysints, sysints+8);

		myintlist.resize(20);
		sysintlist.resize(20);

		REQUIRE(myintlist.size() == sysintlist.size());
		ft::list<int>::iterator myit = myintlist.begin();
		std::list<int>::iterator sysit = sysintlist.begin();

		for (int i = 0; i < (int)myintlist.size(); i++, myit++, sysit++)
		{
//			std::cout << "my it " << *myit << std::endl;
//			std::cout << "sys it " << *sysit << std::endl;
			REQUIRE(*myit == *sysit);
		}
	}
}

TEST_CASE("List: Member Functions Reverse", "[List]")
{
	int myints[] = {1,2,3,4,5,6,7,8,9,10};
	int sysints[] = {1,2,3,4,5,6,7,8,9,10};
	ft::list<int> mylist(myints, myints+10);
	std::list<int> syslist(sysints, sysints+10);

	mylist.reverse();
	syslist.reverse();
	std::cout << "Nee" << std::endl;
	std::cout << mylist.size() << std::endl;
	std::cout << syslist.size() << std::endl;
	REQUIRE(mylist.size() == syslist.size());
	ft::list<int>::iterator myit = mylist.begin();
	std::list<int>::iterator sysit = syslist.begin();

	std::cerr << "Kom ik hier?" << std::endl;
	for (int i = 0; i < (int)mylist.size(); i++, myit++, sysit++)
	{
		std::cerr << "myit = " << *myit << std::endl;
		REQUIRE(*myit == *sysit);
	}
}

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

TEST_CASE("List: Member Functions sort", "[List]")
{

	SECTION("Non templated sort function")
	{
		int myints[] = {1,2,3,4,5,6,7,8,9,10};
		int sysints[] = {1,2,3,4,5,6,7,8,9,10};
		ft::list<int> mylist(myints, myints+10);
		std::list<int> syslist(sysints, sysints+10);
		mylist.sort();
		syslist.sort();
		REQUIRE(mylist.size() == syslist.size());
		ft::list<int>::iterator myit = mylist.begin();
		std::list<int>::iterator sysit = syslist.begin();

		for (int i = 0; i < (int)mylist.size(); i++, myit++, sysit++)
		{
//			std::cout << "my it " << *myit << std::endl;
//			std::cout << "sys it " << *sysit << std::endl;
			REQUIRE(*myit == *sysit);
//			std::cout<< "[" << *myit << "]" << " VS " << "[" << *sysit << "]" << std::endl;
		}

	}
	SECTION("Templated sort function")
	{

		ft::list<std::string> mylist;
		std::list<std::string> syslist;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");
		mylist.push_back ("Four");
		mylist.push_back ("Six");
		mylist.push_back ("ten");

		syslist.push_back ("one");
		syslist.push_back ("two");
		syslist.push_back ("Three");
		syslist.push_back ("Four");
		syslist.push_back ("Six");
		syslist.push_back ("ten");

		syslist.sort(compare_nocase);
		mylist.sort(compare_nocase);
		ft::list<std::string>::iterator myit = mylist.begin();
		std::list<std::string>::iterator sysit = syslist.begin();
		for (int i = 0; i < (int)mylist.size(); i++, myit++, sysit++)
		{
//			std::cout << "my it " << *myit << std::endl;
//			std::cout << "sys it " << *sysit << std::endl;
			REQUIRE(*myit == *sysit);
//			std::cout<< "[" << *myit << "]" << " VS " << "[" << *sysit << "]" << std::endl;
		}

	}
}

TEST_CASE("List: Member Functions Splice", "[List]")
{
	SECTION("Full list transfer")
	{
		int myints[] = {1,2,3,4,5,6,7,8,9,10};
		int insertints[] = {11,12,13,14,15,16,17,18,19,20};


		ft::list<int> insertlist(insertints, insertints+10);
		std::list<int> sysinsertlist(insertints, insertints+10);


		ft::list<int> mylist(myints, myints+10);
		std::list<int> syslist(myints, myints+10);

		ft::list<int>::iterator myit = mylist.end();
		std::list<int>::iterator sysit = syslist.end();
		*myit--;
		*myit--;
		*sysit--;
		*sysit--;
		mylist.splice(myit, insertlist);
		syslist.splice(sysit, sysinsertlist);

		ft::list<int>::iterator myit2 = mylist.begin();
		std::list<int>::iterator sysit2 = syslist.begin();

		for (int i = 0; i < (int)mylist.size(); i++, myit2++, sysit2++)
		{

			REQUIRE(*myit2 == *sysit2);
		}
		REQUIRE(insertlist.size() == sysinsertlist.size());
	}

	SECTION("Range of list transfer")
	{

		// ft part of construction
		int startlist[5] = {1,2,3,4,5};
		ft::list<int> mylist(startlist, startlist+5);

		int insertionnumbers[5] = {100, 101, 102, 103, 104};
		ft::list<int> insertionlist(insertionnumbers, insertionnumbers+5);

		ft::list<int>::iterator position = mylist.end();
		ft::list<int>::iterator start = insertionlist.begin();
		ft::list<int>::iterator end = insertionlist.end();
		end--;
		end--;
		// end of ft part of construction
		// std::part of construction
//		int sysstartlist[5] = {1,2,3,4,5};
		std::list<int> syslist(startlist, startlist+5);

		int sysinsertionnumbers[5] = {100, 101, 102, 103, 104};
		std::list<int> sysinsertionlist(sysinsertionnumbers, sysinsertionnumbers+5);

		std::list<int>::iterator sysposition = syslist.end();
		std::list<int>::iterator sysstart = sysinsertionlist.begin();
		std::list<int>::iterator sysend = sysinsertionlist.end();
		sysend--;
		sysend--;
		// end of std:: part of construction

		mylist.splice(position, insertionlist, start, end);
		syslist.splice(sysposition, sysinsertionlist, sysstart, sysend);

		ft::list<int>::iterator myit2 = mylist.begin();
		std::list<int>::iterator sysit2 = syslist.begin();
		for (int i = 0; i < (int)mylist.size(); i++, myit2++, sysit2++)
		{
			REQUIRE(*myit2 == *sysit2);
		}
		REQUIRE(insertionlist.size() == sysinsertionlist.size());
	}
}

TEST_CASE("List: Member Functions Swap", "[List]")
{
	SECTION("Same length")
	{
		int startlist[5] = {1,2,3,4,5};
		ft::list<int> mystartlist(startlist, startlist+5);
		int secondlist[5] = {10,11,12,13,14};
		ft::list<int> mysecondlist(secondlist, secondlist+5);

		int sysstart[5] = {1,2,3,4,5};
		std::list<int> sysstartlist(sysstart, sysstart+5);
		int syssecond[5] = {10,11,12,13,14};
		std::list<int> syssecondlist(syssecond, syssecond+5);

		mystartlist.swap(mysecondlist);
		sysstartlist.swap(syssecondlist);

		ft::list<int>::iterator myit2 = mystartlist.begin();
		std::list<int>::iterator sysit2 = sysstartlist.begin();
		for (int i = 0; i < (int)mystartlist.size(); i++, myit2++, sysit2++)
		{
			REQUIRE(*myit2 == *sysit2);
		}
		REQUIRE(mystartlist.size() == sysstartlist.size());
		REQUIRE(mysecondlist.size() == syssecondlist.size());
	}
}

struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

TEST_CASE("List: Member Functions Unique", "[List]")
{
	SECTION("Unique without binary predicate")
	{
		int startlist[5] = {1,2,3,3,3};
		ft::list<int> mystartlist(startlist, startlist+5);

		int sysstart[5] = {1,2,3,3,3};
		std::list<int> sysstartlist(sysstart, sysstart+5);

		mystartlist.unique();
		sysstartlist.unique();

		ft::list<int>::iterator myit2 = mystartlist.begin();
		std::list<int>::iterator sysit2 = sysstartlist.begin();
		for (int i = 0; i < (int)mystartlist.size(); i++, myit2++, sysit2++)
		{
			REQUIRE(*myit2 == *sysit2);
		}
		REQUIRE(mystartlist.size() == sysstartlist.size());
	}

	SECTION("Unique with binary predicate")
	{
		double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
							 12.77, 73.35, 72.25, 15.3,  72.25 };
		double sysdoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
							  12.77, 73.35, 72.25, 15.3,  72.25 };

		ft::list<double> mylist (mydoubles,mydoubles+10);
		std::list<double> syslist(sysdoubles, sysdoubles+10);
		mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
		syslist.sort();
		mylist.unique (is_near());           //  2.72, 12.15, 72.25
		syslist.unique(is_near());
		ft::list<double>::iterator myit2 = mylist.begin();
		std::list<double>::iterator sysit2 = syslist.begin();
		for (int i = 0; i < (int)mylist.size(); i++, myit2++, sysit2++)
		{
			REQUIRE(*myit2 == *sysit2);
			std::cout << "my it " << *myit2 << std::endl;
			std::cout << "sys it " << *sysit2 << std::endl;
		}
		REQUIRE(mylist.size() == syslist.size());
	}
}

TEST_CASE("List: overlaods ", "[List]")
{
	ft::list<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	ft::list<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	ft::list<int> c;
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

