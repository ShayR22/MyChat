#ifndef VIEW_CONNECTION_DTO_HEADER
#define VIEW_CONNECTION_DTO_HEADER

#include <string>

class ViewConnectionDTO {
private:
    bool isAcceptingCall;
    std::string connectTo;

public:
    ViewConnectionDTO(std::string connectTo, bool isAcceptingCall);
    std::string getWhoToConnect();
    bool getIsAcceptingCall();


};

#endif // !VIEW_DTO_HEADER
