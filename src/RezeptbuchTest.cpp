/*
 * RezeptbuchTest.cpp
 *
 *  Created on: 14.05.2014
 *      Author: gugugs
 */

#include <RezeptbuchTest.h>

RezeptbuchTest::RezeptbuchTest() :
		CppUnit::TestCase("mischbaresRezeptbuch") {

	cout << "Tests werden gestartet..." << endl;
	testDifference();
	testRange();
	cout << "Alle Tests sind erfolgreich" << endl;
}

RezeptbuchTest::~RezeptbuchTest() {

}

void RezeptbuchTest::testDifference() {
	CPPUNIT_ASSERT(
			mischbaresRezeptbuch.getRezept(0)->getName() == "Caipirinha");
	CPPUNIT_ASSERT(
			mischbaresRezeptbuch.getRezept(1)->getName() == "Planters Punch");
	CPPUNIT_ASSERT(
			mischbaresRezeptbuch.getRezept(2)->getName() == "Caipiroska");
	CPPUNIT_ASSERT(
			mischbaresRezeptbuch.getRezept(3)->getName() == "Caipirissima");
}

void RezeptbuchTest::testRange() {
	CPPUNIT_ASSERT(mischbaresRezeptbuch.getAnzahlRezepte() == 4);
	CPPUNIT_ASSERT(mischbaresRezeptbuch.getRezept(-1) == NULL);
	CPPUNIT_ASSERT(mischbaresRezeptbuch.getRezept(5) == NULL);
}
