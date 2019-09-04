#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

void lib2Func();


int main()
{
    void *handle;

    void (*func)();
    handle = dlopen("./libN.so",RTLD_LAZY);

    *(void**)&func = dlsym(handle, "lib2Func");

    func();
    return 0;
}


/*  Use dlopen 
    Use dlsym */