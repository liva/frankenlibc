#include <sys/uio.h>
#include "syscall.h"

ssize_t writev(int fd, const struct iovec *iov, int count)
{
	return syscall_3(SYS_writev, fd, (intptr_t)iov, count);
}

