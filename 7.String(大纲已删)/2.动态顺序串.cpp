#include "init.h"
//堆分配储存
typedef struct{
    char *ch;
    int length;
}HString;
int main(){
    HString S;
    S.ch=new char(255);
    S.length=0;
    return 0;
}