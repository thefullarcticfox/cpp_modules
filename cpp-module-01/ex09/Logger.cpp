#include "Logger.hpp"

Logger::Logger(std::string file) : filename(file)
{
	logfile.open(this->filename);
	if (!(logfile.is_open()))
		logToConsole(makeLogEntry("Log error: failed to open " + filename +
									" file to write logs"));
}

Logger::~Logger()
{
	if (logfile.is_open())
		logfile.close();
}

std::string		Logger::makeLogEntry(std::string msg)
{
	std::stringstream	ss;
	time_t				rawtime;
	struct tm			*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	ss << "[" << std::setfill('0') <<
		timeinfo->tm_year + 1900 << std::setw(2) <<
		timeinfo->tm_mon + 1 << std::setw(2) <<
		timeinfo->tm_mday << "_" << std::setw(2) <<
		timeinfo->tm_hour << std::setw(2) <<
		timeinfo->tm_min << std::setw(2) <<
		timeinfo->tm_sec << std::setfill(' ') << "] " << msg;
	return (ss.str());
}

void			Logger::logToConsole(std::string const msg)
{
	std::cout << msg << std::endl;
}

void			Logger::logToFile(std::string const msg)
{
	if (logfile.is_open())
	{
		logfile << msg << std::endl;
		logfile.flush();
	}
	else
		logToConsole(makeLogEntry("Log error: failed to write log message \"" +
							msg.substr(18) + "\" to " + filename + " file"));
}

void			Logger::log(std::string const &dest, std::string const &message)
{
	std::string	dests[2] = {"console", "file"};
	void		(Logger::*logfuncs[2])(std::string const) = {
		&Logger::logToConsole,
		&Logger::logToFile
	};
	int			i = 0;

	while (i < 2 && (dests[i].compare(dest) != 0))
		i++;
	if (i < 2)
		(this->*logfuncs[i])(makeLogEntry(message));
	else
		(this->*logfuncs[0])(makeLogEntry("Log error: undefined destination \"" +
			dest + "\""));
}
