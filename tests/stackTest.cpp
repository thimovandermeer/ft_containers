//
// Created by Thimo Van der meer on 20/05/2021.
//

#include "Catch2.h"
#include "../srcs/stack/stack.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <stack>
#include <list>


TEST_CASE("Stack: Constructors", "[Stack]")
{
	ft::list<int> mylist (10);          // deque with 3 elements
	std::vector<int> myvector (2,200);        // vector with 2 elements

	ft::stack<int> first;                    // empty stack
	ft::stack<int> second (mylist);         // stack initialized to copy of deque

	ft::stack<int,std::vector<int> > third;  // empty stack using vector
	ft::stack<int,ft::list<int> > fourth (mylist);

	REQUIRE(first.size() == 0);
	REQUIRE(second.size() == 10);
	REQUIRE(third.size() == 0);
	REQUIRE(fourth.size() == 10);
}

TEST_CASE("Stack: Empty", "[Stack]")
{
	ft::list<int> mylist (10);

	std::list<int> syslist (10);

	ft::stack<int,ft::list<int> > mystack(mylist);  // empty stack using vector
	std::stack<int,std::list<int> > sysstack (syslist);


	REQUIRE(mystack.empty() == sysstack.empty());

}

TEST_CASE("Stack: size", "[Stack]")
{
	ft::list<int> mylist (10);

	std::list<int> syslist (10);

	ft::stack<int,ft::list<int> > mystack(mylist);  // empty stack using vector
	std::stack<int,std::list<int> > sysstack (syslist);


	REQUIRE(mystack.size() == sysstack.size());
}

TEST_CASE("Stack: top", "[Stack]")
{
	ft::stack<int> mystack;
	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::stack<int> sysstack;
	sysstack.push(10);
	sysstack.push(20);

	sysstack.top() -= 5;

	REQUIRE(mystack.top() == sysstack.top());

}

TEST_CASE("Stack: push", "[Stack]")
{
	ft::stack<int> mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);

	std::stack<int> sysstack;
	for (int i = 0; i < 5; ++i)
		sysstack.push(i);

	for (int i = 0; i < 5; ++i) {
		REQUIRE(mystack.top() == sysstack.top());
		mystack.pop();
		sysstack.pop();
	}

}

TEST_CASE("Stack: Pop", "[Stack]")
{
	ft::stack<int> mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);

	std::stack<int> sysstack;
	for (int i = 0; i < 5; ++i)
		sysstack.push(i);

	for (int i = 0; i < 5; ++i) {
		REQUIRE(mystack.top() == sysstack.top());
		mystack.pop();
		sysstack.pop();
	}
}




