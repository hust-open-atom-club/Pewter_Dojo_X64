`pwn.hust.college` 平台核心之一是 `setUID` 标志位。当前 `/flag` 文件是 `root` 用户只读，`hacker` 并没有读权限。
挑战关卡要做的事情获取 `root` 权限，读取 `/flag`。而完成这种提权操作最简单的方法是 `setUID` 标志位。

```sh
hacker@welcome~:~$ ls -l /flag
-r--------. 1 root root 50 Mar 18 01:30 /flag
```

SetUID 允许任何拥有文件执行权限的用户，以当前文件所属者（通常是 root）的权限执行该文件。 
**注意，为了更有效地解决这些挑战关卡，你首先需要运行 /challenge 目录下的挑战题目，随后根据提示完成挑战。**

**关卡等级分布：**
- Level 1.0 - 利用设置了 SetUID 的挑战关卡程序直接读取 /flag
- Level 1.1 - 利用设置了 SetUID 的 /usr/bin/cat 命令读取 /flag
- Level 1.2 - 利用设置了 SetUID 的 /usr/bin/vim 命令读取 /flag
- Level 1.3 - 利用设置了 SetUID 的 /usr/bin/hexedit 命令读取 /flag
- Level 2.0 - 理解 /usr/bin/rev 功能，并通过设置了 SUID 的该命令获取 /flag 
- Level 2.1 - 理解 /usr/bin/gzip 功能，并通过设置了 SUID 的该命令获取 /flag 
- Level 2.2 - 理解 /usr/bin/date 功能，并通过设置了 SUID 的该命令获取 /flag 
- Level 3.0 - 学习 /usr/bin/chmod 命令设置文件权限，并通过设置了 SUID 的该命令获取 /flag 
- Level 3.1 - 学习 /usr/bin/chown 命令设置文件权限，并通过设置了 SUID 的该命令获取 /flag 
- Level 3.2 - 学习 /usr/bin/cp 命令设置文件权限，并通过设置了 SUID 的该命令获取 /flag 
- Level 4.0 - 学习 /usr/bin/python 解释器的语法，并编程实现获取 /flag 
- Level 4.1 - 学习 /usr/bin/perl 解释器的语法，并编程实现获取 /flag 
- Level 4.2 - 学习 /usr/bin/ruby 解释器的语法，并编程实现获取 /flag

Reference
- [Why You Can't Un-Root a Compromised Machine](https://gist.github.com/mudongliang/7b68290c2b4d5da0b7140c8b0e1827d0)