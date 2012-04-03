#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  pid_t pid;

  pid = fork();

  fprintf(stdout, "%ld, pid \n", (long) pid);
  fprintf(stdout, "%d, pid_t \n", (pid_t) -1);

  if (pid == (pid_t)(-1)) {
    fprintf(stderr, "%s, Fallo al hacer el fork\n", strerror(errno));
    exit(1);
  } else if (pid == 0) {
    fprintf(stdout, "PID: %ld: El proceso hijo iniciado, el padre es %ld.\n", (long) getpid(), (long) getppid());
  } else {
    fprintf(stdout, "PID: %ld: PID del hijo iniciado: %ld.\n", (long) getpid(), (long) pid);
  }

  sleep(1);
  return 0;
}
