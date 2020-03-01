# Process-Tree
Mini-Project for course IOPS332C

Each process in the tree is given a unique userdefined tag. The root process that you run by executing your code (a.out)
is called the initial process, and is given the first tag. Other processes
created by your program obtain their appropriate tags from their
respective parents. Each process know the tag of itself, and the tags
of the child processes it creates.
following information is stored in a structure against every process.
• The tag of the process.
• The PID (system-generated) of the process.
• The number of child processes that the process forks.
• An array of the tags of the child processes forked.
• An array of the PIDs of the child processes forked. 
