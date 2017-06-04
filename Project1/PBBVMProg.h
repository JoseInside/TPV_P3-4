#pragma once
#include <stdio.h>
#include <string>
#include <fstream>
#include <assert.h>
#include <iostream>

using namespace std;

class PBBVMProg
{

	static const int MAX_SIZE = 100;
	char instr[MAX_SIZE];
	int size;

public:

	enum ENUM {
		GET_DX, GET_DY, SET_DX, SET_DY, GET_CLICKS, DEACTIVATE,
		GET_POINTS, SET_POINTS, GAIN_POINTS, ADD, MUL, SUB, PUSH_N, GOTO_N, JMPZ_N, JMPGT_N
	};

	PBBVMProg(string filename) {

		ifstream in;
		in.open(filename, ios::binary);

		in.seekg(0, ios::end);
		size = (int)in.tellg();
		assert(size <= MAX_SIZE);
		in.seekg(0, ios::beg);
		in.read(instr, size);

		in.close();
	
	};
	~PBBVMProg() {};

	const char* getInstr() {
		return instr;
	}

	int getInstrSize() {
		return size;
	}

	static void compile(string infile, string outfile) {
	
		ifstream in;
		ofstream out;

		int aux1, aux2, aux3, n;

		in.open(infile);
		out.open(outfile, ios::binary);

		string keyword;
		int  pc = 0;
		int bytecodeNum = -1;

		char bytecode[MAX_SIZE];
		int addr[MAX_SIZE];
		bool pending[MAX_SIZE];

		while (!in.eof()) {
			in >> keyword;
			if (in.good()) {
				cout << "Compiling: " << keyword << endl;
				if (keyword == "get_dx") {
					bytecode[pc++] = GET_DX;
				}
				else if (keyword == "get_dy") {
					bytecode[pc++] = GET_DY;
				}
				else if (keyword == "set_dx") {
					bytecode[pc++] = SET_DX;
				}
				else if (keyword == "set_dy") {
					bytecode[pc++] = SET_DY;
				}
				else if (keyword == "get_clicks") {
					bytecode[pc++] = GET_CLICKS;
				}
				else if (keyword == "deactivate") {
					bytecode[pc++] = DEACTIVATE;
				}
				else if (keyword == "get_points") {
					bytecode[pc++] = GET_POINTS;
				}
				else if (keyword == "set_points") {
					bytecode[pc++] = SET_POINTS;
				}
				else if (keyword == "gain_points") {
					bytecode[pc++] = GAIN_POINTS;
				}
				else if (keyword == "add") {
					bytecode[pc++] = ADD;
				}
				else if (keyword == "mul") {
					bytecode[pc++] = MUL;
				}
				else if (keyword == "sub") {
					bytecode[pc++] = SUB;
				}
				else if (keyword == "push") {
					bytecode[pc++] = PUSH_N;
				}
				else if (keyword == "go_to") {
					in >> aux1;
					bytecode[pc++] = GOTO_N;
					if (aux1 < bytecodeNum) {
						(*((int*)(bytecode + pc + 1))) = addr[aux1];
					}
					else {
						pending[pc] = true;
						(*((int*)(bytecode + pc + 1))) = aux1;
					}
					pc = pc + sizeof(int);
				}
				else if (keyword == "jump_n_0") {
					in >> aux2;
					bytecode[pc++] = JMPZ_N;
					if (aux2 < bytecodeNum) {
						(*((int*)(bytecode + pc + 1))) = addr[aux2];
					}
					else {
						pending[pc] = true;
						(*((int*)(bytecode + pc + 1))) = aux2;
					}
					pc = pc + sizeof(int);
				}
				else if (keyword == "jump_n") {
					in >> aux3;
					bytecode[pc++] = JMPGT_N;
					if (aux3 < bytecodeNum) {
						(*((int*)(bytecode + pc + 1))) = addr[aux3];
					}
					else {
						pending[pc] = true;
						(*((int*)(bytecode + pc + 1))) = aux3;
					}
					pc = pc + sizeof(int);
				}
				else {
					throw "Error!";
				}
			}
		}


		for (int i = 0; i <= bytecodeNum; i++) {
			
			if (pending[i]) {
				n = *((int*)(bytecode + addr[i] + 1));
				if (n <= bytecodeNum) {
					*((int*)(bytecode + addr[i] + 1)) = addr[n];
				}
				else
				{
					*((int*)(bytecode + addr[i] + 1)) = pc++;
				}
			}

		}

		out.write(bytecode, pc);

		in.close();
		out.close();
	}


};

