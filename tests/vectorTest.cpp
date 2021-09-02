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
		ft::vector<int>		own(6, 100);
		std::vector<int>	real(6, 100);

		ft::vector<int>		own2(own.begin(), own.end());
		std::vector<int>	real2(real.begin(), real.end());

		REQUIRE(own2.size() == real2.size());
		REQUIRE(own2[0] ==  real2[0]);
		REQUIRE(own2[1] == real2[1]);

		own.clear();
		real.clear();
		int sum = 0;
		for (int i = 0; i < 5; ++i)
		{
			own.push_back(sum);
			real.push_back(sum);
			sum += 1;
		}
		own.pop_back();
		real.pop_back();

		ft::vector<int> 	own3(own.begin() + 1, own.end());
		std::vector<int>	real3(real.begin() + 1, real.end());

		REQUIRE(own3.size() == real3.size());
		REQUIRE(own3[0] == real3[0]);
		REQUIRE(own3[1] == real3[1]);
	
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

		ft::vector<int> 	own1(5, 5);
		std::vector<int> 	real1(5, 5);

		ft::vector<int> 	own2(own1);
		std::vector<int> 	real2(real1);

		REQUIRE(own2.size() == real2.size());
		REQUIRE(own2[2] == real2[2]);
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

		ft::vector<std::string>::const_iterator myconstit = myconstvector.begin();
		std::vector<std::string>::const_iterator sysconstit = sysconstvector.begin();

		REQUIRE(*myconstit == *sysconstit);
		ft::vector<int> 	own(4, 3);
		std::vector<int> 	real(4, 3);

		ft::vector<int>::iterator own_it = own.begin();
		std::vector<int>::iterator real_it = real.begin();

		REQUIRE(*own_it == *real_it);

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

		ft::vector<int> 	own(4, 3);
		std::vector<int> 	real(4, 3);

		ft::vector<int>::const_iterator own_ite = own.end();
		std::vector<int>::const_iterator real_ite = real.end();

		own_ite--;
		real_ite--;
		REQUIRE(*own_ite == *real_ite);
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

		int sum = 0;
		ft::vector<int>		own(5);
		std::vector<int>	real(5);

		for(int i = 0; i < 5; i++)
		{
			real.at(i) = sum;
			own.at(i) = sum;
			sum += 1;
		}

		ft::vector<int>::reverse_iterator own_rit = own.rbegin();
		ft::vector<int>::reverse_iterator old_own_rit;
		std::vector<int>::reverse_iterator real_rit = real.rbegin();
		std::vector<int>::reverse_iterator old_real_rit;

		++own_rit;
		++real_rit;
		REQUIRE(*own_rit == *real_rit);

		old_own_rit = own_rit++;
		old_real_rit = real_rit++;
		REQUIRE(*old_real_rit == *old_own_rit);
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
		int sum = 0;
		ft::vector<int>		own(5);
		std::vector<int>	real(5);

		for(int i = 0; i < 5; i++)
		{
			real.at(i) = sum;
			own.at(i) = sum;
			sum += 1;
		}

		ft::vector<int>::const_reverse_iterator own_rit = own.rbegin();
		ft::vector<int>::const_reverse_iterator old_own_rit;
		std::vector<int>::const_reverse_iterator real_rit = real.rbegin();
		std::vector<int>::const_reverse_iterator old_real_rit;

		++own_rit;
		++real_rit;
		REQUIRE(*own_rit == *real_rit);

		old_own_rit = own_rit++;
		old_real_rit = real_rit++;
		REQUIRE(*old_real_rit == *old_own_rit);
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
		int sum = 0;
		ft::vector<int>		own(5);
		std::vector<int>	real(5);

		for(int i = 0; i < 5; i++)
		{
			real.at(i) = sum;
			own.at(i) = sum;
			sum += 1;
		}

		ft::vector<int>::reverse_iterator own_rite = own.rend();
		ft::vector<int>::reverse_iterator old_own_rite;
		std::vector<int>::reverse_iterator real_rite = real.rend();
		std::vector<int>::reverse_iterator old_real_rite;

		--own_rite;
		--real_rite;
		REQUIRE(*own_rite == *real_rite);

		old_own_rite = own_rite--;
		old_real_rite = real_rite--;
		REQUIRE(*old_real_rite == *old_own_rite);
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

		int sum = 0;
		ft::vector<int>		own(5);
		std::vector<int>	real(5);

		for(int i = 0; i < 5; i++)
		{
			real.at(i) = sum;
			own.at(i) = sum;
			sum += 1;
		}

		ft::vector<int>::const_reverse_iterator own_rite = own.rend();
		ft::vector<int>::const_reverse_iterator old_own_rite;
		std::vector<int>::const_reverse_iterator real_rite = real.rend();
		std::vector<int>::const_reverse_iterator old_real_rite;

		--own_rite;
		--real_rite;
		REQUIRE(*own_rite == *real_rite);

		old_own_rite = own_rite--;
		old_real_rite = real_rite--;
		REQUIRE(*old_real_rite == *old_own_rite);
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

		ft::vector<int> 	own(8, 5);
		std::vector<int> 	real(8, 5);

		own.resize(2, 2);
		real.resize(2, 2);

		REQUIRE(own.size() == real.size());
		REQUIRE(own[1] == real[1]);

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

		int sum = 0;
		ft::vector<int>		own(5);
		std::vector<int>	real(5);

		for(int i = 0; i < 5; i++)
		{
			real[i] = sum;
			own[i] = sum;
			sum += 1;
		}
		REQUIRE(own[0] == real[0]);
		REQUIRE(own[1] == real[1]);
		REQUIRE(own[2] == real[2]);
		REQUIRE(own[3] == real[3]);
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

		int sum = 0;
		ft::vector<int>		own(5);
		std::vector<int>	real(5);

		for(int i = 0; i < 5; i++)
		{
			real.at(i) = sum;
			own.at(i) = sum;
			sum += 1;
		}
		REQUIRE(own.at(0) == real.at(0));
		REQUIRE(own.at(1) == real.at(1));
		REQUIRE(own.at(2) == real.at(2));
		REQUIRE(own.at(3) == real.at(3));
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

		int sum = 0;
		ft::vector<int>		own(5);
		std::vector<int>	real(5);

		for(int i = 0; i < 5; i++)
		{
			real.at(i) = sum;
			own.at(i) = sum;
			sum += 1;
		}

		REQUIRE(own.front() == real.front());
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

		int sum = 0;
		ft::vector<int>		own(5);
		std::vector<int>	real(5);

		for(int i = 0; i < 5; i++)
		{
			real.at(i) = sum;
			own.at(i) = sum;
			sum += 1;
		}

		REQUIRE(own.back() == real.back());
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

		ft::vector<int>		own1(5, 100);
		ft::vector<int>		own2;
		std::vector<int>	real1(5, 100);
		std::vector<int>	real2;

		own2.assign(own1.begin(), own1.begin() + 3);
		real2.assign(real1.begin(), real1.begin() + 3);

		ft::vector<int>::iterator own_it = own2.begin();
		std::vector<int>::iterator real_it = real2.begin();

		REQUIRE(own2.size() == real2.size());
		while (own_it != own2.end())
		{
			REQUIRE(*own_it == *real_it);
			++own_it;
			++real_it;
		}

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

		ft::vector<int>		own;
		std::vector<int>	real;

		int sum = 10;
		for(int i = 0; i < 4; ++i)
		{
			own.push_back(sum);
			real.push_back(sum);
			sum += 10;
		}
		REQUIRE(own[0] == real[0]);
		REQUIRE(own[1] == real[1]);
		REQUIRE(own[2] == real[2]);
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

		int sum = 10;
		ft::vector<int>		own;
		std::vector<int>	real;

		for(int i = 0; i < 4; ++i)
		{
			own.push_back(sum);
			real.push_back(sum);
			sum += 10;
		}
		REQUIRE(own.size() == real.size());
		own.pop_back();
		real.pop_back();
		REQUIRE(own.size() == real.size());
		REQUIRE(own[2] == real[2]);
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

	SECTION("INSERT TRY ALL")
	{
		ft::vector<int>		own(6, 100);
		std::vector<int>	real(6, 100);

		ft::vector<int>::iterator	it_own = own.begin();
		std::vector<int>::iterator	it_real = real.begin();

		it_own = own.insert(it_own, 200);
		it_real = real.insert(it_real, 200);
		//  200 100 100 100 100 100 100
		//  ^
		REQUIRE(*it_own == *it_real);

		own.insert(it_own, 2, 300);
		real.insert(it_real, 2, 300);
		// 300 300 200 100 100 100 100 100 100
		// ^   ^

		REQUIRE(own[0] == real[0]);
		REQUIRE(own[1] == real[1]);

		ft::vector<int> 	own1(2, 400);
		std::vector<int>	real2(2, 400);

		it_own = own.begin();
		it_real = real.begin();

		own.insert(it_own + 2, own1.begin(), own1.end());
		real.insert(it_real + 2, real2.begin(), real2.end());
		// 300 300 400 400 200 100 100 100 100 100 100
		//         ^   ^
		REQUIRE(own[2] == real[2]);
		REQUIRE(own[3] == real[3]);

		int myarray[] = {101, 102, 103};

		it_own = ft::vector<int>::iterator(myarray);

		own.insert(own.begin(), it_own, it_own + 3);
		real.insert(real.begin(), myarray, myarray + 3);
		// 101 102 103 300 300 400 400 200 100 100 100 100 100 100
		// ^   ^   ^
		REQUIRE(own[0] == real[0]);
		REQUIRE(own[1] == real[1]);
		REQUIRE(own[2] == real[2]);
		REQUIRE(own.size() == real.size());

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

		ft::vector<int> 	own(4, 100);
		ft::vector<int> 	own2(5, 300);
		ft::vector<int>		own3;
		std::vector<int> 	real(4, 100);
		std::vector<int>	real2(5, 300);
		std::vector<int>	real3;

		own.swap(own2);
		real.swap(real2);

		REQUIRE(own.size() == real.size());
		REQUIRE(own.capacity() == real.capacity());
		REQUIRE(own[0] == real[0]);
		REQUIRE(own[1] == real[1]);
		REQUIRE(own[2] == real[2]);

		std::swap(own3, own2);
		std::swap(real3, real2);

		REQUIRE(own3.size() == real3.size());
		REQUIRE(own3.capacity() == real3.capacity());
		REQUIRE(own3[0] == real3[0]);
		REQUIRE(own3[1] == real3[1]);
		REQUIRE(own3[2] == real3[2]);
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

TEST_CASE("Vector: Get allocator")
{
	ft::vector<int>		own;
	std::vector<int>	real;

	int *p_own;
	int *p_real;
	bool own_return = false;
	bool real_return = false;
	unsigned int i_own;
	unsigned int i_real;

	// allocate an array with space for 5 elements using vector's allocator:
	p_own = own.get_allocator().allocate(5);
	p_real = real.get_allocator().allocate(5);

	if (!p_own)
		own_return = false;
	else
		own_return = true;

	if (!p_real)
		real_return = false;
	else
		real_return = true;

	REQUIRE(own_return == real_return);

	// construct values in-place on the array:
	for (i_own = 0; i_own < 5; i_own++) own.get_allocator().construct(&p_own[i_own],i_own);
	for (i_real = 0; i_real < 5; i_real++) real.get_allocator().construct(&p_real[i_real],i_real);

	REQUIRE(p_own[0] == p_real[0]);
	REQUIRE(p_own[1] == p_real[1]);
	REQUIRE(p_own[2] == p_real[2]);
	REQUIRE(p_own[3] == p_real[3]);

	// destroy and deallocate:
	for (i_own = 0; i_own < 3; i_own++) own.get_allocator().destroy(&p_own[i_own]);
	for (i_real = 0; i_real < 3; i_real++) own.get_allocator().destroy(&p_own[i_real]);

	REQUIRE(p_own[0] == p_real[0]);
	REQUIRE(p_own[1] == p_real[1]);

	own.get_allocator().deallocate(p_own,5);
	real.get_allocator().deallocate(p_real,5);

	if (!p_own)
		own_return = false;
	else
		own_return = true;

	if (!p_real)
		real_return = false;
	else
		real_return = true;

	REQUIRE(own_return == real_return);
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
