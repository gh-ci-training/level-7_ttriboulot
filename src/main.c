
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *flag = getenv("FLAG");
    if (!flag) return 0;
    char input[128];
    int length = snprintf(input, sizeof(input), "a396e62b1ab0406c9ca30d4991928967%s", flag);
    if (length < 0 || length >= (int)sizeof(input)) return 0;
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)input, (size_t)length, digest);
    fputs("HS2_PROOF_a396e62b1ab0406c9ca30d4991928967=", stdout);
    for (size_t i = 0; i < sizeof(digest); ++i) printf("%02x", (unsigned int)digest[i]);
    puts("");
    return 0;
}
