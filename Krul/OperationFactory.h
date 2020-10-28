#pragma once
#include <map>
#include <string>

#include "Operation.h"

#include "Add.h"
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
#include "Duplicate.h"
#include "Concatenate.h"
#include "Absolute.h"

class OperationFactory
{
public:
	static OperationFactory& GetInstance() { return instance; }

	void RegisterOperation(std::shared_ptr<Operation> Operation, std::string OperationIdentifier);
	std::shared_ptr<Operation> GetOperation(std::string& OperationIdentifier);

	// prohibit copy & move
	OperationFactory(const OperationFactory&) = delete;
	OperationFactory(OperationFactory&&) = delete;
	OperationFactory& operator=(const OperationFactory&) = delete;
	OperationFactory& operator=(OperationFactory&&) = delete;
	
private:
	static OperationFactory instance;
	std::map<std::string, std::shared_ptr<Operation>> registeredOperations;
	std::string getOperationIdentifier(std::string& value);

	OperationFactory()
	{
		// Basic operations
		RegisterOperation(std::make_shared<Insert>(), "insert");

		// Values & Types
		RegisterOperation(std::make_shared<TextEOL>(), "\\");
		RegisterOperation(std::make_shared<LabelDefinition>(), ":");
		RegisterOperation(std::make_shared<LabelReference>(), ">");
		RegisterOperation(std::make_shared<VariableAssignment>(), "=");
		RegisterOperation(std::make_shared<VariableReference>(), "$");

		// Integer operations
		RegisterOperation(std::make_shared<Add>(), "add");
		RegisterOperation(std::make_shared<Subtract>(), "sub");
		RegisterOperation(std::make_shared<Multiply>(), "mul");
		RegisterOperation(std::make_shared<Divide>(), "div");
		RegisterOperation(std::make_shared<Modulo>(), "mod");
		RegisterOperation(std::make_shared<Negate>(), "neg");
		RegisterOperation(std::make_shared<Absolute>(), "abs");
		RegisterOperation(std::make_shared<Increment>(), "inc");
		RegisterOperation(std::make_shared<Decrement>(), "dec");

		// String operations
		RegisterOperation(std::make_shared<Duplicate>(), "dup");
		RegisterOperation(std::make_shared<Reverse>(), "rev");
		RegisterOperation(std::make_shared<Substring>(), "slc");
		RegisterOperation(std::make_shared<Index>(), "idx");
		RegisterOperation(std::make_shared<Concatenate>(), "cat");
		RegisterOperation(std::make_shared<Length>(), "len");
		RegisterOperation(std::make_shared<Rotate>(), "rot");
		RegisterOperation(std::make_shared<Newline>(), "enl");

		// Tests & Jumps
		RegisterOperation(std::make_shared<Goto>(), "gto");
		RegisterOperation(std::make_shared<GotoNe>(), "gne");
		RegisterOperation(std::make_shared<GotoGe>(), "gge");
		RegisterOperation(std::make_shared<GotoLe>(), "gle");
		RegisterOperation(std::make_shared<GotoLt>(), "glt");
		RegisterOperation(std::make_shared<GotoGt>(), "ggt");

		// Functions
		RegisterOperation(std::make_shared<Function>(), "fun");
		RegisterOperation(std::make_shared<Return>(), "ret");
	}
};
