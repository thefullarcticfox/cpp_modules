#include "Logger.hpp"

int		main(void)
{
	Logger	logger("logger.log");

	logger.log("console", "Error message");
	logger.log("console", "Informational message");
	logger.log("console","Critical message");
	logger.log("console","Debug message");
	logger.log("file", "Logger message");
	logger.log("file", "this one goes to the file too");
	logger.log("file", "Error message 2");
	logger.log("file", "Logfile end");
	logger.log("internet", "bad dest");
	return (0);
}
