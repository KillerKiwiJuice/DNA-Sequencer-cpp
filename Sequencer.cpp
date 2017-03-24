/*****************************************
** File:    Sequencer.cpp
** Project: CMSC 202 Project 3, Spring 2017
** Author:  Eoin Fitzpatrick
** Date:    3/15/17
** Section: 19
** E-mail:  efitz1@umbc.edu
**
** Source code for Sequencer class
**
***********************************************/
#include "Sequencer.h"

Sequencer::Sequencer(string filename) {
	m_fileName = filename;
	mainMenu();
}
Sequencer::~Sequencer(void) {
	cout << "DNA removed from memory." << endl;
}
void Sequencer::readFile() {
	ifstream file(m_fileName.c_str());
	for (string line; getline(file, line);) {
		const char * c = line.c_str();
		m_dna.InsertEnd(*c); 
	}
}
void Sequencer::mainMenu() {
	cout << "New sequencer loaded." << endl;
	int choice1 = NULL;
	readFile();
	m_dna.SizeOf();
	while (choice1 != 5) {
		cout << "What would you like to do?\n1. Display Sequencer (leading strand)\n2. Display Sequencer(base pairs)\n"
			+ string("3. Inventory Basic Amino Acids\n4. Sequence Entire DNA Strand\n5. Exit") << endl;
		cin >> choice1;
		while (choice1 > 5 || choice1 < 1) {
			cout << "Invalid input! Enter a number between 1 and 5 (inclusive)." << endl;
			cin >> choice1;
		}
		switch (choice1) {
		case 1: {
			m_dna.Display(1);
			break;
		}
		case 2: {
			m_dna.Display(2);
			break;
		}
		case 3: {
			m_dna.NumAmino("Tryptophan", "TGG");
			m_dna.NumAmino("Phenylalanine", "TTT");
			break;
		}
		case 4: {
			m_dna.Sequence();
			break;
		}
		case 5: {
			break;
		}
		default: {
			break;
		}
		}
	}
}