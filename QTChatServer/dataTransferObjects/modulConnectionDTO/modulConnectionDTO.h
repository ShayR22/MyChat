#ifndef MODUL_CONNECTION_DTO_HEADER
#define MODUL_CONNECTION_DTO_HEADER

#include <string>

class ModulConnectionDTO {
private:
    bool incomingCall;
    std::string incomingCallFrom;
    bool ConnectionSuccess;


public:
    ModulConnectionDTO(bool isIncomingCall, bool isConnectionSuccess, std::string incomingCallFrom);
    bool isIncomingCall();
    bool isConnectionSuccess();
    std::string getIncmingCallFrom();

};


#endif // !MODUL_CONNECTION_DTO_HEADER
