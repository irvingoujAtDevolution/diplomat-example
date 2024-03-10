#include <windows.h>
#include <stdio.h>
#include <stdint.h>

typedef struct Example Example;

typedef Example* (*PFN_Example_new)(void);
typedef void (*PFN_Example_do_something)(const Example*, uint8_t*, size_t);
typedef void (*PFN_Example_destroy)(Example*);

int main() {
    HMODULE hModule = LoadLibrary(TEXT("C:\\Users\\jou\\code\\examples\\diplomat-example\\target\\debug\\diplomat_example.dll"));
    if (!hModule) {
        printf("Failed to load the DLL.\n");
        return 1;
    }

    PFN_Example_new Example_new = (PFN_Example_new)GetProcAddress(hModule, "Example_new");
    PFN_Example_do_something Example_do_something = (PFN_Example_do_something)GetProcAddress(hModule, "Example_do_something");
    PFN_Example_destroy Example_destroy = (PFN_Example_destroy)GetProcAddress(hModule, "Example_destroy");

    if (!Example_new || !Example_do_something || !Example_destroy) {
        printf("Failed to retrieve function addresses.\n");
        FreeLibrary(hModule);
        return 1;
    }

    Example* example = Example_new();
    if (example == NULL) {
        printf("Example_new failed to create an instance.\n");
        FreeLibrary(hModule);
        return 1;
    }

    // initialize the buffer to size 100
    uint8_t data[100];
    size_t data_len = sizeof(data) / sizeof(data[0]);
    Example_do_something(example, data, data_len);

    //print the buffer as utf-8
    for (int i = 0; i < data_len; i++) {
        printf("%c", data[i]);
    }

    Example_destroy(example);
    FreeLibrary(hModule);

    return 0;
}
