#include <linux/input.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(){
        char* keyboard = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
        int fd = open(keyboard, O_RDONLY);
        if(fd == -1){
                return EXIT_FAILURE;
        }else{
                struct input_event evt;
		int p = 0, e = 0;
		int c = 0, a = 0;
                while(1){
                   	ssize_t b = read(fd, &evt, sizeof(evt));
			if(evt.code == 0 || evt.code == 4 || evt.value == 1) continue;
			//printf("p = %d, e = %d, c = %d, a = %d\n", p, e, c, a);
			if(evt.code == 25){
				p = 1;
				if(c == 1 && a == 1){
					printf("Get some cappuccino!\n");
					c = 0, a = 0, p = 0;
				}
				if(e == 1){
                                        printf("I passed the Exam!\n");
                                        p = 0, e = 0;
                                }
			}else if(evt.code == 18){
				e = 1;
				if(p == 1){
					printf("I passed the Exam!\n");
					p = 0, e = 0;
				}
			}else if(evt.code == 46){
				c = 1;
				if(p == 1 && a == 1){
                                        printf("Get some cappuccino!\n");
                                        c = 0, a = 0, p = 0;
                                }
			}else if(evt.code == 30){
				a = 1;
				if(c == 1 && p == 1){
                                        printf("Get some cappuccino!\n");
                                        c = 0, a = 0, p = 0;
                                }

			}else{
				p = 0; e = 0;
				c = 0; a = 0;
			}
                }

        }
        fflush(stdout);
        return EXIT_SUCCESS;
}
