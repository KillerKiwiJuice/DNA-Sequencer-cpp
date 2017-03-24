/*****************************************
** File:    DNA.cpp
** Project: CMSC 202 Project 3, Spring 2017
** Author:  Eoin Fitzpatrick
** Date:    3/15/17
** Section: 19
** E-mail:  efitz1@umbc.edu
**
** Source code for DNA class
**
***********************************************/

#include "DNA.h"
DNA::DNA() {
	m_head = NULL;
	m_tail = NULL;
}
DNA::~DNA() {
	Clear();
}
void DNA::InsertEnd(char payload) {
	// create new link for the DNA chain
	Nucleotide * newNucleotide = new Nucleotide;
	// set values
	newNucleotide->m_payload = payload;
	newNucleotide->m_next = NULL;
	// if the head has no information, set the head equal to the first link in the DNA chain
	if (m_head == NULL) {
		m_head = newNucleotide;
	}
	// if the head already has information, create a new chain
	else {
		// need to start at m_head, so a dummy link is created so that m_head is not overwritten
		Nucleotide * iterator = m_head;
		// traverse through the chain and set each link's value of m_next equal to the next link in the chain. 
		// this loop only runs after InsertEnd() has run twice, because at first, m_head points to null, and secondly we 
		// need to insert a chain between m_head and m_tail (which happens directly under the loop).
		while (iterator->m_next != NULL) {
			iterator = iterator->m_next;
		}
		iterator->m_next = newNucleotide;
	}
}
void DNA::Display(int numStrand) {
	Nucleotide * tmp = m_head;
	// nucleotides only
	if (numStrand == 1) {
		cout << "Base Pairs (Leading strand): " << endl;
		while (tmp != NULL) {
			cout << tmp->m_payload << endl;
			tmp = tmp->m_next;
		}
	}
	// base pairs
	else {
		cout << "Base Pairs:" << endl;
		string pair;
		while (tmp != NULL) {
			if (tmp->m_payload == 'A') {
				pair = "T";
			}
			else if (tmp->m_payload == 'T') {
				pair = "A";
			}
			else if (tmp->m_payload == 'G') {
				pair = "C";
			}
			else if (tmp->m_payload == 'C') {
				pair = "G";
			}
			cout << tmp->m_payload << "-" << pair << endl;
			tmp = tmp->m_next;
		}
	}
	cout << "END" << endl;
	cout << m_size << " nucleotides listed." << endl;
	cout << m_size / 3 << " trinucleotides listed" << endl;
}
void DNA::NumAmino(string name, string trinucleotide) {
	Nucleotide * tmp = m_head;
	int counter = 0;
	string codon = "";
	int numFound = 0;
	while (tmp != NULL) {
		counter++;
		codon += tmp->m_payload;
		if (counter == 3) {
			counter = 0;
			if (codon == trinucleotide) {
				numFound++;
			}
			codon = "";
		}
		tmp = tmp->m_next;
	}
	cout << numFound << " instances of " << name << " found." << endl;
}
void DNA::Sequence() {
	Nucleotide * tmp = m_head;
	int counter = 0;
	string codon = "";
	while (tmp != NULL) {
		counter++;
		codon += tmp->m_payload;
		if (counter == 3) {
			counter = 0;
			cout << Translate(codon) << " found." << endl;
			codon = "";
		}
		tmp = tmp->m_next;
	}
}
bool DNA::IsEmpty() {
	if (m_size < 1) {
		return true;
	}
	else {
		return false;
	}
}
void DNA::SizeOf() {
	Nucleotide * tmp = m_head;
	m_size = 0;
	while (tmp != NULL) {
		m_size++;
		tmp = tmp->m_next;
	}
}
void DNA::Clear() {
	// traversal pointer
	Nucleotide * theTerminator = m_head;
	// while the traversal pointer does not point to NULL (or, m_tail in this case)
	while (theTerminator != NULL) {
		// hold on to the traversal pointer's next address so we can delete that later
		Nucleotide * tmp = theTerminator->m_next;
		// free the memory on the heap
		delete theTerminator;
		// this sets the terminator equal to the next node
		theTerminator = tmp;
	}
}
string DNA::Translate(const string trinucleotide) {
	if ((trinucleotide == "ATT") || (trinucleotide == "ATC") || (trinucleotide == "ATA"))
		return ("Isoleucine");
	else if ((trinucleotide == "CTT") || (trinucleotide == "CTC") || (trinucleotide == "CTA") ||
		(trinucleotide == "CTG") || (trinucleotide == "TTA") || (trinucleotide == "TTG"))
		return ("Leucine");
	else if ((trinucleotide == "GTT") || (trinucleotide == "GTC") ||
		(trinucleotide == "GTA") || (trinucleotide == "GTG"))
		return ("Valine");
	else if ((trinucleotide == "TTT") || (trinucleotide == "TTC"))
		return ("Phenylalanine");
	else if ((trinucleotide == "ATG"))
		return ("Methionine");
	else if ((trinucleotide == "TGT") || (trinucleotide == "TGC"))
		return ("Cysteine");
	else if ((trinucleotide == "GCT") || (trinucleotide == "GCC") ||
		(trinucleotide == "GCA") || (trinucleotide == "GCG"))
		return ("Alanine");
	else if ((trinucleotide == "GGT") || (trinucleotide == "GGC") ||
		(trinucleotide == "GGA") || (trinucleotide == "GGG"))
		return ("Glycine");
	else if ((trinucleotide == "CCT") || (trinucleotide == "CCC") ||
		(trinucleotide == "CCA") || (trinucleotide == "CCG"))
		return ("Proline");
	else if ((trinucleotide == "ACT") || (trinucleotide == "ACC") ||
		(trinucleotide == "ACA") || (trinucleotide == "ACG"))
		return ("Threonine");
	else if ((trinucleotide == "TCT") || (trinucleotide == "TCC") ||
		(trinucleotide == "TCA") || (trinucleotide == "TCG") ||
		(trinucleotide == "AGT") || (trinucleotide == "AGC"))
		return ("Serine");
	else if ((trinucleotide == "TAT") || (trinucleotide == "TAC"))
		return ("Tyrosine");
	else if ((trinucleotide == "TGG"))
		return ("Tryptophan");
	else if ((trinucleotide == "CAA") || (trinucleotide == "CAG"))
		return ("Glutamine");
	else if ((trinucleotide == "AAT") || (trinucleotide == "AAC"))
		return ("Asparagine");
	else if ((trinucleotide == "CAT") || (trinucleotide == "CAC"))
		return ("Histidine");
	else if ((trinucleotide == "GAA") || (trinucleotide == "GAG"))
		return ("Glutamic acid");
	else if ((trinucleotide == "GAT") || (trinucleotide == "GAC"))
		return ("Aspartic acid");
	else if ((trinucleotide == "AAA") || (trinucleotide == "AAG"))
		return ("Lysine");
	else if ((trinucleotide == "CGT") || (trinucleotide == "CGC") || (trinucleotide == "CGA") ||
		(trinucleotide == "CGG") || (trinucleotide == "AGA") || (trinucleotide == "AGG"))
		return ("Arginine");
	else if ((trinucleotide == "TAA") || (trinucleotide == "TAG") || (trinucleotide == "TGA"))
		return ("Stop");
	else
		cout << "returning unknown" << endl;
	return ("Unknown");
}