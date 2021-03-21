#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <sstream>
# include <ctime>

class Logger {
private:
	std::string		filename;
	std::ofstream	logfile;
	std::string		makeLogEntry(const std::string& msg);
	void			logToConsole(const std::string& msg);
	void			logToFile(const std::string& msg);
public:
	Logger(std::string file);
	~Logger();
	void			log(const std::string& dest, const std::string& message);
};

#endif
