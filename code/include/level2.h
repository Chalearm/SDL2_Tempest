//  
//
//     Level2
//
//     define in header Level1
//     
//     control all events/ drawn objects happening on the Level1

#ifndef __LEVEL2__
#define __LEVEL2__
#include "level.h"

class level2 : public level
{
public:

    level2();
    level2(const level2& obj);
    ~level2();
    level2& operator=(const level2& obj);

    void init();
    void render();
    void update();
    void handleEvents(const unsigned char& keyPress = 0);
    void clean();
    std::shared_ptr<std::vector<walkPath<double> > > getWalkPaht()const;
    void setSDLHandler(const std::shared_ptr<SDLHandler> &obj);
};


#endif /* define (__LEVEL2__) */
