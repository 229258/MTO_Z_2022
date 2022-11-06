#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <ctype.h>

void reverse(char *string) {

}


int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'g')){
			i++;

			int j = 0;
			for (j = 0; j < strlen(param); ++j) {
				if (!isdigit(param[j]))
					break;
			
			}



		}else
			putchar(format_string[i]);
	}
	puts("");
	return 0;
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}
