# 42seoul  

# information  
> Name : Yoon Kiung (윤기웅)  
> NickName : kiyoon  
> since Sep 2021 to Sep 2023 (2 year)

# complete task
### libft
My very first own library  
implement 50+ utility function and archiving it to use like standard library
### get_next_line
Implement input buffer through random file desciprter seperated by new line ('\n)
### ft_printf
Implement printf function only use ```write()``` ```va_start()``` ```va_arg()``` ```va_copy()``` ```va_end()```
### push_swap
Use two stack to sort integer  
```push``` ```pop``` ```rotate``` ```reverse rotate``` ```swap``` are possible commands  
Use QuickSort with 2 pivot So time complexity is $\log_3 n + C$  
for optimization use insertion sort under $n < 11$
### pipex
Implements shell pipes use ```execve()``` function  
Use dup2, ```execve()``` ```fork()``` ```pipe()``` ```wait()``` ```waitpid()``` to handle parent and child process  
Use ```open()``` ```close()``` ```read()``` ```write()``` ```unlink()``` to handle file descripter  
Works exactly like real shell commands like ```< file1 cmd1 | cmd2 > file2```
### so_long
Implementation of a game to escape a maze by avoiding obstacles  
Use ```MLX```library to design  
### philosophers
Consider the philosophers as threads, and the philosophers sitting at a round table eat when they own the two forks(Share resources) sitting between them and then put them down again.  
Manages shared resources to prevent deadlock, starvation, and data races from occurring, and applies a scheduling algorithm to prevent Philosopher from starving to death(to receive CPU allocation) for more than a certain period of time.  
I choose odd/even thread id scheduling algorithm. So over ```400``` philosophers can survive without data delay
### minishell (with daechoi)
Implement ```bash```  
It operates very similarly to the actual bash shell  
It can handle ```here_doc``` ```multiple pipe``` ```environment variable``` and all other things in bash
### NetPractice
Practice How IP address interact with router  
### minRT
Randering 3D shapes such as Sphere, cylinder, cone, plane  
Use Ray tracing mathematical algorithm  
Use ```MLX```library to design  
### CPP Module(00 ~ 09)
Learn CPP grammer and STL  
Especially implement ```vector``` ```stack``` ```queue``` are helpful 
### Inception
Web service infrastructure construction project using ```nginx``` ```wordpress``` ```mariadb```  
Configured with multiple containers so that the hardware required for each open source can be upgraded individually  
Use Docker, Docker Compose, makefile to construct CI/CD
### ft_irc (with daechoi)
It has own git url  
```https://github.com/yoonkiung/ft_irc```
### ft_transcendence (with jiyunpar, hanbkim, yehan, chulee) 
It has own git url  
```https://github.com/yoonkiung/ft_transcendence_frontend```   
```https://github.com/yoonkiung/ft_transcendence_backend```   
