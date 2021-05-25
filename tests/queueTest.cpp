//
// Created by Thimo Van der meer on 25/05/2021.
//

#include "Catch2.h"
#include "../srcs/queue/queue.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <stack>
#include <list>
#include <queue>

TEST_CASE("Queue: Constructors", "[Queue]")
{
	std::vector<int> myvector (2,200);        // vector with 2 elements
	ft::list<int> mylist(10);
	ft::queue<int> first;                    // empty stack
	ft::queue<int> second (mylist);         // stack initialized to copy of deque

	ft::queue<int,std::vector<int> > third;  // empty stack using vector
	ft::queue<int,ft::list<int> > fourth (mylist);

	REQUIRE(first.size() == 0);
	REQUIRE(second.size() == 10);
	REQUIRE(third.size() == 0);
	REQUIRE(fourth.size() == 10);
}

TEST_CASE("Queue: Empty", "[Queue]")
{
	ft::list<int> mylist (10);

	std::list<int> syslist (10);

	ft::queue<int,ft::list<int> > myqueue(mylist);  // empty stack using vector
	std::queue<int,std::list<int> > sysqueue (syslist);


	REQUIRE(myqueue.empty() == sysqueue.empty());

}

TEST_CASE("Queue: size", "[Queue]")
{
	ft::list<int> mylist (10);

	std::list<int> syslist (10);

	ft::queue<int,ft::list<int> > myqueue(mylist);  // empty stack using vector
	std::queue<int,std::list<int> > sysqueue (syslist);


	REQUIRE(myqueue.size() == sysqueue.size());
}

TEST_CASE("Queue: front", "[Queue]")
{
	ft::queue<int> myqueue;
	myqueue.push(10);
	myqueue.push(20);

	myqueue.front() -= 5;

	std::queue<int> sysqueue;
	sysqueue.push(10);
	sysqueue.push(20);

	sysqueue.front() -= 5;

	REQUIRE(myqueue.front() == sysqueue.front());

}

TEST_CASE("Queue: push", "[Queue]")
{
	ft::queue<int> myqueue;

	for (int i = 0; i < 5; ++i)
		myqueue.push(i);

	std::queue<int> sysqueue;
	for (int i = 0; i < 5; ++i)
		sysqueue.push(i);

	for (int i = 0; i < 5; ++i) {
		REQUIRE(myqueue.front() == sysqueue.front());
		myqueue.pop();
		sysqueue.pop();
	}

}

TEST_CASE("Queue: Pop", "[Queue]")
{
	ft::queue<int> myqueue;

	for (int i = 0; i < 5; ++i)
		myqueue.push(i);

	std::queue<int> sysqueue;
	for (int i = 0; i < 5; ++i)
		sysqueue.push(i);

	for (int i = 0; i < 5; ++i) {
		REQUIRE(myqueue.front() == sysqueue.front());
		myqueue.pop();
		sysqueue.pop();
	}
}