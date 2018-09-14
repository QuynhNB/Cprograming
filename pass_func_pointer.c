#include <stdio.h>

int DoIt (float a, char b, char c)
{ 
    printf("DoIt\n");
    return a+b+c;
} 

void PassPtr(int (*pt2Func)(float, char, char))  
{  
    int result = (*pt2Func)(12, -12, 100); // call using function pointer  
    printf("%d", result);  
}  

void Pass_A_Function_Pointer()  
{  
    printf("Executing 'Pass_A_Function_Pointer'\n");  
    PassPtr(&DoIt);  
}  

int main()
{
    Pass_A_Function_Pointer();
    return 0;
}
