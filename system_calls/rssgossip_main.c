#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// remember to include the search_phrase when trying to run the programme.
int main(int argc, char *argv[]){
	char *feeds[] = {
		"http://rss.cnn.com/rss/cnn_topstories.rss", 
		"https://news.un.org/feed/subscribe/en/news/all/rss.xml",
	};
	int link_count = 2;
	char *search_phrase = argv[1];
	
	for(int i=0; i<link_count;i++){
		char buffer[256];
		sprintf(buffer, "RSS_FEED=%s", feeds[i]);
		char *env_var[] = {buffer, NULL};

		pid_t pid = fork();


	
		if(pid == -1){
			fprintf(stderr, "Encountered some issues while trying to 'fork' current process: %s\n", strerror(errno));
			return 1;
		}
		if(!pid){
				if(execle("/usr/bin/python3", "/usr/bin/python3", "./rssgossip.py",search_phrase, NULL, env_var) == -1){
					fprintf(stderr, "Encountered issues running the script: %s\n", strerror(errno));
					return 2; 
				}
			}
		}
		return 0;
	}
