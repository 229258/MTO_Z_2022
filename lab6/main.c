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
		if ((format_string[i] == '#') && (format_string[i+1] == '.') && (isdigit(format_string[i + 2])) && (format_string[i+3] == 'd')) {
			i+=3;

			int j = 0;
			for (j = 0; j < strlen(param); ++j) {
				char c = param[j];
				if (isdigit(c))
					switch (c) {
						case '9':
							param[j] = '8';
							break;
						case '8':
							param[j] = '7';
							break;
						case '7':
							param[j] = '6';
							break;
						case '6':
							param[j] = '5';
							break;
						case '5':
							param[j] = '4';
							break;
						case '4':
							param[j] = '3';
							break;
						case '3':
							param[j] = '2';
							break;
						case '2':
							param[j] = '1';
							break;
						case '1':
							param[j] = '0';
							break;
						case '0':
							param[j] = '9';
							break;
						default:
							break;


					}
				else
					break;
			}
			if (j < strlen(param)) {
				puts("");
				return -1;
			} else {
				printf("%s", param);
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
