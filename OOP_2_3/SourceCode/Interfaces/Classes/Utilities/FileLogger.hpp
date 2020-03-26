#ifndef FileLogger_hpp
#define FileLogger_hpp

#include <ctime>
#include <string>
#include <fstream>

namespace Logger {
    
    class FileLogger {
    private:
        std::ofstream file;
        
        unsigned int errorsCount;
        unsigned int warningsCount;
        
        std::string getLogTime() {
            time_t now = time(0);
            return ctime(&now);
        }
    public:
        enum log_type {LOG_ERROR, LOG_WARNING, LOG_INFO};
        
        FileLogger(const FileLogger& other) = delete;
        FileLogger& operator= (const FileLogger& other) = delete;
        
        explicit FileLogger(std::string filename = "log.txt") {
            errorsCount = 0;
            warningsCount = 0;
            
            file.open(filename, std::ios_base::app);
            if (file.is_open()) {
                file << "Log file created" << std::endl << getLogTime() << "\n";
            }
        }
        
        
    };
}

#endif
