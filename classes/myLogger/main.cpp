#include<iostream>

class Log {
public:
    enum LogLevel { LogLevelError, LogLevelWarning, LogLevelInfo };
private:
    LogLevel _logLevel;
public:
    void setLevel(LogLevel level) {
        _logLevel = level;
    }

    void log(const char* message) {
        switch (_logLevel)
        {
        case LogLevelError:
            error(message);
            break;
        case LogLevelWarning:
            warn(message);
            break;
        case LogLevelInfo:
            info(message);
            break;
        
        default:
            break;
        }
    }

private:
    void error(const char* message) {
        print("ERROR", message);
    }

    void warn(const char* message) {
        print("WARNING", message);
    }

    void info(const char* message) {
        print("INFO", message);
    }

    void print(const char* type, const char* message) {
        std::cout << '[' << type << ']' << '\t' << message << std::endl;
    }
};

int main() {
    Log log;
    log.setLevel(Log::LogLevelInfo);
    log.log("Hello");
    return 0;
}