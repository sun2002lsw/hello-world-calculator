// calculator.cpp
// Header file for Calculator class and its constituting classes
//
// Author  : Jinwook Lee
// Reviewer: Sungwook Lee
// First version: April 11, 2020
// Last update  : April 12, 2020
//

#ifndef ULTRA_DOUBLE_H
#include "ultra_double.h"
#endif

#ifndef COMMAND_H
#include "Command.h"
#endif

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <chrono>
#include <thread>
#include <string>
#include <cmath>
#include <vector>
#include <deque>

enum class INPUT_CMD_TYPE { EXIT = 0, CLEAR, ALL_CLEAR, EXECUTE, UNDETERMINED, NUMBER, OPERATOR };
enum class INPUT_OPR_TYPE { PLUS = 0, MINUS, MULTIPLY, DIVIDE };

class Calculator
{
	public:
		// Constructor and destructor
		Calculator(int pFactor=1, int nHistory=10); // Precision factor is set at construction
		~Calculator(){} 

		// Input accumulation
		INPUT_CMD_TYPE ReadCommand(); // cmdCurrent is updated

		// Parsing command line and execute command
		int ExecuteCommand(); // Execute current command and update cmdHistory and ansHistory

		// Display current status
		int DisplayStatus();

		int Wait(int waitMilliseconds = 10);

	private:
		std::deque<Command>     cmdHistory; // Command history
		std::deque<UltraDouble> ansHistory; // Answer history

		Command cmdCurrent; // Current command 
		UltraDouble ansCurrent; // Current answer

		int precisionFactor; // Amplification factor for significant digit beyond double precision
		int sizeHistory; // Size of history to be recorded
};

#endif // End of include guard
