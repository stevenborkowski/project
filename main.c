#include "face.h"

int main()
{
    Face_initialize();
    int a = Face_recognize();
    printf("Face_recognize returns %i\n",a);
    Face_cleanup();
    return 0;
}