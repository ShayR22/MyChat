#ifndef MODULCHATODTO_H
#define MODULCHATODTO_H

#include <string>

class ModulChatDTO
{
private:
    std::string incomingData;

public:
    ModulChatDTO(std::string message);
    std::string getMessage();

};

#endif // MODULCHATODTO_H
