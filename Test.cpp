/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		//BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4");     // 0 bull, 4 pgia
		

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) 
		{
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

		
		////////////////////OUR TESTS////////////////////////////

		ConstantChooser c123{"123"}, c12347{"12347"},c2324{"2324"}, c8888{"8888"}, c123456789{"123456789"},c12{"12"};
		ConstantGuesser g123{"123"}, g12347{"12347"},g3242{"3242"}, g8888{"8888"}, g987654321{"987654321"},g21{"21"};
		

		testcase.setname("OUR Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("2","2"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3","2"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2","2"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2","2"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("24","23"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("245","234"), "1,1")      // 1 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("313","678"), "0,0")		// 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4","26"), "0,0") 		// 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4444","44"), "2,0")       // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("564","456"), "0,3")      // 0 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("245","245"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2451","2451"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2213","1234"), "1,2")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("5517","4321"), "0,1")      // 0 bull, 4 pgia
		;
	
		testcase.setname("OUR Play with dummy choosers and guessers - right lenght")
		.CHECK_EQUAL(play(c123, g123, 3, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c8888, g8888, 4, 100), 101)   
		.CHECK_EQUAL(play(c12, g21, 2, 100), 101)   
		.CHECK_EQUAL(play(c2324, g3242, 4, 100), 65)    
		;
		testcase.setname("OUR Play with dummy choosers and guessers - worng lenght")
		.CHECK_EQUAL(play(c123, g12347, 3, 100), 0)      
		.CHECK_EQUAL(play(c123456789, g987654321, 4, 100), 1)   
		.CHECK_EQUAL(play(c12347, g12347, 2, 100), 101)   
		.CHECK_EQUAL(play(c2324, g123, 4, 100), 101);

		testcase.setname("OUR Play with smart guesser");
		RandomChooser OurRandy1;
		SmartGuesser OurSmarty1;
		for (uint i=0; i<100; ++i) 
		{
			testcase.CHECK_EQUAL(play(OurRandy1, OurSmarty1, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
		
		RandomChooser OurRandy2;
		SmartGuesser OurSmarty2;
		for (uint i=0; i<100; ++i) 
		{
			testcase.CHECK_EQUAL(play(OurRandy2, OurSmarty2, 5, 100)<=100, true);  // smarty should always win in at most 100 turns!
		}		

		
		
	

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}

	cout << "Your grade is: "  << grade << endl;
	return 0;


	///////////MyTest 


		
}

