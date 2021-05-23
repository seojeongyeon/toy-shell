# Project #1 _ make shell
+ This code ccompiled in `Linux`
+ I added the functions
<br>
<br>

`1. color change`<br>
Output values changed color
```
#define COLOR_YELLOW "\x1B[33m"
#define COLOR_RESET "\x1B[0m"

printf(COLOR_YELLOW);
printf(COLOR_RESET);
```

<br>

`2. exit` <br>
if you write "exit", you can exit from the current location

```
if(!strcmp(command, "exit")){
        printf("exit!!!\n");
        return -1;
}
```

<br> 

`3. ls`  <br>
if you write "ls", you can see files from the current location
```
arg[0] = command;
if(!strcmp(command, "ls")){
    args[0] = "/bin/ls";
}
```

