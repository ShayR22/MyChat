#include "viewchatdto.h"

using namespace std;

ViewChatDTO::ViewChatDTO(string message)
{
    this->message = message;
}

string ViewChatDTO::getMessage(){
    return this->message;
}
