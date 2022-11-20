#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <ctype.h>

void reverse(char *string) {
	int string_length = strlen(string);

	for (int i = 0; i < string_length / 2; ++i) {
		char temp = string[i];
		string[i] = string[string_length - i - 1];
		string[string_length - i - 1] = temp;
	}
}

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if ((format_string[i] == '#') && (format_string[i+2] == 'g')) {
			i+=2;

			int j = 0;
			for (j = 0; j < strlen(param); ++j) {
				if (!isdigit(param[j]))
					break;
			}

		} else if((format_string[i] == '#') && (isdigit(format_string[i + 1])) && (format_string[i+1] == 'g')){
			i++;

			int j = 0;
			for (j = 0; j < strlen(param); ++j) {
				if (!isdigit(param[j]))
					break;
			}
						
			if (j < strlen(param)) {
				puts("");
				return -1;
			} else {
				reverse(param);
				printf("%d", atoi(param));
			}
		} else
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
