#include "dataTransferObjects/modulConnectionDTO/modulConnectionDTO.h"

ModulConnectionDTO::ModulConnectionDTO(bool isIncomingCall, bool isConnectionSuccess, std::string incomingCallFrom){
    this->incomingCall = isIncomingCall;
    this->ConnectionSuccess = isConnectionSuccess;
    this->incomingCallFrom = incomingCallFrom;
}

bool ModulConnectionDTO::isIncomingCall(){
    return incomingCall;
}

bool ModulConnectionDTO::isConnectionSuccess(){
    return ConnectionSuccess;
}

std::string ModulConnectionDTO::getIncmingCallFrom(){
    return incomingCallFrom;
}



