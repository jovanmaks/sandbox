    #ifndef __ATRIBUTES_H__
#define __ATRIBUTES_H__


class Atributes
{
private:
    
public:
    unsigned  int moduo;

    int ScreenWidth = 900;
    int ScreenHeight = 900;

    float GridValue = 0.5;/* VAZNO */
    float RGB1      = 0.6;/* VAZNO */
    float RGB2      = 0.6;/* VAZNO */


//============== GRID - CELL ==========================

    unsigned int rows = 3;/* VAZNO */
    unsigned int colums = 3;/* VAZNO */

//============== GRID - VERTEX ========================= 

    unsigned int widthVertex  = rows   + 1;/* VAZNO */
    unsigned int heightVertex = colums + 1;/* VAZNO */  

//============= BUFFERS - COUNT =======================

    unsigned int countVerteks           = widthVertex * heightVertex; /* VAZNO */
    unsigned int countCoordinatesXY     = widthVertex * heightVertex * 2; /* VAZNO */
    unsigned int countCoordinatesXYZ    = widthVertex * heightVertex * 3; /* VAZNO */


    unsigned int countValues = rows * colums;
    unsigned int countIndeks = rows * colums * 6;

    unsigned int countSingleColor = countVerteks;
    unsigned int countAlfa        = countVerteks;
    unsigned int countColor       = countVerteks * 3;


    unsigned int countAllXY  = countCoordinatesXY  + countColor + countAlfa;
    unsigned int countAllXYZ = countCoordinatesXYZ + countColor + countAlfa;




//======================================================
////// ovo jos nije odradjeno //////
    unsigned int posX;
    unsigned int posY;

//============= ELEMENT - CELL ========================
    unsigned int ColumnWidth = 2;
    unsigned int ColumnHeight = 2;
    unsigned int ColumnValue = 5;

    unsigned int FurnitureWidth = 4;
    unsigned int FurnitureHeight = 4;
    unsigned int FurnitureValue = 6;



    //mozes ubaciti i funkcije koje su globalne


    //============================================
    /*
    
    -STUB == 15;
    -ZID == 14;
    -OTVOR== -8;   ONDA TI KAD SABERES OTVOR DODJE NPR 14 - 8 = 6
        -PROZOR
        -VRATA
        -PROLAZ


    -KOMUNIKACIJA
        -STEPENISTE
        -LIFT
        

    -NAMJESTAJ
        IIMA KOLKO TI BOG HOCE ALI NEKA GRUBA PODJELA PO SOBAMA

    */
   //=============================================


};



#endif