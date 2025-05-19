#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    static const char desc[2][5] = {"even", "odd"};
    const size_t len = (argc == 2) ? strlen(argv[1]) : 0;
    char *end = NULL;
    long long num;
    /*
     * Also branches if the argument is empty, so it prints out a
     * nice help message instead of an error with empty quotes.
     */
    if (!len) {
        printf(
            "Usage: %s <number>\nTells if the number is even or odd.\n",
            argv[0]
        );
        return EXIT_FAILURE;
    }
    /*
     * Unroll the first iteration of the check since the minus
     * character/sign can only appear to the left of a number.
     */
    if ((!isdigit(argv[1][0])) & ((argv[1][0] != '-') | (len == 1))) {
        goto scanfail;
    }
    /* 
     * Since the first check discards empty arguments, it is invariant
     * that strlen is at least 1, so the loop can test for equality
     * instead of the more expensive inequality.
     */
    for (size_t i = 1; i != len; ++i) {
        if (!isdigit(argv[1][i])) {
            goto scanfail;
        }
    }
    errno = 0;
    num = strtoll(argv[1], &end, 10);
    if (errno == ERANGE) {
        printf(
            "%s is outside [%lld, %lld].\n", argv[1], LLONG_MIN, LLONG_MAX
        );
        return EXIT_FAILURE;
    }
    /*
     * The crux of this program. Since all odd numbers (in most sign
     * representations) have the lowest bit set, you can get the
     * answer in a branchless way by indexing the array with the
     * extracted bit.
     */
    printf("%lld is %s.\n", num, desc[num & 1]);
    return EXIT_SUCCESS; /* Used for consistency with other returns. */
  scanfail:
    printf("\"%s\" isn't a number.\n", argv[1]);
    return EXIT_FAILURE;
}