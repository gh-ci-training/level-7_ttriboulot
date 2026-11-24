
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *flag = getenv("FLAG");
    if (!flag) return 0;
    char input[128];
    int length = snprintf(input, sizeof(input), "08fd7aa833b94b6e8406ed80ee3ba3d8%s", flag);
    if (length < 0 || length >= (int)sizeof(input)) return 0;
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)input, (size_t)length, digest);
    fputs("HS2_PROOF_08fd7aa833b94b6e8406ed80ee3ba3d8=", stdout);
    for (size_t i = 0; i < sizeof(digest); ++i) printf("%02x", (unsigned int)digest[i]);
    puts("");
    return 0;
}
