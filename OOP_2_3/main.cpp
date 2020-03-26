#include "SourceCode/Interfaces/Menu.hpp"
#include "SourceCode/Interfaces/Classes/Utilities/FileLogger.hpp"

using namespace std;

Logger::FileLogger logger;

int main() {
	while (mainMenu()) {};
	return 0;
}


