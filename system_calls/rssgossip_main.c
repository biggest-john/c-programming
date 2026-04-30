#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void error(char msg[]){
	fprintf(stderr, "%s : %s\n", msg, strerror(errno)); 
	exit(1);
}
// remember to include the search_phrase when trying to run the programme.
int main(int argc, char *argv[]){
	char *feeds[] = {
		"http://rss.cnn.com/rss/cnn_topstories.rss", 
		"https://news.un.org/feed/subscribe/en/news/all/rss.xml",
	};
	int link_count = 2;
	char *search_phrase = argv[1];
	FILE *file_out;
	
	for(int i=0; i<link_count;i++){
		char buffer[256];
		sprintf(buffer, "RSS_FEED=%s", feeds[i]);
		char *env_var[] = {buffer, NULL};
		file_out = fopen("headlines.txt", "w"); //due to this w-mode, we will not get CNN news headlines.

		pid_t pid = fork();
	
		if(pid == -1){
			error("Can't fork process");
		}
		if(!pid){
				if(dup2(fileno(file_out),1) == -1){
					error("Can't redirect standard output.");
				}
				if(execle("/usr/bin/python3", "/usr/bin/python3", "./rssgossip.py","-u",search_phrase, NULL, env_var) == -1){
						error("Can't run script");
				}
			}
		int pid_status;
		//passing 0 as the last arguement into waitpid because we do not have any extra args to pass
		if(waitpid(pid, &pid_status, 0)==-1){
			error("Error while waiting for the child process");
		}
		}
		fclose(file_out);
		return 0;
	}
