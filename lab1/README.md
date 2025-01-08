# Lab 1

1. Create file1 in dac_lab directory

2. Add user bob and set permissions

```
sudo adduser bob
sudo passwd bob

setfacl -m u:bob:r-- file1
getfacl file1
```

3. Switch to bob and try to read file
```
su - bob
cat /home/ubuntu/dac_lab/file1
echo "test" >> /home/ubuntu/dac_lab/file1
```

*Both should fail, because bob does not have rights to the ubuntu home dir*

4. Add bob user rights to ubuntu home dir, try again

*Read works, write fails as expected*

5. Add bob user rights to dir1 and recursively to the dir

```
getfacl dac_lab/dir1/
# file: dac_lab/dir1/
# owner: ubuntu
# group: ubuntu
user::rwx
user:bob:rwx
group::rwx
mask::rwx
other::r-x

getfacl dac_lab/dir1/file3 
# file: dac_lab/dir1/file3
# owner: ubuntu
# group: ubuntu
user::rw-
user:bob:rwx
group::rw-
mask::rwx
other::r--
```

6. Created file `newfile` in dir1 and verified existence with cat

7. Remove bob's permissions from file1

```
setfacl -x u:bob dac_lab/file1
```

*Read still works! because user bob has permissions on the dir*

8. Clean up: remove user and test dir (dac_lab)
