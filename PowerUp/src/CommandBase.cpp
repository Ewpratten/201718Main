#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"

/**
 *
 */

OI* CommandBase::pOI = NULL;
DriveTrain* CommandBase::pDriveTrain = NULL;
Intake* CommandBase::pIntake = NULL;

CommandBase::CommandBase() : Command()
{
	std::cout << "[CommandBase] Constructed" << std::endl;

	this->init();

	return;
}

/**
 *
 */

CommandBase::~CommandBase()
{
	delete this->pDriveTrain;
	delete this->pIntake;
	delete this->pOI;

	return;
}

/**
 *
 */

CommandBase::CommandBase(char const *name) : Command(name)
{
	std::cout << "[CommandBase] Constructed with name: " << name << std::endl;

	return;
}

/**
 *
 */

void CommandBase::init()
{
	std::cout << "[CommandBase] Initialized" << std::endl;

	// Note: These aren't "this" because they are static,
	//	so there is only one instance of these variables in
	//	the CommandBase class. "this" pointers refer to
	//	regular variables that are created (and are unique)
	//	to the 'instance' of the object.

	if (CommandBase::pOI == nullptr)
	{
		CommandBase::pOI = new OI();
	}

	if (CommandBase::pDriveTrain == nullptr)
	{
		CommandBase::pDriveTrain = new DriveTrain();
	}

	if (CommandBase::pIntake == nullptr)
	{
		CommandBase::pIntake = new Intake();
	}

	return;
}


