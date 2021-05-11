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
}

TEST_CASE("List: Member Functions Back", "[List]")
{

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

}

TEST_CASE("List: Member Functions Front", "[List]")
{

}

TEST_CASE("List: Member Functions Insert", "[List]")
{

}

TEST_CASE("List: Member Functions Merge", "[List]")
{

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

}

TEST_CASE("List: Member Functions RemoveIF", "[List]")
{

}

TEST_CASE("List: Member Functions Resize", "[List]")
{

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
