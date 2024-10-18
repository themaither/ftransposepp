#include <unistd.h>
int main(int argc, char **argv) { execl("/usr/bin/pwd", "/usr/bin/pwd"); }