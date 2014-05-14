/*
 * RezeptbuchTest.h
 *
 *  Created on: 14.05.2014
 *      Author: gugugs
 */

#ifndef REZEPTBUCHTEST_H_
#define REZEPTBUCHTEST_H_

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <string>

using namespace std;

class RezeptbuchTest : CppUnit::TestCase {
public:
	RezeptbuchTest(string name);
	virtual ~RezeptbuchTest();
};

#endif /* REZEPTBUCHTEST_H_ */
