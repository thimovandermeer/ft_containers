//
// Created by Thimo Van der meer on 08/06/2021.
//

#include "catch.hpp"
#include <map>
#include "../srcs/map/map.hpp"
#include "../srcs/map/MapNode.hpp"
#include <iostream>
namespace ft
{
	template<class T, class Alloc>
	bool operator==(const ft::map<T, Alloc> &mine,
					const std::map<T, Alloc> &real)
	{
		if (mine.size() != real.size())
			return (false);
		if (mine.get_allocator() != real.get_allocator())
			return (false);
		auto myit = mine.begin();
		auto realit = real.begin();
		for (size_t i = 0; i < mine.size(); ++i, ++myit, ++realit)
		{
			if (myit->first != realit->first || myit->second != realit->second)
				return (false);
		}
		return (true);
	}

	template<class T, class Alloc>
	bool operator==(const std::map<T, Alloc> &real,
					const ft::map<T, Alloc> &mine)
	{ return (mine == real); }

	template<class T, class Alloc>
	bool operator!=(const ft::map<T, Alloc> &mine,
					const std::map<T, Alloc> &real)
	{ return !(mine == real); }

	template<class T, class Alloc>
	bool operator!=(const std::map<T, Alloc> &real,
					const ft::map<T, Alloc> &mine)
	{ return !(mine == real); }

	template<class T, class Compare, class Alloc>
	bool operator==(const ft::map<T, Compare, Alloc> &mine,
					const std::map<T, Compare, Alloc> &real)
	{
		if (mine.size() != real.size())
			return (false);
		if (mine.get_allocator() != real.get_allocator())
			return (false);
		auto myit = mine.begin();
		auto realit = real.begin();
		for (size_t i = 0; i < mine.size(); ++i, ++myit, ++realit)
		{
			if (myit->first != realit->first || myit->second != realit->second)
				return (false);
		}
		return (true);
	}

	template<class T, class Compare, class Alloc>
	bool operator==(const std::map<T, Compare, Alloc> &real,
					const ft::map<T, Compare, Alloc> &mine)
	{ return (mine == real); }

	template<class T, class Compare, class Alloc>
	bool operator!=(const ft::map<T, Compare, Alloc> &mine,
					const std::map<T, Compare, Alloc> &real)
	{ return !(mine == real); }

	template<class T, class Compare, class Alloc>
	bool operator!=(const std::map<T, Compare, Alloc> &real,
					const ft::map<T, Compare, Alloc> &mine)
	{ return !(mine == real); }
}
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

			root.left = &firstleft;
			root.right = &firstright;

			firstleft.parent = &root;
			firstleft.left = &leftchildleft;
			firstleft.right = &leftchildright;

			firstright.parent = &root;
			firstright.left = &rightchildleft;
			firstright.right = &rightchildright;

			leftchildright.parent = &firstleft;
			leftchildleft.parent = &firstleft;

			rightchildright.parent =&firstright;
			rightchildleft.parent =&firstright;

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

			root.left = &firstleft;
			root.right = &firstright;

			firstleft.parent = &root;
			firstleft.left = &leftchildleft;
			firstleft.right = &leftchildright;

			firstright.parent = &root;
			firstright.left = &rightchildleft;
			firstright.right = &rightchildright;

			leftchildright.parent = &firstleft;
			leftchildleft.parent = &firstleft;

			rightchildright.parent = &firstright;
			rightchildleft.parent = &firstright;

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

			REQUIRE(mymap1.size() == sysmap1.size());
			REQUIRE(mymap1.get_allocator() == sysmap1.get_allocator());


		}

		SECTION("Range")
		{
			ft::map<int, int>	own;
			std::map<int, int>	real;

			int sum = 1;
			for (int i = 0; i < 6; ++i)
			{
				own.insert(std::pair<int, int>(sum, sum));
				real.insert(std::pair<int, int>(sum, sum));
				sum += 1;
			}
			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			std::map<int, int>::iterator	real_it = real.begin();
			ft::map<int, int>::iterator		own_it = own.begin();

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}

			std::map<int, int>	real2(real.begin(), real.end());
			ft::map<int, int>	own2(own.begin(), own.end());

			REQUIRE(own2.size() == real2.size());
			REQUIRE(own2.empty() == real2.empty());

			real_it = real2.begin();
			own_it = own2.begin();
			while (own_it != own2.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}
		}

		SECTION("Copy")
		{
			{
				ft::map<int, int>	own;

				int sum = 1;
				for (int i = 0; i < 6; ++i)
				{
					own.insert(std::pair<int, int>(sum, sum));
					sum += 1;
				}
				ft::map<int, int> newmap(own);
				REQUIRE(newmap.size() == own.size());
				ft::map<int, int>::iterator it = newmap.begin();
				for(int i = 1;it != newmap.end(); it++, i++)
				{
					REQUIRE(it->first == i);
				}
			}

			ft::map<int, int>	own;
			std::map<int, int>	real;

			int sum = 1;
			for (int i = 0; i < 6; ++i)
			{
				own.insert(std::pair<int, int>(sum, sum));
				real.insert(std::pair<int, int>(sum, sum));
				sum += 1;
			}

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			std::map<int, int>::iterator	real_it = real.begin();
			ft::map<int, int>::iterator		own_it = own.begin();

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}

			std::map<int, int>	real2(real);
			ft::map<int, int>	own2(own);

			REQUIRE(own2.size() == real2.size());
			REQUIRE(own2.empty() == real2.empty());

			real_it = real2.begin();
			own_it = own2.begin();
			while (own_it != own2.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}

		}
	}

	TEST_CASE("Map: Destructors", "[Map]")
	{

	}

	TEST_CASE("Map: Operator==", "[Map]")
	{
		ft::map<int, int>	own;
		std::map<int, int>	real;

		int sum = 1;
		for (int i = 0; i < 6; ++i)
		{
			own.insert(std::pair<int, int>(sum, sum));
			real.insert(std::pair<int, int>(sum, sum));
			sum += 1;
		}

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());

		std::map<int, int>::iterator	real_it = real.begin();
		ft::map<int, int>::iterator		own_it = own.begin();

		while (own_it != own.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}

		std::map<int, int>	real2;
		ft::map<int, int>	own2;

		own2 = own;
		real2 = real;

		REQUIRE(own2.size() == real2.size());
		REQUIRE(own2.empty() == real2.empty());

		real_it = real2.begin();
		own_it = own2.begin();
		while (own_it != own2.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: Iterator begin", "[Map]")
	{
		ft::map<int, int>	own;
		std::map<int, int>	real;

		int sum = 1;
		for (int i = 0; i < 6; ++i)
		{
			own.insert(std::pair<int, int>(sum, sum));
			real.insert(std::pair<int, int>(sum, sum));
			sum += 1;
		}

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());

		std::map<int, int>::iterator	real_it = real.begin();
		ft::map<int, int>::iterator		own_it = own.begin();

		while (own_it != own.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: Iterator end", "[Map]")
	{
		ft::map<int, int>	own;
		std::map<int, int>	real;

		int sum = 1;
		int random = 1;
		for (int i = 0; i < 6; ++i)
		{
			own.insert(std::pair<int, int>(random, sum));
			real.insert(std::pair<int, int>(random, sum));
			sum += 1;
			random % 2 == 0 ? random += 4 : random *= 2;
		}

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());

		std::map<int, int>::iterator	real_it = real.begin();
		ft::map<int, int>::iterator		own_it = own.begin();

		while (own_it != own.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}

		std::map<int, int>::iterator	real_ite = real.end();
		ft::map<int, int>::iterator		own_ite = own.end();

		--real_ite;
		--own_ite;
		--real_ite;
		--own_ite;
		own_it = own.begin();
		real_it = real.begin();
		while (real_it != real_ite)
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: Iterator rbegin", "[Map]")
	{
		ft::map<int, int>	own;
		std::map<int, int>	real;

		int sum = 1;
		for (int i = 0; i < 6; ++i)
		{
			own.insert(std::pair<int, int>(sum, sum));
			real.insert(std::pair<int, int>(sum, sum));
			sum += 1;
		}

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());

		std::map<int, int>::reverse_iterator	real_it = real.rbegin();
		ft::map<int, int>::reverse_iterator		own_it = own.rbegin();
		++real_it;
		++own_it;
		REQUIRE(real_it->first == own_it->first);
		REQUIRE(real_it->second == own_it->second);

		while (own_it != own.rend())
		{

			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: Iterator rend", "[Map]")
	{
		ft::map<int, int>	own;
		std::map<int, int>	real;

		int sum = 1;
		int random = 1;
		for (int i = 0; i < 6; ++i)
		{
			own.insert(std::pair<int, int>(random, sum));
			real.insert(std::pair<int, int>(random, sum));
			sum += 1;
			random % 2 == 0 ? random += 4 : random *= 2;
		}

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());

		std::map<int, int>::reverse_iterator	real_it = real.rbegin();
		ft::map<int, int>::reverse_iterator		own_it = own.rbegin();
		while (own_it != own.rend())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}

		std::map<int, int>::reverse_iterator	real_ite = real.rend();
		ft::map<int, int>::reverse_iterator		own_ite = own.rend();
//		std::cerr << "wat is de waarde hiervan?" << own_ite->first << std::endl;
//		std::cerr <<"value is " << own_it->first << std::endl;
//		std::cerr <<"real value is " << real_it->first << std::endl;
		--real_ite;
		--own_ite;
//		std::cerr <<"value is " << &own_it->first << std::endl;
//		std::cerr <<"real value is " << &real_it->first << std::endl;
		--real_ite;
		--own_ite;
//		std::cerr <<"value is " << own_it->first << std::endl;
//		std::cerr <<"real value is " << real_it->first << std::endl;
		own_it = own.rbegin();
		real_it = real.rbegin();
		while (real_it != real_ite)
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: empty", "[Map]")
	{
		ft::map<std::string, int>	own;
		std::map<std::string, int>	real;

		REQUIRE(own.empty() == real.empty());

		own.insert(std::pair<std::string, int>("test", 1));
		real.insert(std::pair<std::string, int>("test", 1));

		REQUIRE(own.empty() == real.empty());
	}

	TEST_CASE("Map: size", "[Map]")
	{
		ft::map<std::string, int>	own;
		std::map<std::string, int>	real;

		own.insert(std::pair<std::string, int>("try", 1));
		own.insert(std::pair<std::string, int>("to", 1));
		own.insert(std::pair<std::string, int>("do", 1));
		own.insert(std::pair<std::string, int>("this", 1));

		real.insert(std::pair<std::string, int>("try", 1));
		real.insert(std::pair<std::string, int>("to", 1));
		real.insert(std::pair<std::string, int>("do", 1));
		real.insert(std::pair<std::string, int>("this", 1));

		REQUIRE(own.size() == real.size());

		std::map<std::string, int>::iterator	real_it = real.begin();
		ft::map<std::string, int>::iterator		own_it = own.begin();

		while (own_it != own.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}

		own.erase("try");
		real.erase("try");

		REQUIRE(own.size() == real.size());

		own.erase("to");
		real.erase("to");

		REQUIRE(own.size() == real.size());

		own.erase("do");
		real.erase("do");

		REQUIRE(own.size() == real.size());

		own.erase("this");
		real.erase("this");

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());
	}

	TEST_CASE("Map: Operator[]", "[Map]")
	{
		std::map<char, int> sysfirst;
		sysfirst['a'] = 10;
		sysfirst['b'] = 30;
		sysfirst['c'] = 50;
		sysfirst['d'] = 70;

		ft::map<char, int> myfirst;
		myfirst['a'] = 10;
		myfirst['b'] = 30;
		myfirst['c'] = 50;
		myfirst['d'] = 50;

		REQUIRE(myfirst.size() == sysfirst.size());
		ft::map<char,std::string> 	own;
		std::map<char,std::string> 	real;


		own['a'] = "an element";
		own['b'] = "another element";
		own['c'] = own['b'];
		real['a'] = "an element";
		real['b'] = "another element";
		real['c'] = real['b'];

		REQUIRE(own.size() == real.size());

		std::map<char, std::string>::iterator		real_it = real.begin();
		ft::map<char, std::string>::iterator		own_it = own.begin();

		while (own_it != own.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: Insert", "[Map]")
	{
		SECTION("Insert one")
		{
			ft::map<char,int>	own;
			std::map<char,int>	real;


			// first insert function version (single parameter):
			own.insert ( std::pair<char,int>('a',100) );
			own.insert ( std::pair<char,int>('z',200) );
			real.insert ( std::pair<char,int>('a',100) );
			real.insert ( std::pair<char,int>('z',200) );

			std::pair<ft::map<char,int>::iterator,bool> own_ret;
			std::pair<std::map<char,int>::iterator,bool> real_ret;

			own_ret = own.insert ( std::pair<char,int>('z',500) );
			real_ret = real.insert ( std::pair<char,int>('z',500) );

			REQUIRE(own_ret.second == real_ret.second);

			std::map<char, int>::iterator		real_it = real.begin();
			ft::map<char, int>::iterator		own_it = own.begin();

			REQUIRE(own.size() == real.size());
			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}
		}

		SECTION("Insert with hint")
		{
			ft::map<char,int>	own;
			std::map<char,int>	real;


			// first insert function version (single parameter):
			own.insert ( std::pair<char,int>('a',100) );
			own.insert ( std::pair<char,int>('z',200) );
			real.insert ( std::pair<char,int>('a',100) );
			real.insert ( std::pair<char,int>('z',200) );

			std::pair<ft::map<char,int>::iterator,bool> own_ret;
			std::pair<std::map<char,int>::iterator,bool> real_ret;

			own_ret = own.insert ( std::pair<char,int>('z',500) );
			real_ret = real.insert ( std::pair<char,int>('z',500) );

			REQUIRE(own_ret.second == real_ret.second);


			std::map<char, int>::iterator		real_it = real.begin();
			ft::map<char, int>::iterator		own_it = own.begin();

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}

			// second insert function version (with hint position):
			real_it = real.begin();
			own_it = own.begin();

			std::map<char, int>::iterator		real_it_return;
			ft::map<char, int>::iterator		own_it_return;

			own.insert(own_it, std::pair<char,int>('b',300));
			own_it_return = own.insert(own_it, std::pair<char,int>('c',400));
			real.insert(real_it, std::pair<char,int>('b',300));
			real_it_return = real.insert(real_it, std::pair<char,int>('c',400));

			REQUIRE(own.size() == real.size());
			REQUIRE(own_it_return->first == real_it_return->first);
			REQUIRE(own_it_return->second == real_it_return->second);

			real_it = real.begin();
			own_it = own.begin();

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}
		}

		SECTION("Insert Range")
		{
			ft::map<char,int>	own;
			std::map<char,int>	real;


			// first insert function version (single parameter):
			own.insert( std::pair<char,int>('a',100) );
			own.insert( std::pair<char,int>('z',200) );
			real.insert( std::pair<char,int>('a',100) );
			real.insert( std::pair<char,int>('z',200) );

			std::pair<ft::map<char,int>::iterator,bool> own_ret;
			std::pair<std::map<char,int>::iterator,bool> real_ret;

			own_ret = own.insert ( std::pair<char,int>('z',500) );
			real_ret = real.insert ( std::pair<char,int>('z',500) );

			REQUIRE(own_ret.second == real_ret.second);

			std::map<char, int>::iterator		real_it = real.begin();
			ft::map<char, int>::iterator		own_it = own.begin();

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}

			// second insert function version (with hint position):
			real_it = real.begin();
			own_it = own.begin();

			std::map<char, int>::iterator		real_it_return;
			ft::map<char, int>::iterator		own_it_return;

			own.insert(own_it, std::pair<char,int>('b',300));
			own_it_return = own.insert(own_it, std::pair<char,int>('c',400));
			real.insert(real_it, std::pair<char,int>('b',300));
			real_it_return = real.insert(real_it, std::pair<char,int>('c',400));

			REQUIRE(own.size() == real.size());
			REQUIRE(own_it_return->first == real_it_return->first);
			REQUIRE(own_it_return->second == real_it_return->second);

			real_it = real.begin();
			own_it = own.begin();

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}

			// third insert function version (range insertion):
			ft::map<char,int> own2;
			std::map<char,int> real2;

			// case where a key_value already exists
			own2.insert( std::pair<char,int>('a',100) );
			real2.insert( std::pair<char,int>('a',100) );

			// own2.insert(own.begin(), own.find('c'));
			own2.insert(own.begin(), own.find('c'));
			real2.insert(real.begin(), real.find('c'));

			real_it = real2.begin();
			own_it = own2.begin();

			REQUIRE(own2.size() == real2.size());

			while (own_it != own2.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}
		}
	}

	TEST_CASE("Map: Erase", "[Map]")
	{
		SECTION("Erase one")
		{
			ft::map<char,int> own;
			std::map<char,int> real;

			std::map<char, int>::iterator		real_it;
			ft::map<char, int>::iterator		own_it;

			// insert some values:
			own['a'] = 10;
			own['b'] = 20;
			own['c'] = 30;
			own['d'] = 40;
			own['e'] = 50;
			own['f'] = 60;

			real['a'] = 10;
			real['b'] = 20;
			real['c'] = 30;
			real['d'] = 40;
			real['e'] = 50;
			real['f'] = 60;

			own_it = own.find('b');
			real_it = real.find('b');
			own.erase(own_it);                   // erasing by iterator
			real.erase(real_it);                   // erasing by iterator

			real_it = real.begin();
			own_it = own.begin();

			REQUIRE(own.size() == real.size());

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}
		}

		SECTION("Erase with hint")
		{
			ft::map<int, int>	own;
			std::map<int, int>	real;

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			// Delete only root
			own.insert(std::pair<int, int>(6, 8));
			real.insert(std::pair<int, int>(6, 8));

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			own.erase(6);
			real.erase(6);

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			// Delete root with one right child
			own.insert(std::pair<int, int>(6, 8));
			own.insert(std::pair<int, int>(10, 8));
			real.insert(std::pair<int, int>(6, 8));
			real.insert(std::pair<int, int>(10, 8));

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			own.erase(6);
			real.erase(6);

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());
			own.erase(10);
			real.erase(10);

			// Delete root with one left Child
			own.insert(std::pair<int, int>(6, 8));
			real.insert(std::pair<int, int>(6, 8));
			own.insert(std::pair<int, int>(4, 8));
			real.insert(std::pair<int, int>(4, 8));

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			own.erase(6);
			real.erase(6);

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());
			own.erase(4);
			real.erase(4);

			// Delete Root with 2 children
			own.insert(std::pair<int, int>(15, 15));
			own.insert(std::pair<int, int>(10, 10));
			own.insert(std::pair<int, int>(20, 20));
			own.insert(std::pair<int, int>(5, 5));
			own.insert(std::pair<int, int>(19, 19));
			own.insert(std::pair<int, int>(25, 25));
			own.insert(std::pair<int, int>(13, 13));

			real.insert(std::pair<int, int>(15, 15));
			real.insert(std::pair<int, int>(10, 10));
			real.insert(std::pair<int, int>(20, 20));
			real.insert(std::pair<int, int>(5, 5));
			real.insert(std::pair<int, int>(19, 19));
			real.insert(std::pair<int, int>(25, 25));
			real.insert(std::pair<int, int>(13, 13));

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());
			own.erase(6);
			real.erase(6);

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			// Delete a Leaf Node Max
			own.erase(25);
			real.erase(25);
			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			// Delete a Leaf Node Min
			own.erase(5);
			real.erase(5);
			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			// Delete with only one Son and is the Min Node
			own.erase(10);
			real.erase(10);

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			// Delete with only one Son and is the Max Node
			own.erase(20);
			real.erase(20);

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());

			own.insert(std::pair<int, int>(15, 15));
			own.insert(std::pair<int, int>(10, 10));
			own.insert(std::pair<int, int>(20, 20));
			own.insert(std::pair<int, int>(5, 5));
			own.insert(std::pair<int, int>(19, 19));
			own.insert(std::pair<int, int>(25, 25));
			own.insert(std::pair<int, int>(13, 13));

			real.insert(std::pair<int, int>(15, 15));
			real.insert(std::pair<int, int>(10, 10));
			real.insert(std::pair<int, int>(20, 20));
			real.insert(std::pair<int, int>(5, 5));
			real.insert(std::pair<int, int>(19, 19));
			real.insert(std::pair<int, int>(25, 25));
			real.insert(std::pair<int, int>(13, 13));

			// Delete a node which has two sons
			own.erase(20);
			real.erase(20);

			REQUIRE(own.size() == real.size());
			REQUIRE(own.empty() == real.empty());
		}

		SECTION("Erase range")
		{
			ft::map<char,int> own;
			std::map<char,int> real;

			std::map<char, int>::iterator		real_it;
			ft::map<char, int>::iterator		own_it;

			// insert some values:
			own['a'] = 10;
			own['b'] = 20;
			own['c'] = 30;
			own['d'] = 40;
			own['e'] = 50;
			own['f'] = 60;

			real['a'] = 10;
			real['b'] = 20;
			real['c'] = 30;
			real['d'] = 40;
			real['e'] = 50;
			real['f'] = 60;

			own_it = own.find('b');
			real_it = real.find('b');
			own.erase(own_it);                   // erasing by iterator
			real.erase(real_it);                   // erasing by iterator

			real_it = real.begin();
			own_it = own.begin();

			REQUIRE(own.size() == real.size());

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}

			own_it = own.find ('e');
			real_it = real.find('e');
			own.erase ( own_it, own.end() );    // erasing by range
			real.erase ( real_it, real.end() );    // erasing by range

			real_it = real.begin();
			own_it = own.begin();

			REQUIRE(own.size() == real.size());

			while (own_it != own.end())
			{
				REQUIRE(own_it->first == real_it->first);
				REQUIRE(own_it->second == real_it->second);
				++own_it;
				++real_it;
			}
		}
	}

	TEST_CASE("Map: Swap", "[Map]")
	{
		ft::map<char,int> own;
		ft::map<char,int> own2;
		ft::map<char,int> own3;

		std::map<char,int> real;
		std::map<char,int> real2;
		std::map<char,int> real3;

		own['x']=100;
		own['y']=200;

		own2['a']=11;
		own2['b']=22;
		own2['c']=33;

		real['x']=100;
		real['y']=200;

		real2['a']=11;
		real2['b']=22;
		real2['c']=33;

		own.swap(own2);
		real.swap(real2);

		REQUIRE(own.size() == real.size());

		std::map<char, int>::iterator		real_it = real.begin();
		ft::map<char, int>::iterator		own_it = own.begin();

		while (own_it != own.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: Clear", "[Map]")
	{
		std::map<char,int>	real;
		ft::map<char,int>	own;


		own['x'] = 100;
		own['y'] = 200;
		own['z'] = 300;

		real['x'] = 100;
		real['y'] = 200;
		real['z'] = 300;

		REQUIRE(own.size() == real.size());

		std::map<char, int>::iterator		real_it = real.begin();
		ft::map<char, int>::iterator		own_it = own.begin();

		while (own_it != own.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}

		own.clear();
		real.clear();

		own['a'] = 1101;
		own['b'] = 2202;

		real['a'] = 1101;
		real['b'] = 2202;

		REQUIRE(own.size() == real.size());

		real_it = real.begin();
		own_it = own.begin();

		while (own_it != own.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: Key_compare", "[Map]")
	{
		ft::map<char,int> own;
		std::map<char,int> real;

		ft::map<char,int>::key_compare own_compare = own.key_comp();
		std::map<char,int>::key_compare real_compare = real.key_comp();

		own['a'] = 100;
		own['b'] = 200;
		own['c'] = 300;

		real['a'] = 100;
		real['b'] = 200;
		real['c'] = 300;
		char highest_own = own.rbegin()->first;     // key value of last element
		char highest_real = real.rbegin()->first;     // key value of last element

		REQUIRE(own_compare(own.begin()->first, highest_own) == real_compare(real.begin()->first, highest_real) );
	}

	TEST_CASE("Map: Value_compare", "Map")
{
	std::map<char, int> real1;
	ft::map<char, int> mine1;

	int n = 1001;
	char c = 'x';
	for (int i = 0; i < 3; ++i, ++c, n += 1001) {
		real1[c] = n;
		mine1[c] = n;
	}
	REQUIRE(mine1 == real1);

	std::pair<char, int> realHigh(*real1.rbegin());
	std::pair<char, int> myHigh(*mine1.rbegin());

	auto realIt = real1.begin();
	auto myIt = mine1.begin();
	while (real1.value_comp()(*realIt++, realHigh) && mine1.value_comp()(*myIt++, myHigh)) {
		REQUIRE(realIt->first == myIt->first);
		REQUIRE(realIt->second == myIt->second);
	}
}

	TEST_CASE("Map: Find", "[Map]")
	{
		ft::map<char,int> own;
		std::map<char,int> real;

		ft::map<char,int>::iterator own_it;
		std::map<char,int>::iterator real_it;

		own['a'] = 50;
		own['b'] = 100;
		own['c'] = 150;
		own['d'] = 1233;
		own['e'] = 533;
		own['f'] = 1876;
		own['g'] = 1928;
		own['h'] = 4887;

		real['a'] = 50;
		real['b'] = 100;
		real['c'] = 150;
		real['d'] = 1233;
		real['e'] = 533;
		real['f'] = 1876;
		real['g'] = 1928;
		real['h'] = 4887;

		own_it = own.find('b');
		real_it = real.find('b');
		if (own_it != own.end() && real_it != real.end())
		{
			real.erase(real_it);
			own.erase(own_it);
		}
		own_it = own.find('f');
		real_it = real.find('f');

		own.erase(own_it, own.end());
		real.erase(real_it, real.end());

		real_it = real.begin();
		own_it = own.begin();

		REQUIRE(own.size() == real.size());

		while (real_it != real.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}
	}

	TEST_CASE("Map: Count", "[Map]")
	{
		ft::map<char,int> own;
		std::map<char,int> real;

		own['a'] = 50;
		own['b'] = 100;
		own['c'] = 150;
		own['d'] = 1233;
		own['e'] = 533;
		own['f'] = 1876;
		own['g'] = 1928;
		own['h'] = 4887;

		real['a'] = 50;
		real['b'] = 100;
		real['c'] = 150;
		real['d'] = 1233;
		real['e'] = 533;
		real['f'] = 1876;
		real['g'] = 1928;
		real['h'] = 4887;

		ft::map<char,int>::iterator own_it = own.begin();
		std::map<char,int>::iterator real_it = real.begin();

		REQUIRE(own.size() == real.size());

		while (real_it != real.end())
		{
			REQUIRE(own_it->first == real_it->first);
			REQUIRE(own_it->second == real_it->second);
			++own_it;
			++real_it;
		}

		REQUIRE(own.count('a') == real.count('a'));
		REQUIRE(own.count('b') == real.count('b'));

		own_it = own.find('b');
		real_it = real.find('b');

		if (own_it != own.end() && real_it != real.end())
		{
			real.erase(real_it);
			own.erase(own_it);
		}

		REQUIRE(own.count('b') == real.count('b'));
		REQUIRE(own.count('z') == real.count('z'));
	}

	TEST_CASE("Map: Lower_bound", "[Map]")
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		REQUIRE(itlow->first == 'b');
		REQUIRE(itup->first == 'e');
	}


	TEST_CASE("Map: Equal_range", "[Map]")
	{
		std::map<char,int>	real;
		ft::map<char,int>	own;


		own['a'] = 20;
		own['b'] = 40;
		own['c'] = 60;
		own['d'] = 80;
		own['e'] = 100;

		real['a'] = 20;
		real['b'] = 40;
		real['c'] = 60;
		real['d'] = 80;
		real['e'] = 100;

		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator>	real_ret;
		std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator>		own_ret;

		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator>	real_ret_const;
		std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator>		own_ret_const;

		own_ret = own.equal_range('b');
		real_ret = real.equal_range('b');

		REQUIRE(own_ret.first->first == real_ret.first->first);
		REQUIRE(own_ret.first->second == real_ret.first->second);
		REQUIRE(own_ret.second->first == real_ret.second->first);
		REQUIRE(own_ret.second->second == real_ret.second->second);


		real_ret_const = real.equal_range('d');
		own_ret_const = own.equal_range('d');

		REQUIRE(own_ret_const.first->first == real_ret_const.first->first);
		REQUIRE(own_ret_const.first->second == real_ret_const.first->second);
		REQUIRE(own_ret_const.second->first == real_ret_const.second->first);
		REQUIRE(own_ret_const.second->second == real_ret_const.second->second);

		own.erase('b');
		real.erase('b');

		own_ret = own.equal_range('b');
		real_ret = real.equal_range('b');

		REQUIRE(own_ret.first->first == real_ret.first->first);
		REQUIRE(own_ret.first->second == real_ret.first->second);
		REQUIRE(own_ret.second->first == real_ret.second->first);
		REQUIRE(own_ret.second->second == real_ret.second->second);
	}
