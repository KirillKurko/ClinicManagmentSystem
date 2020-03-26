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
                file << "Logging started" << std::endl << getLogTime() << "\n";
            }
        }
        
        ~FileLogger() {
            if (file.is_open()) {
                file << "\n" << warningsCount << " warnings" << std::endl;
                file << errorsCount << " errors" << std::endl;
                file << "Logging finished" << std::endl << getLogTime() << "\n\n";
                
                file.close();
            }
        }
        
        friend FileLogger& operator<< (FileLogger& logger, std::pair<const log_type, std::string> message) {
            auto [type, text] = message;
            switch (type) {
                case FileLogger::LOG_ERROR:
                    logger.file << "[ERROR]: " << text << std::endl;
                    logger.errorsCount++;
                    break;
                case FileLogger::LOG_WARNING:
                    logger.file << "[WARNING]: " << text << std::endl;
                    logger.warningsCount++;
                    break;
                case FileLogger::LOG_INFO: default:
                    logger.file << "[INFO]: " << text << std::endl;
            }
            return logger;
        }
        
    };
}

#endif
