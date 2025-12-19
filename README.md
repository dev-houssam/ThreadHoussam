# ThreadHoussam
ThreadHoussam : a very very simple thread lib !

Ultimately, we create a library of isolated threads. Isolated threads are threads that do not depend on the host for their execution. As soon as they are executed, the memory is protected, and any code execution is considered to have no side effects on the process executing them. Isolated threads differ from conventional threads in that they use very light virtualisation, offering a great deal of flexibility for massive data processing while avoiding the notorious segmentation fault. Isolated threads also offer the advantage of a completely closed box: there is no possibility of propagating critical errors during execution. However, this requires only a good implementation of the tasks to be executed correctly. The communication stack will be implemented for exchanges with its host. Isolated threads are not completely independent and can communicate with each other, but they cannot communicate with other processes: they only exchange with their single host, and processes launched by the host cannot communicate with isolated threads. Isolated threads are virtual: this virtualisation allows for better decoupling and raw processing.

However, isolated threads also allow internal memory leaks, but this is offset by the fact that the threads run in isolation.

Ideas to explore: Add an LLM (ByteCoder Code Corrector) to the manager, which will allow bugs to be tolerated by having a functional programme.

