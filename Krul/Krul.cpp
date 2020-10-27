#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <vector>
#include <crtdbg.h>

#include "Absolute.h"
#include "Add.h"
#include "Duplicate.h"
#include "Concatenate.h"
#include "ContainerManager.h"
#include "Decrement.h"
#include "Divide.h"
#include "Function.h"
#include "Goto.h"
#include "GotoGe.h"
#include "GotoGt.h"
#include "GotoLe.h"
#include "GotoLt.h"
#include "GotoNe.h"
#include "Increment.h"
#include "Index.h"
#include "Libcurl.h"
#include "OperationFactory.h"
#include "Insert.h"
#include "TextEOL.h"
#include "LabelDefinition.h"
#include "LabelReference.h"
#include "Length.h"
#include "Modulo.h"
#include "Multiply.h"
#include "Negate.h"
#include "Newline.h"
#include "Return.h"
#include "Reverse.h"
#include "Rotate.h"
#include "Substring.h"
#include "Subtract.h"
#include "VariableAssignment.h"
#include "VariableReference.h"

const std::string baseURL = "https://www.swiftcoder.nl/cpp1/";
std::string appendURL = "start.txt";

void initializeOperationFactory();
void krulSequence(ContainerManager& containerManager);

int main()
{
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(946942);*/
	
	ContainerManager containerManager;
	initializeOperationFactory();
	
	krulSequence(containerManager);

	// delete containerManager;
	
	_CrtDumpMemoryLeaks();
}

void krulSequence(ContainerManager& containerManager)
{
	std::istringstream response(makeCurlRequest(baseURL + appendURL));
	bool endIsHere = false;
	
	for (std::string line; std::getline(response, line); )
	{
		containerManager.raw.push_back(line);
	}

	// Index-based iteration
	for (int i = 0; i != containerManager.raw.size(); ++i)
	{
		if(containerManager.raw[i] == "end")
		{
			endIsHere = true;
			break;
		}
		
		std::string identifier = containerManager.raw[i];
		OperationFactory::GetInstance().GetOperation(identifier)->execute(identifier, i, containerManager);
	}

	// Print stack
	for (const std::string& i : containerManager.stack)
	{
		std::cout << i << '\n';
	}

	// Set new iteration data
	if(!endIsHere)
	{
		appendURL = containerManager.stack.back();
		containerManager.clearContainers();
		krulSequence(containerManager);
	}
}

void initializeOperationFactory()
{
	// Basic operations
	OperationFactory::GetInstance().RegisterOperation(new Insert, "insert");
	
	// Values & Types
	OperationFactory::GetInstance().RegisterOperation(new TextEOL, "\\");
	OperationFactory::GetInstance().RegisterOperation(new LabelDefinition, ":");
	OperationFactory::GetInstance().RegisterOperation(new LabelReference, ">");
	OperationFactory::GetInstance().RegisterOperation(new VariableAssignment, "=");
	OperationFactory::GetInstance().RegisterOperation(new VariableReference, "$");

	// Integer operations
	OperationFactory::GetInstance().RegisterOperation(new Add, "add");
	OperationFactory::GetInstance().RegisterOperation(new Subtract, "sub");
	OperationFactory::GetInstance().RegisterOperation(new Multiply, "mul");
	OperationFactory::GetInstance().RegisterOperation(new Divide, "div");
	OperationFactory::GetInstance().RegisterOperation(new Modulo, "mod");
	OperationFactory::GetInstance().RegisterOperation(new Negate, "neg");
	OperationFactory::GetInstance().RegisterOperation(new Absolute, "abs");
	OperationFactory::GetInstance().RegisterOperation(new Increment, "inc");
	OperationFactory::GetInstance().RegisterOperation(new Decrement, "dec");

	// String operations
	OperationFactory::GetInstance().RegisterOperation(new Duplicate, "dup");
	OperationFactory::GetInstance().RegisterOperation(new Reverse, "rev");
	OperationFactory::GetInstance().RegisterOperation(new Substring, "slc");
	OperationFactory::GetInstance().RegisterOperation(new Index, "idx");
	OperationFactory::GetInstance().RegisterOperation(new Concatenate, "cat");
	OperationFactory::GetInstance().RegisterOperation(new Length, "len");
	OperationFactory::GetInstance().RegisterOperation(new Rotate, "rot");
	OperationFactory::GetInstance().RegisterOperation(new Newline, "enl");

	// Tests & Jumps
	OperationFactory::GetInstance().RegisterOperation(new Goto, "gto");
	OperationFactory::GetInstance().RegisterOperation(new GotoNe, "gne");
	OperationFactory::GetInstance().RegisterOperation(new GotoGe, "gge");
	OperationFactory::GetInstance().RegisterOperation(new GotoLe, "gle");
	OperationFactory::GetInstance().RegisterOperation(new GotoLt, "glt");
	OperationFactory::GetInstance().RegisterOperation(new GotoGt, "ggt");
	
	// Functions
	OperationFactory::GetInstance().RegisterOperation(new Function, "fun");
	OperationFactory::GetInstance().RegisterOperation(new Return, "ret");
}