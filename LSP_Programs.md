1. Write a C program to create a new text file and write "Hello, World!" to it?
```
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(void)
{
	int fd,ret;
	char buf[]="Hello world";
	fd=open("myfile.txt",O_CREAT | O_WRONLY,0660);
	if(fd<0)
	{
		printf("Failed to open the file");
		return 1;
	}
	ret=write(fd,buf,strlen(buf));
	printf("written %d bytes into the file\n",ret);
	close(fd);
	return 0;
}
```
2.Develop a C program to open an existing text file and display its contents?
```
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(void)
{
	int fd,ret;
	char buff[1200];
	fd=open("myfile.txt",O_RDONLY);
	if(fd<0)
	{
		printf("File open failed");
		return 1;
	}
	while((ret=read(fd,buff,sizeof(buff)-1))>0)
	{
		buff[ret]='\0';
		printf("%s\n",buff);
	}
	close(fd);
	return 0;
}
```
3.Implement a C program to create a new directory named "Test" in the current directory? 
```
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(void)
{
	int result;
	result=mkdir("Test",0777);
	if(result==0)
	{
		printf("Directory created succesfully");
	}
	else
	{
		printf("Failed to create a directory");
	}
	return 0;
}
```
4. Write a C program to check if a file named "sample.txt" exists in the current directory?
```
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
	int fd;
	fd=open("myfile.txt",O_RDONLY);
	if(fd<0)
	{
		printf("File doesnot exist");
	}
	else
	{
		printf("File exist");
	}
	close(fd);
	return 0;
}
/*
 if (access("myfile.txt", F_OK) == 0)
    {
        printf("File exists\n");
    }
    else
    {
        printf("File does not exist\n");
    }
*/
```
5. Develop a C program to rename a file from "oldname.txt" to "newname.txt"?
```
#include<stdio.h>
int main(void)
{
	const char *old="myfile.txt";
	const char *new="file.txt";
	if(rename(old,new)==0)
	{
		printf("The old name %s is changed to new name %s\n",old,new);
	}
	else
	{
		printf("Rename failed\n");
	}
	return 0;
}
```
6. Implement a C program to delete a file named "delete_me.txt"?
```
#include<stdio.h>
int main(void)
{
	const char *name= "myfile.txt";
	if(remove(name)==0)
	{
		printf("File is deleted succesfully");
	}
	else
	{
		printf("File deletion failed");
	}
	return 0;
}
```
7.Write a C program to copy the contents of one file to another?
```
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	int fdsrc,fddst;
	char *src=argv[1];
	char *dst=argv[2];
	char buf;
	fdsrc=open(src,O_RDONLY,0);
	fddst=open(dst,O_CREAT | O_WRONLY,0666);
	while(read(fdsrc,&buf,1))
	{
		write(fddst,&buf,1);
	}
	close(fdsrc);
	close(fddst);
}
```
8.Develop a C program to move a file from one directory to another?
```
#include<stdio.h>
int main(int argc,char *argv[])
{
	if(rename(argv[1],argv[2])==0)
	{
		printf("File moved succesfully from %s to %s",argv[1],argv[2]);
	}
	else
	{
		printf("Failed");
		return 1;
	}
	return 0;
}
```
9.Implement a C program to list all files in the current directory?
```
#include<stdio.h>
#include<dirent.h>
int main(void)
{
	struct dirent *de;
	DIR *dr = opendir(".");
	if(dr==NULL)
	{
		perror("could not open the directory");
		return 1;
	}
	printf("Files in the current directory are:");
	while((de=readdir(dr))!=NULL)
	{
		if(de->d_name[0]!='.')
			printf("%s\n",de->d_name);
	}
	return 0;
}
```
10.Write a C program to get the size of a file named "file.txt"?
```
#include<stdio.h>
int main(int argc,char *argv[])
{
	FILE *fp;
	long size;
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("Error in opening the file");
		return 1;
	}
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	pclose(fp);
	printf("SIZE of the file is :%ld",size);
	return 0;
}
```
11. Develop a C program to check if a directory named "Test" exists in the current directory
```
#include<stdio.h>
#include<dirent.h>
int main(void)
{
	const char *dirName="Test";
	DIR *dir=opendir(dirName);
	if(dir)
	{
		printf("Directory %s exists.\n",dirName);
		closedir(dir);
	}
	else
	{
		printf("Directory %s doesnot exists.\n",dirName);
	}
	return 0;
}
```
12.Implement a C program to create a new directory named "Backup" in the parent directory
```
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
int main(void)
{
	const char *dirpath="../Backup";
	if(mkdir(dirpath,0755)==0)
	{
		printf("Directory is created succesfully");
	}
	else
	{
		if(errno==EEXIST)
		{
			printf("directory already exist");
		}
		else
		{
			printf("Error creating directory");
		}
	}
	return 0;
}
```
13.Write a C program to recursively list all files and directories in a given directory
#include<stdio.h>

14.Develop a C program to delete all files in a directory named "Temp"?
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>
int main(void)
{
	const char *dirpath="../Temp";
	DIR *dir;
	struct dirent *entry;
	char filepath[1024];
	struct stat filestat;
	dir=opendir(dirpath);
	if(dir==NULL)
	{
		printf("Error opening directory");
		return 1;
	}
	while((entry=readdir(dir))!=NULL)
	{
		if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0)
			continue;	
	snprintf(filepath,sizeof(filepath),"%s/%s",dirpath,entry->d_name);

	if(stat(filepath,&filestat)==0 && S_ISREG(filestat.st_mode))
	{
		if(remove(filepath)==0)
		{
			printf("Deleted file:%s\n",filepath);
		}
		else
		{
			perror(filepath);
		}
	}
	}
	closedir(dir);
	return 0;
}
```
15.Implement a C program to count the number of lines in a file named "data.txt"?
```
#include<stdio.h>
int main(void)
{
	FILE *file=fopen("myfile.txt","r");
	int lines=0;
	char ch,last=0;
	if(file==NULL)
	{
		printf("could not open file\n");
		return 1;
	}
	while((ch=fgetc(file))!=EOF)
	{
		if(ch=='\n')
		{
			lines++;
		}
	}
	fclose(file);
	if(last!='\n' && last!=0)
	{
		lines++;
	}
	printf("Number of lines in file:%d\n",lines);
	return 0;
}
```
16.Write a C program to append "Goodbye!" to the end of an existing file
```
#include<stdio.h>
int main(void)
{
	FILE *file=fopen("myfile.txt","a");
	if(file == NULL)
	{
		printf("could not open file");
		return 1;
	}
	fprintf(file,"Goodbye\n");
	fclose(file);
	printf("File appened succesfully");
	return 0;
}
```
17.Implement a C program to change the permissions of a file named "file.txt" to read only
```
#include<stdio.h>
#include<sys/stat.h>
int main()
{
	const char *file="myfile.txt";
	if(chmod(file,0444)==0)
	{
		printf("permissions changed it is now read only file");
	}
	else
	{
		printf("chmod failed");
		return 1;
	}
	return 0;
}
```
18. Write a C program to change the ownership of a file named "file.txt" to the user "user1"?
```
#include<stdio.h>
#include<unistd.h>
#include<pwd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(void)
{
	const char *file="myfile.txt";
	const char *user="veeru";
	struct passwd *pwd = getpwnam(user);
	if(pwd == NULL)
	{
		printf("getpawn failed");
		return 1;
	}
	if(chown(file,pwd->pw_uid,-1)!=0)
	{
		printf("chown failed");
		return 1;
	}
	printf("ownership is changed");
	return 0;
}
```
19. Develop a C program to get the last modified timestamp of a file named "file.txt"?
```
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
int main()
{
	const char *file="myfile.txt";
	struct stat filestat;
	if(stat(file,&filestat)!=0)
	{
		printf("stat failed");
		return 1;
	}
	printf("Last modified time of %s: %s",file,ctime(&filestat.st_mtime));
	return 0;
}
```
20.Implement a C program to create a temporary file and write some data to it?
```
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE *tmp=tmpfile();
	if(tmp==NULL)
	{
		printf("Failed to create temporary file");
		return 1;
	}
	fprintf(tmp,"This is a temporary file.\n Temporary data inside\n");
	rewind(tmp);
	char ch;
	while((ch=fgetc(tmp)!=EOF))
	{
		putchar(ch);
	}
	fclose(tmp);
	return 0;
}
```
21.Write a C program to check if a given path refers to a file or a directory?
```
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	struct stat pathstat;
	 if (stat(argv[1], &pathstat) != 0) {
        perror("stat failed");
        return 1;
    }

    if (S_ISREG(pathstat.st_mode)) {
        printf("'%s' is a regular file.\n", argv[1]);
    } else if (S_ISDIR(pathstat.st_mode)) {
        printf("'%s' is a directory.\n", argv[1]);
    } else {
        printf("'%s' is neither a regular file nor a directory.\n", argv[1]);
    }

    return 0;
}
```
22. Develop a C program to create a hard link named "hardlink.txt" to a file named "source.txt"?
```
#include<stdio.h>
#include<unistd.h>

int main(void)
{
    const char *source = "myfile.txt";
    const char *linkname = "hardlink.txt";

    // Create hard link
    if (link(source, linkname) == 0)
    {
        printf("Hard link '%s' created for file '%s'.\n", linkname, source);
    }
    else
    {
        perror("link failed");
        return 1;
    }

    return 0;
}
```
23. Implement a C program to read and display the contents of a CSV file named "data.csv"
```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("data.csv", "r");
    char line[1024];

    if (file == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    printf("Contents of data.csv:\n");

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);  // Print each line as-is
    }

    fclose(file);
    return 0;
}
```
24.Write a C program to get the absolute path of the current working directory?
```
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
    char path[PATH_MAX];  // PATH_MAX is the maximum length allowed

    // Get current working directory
    if (getcwd(path, sizeof(path)) != NULL)
    {
        printf("Current working directory: %s\n", path);
    }
    else
    {
        perror("getcwd() error");
        return 1;
    }

    return 0;
}
```
25.Develop a C program to get the size of a directory named "Documents"?
```
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
int main(void)
{
	const char *dpath="../signals";
	struct dirent *entry;
	struct stat st;
	DIR *dir;
	char fpath[512];
	long size=0;
	dir=opendir(dpath);
	if(dir==NULL)
	{
		printf("opendir failed");
		return 1;
	}
	while((entry=readdir(dir))!=NULL)
	{
		if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)
		{
			continue;
		}
		snprintf(fpath,sizeof(fpath),"%s/%s",dpath,entry->d_name);
		if(stat(fpath,&st)==0 && S_ISREG(st.st_mode))
		{
			size=size + st.st_size;
		}
	}
	closedir(dir);
	printf("Total size of files in '%s':%ld bytes\n",dpath,size);
	return 0;
}
```
26.Implement a C program to recursively copy all files and directories from one directory to another
```
#include<stdio.h>
```
27.Write a C program to get the number of files in a directory named "Images"?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(void) {
    const char *dirpath = "./Images";  // Path to the Images directory
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char fullpath[1024];
    int file_count = 0;

    dir = opendir(dirpath);
    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", dirpath, entry->d_name);

        if (stat(fullpath, &file_stat) == 0 && S_ISREG(file_stat.st_mode)) {
            file_count++;
        }
    }

    closedir(dir);

    printf("Number of files in '%s': %d\n", dirpath, file_count);
    return 0;
}
```
Develop a C program to create a FIFO (named pipe) named "myfifo" in the current directory
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
    const char *fifo_path = "./myfifo";

    // Create the FIFO with read-write permissions (0666)
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }

    printf("FIFO '%s' created successfully.\n", fifo_path);
    return 0;
}
```
//mplement a C program to read data from a FIFO named "myfifo"?
```
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    const char *fifo_path = "./myfifo";
    char buffer[256];
    int fd;

    // Open FIFO for reading
    fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open FIFO for reading");
        return 1;
    }

    printf("Waiting for data from FIFO...\n");

    // Read data from FIFO
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Received from FIFO: %s\n", buffer);
    } else {
        printf("No data read or error occurred.\n");
    }

    close(fd);
    return 0;
}
```
// Write a C program to truncate a file named "file.txt" to a specified length?
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    const char *filename = "myfile.txt";
    off_t new_length;

    printf("Enter the length to truncate '%s' to: ", filename);
    if (scanf("%ld", &new_length) != 1 || new_length < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (truncate(filename, new_length) == -1) {
        perror("truncate failed");
        return 1;
    }

    printf("File '%s' truncated to %ld bytes successfully.\n", filename, (long)new_length);
    return 0;
}
```
//. Develop a C program to search for a specific string in a file named "data.txt" and 
//display the line number(s) where it occurs? 
```
#include<stdio.h>
#include<string.h>
int main(void)
{
	FILE *file=fopen("myfile.txt","r");
	if(file== NULL)
	{
		printf("couldnot open file");
		return 1;
	}
	char line[1024];
	char search[200];
	int linenumber=0;
	int found=0;
	printf("Enter the string to search:");
	fgets(search,sizeof(search),stdin);
	size_t len=strlen(search);
	if(len>0 && search[len-1]=='\n')
	{
		search[len-1]='\0';
	}
	while(fgets(line,sizeof(line),file))
	{
		linenumber++;
		if(strstr(line,search)!=NULL)
		{
			printf("Found on line %d: %s\n",linenumber,line);
			found=1;
		}
	}
	if(!found)
	{
		printf("string \"%s\" not found in the file.\n",search);
	}
	fclose(file);
	return 0;
}
```
// Implement a C program to get the file type (regular file, directory, symbolic link, etc.) of 
//a given path?
```
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
int main(void)
{
	char path[255];
	struct stat filestat;
	printf("Enter the file or directory path");
	scanf("%255s",path);
	if(lstat(path,&filestat)!=0)
	{
		printf("lstat");
		return 1;
	}
	if (S_ISREG(filestat.st_mode)) {
        printf("It is a regular file.\n");
    } else if (S_ISDIR(filestat.st_mode)) {
        printf("It is a directory.\n");
    } else if (S_ISLNK(filestat.st_mode)) {
        printf("It is a symbolic link.\n");
    } else if (S_ISCHR(filestat.st_mode)) {
        printf("It is a character device.\n");
    } else if (S_ISBLK(filestat.st_mode)) {
        printf("It is a block device.\n");
    } else if (S_ISFIFO(filestat.st_mode)) {
        printf("It is a FIFO (named pipe).\n");
    } else if (S_ISSOCK(filestat.st_mode)) {
        printf("It is a socket.\n");
    } else {
        printf("Unknown file type.\n");
    }

    return 0;
}
```
// Develop a C program to get the permissions (mode) of a file 
```
#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
	struct stat filestat;
	if(argc<2)
	{
		printf("usage: %s <filename>\n",argv[0]);
		return 1;
	}
	if(stat(argv[1],&filestat)!=0)
	{
		printf("stat");
		return 1;
	}
	printf("File:%s\n",argv[1]);
	printf("octal permissions:%o\n",filestat.st_mode & 0777);

    printf("Symbolic Permissions: ");
    printf( (filestat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (filestat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (filestat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (filestat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (filestat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (filestat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (filestat.st_mode & S_IROTH) ? "r" : "-");
    printf( (filestat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (filestat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    return 0;
}
```
// Implement a C program to recursively delete a directory named "Temp" and all its 
//contents?
```
#include<stdio.h>
#
//36. Write a C program to read and display the first 10 lines of a file named "log.txt"?
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[1024];  // Buffer to store each line
    int count = 0;

    // Open the file in read mode
    file = fopen("log.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file 'log.txt'\n");
        return 1;
    }

    // Read and print the first 10 lines
    while (fgets(line, sizeof(line), file) != NULL && count < 10) {
        printf("%s", line);
        count++;
    }

    fclose(file); // Close the file
    return 0;
}
```
// Develop a C program to read data from a text file named "input.txt" and write it to 
//another file named "output.txt" in reverse order?
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin, *fout;
    long file_size;
    char ch;

    // Open input file for reading
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error: Cannot open input.txt for reading.\n");
        return 1;
    }

    // Open output file for writing
    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error: Cannot open output.txt for writing.\n");
        fclose(fin);
        return 1;
    }

    // Move file pointer to end of file
    fseek(fin, 0, SEEK_END);
    file_size = ftell(fin);

    // Read characters from end to start and write to output
    for (long i = file_size - 1; i >= 0; i--) {
        fseek(fin, i, SEEK_SET);
        ch = fgetc(fin);
        fputc(ch, fout);
    }

    printf("Data has been written to output.txt in reverse order.\n");

    fclose(fin);
    fclose(fout);
    return 0;
}
```
//Implement a C program to create a new directory named with the current date in the format "YYYY-MM-DD"? 
```
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(void) 
{
  time_t now;
  struct tm *timeinfo;
  char dirname[20];
  // Get current time
  time(&now);
  timeinfo = localtime(&now);
  // Format time as "YYYY-MM-DD"
  strftime(dirname, sizeof(dirname), "%Y-%m-%d", timeinfo);
  // Create the directory with 0755 permissions
  if (mkdir(dirname, 0755) == 0) 
  {
    printf("Directory '%s' created successfully.\n", dirname);
  }
  else
  {
    perror("Directory creation failed");
  }
  return 0;
}
```
//Write a C program to read and display the contents of a binary file named "binary.bin"?  
```
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  FILE *file;
  unsigned char buffer[16];  // Read in chunks of 16 bytes
  size_t bytesRead;
  int offset = 0;
  file = fopen("binary.bin", "rb");
  if (file == NULL) 
  {
    perror("Error opening binary file");
    return 1;
  }
  printf("Contents of binary.bin in hexadecimal:\n\n");
  while ((bytesRead = fread(buffer, sizeof(unsigned char), sizeof(buffer), file)) > 0) 
  {
    printf("0x%04X : ", offset);
    for (size_t i = 0; i < bytesRead; i++) 
    {
      printf("%02X ", buffer[i]);
    }
    printf("\n");
    offset += bytesRead;
  }
  fclose(file);
  return 0;
}
```
//Develop a C program to get the size of the largest file in a directory?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>


off_t get_largest_file_size(const char *path, char *largest_file_path);

int main(void) 
{
  const char *directory = ".";  // current directory
  char largest_file[PATH_MAX] = {0};
  off_t size = get_largest_file_size(directory, largest_file);
  if (size >= 0)
  {
    printf("Largest file: %s\n", largest_file);
    printf("Size: %ld bytes\n", size);
  }
  else
  {
    printf("Failed to determine largest file.\n");
  }
  return 0;
}
off_t get_largest_file_size(const char *path, char *largest_file_path) 
{
  struct dirent *entry;
  struct stat file_stat;
  DIR *dir = opendir(path);
  if (dir == NULL) 
  {
    perror("opendir failed");
    return -1;
  }
  off_t max_size = 0;
  char full_path[PATH_MAX];
  while ((entry = readdir(dir)) != NULL) 
  {
    // Ignore "." and ".."
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
       continue;
    snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
    if (stat(full_path, &file_stat) == -1) 
    {
      perror("stat failed");
      continue;
    }
    if (S_ISDIR(file_stat.st_mode)) 
    {
      // Recurse into subdirectory
      off_t sub_size = get_largest_file_size(full_path, largest_file_path);
      if (sub_size > max_size) 
      {
        max_size = sub_size;
      }
    }
    else if (S_ISREG(file_stat.st_mode)) 
    {
      // It's a regular file
      if (file_stat.st_size > max_size) 
      {
        max_size = file_stat.st_size;
        strcpy(largest_file_path, full_path);
      }
    }
  }
  closedir(dir);
  return max_size;
}
```
//Implement a C program to check if a file named "data.txt" is readable?
```
#include <stdio.h>
#include <unistd.h>

int main(void) 
{
  const char *filename = "message.txt";
  // Use access() with R_OK to check readability
  if (access(filename, R_OK) == 0)
  {
     printf("The file \"%s\" is readable.\n", filename);
  }
  else
  {
    perror("File check failed");
  }
  return 0;
}
```
//Write a C program to create a new directory named "Logs" and move all files with the ".log" extension into it?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) 
{
  DIR *d;
  struct dirent *dir;
  char src_path[512], dest_path[512];
  // Step 1: Create "Logs" directory if it doesn't exist
  if (mkdir("Logs", 0777) == -1) 
  {	 
    perror("mkdir");
    // Continue anyway in case it already exists
  }
  else
  {
    printf("Directory 'Logs' created successfully.\n");
  }
  // Step 2: Open current directory
  d = opendir(".");
  if (d == NULL)
  {
    perror("opendir");
    return 1;
  }
  // Step 3: Read directory entries
  while ((dir = readdir(d)) != NULL) 
  {
    // Skip . and ..
    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
        continue;
    // Check for ".log" extension
    if (strstr(dir->d_name, ".log") != NULL &&
            strcmp(dir->d_name + strlen(dir->d_name) - 4, ".log") == 0) 
    {
      // Construct source and destination paths
      snprintf(src_path, sizeof(src_path), "./%s", dir->d_name);
      snprintf(dest_path, sizeof(dest_path), "./Logs/%s", dir->d_name);
      // Move the file
      if (rename(src_path, dest_path) == 0) 
      {
        printf("Moved: %s --> Logs/\n", dir->d_name);
      }
      else
      {
         perror("rename");
      }
    }
  }
  closedir(d);
  return 0;
}
```
//Develop a C program to check if a file named "config.ini" is writable?
```
#include <stdio.h>
#include <unistd.h>

int main(void) 
{
  char *filename = "config.ini";
  // Check write permission using access()
  if (access(filename, W_OK) == 0) 
  {
    printf("The file \"%s\" is writable.\n", filename);
  }
  else 
  {
    perror("Access check failed");
    printf("The file \"%s\" is not writable.\n", filename);
  }
  return 0;
}
```
//Implement a C program to read the contents of a text file named "instructions.txt" and execute the instructions as shell commands?
```
#include <stdio.h>

int main(void) 
{
  FILE *f = fopen("execute.txt", "w");
  if (!f) 
  {
    perror("Unable to create instructions.txt");
    return 1;
  }
  fprintf(f, "echo \"Hello from shell command\"\n");
  fprintf(f, "pwd\n");
  fprintf(f, "ls -l\n");
  fprintf(f, "date\n");
  fprintf(f, "whoami\n");
  fclose(f);
  printf("instructions.txt created successfully.\n");
  return 0;
}
```
//Write a C program to get the number of hard links to a file named "file.txt"?
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(void)
{
  struct stat fileStat;
  // Get file stats
  if (stat("file2.txt", &fileStat) < 0)
  {
    perror("stat() failed");
    return 1;
  }
  // Display number of hard links
  printf("Number of hard links to file.txt: %lu\n", (unsigned long)fileStat.st_nlink);
  return 0;
}
```
// Develop a C program to copy the contents of all text files in a directory into a single file named "combined.txt"?
```
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(void) 
{
  DIR *dir;
  struct dirent *entry;
  FILE *src, *dest;
  char buffer[1024];
  dir = opendir(".");
  if (dir == NULL)
  {
    perror("Failed to open current directory");
    return 1;
  }
  dest = fopen("combined.txt", "w");
  if (dest == NULL)
  {
    perror("Failed to open combined.txt");
    closedir(dir);
    return 1;
  }
  while ((entry = readdir(dir)) != NULL)
  {
    // Check for .txt extension and exclude combined.txt itself
    if (strstr(entry->d_name, ".c") != NULL && strcmp(entry->d_name, "combined.txt") != 0)
    {
      src = fopen(entry->d_name, "r");
      if (src == NULL) 
      {
        perror("Failed to open source file");
        continue;
      }
      size_t n;
      while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0)
      {	      
	fwrite(buffer, 1, n, dest);    
      }
      fclose(src);
    }
  }
  fclose(dest);
  closedir(dir);
  printf("All text files have been combined into combined.txt\n");
  return 0;
}
```
//Implement a C program to recursively calculate the total size of all files in a directory and its subdirectories?     
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

long long get_directory_size(const char *path);

int main(void)
{
  const char *target_directory = ".";  // current directory
  long long total_size = get_directory_size(target_directory);
  printf("Total size of all files: %lld bytes\n", total_size);
  return 0;
}

long long get_directory_size(const char *path)
{
  struct dirent *entry;
  struct stat statbuf;
  DIR *dir = opendir(path);
  long long total_size = 0;
  if (!dir) 
  {
    perror("Failed to open directory");
    return 0;
  }
  while ((entry = readdir(dir)) != NULL) 
  {
    char fullpath[1024];
    // Skip current and parent directory entries
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;
    snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
    if (stat(fullpath, &statbuf) == -1) 
    {
      perror("stat failed");
      continue;
    }
    if (S_ISDIR(statbuf.st_mode)) 
    {
      total_size += get_directory_size(fullpath); // Recurse into subdirectory
    }
    else if (S_ISREG(statbuf.st_mode)) 
    {
      total_size += statbuf.st_size; // Add file size
    }
  }
  closedir(dir);
  return total_size;
}
```
//Write a C program to get the number of bytes in a file named "data.bin"?
```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *file = fopen("data.bin", "rb");  // Open in binary read mode
  if (file == NULL) 
  {
    perror("Error opening file");
    return 1;
  }
  // Move file pointer to end
  fseek(file, 0, SEEK_END);
  // Get current position, which is file size
  long size = ftell(file);
  fclose(file);
  if (size < 0) 
  {
    perror("ftell failed");
    return 1;
  }
  printf("Size of data.bin: %ld bytes\n", size);
  return 0;
}
```
//Develop a C program to create a new directory named with the current timestamp in the format "YYYY-MM-DD-HH-MM-SS"? 
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>

int main(void) 
{
  time_t now;
  struct tm *timeinfo;
  char dir_name[100];
  // Get current time
  time(&now);
  timeinfo = localtime(&now);
  // Format: YYYY-MM-DD-HH-MM-SS
  strftime(dir_name, sizeof(dir_name), "%Y-%m-%d-%H-%M-%S", timeinfo);
  // Create directory
  if (mkdir(dir_name, 0777) == 0)
  {
    printf("Directory '%s' created successfully.\n", dir_name);
  }
  else
  {
    perror("mkdir failed");
    return 1;
  }
  return 0;
}
```
//Implement a C program to open a file named "data.txt" in read mode and display its contents?  
```
#include <stdio.h>

int main(void) 
{
  FILE *fp;
  char ch;
  // Open the file in read mode
  fp = fopen("data.txt", "r");
  if (fp == NULL) 
  {
    perror("Failed to open file");
    return 1;
  }
  // Read and display each character
  while ((ch = fgetc(fp)) != EOF) 
  {
    putchar(ch);
  }
  // Close the file
  fclose(fp);
  return 0;
}
```
//Write a C program to create a symbolic link named "link.txt" to a file named "target.txt"? 
```
#include <stdio.h>
#include <unistd.h>

int main(void) 
{
  const char *target = "target.txt";
  const char *symlink_name = "link.txt";
  if (symlink(target, symlink_name) == 0) 
  {
    printf("Symbolic link '%s' created to '%s'\n", symlink_name, target);
  }
  else
  {
    perror("Error creating symbolic link");
  }
  return 0;
}
```
//Implement a C program to read and display the contents of a binary file named "binary.bin"?
```
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  FILE *file;
  unsigned char buffer[1024];
  size_t bytesRead, i;
  // Open the binary file for reading
  file = fopen("binary.bin", "rb");
  if (file == NULL) 
  {
    perror("Error opening file");
    return 1;
  }
  // Read and display the contents
  while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) 
  {
    for (i = 0; i < bytesRead; i++) 
    {
      printf("%c", buffer[i]);  // Prints as characters (might not be readable)
    }
  }
  fclose(file);
  return 0;
}
```
//Develop a C program to read data from a binary file named "data.bin" and display it in hexadecimal format?   
```
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  FILE *fp = fopen("data.bin", "rb");  // Open file in binary read mode
  if (fp == NULL)
  {
    perror("Failed to open data.bin");
    return 1;
  }
  unsigned char buffer[16];  // Buffer to read 16 bytes at a time
  size_t bytesRead;
  int offset = 0;
  while ((bytesRead = fread(buffer, sizeof(unsigned char), sizeof(buffer), fp)) > 0) 
  {
    printf("%08x  ", offset);  // Print offset in hexadecimal
    for (size_t i = 0; i < bytesRead; i++) 
    {
      printf("%02x ", buffer[i]);  // Print byte in hex
    }
    printf("\n");
    offset += bytesRead;
  }
  fclose(fp);
  return 0;
} 
```
