#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

pid_t pid,ppid;
struct proc{
int pid;
int ppid;
int tag;
int ptag;
int ctag[2];
int cpid[2];
};
void waittree(int *status)
{
for(int i=0;i<2;i++)
            wait(&(*status));
}
void printinfo(struct proc *p)//struct proc *p
{
printf("Child-P%d[%d]\n",p->tag,getpid());
printf("Parent-P%d[%d]\n",p->ptag,getppid());
printf("\n");
}
struct proc *createtree(char a[], int h,struct proc *p)
{
        int c=2,i,status;
        if(h>1)
        {
                for(i=0;i<c;i++)
                {
                        if((pid = fork())<0)
                        {
                                fprintf(stderr, "fork failed\n");
                                exit(1);
                        }
                        if(pid==0)
                        {
                           char h1[20];
                           h=h-1;
  snprintf(h1,sizeof(h1),"%d",h);
  if(i==0)
  {
  p->ptag=p->tag;
  p->tag=2*p->tag;
  char c1[20];
                   char c2[20];
  snprintf(c1, sizeof(c1),"%d",p->tag);
                   snprintf(c2, sizeof(c2),"%d",p->ptag);
                          if(execl(a,a,h1,c1,c2,NULL) == -1)
                                  fprintf(stderr, "execl failed\n");
  }
  else if(i==1)
  {
  p->ptag=p->tag;
  p->tag=2*p->tag+1;
                   char c1[20];
  char c2[20];
                   snprintf(c1, sizeof(c1),"%d",p->tag);
  snprintf(c2, sizeof(c2),"%d",p->ptag);
  if(execl(a,a,h1,c1,c2,NULL) == -1)
                                  fprintf(stderr, "execl failed\n");
  }
                        }
if(pid>0)
                waittree(&status);
               }
        }
return p;
}
int main(int argc , char *argv[])
{
int h=atoi(argv[1]);
struct proc p;
p.tag=atoi(argv[2]);
p.ptag=atoi(argv[3]);
createtree(argv[0],h,&p);
printinfo(&p);
}