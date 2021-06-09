//
// Created by Thimo Van der meer on 08/06/2021.
//

#include "Catch2.h"
#include <map>
#include "../srcs/map/map.hpp"
#include "../srcs/map/MapNode.hpp"
#include <iostream>

//namespace ft
//{
//	// have to create the overload for equals
//	template<class Key, class T, class Alloc>
//	bool operator==(const ft::map<Key, T> &mine,
//					const std::map<Key, T> &real)
//	{
//		if (mine.size() != real.size())
//			return (false);
//		if (mine.get_allocator() != real.get_allocator())
//			return (false);
//		auto myit = mine.begin();
//		auto realit = real.begin();
//		for (size_t i = 0; i < mine.size(); i++, myit++, realit++)
//		{
//			if (*myit != *realit)
//				return (false);
//		}
//		return (true);
//	}
//
//	template<class Key, class T>
//	bool operator==(const std::map<Key, T> &real,
//					const ft::map<Key, T> &mine)
//	{ return (mine == real); }
//
//	template<class Key, class T>
//	bool operator!=(const ft::map<Key, T> &mine,
//					const std::map<Key, T> &real)
//	{ return !(mine == real); }
//
//	template<class Key, class T>
//	bool operator!=(const std::map<Key, T> &real,
//					const ft::map<Key, T> &mine)
//	{ return !(mine == real); }
//}


	TEST_CASE("Map: Node check", "[Map]")
	{

		SECTION("GetNext")
		{
			// make for adjecent nodes make 7 nodes {13, 8,17,1,11,15,25}
			// create a tree with root 13 and check if get prev returns 15 as next
			// mock data the get next should return the rightchildleft
			mapNode<int> root(13);
			mapNode<int> firstleft(8);
			mapNode<int> leftchildleft(1);
			mapNode<int> rightchildleft(15);
			mapNode<int> firstright(17);
			mapNode<int> rightchildright(25);
			mapNode<int> leftchildright(11);

			root.setLeft(&firstleft);
			root.setRight(&firstright);

			firstleft.setParent(&root);
			firstleft.setLeft(&leftchildleft);
			firstleft.setRight(&leftchildright);

			firstright.setParent(&root);
			firstright.setLeft(&rightchildleft);
			firstright.setRight(&rightchildright);

			leftchildright.setParent(&firstleft);
			leftchildleft.setParent(&firstleft);

			rightchildright.setParent(&firstright);
			rightchildleft.setParent(&firstright);

			std::cout << root.getNext()->getData() << std::endl;
		}

		SECTION("GetNext without bigger elem")
		{
			// deze moet ik later bouwen omdat ik nu de map nog niet heb geimplementeerd.
			// hierdoor heb ik first and last nog niet vanuit het value pair. Ik kan hierdoor geen vergelijkingen doen op key
			// dit komt dus later
		}


		SECTION("GetPrev")
		{
			// make for adjecent nodes make 7 nodes {13, 8,17,1,11,15,25}
			// create a tree with root 13 and check if get prev returns 15 as next
			// mock data the get next should return the rightchildleft
			mapNode<int> root(13);
			mapNode<int> firstleft(8);
			mapNode<int> leftchildleft(1);
			mapNode<int> rightchildleft(15);
			mapNode<int> firstright(17);
			mapNode<int> rightchildright(25);
			mapNode<int> leftchildright(11);

			root.setLeft(&firstleft);
			root.setRight(&firstright);

			firstleft.setParent(&root);
			firstleft.setLeft(&leftchildleft);
			firstleft.setRight(&leftchildright);

			firstright.setParent(&root);
			firstright.setLeft(&rightchildleft);
			firstright.setRight(&rightchildright);

			leftchildright.setParent(&firstleft);
			leftchildleft.setParent(&firstleft);

			rightchildright.setParent(&firstright);
			rightchildleft.setParent(&firstright);

			std::cout << root.getPrev()->getData() << std::endl;
		}

		SECTION("GetPrev without bigger elem")
		{
			// deze moet ik later bouwen omdat ik nu de map nog niet heb geimplementeerd.
			// hierdoor heb ik first and last nog niet vanuit het value pair. Ik kan hierdoor geen vergelijkingen doen op key
			// dit komt dus later
		}

	}

	TEST_CASE("Map: Constructors", "[Map]")
	{
		SECTION("Default")
		{
			ft::map<char, int> mymap1;
			std::map<char, int> sysmap1;

			ft::map<char, int>::iterator myit1 = mymap1.begin();
			std::map<char, int>::iterator sysit1 = sysmap1.begin();
			*myit1++;
			*sysit1++;
			std::cout << myit1->first << std::endl;
			std::cout << sysit1->first << std::endl;
			REQUIRE(myit1->first == sysit1->first);


		}

		SECTION("Range")
		{

		}

		SECTION("Copy")
		{

		}
	}

	TEST_CASE("Map: Destructors", "[Map]")
	{

	}

	TEST_CASE("Map: Operator==", "[Map]")
	{

	}

	TEST_CASE("Map: Iterator begin", "[Map]")
	{
		SECTION("Normal")
		{

		}

		SECTION("Const")
		{

		}

	}

	TEST_CASE("Map: Iterator end", "[Map]")
	{
		SECTION("Normal")
		{

		}

		SECTION("Const")
		{

		}

	}

	TEST_CASE("Map: Iterator rbegin", "[Map]")
	{
		SECTION("Normal")
		{

		}

		SECTION("Const")
		{

		}

	}

	TEST_CASE("Map: Iterator rend", "[Map]")
	{
		SECTION("Normal")
		{

		}

		SECTION("Const")
		{

		}

	}

	TEST_CASE("Map: empty", "[Map]")
	{

	}

	TEST_CASE("Map: size", "[Map]")
	{

	}

	TEST_CASE("Map: Max size", "[Map]")
	{

	}

	TEST_CASE("Map: Operator[]", "[Map]")
	{

	}

	TEST_CASE("Map: Insert", "[Map]")
	{
		SECTION("Insert one")
		{

		}

		SECTION("Insert with hint")
		{

		}

		SECTION("Insert Range")
		{

		}
	}

	TEST_CASE("Map: Erase", "[Map]")
	{
		SECTION("Erase one")
		{

		}

		SECTION("Erase with hint")
		{

		}

		SECTION("Erase range")
		{

		}
	}

	TEST_CASE("Map: Swap", "[Map]")
	{

	}

	TEST_CASE("Map: Clear", "[Map]")
	{

	}

	TEST_CASE("Map: Key_compare", "[Map]")
	{

	}

	TEST_CASE("Map: Value_compare", "Map")
	{

	}

	TEST_CASE("Map: Find", "[Map]")
	{

	}

	TEST_CASE("Map: Count", "[Map]")
	{

	}

	TEST_CASE("Map: Lower_bound", "[Map]")
	{
		SECTION("Normal")
		{

		}

		SECTION("Const")
		{

		}
	}

	TEST_CASE("Map: Upper_bound", "[Map]")
	{
		SECTION("Normal")
		{

		}

		SECTION("Const")
		{

		}
	}

	TEST_CASE("Map: Equal_range", "[Map]")
	{
		SECTION("Normal")
		{

		}

		SECTION("Const")
		{

		}
	}

	TEST_CASE("Map: Get_allocator", "[Map]")
	{

	}