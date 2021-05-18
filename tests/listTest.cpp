//
// Created by Thimo Van der meer on 06/05/2021.
//

#include "Catch2.h"
#include "../srcs/list/list.hpp"
#include <list>
#include <iostream>

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
}

TEST_CASE("List: Destructors", "[List]")
{

}

TEST_CASE("List: Assignment operators", "[List]")
{

}

TEST_CASE("List: Allocators", "[List]")
{

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

	std::cout << "mylist ";
	for (auto v : mylist)
		std::cout  << "[" << v << "]";
	std::cout << std::endl;
	std::cout << "syslist ";
	for (auto v : syslist)
		std::cout  << "[" << v << "]";
	std::cout << std::endl;
	mylist.remove_if (is_odd());
	syslist.remove_if (is_odd());// 36 20 36 17 20 39
	std::cout << "mylist after remove ";
	for (auto v : mylist)
		std::cout  << "[" << v << "]";
	std::cout << std::endl;
	std::cout << "syslist after remove";
	for (auto v : syslist)
		std::cout  << "[" << v << "]";
	std::cout << std::endl;
	REQUIRE(mylist.size() == syslist.size());
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

		for (int i = 0; i < myintlist.size(); i++, myit++, sysit++)
		{
			std::cout << *myit << std::endl;
			std::cout << *sysit << std::endl;
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

		for (int i = 0; i < myintlist.size(); i++, myit++, sysit++)
		{
			std::cout << "my it " << *myit << std::endl;
			std::cout << "sys it " << *sysit << std::endl;
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

		for (int i = 0; i < myintlist.size(); i++, myit++, sysit++)
		{
			std::cout << "my it " << *myit << std::endl;
			std::cout << "sys it " << *sysit << std::endl;
			REQUIRE(*myit == *sysit);
		}
	}
}

TEST_CASE("List: Member Functions Reverse", "[List]")
{

}

TEST_CASE("List: Member Functions Size", "[List]")
{

}

TEST_CASE("List: Member Functions sort", "[List]")
{

}

TEST_CASE("List: Member Functions Compare", "[List]")
{

}

TEST_CASE("List: Member Functions Splice", "[List]")
{

}

TEST_CASE("List: Member Functions Swap", "[List]")
{

}

TEST_CASE("List: Member Functions Unique", "[List]")
{

}

TEST_CASE("List: NonMember functions operator==", "[List]")
{

}

TEST_CASE("List: NonMember functions operator!=", "[List]")
{

}

TEST_CASE("List: NonMember functions operator<", "[List]")
{

}

TEST_CASE("List: NonMember functions operator>", "[List]")
{

}

TEST_CASE("List: NonMember functions operator<=", "[List]")
{

}

TEST_CASE("List: NonMember functions operator>=", "[List]")
{

}
