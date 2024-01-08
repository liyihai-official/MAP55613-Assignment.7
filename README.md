# MAP55613-Assignment.7
This is the assignment solutions of MAP55613 C Program, the module in Trinity College Dublin.
This should be only a short assignment. 
You will write some code to do a matrix multiplication manually. 
For the second part, you will “parallelize“ two matrix-matrix multiplications by calling fork() and doing each one in a separate process. 
For the third part, you will again do two matrix-matrix multiplications, but this time you will launch a separate thread to do one of them while the main thread is doing the other one.
These are “embarrassingly parallel” problems as we don’t need to do any IPC or coordinating between the processes/threads while each is doing its own share of the tasks.
