//  
//
//     Level3
//
//     define in header Level3
//     
//     control all events/ drawn objects happening on the Level3

#ifndef __LEVEL3__
#define __LEVEL3__
#include "level.h"

class level3 : public level
{
public:

    level3();
    level3(const level3& obj);
    ~level3();
    level3& operator=(const level3& obj);

    void init();
    void render();
    void update();
    void handleEvents(const unsigned char& keyPress = 0);
    void clean();
};


#endif /* define (__LEVEL3__) */
