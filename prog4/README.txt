a.
By running valgrind, it shows that some memory allocated but not freed.
It is because that func(i) in line 15 will return false from time to time,
then free(p) is not called, but malloc is always called.
The fix is simple, just move malloc statement into the if block, so when func(i)
return false, then malloc is not called.

b. I wrote a prog4_rusage.c and run it, it showed something like this:
Executing the code ......
Program execution successfull
User time: 19.860000ms
System time: 0.000000ms
Max resident set size: 26128KB
Signal received: 0
Voluntary context switches: 6
Involuntary context switches: 0

i) The user time is 19.86ms.
ii) The system time is 0.00000ms. The difference is that user time is time spend in user mode,
but system time is time that spend in kernel mode.
iii) The max resident set size is 26128KB, it means the largest amount of memory size this process ever used.
iv) Voluntary context switches: 6
v) Involuntary context switches: 0.
Voluntary context switch means this process gives up running by itself(for example, by calling yield())
Involuntary context switch means that this process is preempted by other higher priority processes.

