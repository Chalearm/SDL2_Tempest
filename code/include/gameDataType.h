//  
//
//     gameDataType
//     
//     provides the specific type to refer to some attributes of some objects: 
//     - pointType : this is used with point.h and to refer the attribute of the point object
//     - GameScene : to refer the game scene - main menu, level1, level2 and level3
//     - MainMenuObj : to refer the objects shown on screen at the main menu scene
//
#ifndef __GAMEDATATYPE__
#define __GAMEDATATYPE__

// Data type define
enum pointType {X,Y};
enum lineType {P1,P2};
enum WalkPathType {LLEFT,LEDGE,LRIGHT};

enum GameScene {MainMenu, Level1, Level2, Level3};

//enum SelectionType {DATA_GAMESCENE};

enum MainMenuObj {BACKGROUND_IMG,LABEL_TEMPEST,LABEL_EXIT,LABEL_LV1,LABEL_LV2,LABEL_LV3,BACK_TO_MAINMENU};

enum EnemyType {ENEMY,FLIPPERS, TANKER, SPIKERS};
//enum baseColor {RED, GREEN, BLUE, ALPHA};
enum GameColor {WHITE, BLACK, BLUE, RED, GREEN, DARK_GREEN, YELLOW, ORANGE,LIGHT_GREY,MAGENTA,ALPHA,NOCOLOR};
// constanst



#endif /* define (__GAMEDATATYPE__) */
