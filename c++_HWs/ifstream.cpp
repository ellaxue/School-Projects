/*
 * ifstream.cpp
 *
 *  Created on: 2015Äê5ÔÂ21ÈÕ
 *      Author: Ella
 */

/*
 * process_text.cpp
 *
 *  Created on: 2014/5/14
 *      Author: Ella
 */

#include <iostream>
#include <fstream>
using namespace std;

#define NEWLINE_ASCII 0x0A
#define EXCLAMATION_ASCII 0x21
#define SPACE_ASCII 0x20
#define CHANGELINE_ASCII 0x0D

int process_text (char* source_file, char* output_file)
{
	//the count of the characters, initialize to zero
	int char_count = 0;

	//open the source file
	ifstream source_f(source_file, ios::in|ios::binary);
	//check if we opened the file correctly
	if (!source_f.is_open())
	{
		cout << "Error! Cannot open input file" << endl;
		return -1;
	}
	//open the output file
	ofstream output_f(output_file, ios::out|ios::binary);
	//check if we opened the file correctly
	if (!output_f.is_open())
	{
		cout << "Error! Cannot open input file" << endl;
		//close the input file before return
		source_f.close();
		return -1;
	}

	//now start to process the file
	//first initialize a temporary holder to store the byte read from the source file
	char temp=0;
	//we need a counter to count the number of exclamation marks at the end of the line
	int exclamation_count = 0;

	//smiley face
	char smiley[] = ":)";

	while(!source_f.eof())
	{
		//read a byte, and since we need to handle the special characters, we should not use ">>" here
		source_f.read(&temp, 1);
		//output to screen
		cout << temp;
		cout<<"first temp\n";

		//check if this is a newline
		if (NEWLINE_ASCII != temp)
		{
			//increase the byte counter if it's not a newline char
			char_count ++;
		}

		//Note, we only might add smiley face if it's the end of the sentence (either followed by a space or change line)
		if ((SPACE_ASCII == temp) || (CHANGELINE_ASCII == temp))
		{
			//now we need to check how many exclamation marks we have, if we have 2, add a smiley before write to the output file
			if (2 == exclamation_count)
			{
				//two exclamation marks, write a smiley
				output_f.write(&smiley[0], 2);
			}
		}

		//now check if the current char is a exclamation mark
		//Note, we do not want to clear the exclamation_count before check the end of the line
		if (EXCLAMATION_ASCII == temp)
		{
			//if it is a exclamation_count mark, then we increase the counter
			exclamation_count ++;
		}
		else
		{
			//since we need two continuous exclamation marks, if the current char is not a exclamation mark, we reset the counter
			exclamation_count = 0;
		}

		//write the byte to output file
		output_f.write(&temp, 1);
	}


	//close both files before returning
	source_f.close();
	output_f.close();

	return char_count;
}

int main (void)
{
	char input_file[] = "test.txt";
	char output_file[] = "output.txt";
	cout << "------------------------------" << endl << "Total length is " << process_text(input_file, output_file) << " bytes" << endl;
	return 0;
}



