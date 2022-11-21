int main(int argc, char **argv) {
    /* code */

    char buffer[256];

    if (argc !=2) {
        exit(0);
    }

    printf("%p\b", buffer);
    strcpy(buffer, argv[1]);
    printf("> %s <", buffer);

    return 0;
}
