 1 pid_t pid;
 2 int status;
 3 char *envp[] = { NULL };
 4 char *argv[] = { "./test_args", "hello", "there", NULL };
 5 
 6 switch ( pid = fork() ) {
 7   case -1:
 8     perror("fork()");
 9     exit(EXIT_FAILURE);
10   case 0: // in the child
11     status = execve("./test_args", argv, envp);
12     exit(status); // only happens if execve(2) fails
13   default: // in parent
14     if ( waitpid(pid, &status, 0) < 0 ) {
15       perror("waitpid()");
16       exit(EXIT_FAILURE);
17     }
18 
19     if ( WIFEXITED(status) ) {
20       // return status from child, ie ./test_args
21       exit( WEXITSTATUS(status) );
22     }
23     exit(EXIT_FAILURE);
24 }
