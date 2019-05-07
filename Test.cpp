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
#include "calculate.hpp"
using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
		
	
		ConstantChooser c2345{"2345"}, c23456{"23456"}, c88888{"88888"},c8888{"8888"};
		ConstantGuesser g2345{"2345"}, g23456{"23456"}, g88888{"88888"},g8888{"8888"};

		testcase.setname("calculateBullAndPgia - our tests")

				//length exceptions
			//	.CHECK_THROWS(calculateBullAndPgia("234", "23456"))
				//.CHECK_THROWS(calculateBullAndPgia("2", "23"))
				
				//all digit are in the guesse
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "64532"), "0,5")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "23456"), "5,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "32546"), "1,4")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "23452"), "4,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "34561"), "0,4")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "25346"), "2,3")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "23546"), "3,2")
				
				
				//with digits are not in the guesse
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "17890"), "0,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "78950"), "1,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "78269"), "0,2")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "13487"), "2,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "34687"), "0,3")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "23489"), "3,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "82734"), "0,3")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "73456"), "4,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "34567"), "0,4")


				//Repeated digit in the guesse
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "22222"), "1,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "33333"), "1,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "44444"), "1,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "55555"), "1,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "66666"), "1,0")
				
				//Repeated digit not in the guesse
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "11111"), "0,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "77777"), "0,0")
				.CHECK_OUTPUT(calculateBullAndPgia("23456", "88888"), "0,0")
				
				
				.CHECK_OUTPUT(calculateBullAndPgia("1113", "1111"), "3,0")
				.CHECK_OUTPUT(calculateBullAndPgia("1113", "3113"), "3,0")
				.CHECK_OUTPUT(calculateBullAndPgia("1113", "3331"), "0,2")
				
				.CHECK_OUTPUT(calculateBullAndPgia("1211", "1111"), "3,0")
				.CHECK_OUTPUT(calculateBullAndPgia("1211", "2222"), "1,0")
				.CHECK_OUTPUT(calculateBullAndPgia("1211", "2111"), "2,2")
				.CHECK_OUTPUT(calculateBullAndPgia("1211", "2112"), "1,2")
				.CHECK_OUTPUT(calculateBullAndPgia("1211", "2221"), "2,0")
				.CHECK_OUTPUT(calculateBullAndPgia("1211", "1112"), "2,2");

				
				
				
				testcase.setname("TEST of play dummy chosser and gussers - our tests")
				.CHECK_EQUAL(play(c2345, g2345, 4, 100), 1)      // guesser wins in one turn.
				.CHECK_EQUAL(play(c1234, g8888, 4, 100), 101)    // guesser loses by running out of turns
			//	.CHECK_EQUAL(play(c23456, g88888, 4, 100), 101)    // guesser loses by running out of turns				
				.CHECK_EQUAL(play(c1234, g23456, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
				.CHECK_EQUAL(play(c1234, g88888, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
				.CHECK_EQUAL(play(c8888, g88888, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
				.CHECK_EQUAL(play(c8888, g23456, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
				.CHECK_EQUAL(play(c23456, g2345, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
				.CHECK_EQUAL(play(c23456, g8888, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
				.CHECK_EQUAL(play(c88888, g2345, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
				.CHECK_EQUAL(play(c88888, g8888, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
				;
		

			testcase.setname("TEST of play smart gusser - our tests");
			RandomChooser rand;
			SmartGuesser smart;
			for (uint i=0; i<50; ++i) {
				testcase.CHECK_EQUAL(play(rand, smart, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
			}
			
			for (uint i=0; i<50; ++i) {
				testcase.CHECK_EQUAL(play(rand, smart, 4, 100)>100, false);  // see if smarty win in at most 10 turns
			}
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}