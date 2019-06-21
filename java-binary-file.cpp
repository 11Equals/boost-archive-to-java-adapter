// java-binary-file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "binary_data.hpp"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include <fstream>

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

	Sam::JavaBinaryData::Data data;
	data.test = 1;

	std::string path = "../../test.bin";

	if (false)
	{	// save
		bool result;

		std::ofstream ofs(path, std::ios::binary);

		if (ofs.is_open()) {
			try {
				boost::archive::binary_oarchive oa(ofs);
				oa << data;
				std::cout<< "Saving data\n";
				result = true;
			}
			catch (std::exception e) {
				std::cout << "Error: \n";
					std::cout << e.what();
				result = false;
			}
			ofs.close();
		}
		else {
		std::cout << "Error: Output file is not open\n";
			result = false;
		}

		if (result) {
			std::cout << "Save successful\n";
		}
		else {
			std::cout << "Save failed\n";
		}

		//return result;
	}
	
	if (true)
	{ // load
		data.test = 5000;
		bool result;

		std::ifstream ifs(path);

		if (ifs.is_open()) {
			try {
				std::cout << "Trying to open Boost archive\n";
				boost::archive::binary_iarchive ia(ifs);
				std::cout << "Opened archive--trying to load data into game\n";
				ia >> data;

				std::cout << "Successfully loaded archive\n" << "Value from file: " << data.test << "\n";
				result = true;
			}
			catch (std::exception e) {	// why isn't boost::exception catching? Maybe I have to build it?
				std::cout << "Load exception: \n";
					std::cout << e.what();
				std::cout << "Unknown file format\n";

				result = false;
			}
			catch (boost::exception &e) {
				e;
				std::cout << "Unknown file format\n";

				result = false;
			}
			ifs.close();
		}
		else {
			std::cout << "Can't open file--does it exist?\n";
			result = false;
		}

		if (result) {
			std::cout << "Load successful\n";
		}
		else {
			std::cout << "Load failed\n";
		}
	}

	int pause;
	std::cin >> pause;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
