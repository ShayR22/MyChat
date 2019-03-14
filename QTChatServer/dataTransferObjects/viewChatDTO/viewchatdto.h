#ifndef VIEWCHATDTO_H
#define VIEWCHATDTO_H

#include <string>

class ViewChatDTO
{
private:
    std::string message;

public:
    ViewChatDTO(std::string message);
    std::string getMessage();
};

#endif // VIEWCHATDTO_H
