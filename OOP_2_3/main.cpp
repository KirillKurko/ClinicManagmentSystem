#include "SourceCode/Interfaces/Menu.hpp"
#include "SourceCode/Interfaces/Classes/Utilities/FileLogger.hpp"
#include "SourceCode/Interfaces/Classes/Utilities/FileSystemManager.hpp"

using namespace std;

Logger::FileLogger logger;

int main() {
	while (mainMenu()) {};
	return 0;
}


