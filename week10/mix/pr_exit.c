#include "../ch10.h"
void pr_exit(int status, pid_t pid)
{
	int sig;
	if (WIFEXITED(status)) //正常终止的子进程
	{
		printf("process %d normal termination, exit status = %d\n",pid,
				WEXITED(status));
	}
	else if(WIFSIGNLED(status)) //异常终止子进程
	{
		sig = WTERMSIG(status);
		printf("process %d abnormal termination, signal numer = %d%s:\n",pid,sig,
	#ifdef WCOREDUMP
			WCOREDUMP(status) ? "(core file generated)":"");
	#else
			"");
	#endif
		psignal(sig, "");
	}
	else if(WIFSTOPPED(status)) //被停止的子进程
	{
		sig = WSTOPSIG (status);
		printf("process %d stopped, signal number = %d: ", pid, sig);
		psignal(sig, "");
	}
}
