# Lab 2 - Environment Variables

## Task 2 - process diff

The environment variables of each process were the same. diff had no output

```
SHELL=/bin/bash
PWD=/home/seed/csc3940/a2_env_vars
LOGNAME=seed
XDG_SESSION_TYPE=tty
MOTD_SHOWN=pam
HOME=/home/seed
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
SSH_CONNECTION=192.168.254.3 35558 10.16.103.195 22
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=seed
SHLVL=1
XDG_SESSION_ID=353
XDG_RUNTIME_DIR=/run/user/1000
SSH_CLIENT=192.168.254.3 35558 22
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:.
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
SSH_TTY=/dev/pts/4
_=./mpe
OLDPWD=/home/seed/csc3940
```

## Task 3 - execve()

The first variation with `execve("/usr/bin/env", argv, NULL);` produced no output, meaning there were no env variables in the new command memory space. Once changed to `execve("/usr/bin/env", argv, environ);`, it produced the above output, showing that we "passed" the environment down.

## Task 4 - system()

Running the program using `system()` to run the `env` command produced the env output above. Showing that the `system()` command passes the env down.

## Task 5 - Set-UID

I added setuid permissions to my compiled setuidenv.c program and set some environment variables (`PATH`, `LD_LIBRARY_PATH`, and `__TESTER`)

It then produced the following output where you can see my env variables that I set:

```
SHELL=/bin/bash
__TESTER=/nuthin
PWD=/home/seed/csc3940/a2_env_vars
LOGNAME=seed
XDG_SESSION_TYPE=tty
MOTD_SHOWN=pam
HOME=/home/seed
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
SSH_CONNECTION=192.168.254.3 34310 10.16.103.195 22
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=seed
SHLVL=1
XDG_SESSION_ID=357
XDG_RUNTIME_DIR=/run/user/1000
SSH_CLIENT=192.168.254.3 34310 22
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/nuthin
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
SSH_TTY=/dev/pts/1
OLDPWD=/home/seed/csc3940
_=./sue
```

This means setuid programs are vulnerable to attacks via the current user's environment variables

## Task 6 - PATH

I can set the path to my assignment dir and write and compile my own "malicious ls" program there:
`export PATH=/home/seed/csc3940/a2_env_vars/`

```
// bad_ls.c
extern char **environ;
int main() {
  int i = 0;
  while (environ[i] != NULL) {
    printf("%s\n", environ[i]);
    i++;
  }
  return 0;
}
```

```
// root_ls.c
int main()
{
  system("ls");
  return 0;
}
```

If I change my bad_ls.c program to run as root (setuid), the result is not run as root because of the /bin/dash protection. I can see that it is run by the seed user because the `HOME` env variable is set to `/home/seed` and `USER=seed`

```
SHELL=/bin/bash
PWD=/home/seed/csc3940/a2_env_vars
LOGNAME=seed
XDG_SESSION_TYPE=tty
MOTD_SHOWN=pam
HOME=/home/seed
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
SSH_CONNECTION=192.168.254.3 47768 10.16.103.195 22
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=seed
SHLVL=1
XDG_SESSION_ID=378
XDG_RUNTIME_DIR=/run/user/1000
SSH_CLIENT=192.168.254.3 47768 22
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/home/seed/csc3940/a2_env_vars/
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
SSH_TTY=/dev/pts/0
OLDPWD=/home/seed/csc3940
_=/home/seed/csc3940/a2_env_vars/ls
Command 'date' is available in the following places
 * /bin/date
 * /usr/bin/date
The command could not be located because '/bin:/usr/bin' is not included in the PATH environment variable.
date: command not found

```

After linking /bin/sh to /bin/zsh, the HOME dir and USER variables stayed the same.

## Task 7 - LD_PRELOAD

After changing the LD_PRELOAD env variable and compiling the programs:

1. As normal user, normal program

`Not sleeping!`

2. As normal user, set-uid program (owned by root)

No output with a slight delay

3. As root, set-uid program (owned by root)

`Not sleeping!`

4. As seed, set-uid program (owned by user1)

No output with a slight delay

---

I believe the difference here is that the LD_PRELOAD environment variable (or any other for that matter) are not set in the Set-UID user's environment when the command is run. Perhaps because it creates a child process in the Set-UID user's environment without passing down the variables (as we saw in task 3 with execve). It may also be sanitizing the LD_PRELOAD command when the user does not match the setuid.

## Task 8 - system() vs execve()

I have created a file `/root/no_write_seed.txt` as root and verified that the seed user cannot read or write to it without the catall command

After compiling the catall program, I can run it with a longer command line argument to run 2 commands with the root privilages 
```
catall "/root/no_write_seed.txt; rm /root/no_write_seed.txt"
This file should not be writable by seed 
```

This reads the file to stdout and then removes it with root privileges. I thought of this solution because of my experience preventing SQL injection in PHP and the like. Before trying this I also tried making my own "cat" program that would call remove() on the file and could be run by manipulating the PATH, but because the catall program runs `/bin/cat`, it kept finding the original `/bin/cat` instead of my program.

## Task 9 - Capability leak

There was no way I was going to figure this out on my own. I had no idea you could write to a file from the command line via a file descriptor. I knew it had something to do with the fd, because the program printed it, but I would never have found `echo "something" >&fd` organically

Once I ran that command inside the privileged process shell, I was able to write to the file at `/etc/zzz`
