#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main(void) {
    const char* p = "111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
    printf("Parsing '%s':\n", p);
    char* end;

    for (double f = strtod(p, &end); p != end; f = strtod(p, &end)) {
        printf("'%.*s' -> ", (int)(end - p), p);
        p = end;

        if (errno == ERANGE) {
            printf("range error, got ");
            errno = 0;
        }

        printf("%f\n", f);
    }

    printf("\"  -0.0000000123junk\"  -->  %g\n", strtod("  -0.0000000123junk", NULL));
    printf("\"junk\"                 -->  %g\n", strtod("junk", NULL));

    _getch();
    return 0;
}