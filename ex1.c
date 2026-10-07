#include <stdio.h>
#include <unistd.h>
#include <time.h>

void print_info(const char *name, clock_t start)
{
    clock_t end = clock();
    printf("%s: PID = %d, PPID = %d, execution time = %.3f ms\n",
           name,
           getpid(),
           getppid(),
           (double)(end - start) * 1000 / CLOCKS_PER_SEC);
}

int main()
{
    pid_t pid1, pid2;
    clock_t start;
    // Create first child
    pid1 = fork();
    if (pid1 == 0)
    {
        start = clock();
        print_info("Child 1", start);
        return 0;
    }

    // Create second child
    pid2 = fork();
    if (pid2 == 0)
    {
        start = clock();
        print_info("Child 2", start);
        return 0;
    }
    // Main process
    start = clock();
    print_info("Main", start);
    return 0;
}
