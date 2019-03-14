#include "dataTransferObjects/viewConnectionDTO/viewConnectionDTO.h"

using namespace std;

ViewConnectionDTO::ViewConnectionDTO(string connectTo, bool isAcceptingCall){
    this->connectTo = connectTo;
    this->isAcceptingCall = isAcceptingCall;
}

string ViewConnectionDTO::getWhoToConnect(){
    return this->connectTo;
}

bool ViewConnectionDTO::getIsAcceptingCall(){
    return this->isAcceptingCall;
}
