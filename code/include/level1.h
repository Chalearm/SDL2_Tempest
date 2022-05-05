//  
//
//     Level1
//
//     define in header Level1
//     
//     control all events/ drawn objects happening on the Level1

#ifndef __LEVEL1__
#define __LEVEL1__
#include "level.h"

class level1 : public level
{
public:

    level1();
    level1(const level1& obj);
    ~level1();
    level1& operator=(const level1& obj);

    void init();
    void render();
    void update();
    void handleEvents(const unsigned char& keyPress = 0);
    void clean();
    std::shared_ptr<std::vector<walkPath<double> > > getWalkPaht()const;
    void setSDLHandler(const std::shared_ptr<SDLHandler> &obj);
};


#endif /* define (__LEVEL1__) */
