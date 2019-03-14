#include "modulchatodto.h"

using namespace std;

ModulChatDTO::ModulChatDTO(string incomingCall)
{
    this->incomingData = incomingCall;
}

string ModulChatDTO::getMessage(){
    return this->incomingData;
}
