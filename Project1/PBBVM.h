#pragma once
#include <stdio.h>
#include <iostream>
#include "PBBVMProg.h"
#include "PBBExternAccess.h"

class PBBVM
{
public:
	PBBVM() {};
	~PBBVM() {};

	void run(PBBVMProg& prog, PBBExternAccess& ball) {
	
		const char *instr = prog.getInstr();
		int size = prog.getInstrSize();
		
		for (int pc = 0; pc < size; pc++) {
			
			switch (instr[pc]) {
			case PBBVMProg::GET_DX:
				_stack.push(ball.getDirectionX());
				break;
			case PBBVMProg::GET_DY:
				_stack.push(ball.getDirectionY());
				break;
			case PBBVMProg::SET_DX:
				ball.setDirectionX(_stack.top());
				_stack.pop();
				break;
			case PBBVMProg::SET_DY:
				ball.setDirectionY(_stack.top());
				_stack.pop();
				break;
			case PBBVMProg::GET_CLICKS:
				_stack.push(ball.getTotalClicks());
				break;
			case PBBVMProg::DEACTIVATE:
				ball.setActive(false);
				break;
			case PBBVMProg::GET_POINTS:
				_stack.push(ball.getPoints());
				break;
			case PBBVMProg::SET_POINTS:
				ball.setPoints(_stack.top());
				_stack.pop();
				break;
			case PBBVMProg::GAIN_POINTS:
				ball.addGlobalPoints(_stack.top());
				_stack.pop();
				break;
			case PBBVMProg::ADD:
				aux1 = _stack.top();
				_stack.pop();
				_stack.push(aux1 + _stack.top());
				_stack.pop();
				break;
			case PBBVMProg::MUL:
				aux2 = _stack.top();
				_stack.pop();
				_stack.push(aux2 * _stack.top());
				_stack.pop();
				break;
			case PBBVMProg::SUB:
				aux3 = _stack.top();
				_stack.pop();
				_stack.push(aux3 - _stack.top());
				_stack.pop();
				break;
			case PBBVMProg::PUSH_N:
				_stack.push(*(int*)(instr + pc + 1));
				pc += sizeof(int);
				break;
			case PBBVMProg::GOTO_N:
				pc = *(int*)(instr + pc) - 1;	//pos instrucción + posición actual + 1;
				break;
			case PBBVMProg::JMPZ_N:
				if (_stack.top() == 0)
					pc = *((int*)(instr + pc + 1) - 1);	//pos instrucción + posición actual + 1;
				_stack.pop();
				break;
			case PBBVMProg::JMPGT_N:
				aux = _stack.top();
				_stack.pop();
				if (aux > _stack.top()) {
					pc = *((int*)(instr + pc + 1) - 1);	//pos instrucción + posición actual + 1;
				}
				break;
			}
		}
	}

protected:

	int aux, aux1, aux2, aux3;
	stack<int>_stack;
};

