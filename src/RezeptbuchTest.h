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
#include <vector>
#include <algorithm>
#include "MischbaresRezeptbuch.h"
#include "Rezeptbuch.h"

using namespace std;

class RezeptbuchTest : CppUnit::TestCase {
public:
	RezeptbuchTest();

	virtual ~RezeptbuchTest();
private:
	MischbaresRezeptbuch mischbaresRezeptbuch;
	void testDifference();
	void testRange();
	void testRezepte();
};

#endif /* REZEPTBUCHTEST_H_ */
