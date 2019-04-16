#pragma once
#include "Chooser.hpp"
using std::string;
using namespace bullpgia;

/**
 * ConstantChooser is a chooser that always chooses the same string. 
 */
class ConstantChooser: public bullpgia::Chooser {
		string myConstantString;
	public:
		ConstantChooser(const string& constantString) { myConstantString = constantString; }
		virtual string choose(uint length) override {
			return myConstantString;
		}
};

/**
 * RandomChooser is a chooser that chooses a random string.
 */
class RandomChooser: public bullpgia::Chooser {
		virtual string choose(uint length) override;
};



