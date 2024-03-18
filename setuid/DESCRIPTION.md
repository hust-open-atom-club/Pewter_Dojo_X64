`pwn.hust.college` 平台核心之一是 `setUID` 标志位。当前 `/flag` 文件是 `root` 用户只读，`hacker` 并没有读权限。
挑战关卡要做的事情获取 `root` 权限，读取 `/flag`。而完成这种提权操作最简单的方法是 `setUID` 标志位。

```sh
hacker@welcome~:~$ ls -l /flag
-r--------. 1 root root 50 Mar 18 01:30 /flag
```
